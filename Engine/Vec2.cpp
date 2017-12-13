#include "Vec2_.h"
#include <cmath>

Vec2_::Vec2_( float x_in,float y_in )
	:
	x( x_in ),
	y( y_in )
{
}

Vec2_ Vec2_::operator+( const Vec2_& rhs ) const
{
	return Vec2_( x + rhs.x,y + rhs.y );
}

Vec2_& Vec2_::operator+=( const Vec2_& rhs )
{
	return *this = *this + rhs;
}

Vec2_ Vec2_::operator*( float rhs ) const
{
	return Vec2_( x * rhs,y * rhs );
}

Vec2_& Vec2_::operator*=( float rhs )
{
	return *this = *this * rhs;
}

Vec2_ Vec2_::operator-( const Vec2_& rhs ) const
{
	return Vec2_( x - rhs.x,y - rhs.y );
}

Vec2_& Vec2_::operator-=( const Vec2_& rhs )
{
	return *this = *this - rhs;
}

float Vec2_::GetLength() const
{
	return std::sqrt( GetLengthSq() );
}

float Vec2_::GetLengthSq() const
{
	return x * x + y * y;
}

Vec2_& Vec2_::Normalize()
{
	return *this = GetNormalized();
}

Vec2_ Vec2_::GetNormalized() const
{
	const float len = GetLength();
	if( len != 0.0f )
	{
		return *this * (1.0f / len);
	}
	return *this;
}
