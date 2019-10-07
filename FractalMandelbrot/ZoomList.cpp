#include "ZoomList.h"

namespace fg
{
	ZoomList::ZoomList(int width, int height):m_height(height),m_width(width) {	}
	
	void ZoomList::add(const Zoom& zoom) {
		zooms.push_back(zoom);

		m_xCenter += (zoom.x - m_width / 2) * m_scale;
		m_yCenter += (zoom.y - m_height / 2) * m_scale;

		m_scale *= zoom.scale;
	}

	std::pair<double, double> ZoomList::doZoom(int x, int y) {
		double xFractal = (x - m_width / 2) * m_scale + m_xCenter;
		double yFractal = (y - m_height / 2) * m_scale + m_yCenter;

		return std::pair<double, double>(xFractal, yFractal);
	}

}