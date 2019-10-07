#pragma once
#include <vector>
#include <utility>

#include "Zoom.h"

namespace fg
{
	class ZoomList
	{
	private:
		double m_xCenter{};
		double m_yCenter{};
		double m_scale{1.0};

		int m_width{};
		int m_height{};
		std::vector<Zoom> zooms;

	public:
		ZoomList(int width, int height);
		void add(const Zoom& zoom);
		std::pair<double, double> doZoom(int x, int y);
	};


}
