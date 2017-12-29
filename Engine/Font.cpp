#include "Font.h"

void Font::Draw(const VecI& pos,const std::string & text, Graphics & gfx) const
{
	VecI curPos = pos;
	for (auto c : text)
	{
		if (c == ' ')
		{
			curPos.x += GlyphWidth;
		}
		else
		{
			gfx.DrawSprite(curPos, GetCharaterRect(c), font, SpriteEffect::Subtitute(chroma, Colors::Blue));
			curPos.x += GlyphWidth;
		}
	}
}

RectI Font::GetCharaterRect(char c) const
{
	const int Index = c - ' ';
	const int xIndex = Index % Collums;
	const int yIndex = Index / Collums;
	return RectI({ xIndex*GlyphWidth, yIndex*GlyphHeight }, GlyphWidth, GlyphHeight);
}
