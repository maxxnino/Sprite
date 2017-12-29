#pragma once
#include "Surface.h"
#include "Rect.h"
#include "Graphics.h"
#include "SpriteEffect.h"

class Font
{
public:
	Font(const std::string& filename, Color chroma)
		:
		font(filename),
		chroma(chroma),
		GlyphWidth(font.GetWidth()/ Collums),
		GlyphHeight(font.GetHeight()/ Rows)
	{}
	void Draw(const VecI& pos, const std::string& words, Graphics& gfx) const;
private:
	RectI GetCharaterRect(const char c) const;
private:
	Surface font;
	Color chroma;
	int Collums = 32;
	int Rows = 3;
	int GlyphWidth;
	int GlyphHeight;
};
