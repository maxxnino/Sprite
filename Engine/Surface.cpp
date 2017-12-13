#include "Surface.h"
#include <fstream>
#include <cassert>
#include "ChiliWin.h"

Surface::Surface(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);
	assert(file);

	BITMAPFILEHEADER bMapFileHeader;
	file.read(reinterpret_cast<char*>(&bMapFileHeader), sizeof(bMapFileHeader));

	BITMAPINFOHEADER bMapInfoHeader;
	file.read(reinterpret_cast<char*>(&bMapInfoHeader), sizeof(bMapInfoHeader));


	assert(bMapInfoHeader.biCompression == BI_RGB);
	assert(bMapInfoHeader.biBitCount == 32 || bMapInfoHeader.biBitCount == 24);
	int yStart = 0;
	int yEnd = 0;
	int dy = 0;
	if (bMapInfoHeader.biHeight > 0 )
	{
		height = bMapInfoHeader.biHeight;
		yStart = height - 1;
		yEnd = -1;
		dy = -1;
	}
	else
	{
		height = -bMapInfoHeader.biHeight;
		yStart = 0;
		yEnd = height;
		dy = 1;
	}
	width = bMapInfoHeader.biWidth;

	pPixel = new Color[width*height];

	const int padding = (4 - (width * 3) % 4) % 4;

	file.seekg(bMapFileHeader.bfOffBits);
	for (; yStart != yEnd; yStart +=dy)
	{
		for (int x = 0; x < width; x++)
		{
			PutPixel(x, yStart,Color( (unsigned char)file.get(),(unsigned char)file.get() ,(unsigned char)file.get() ));
			if (bMapInfoHeader.biBitCount == 32)
			{
				file.seekg(1,std::ios::cur);
			}
		}
		if (bMapInfoHeader.biBitCount == 24)
		{
			file.seekg(padding,std::ios::cur);
		}
	}
}

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixel(new Color[width*height])
{}

Surface::Surface(Surface& src)
	:
	Surface(src.width,src.height)
{
	const int totalPixel = width*height;
	for (int i = 0; i < totalPixel; i++)
	{
		pPixel[i] = src.pPixel[i];
	}
}

Surface & Surface::operator=(const Surface & rhs)
{
	width = rhs.width;
	height = rhs.height;
	delete[] pPixel;
	const int totalPixel = width*height;
	for (int i = 0; i < totalPixel; i++)
	{
		pPixel[i] = rhs.pPixel[i];
	}
	return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
	pPixel[x + y *width] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	return pPixel[x + y* width];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

RectI Surface::GetRect() const
{
	return RectI(0,0,width,height);
}

Surface::~Surface()
{
	delete[] pPixel;
	pPixel = nullptr;
}
