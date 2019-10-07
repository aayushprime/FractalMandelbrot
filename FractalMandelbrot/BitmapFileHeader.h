#pragma once
#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>

#pragma pack(2)
namespace fg
{
	struct BitmapFileHeader {
		char header[2]{ 'B','M' };
		int32_t fileSize;
		int32_t reserved{ 0 };
		int32_t dataOffet;

	};
#pragma pack(pop)
}
#endif