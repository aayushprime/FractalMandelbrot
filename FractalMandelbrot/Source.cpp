#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

int main() {

	const int WIDTH = 2400;			//x 800
	const int HEIGHT = 2400;		//y 600
	fg::Bitmap bitmap(HEIGHT, WIDTH);

	fg::RGB startColor = { 0,0,0 };
	fg::RGB endColor = { 255,128,74 };
	fg::RGB colorDiff =  endColor - startColor;

	//double min = 999999;
	//double max = -999999;

	fg::ZoomList zoomList(WIDTH, HEIGHT);
	//Add entries to the zoomlist object for continuously zooming into output of the 
	zoomList.add(fg::Zoom(WIDTH / 2, HEIGHT / 2, 4.0/WIDTH));
	//zoomList.add(fg::Zoom(295, HEIGHT - 202, 0.1));
	//zoomList.add(fg::Zoom(312, HEIGHT - 304, 0.1));
	
	std::unique_ptr<int[]> histogram(new int[fg::Mandelbrot::MAX_ITERATIONS + 1]{});
	std::unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{});

	//First loop : building the histogram
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			//Change screen space to normalized coordinates (-1 to 1)
			//Apply same scale to both x and y axis
			std::pair<double, double> coords = zoomList.doZoom(x, y);

			int iterations = fg::Mandelbrot::getIterations(coords.first, coords.second);
			fractal[y * WIDTH + x] = iterations;

			if (iterations != fg::Mandelbrot::MAX_ITERATIONS)
			{
				histogram[iterations]++;
			}

			
		}
	}

	//Second : Calculating the total number of iterations
	int total = 0;
	for (int i = 0; i < fg::Mandelbrot::MAX_ITERATIONS; i++){
		total += histogram[i];
	}

	//Drawing 
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = fractal[y * WIDTH + x];
			if (iterations != fg::Mandelbrot::MAX_ITERATIONS) {

				double hue = 0.0;
				for (int i = 0; i <= iterations; i++) {
					hue += (double)histogram[i] / total;
				}
				red = startColor.r + colorDiff.r * hue;
				green = startColor.g + colorDiff.g * hue;
				blue = startColor.b + colorDiff.b * hue;
			}

			bitmap.setPixel(x, y, red, green, blue);

		}
	}

	//Write the file
	bitmap.write("test.bmp");
	//std::cout << min << ":" << max << std::endl;

	std::cout << "Finished " << std::endl;
	std::cin.get();
	return 0;
}