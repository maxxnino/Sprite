#pragma once
#include "Rect.h"
#include "Colors.h"
#include <string>

class Surface
{
public:
	Surface(const std::string& filename);
	Surface(int width, int height);
	Surface(Surface& src);
	Surface& operator=(const Surface& rhs);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
	~Surface();
private:
	int width;
	int height;
	Color* pPixel;
};
