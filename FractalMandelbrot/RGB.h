#pragma once
namespace fg
{
	struct RGB
	{
		double r;
		double b;
		double g;
		RGB(double r, double g, double b);

	};

	RGB operator-(const RGB& first, const RGB& second);
}