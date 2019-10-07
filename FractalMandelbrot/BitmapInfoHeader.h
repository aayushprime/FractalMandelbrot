#pragma once
#ifndef BITMAPINFOHEADER_H
#define BITMAPINFOHEADER_H

#include <cstdlib>

#pragma pack(2)

namespace fg
{
	struct BitmapInfoHeader {
		int32_t headerSize{ 40 };
		int32_t width;
		int32_t height;
		int16_t planes{ 1 };
		int16_t bitsPerPixel{ 24 };
		int32_t compression{ 0 };
		int32_t dataSize{ 0 };
		int32_t horizontalResolution{ 2400 };
		int32_t verticalResolution{ 2400 };
		int32_t colors{ 0 };
	};
#pragma pack(pop)
}
#endif