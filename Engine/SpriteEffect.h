#pragma once
#include "Graphics.h"
#include "Vec2.h"

namespace SpriteEffect
{
	class Chroma
	{
	public:
		Chroma (Color chroma)
			:
			chroma(chroma)
		{}
		void operator()(VecI pos, Color src,Graphics& gfx)
		{
			if (src != chroma)
			{
				gfx.PutPixel(pos.x, pos.y, src);
			}
		}
	private:
		Color chroma;
	};
	class Copy
	{
	public:
		void operator()(VecI pos, Color src, Graphics& gfx)
		{
			gfx.PutPixel(pos.x, pos.y, src);
		}
	};
	class Ghost
	{
	public:
		Ghost(Color chroma)
			:
			chroma(chroma)
		{}
		void operator()(VecI pos, Color src, Graphics& gfx)
		{
			if (src != chroma)
			{
				Color bgColor = gfx.GetPixel(pos.x, pos.y);
				Color blendedPixel = { 
					unsigned char((src.GetR() + bgColor.GetR()) / 2),
					unsigned char((src.GetG() + bgColor.GetG()) / 2),
					unsigned char((src.GetB() + bgColor.GetB()) / 2) };
				gfx.PutPixel(pos.x, pos.y, blendedPixel);
			}
		}
	private:
		Color chroma;
	};
	class EffectStatus
	{
	public:
		EffectStatus(Color chroma,Color effect)
			:
			chroma(chroma),
			effect(effect)
		{}
		void operator()(VecI pos, Color src, Graphics& gfx)
		{
			if (src != chroma)
			{
				Color blendedPixel = { 
					unsigned char((src.GetR() + effect.GetR()) / 2),
					unsigned char((src.GetG() + effect.GetG()) / 2),
					unsigned char((src.GetB() + effect.GetB()) / 2) };
				gfx.PutPixel(pos.x, pos.y, blendedPixel);
			}
		}
	private:
		Color chroma;
		Color effect;
	};
	class Subtitute
	{
	public:
		Subtitute(Color chroma, Color sub)
			:
			chroma(chroma),
			sub(sub)
		{}
		void operator()(VecI pos, Color src, Graphics& gfx)
		{
			if (src != chroma)
			{
				gfx.PutPixel(pos.x, pos.y, sub);
			}
		}
	private:
		Color chroma;
		Color sub;
	};
	class CopyGhost
	{
	public:
		void operator()(VecI pos, Color src, Graphics& gfx)
		{
			Color bgColor = gfx.GetPixel(pos.x, pos.y);
			Color blendedPixel = {
				unsigned char((src.GetR() + bgColor.GetR()) / 2),
				unsigned char((src.GetG() + bgColor.GetG()) / 2),
				unsigned char((src.GetB() + bgColor.GetB()) / 2) };
			gfx.PutPixel(pos.x, pos.y, blendedPixel);
		}
	};
};