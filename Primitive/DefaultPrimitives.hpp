#pragma once
#include "OpenGL_Mirror\BasicTypes\BasicColors.hpp"

namespace mgl {
	class Primitive;

	enum class PoligonPlacing {
		zero_Center, 
		zero_TopLeftCorner, zero_TopRightCorner, 
		zero_BottomLeftCorner, zero_BottomRightCorner
	};
	Primitive* changePlacing(Primitive* primitive, PoligonPlacing from, PoligonPlacing to);

	Primitive* generateN_Polygon(size_t n = 6, Color* color = Colors::Black(), PoligonPlacing placing = PoligonPlacing::zero_Center, bool isFilled = false);
	Primitive* generateRectangle(float aspectRatio = 1.f, Color* color = Colors::Black(), PoligonPlacing placing = PoligonPlacing::zero_Center, bool isFilled = false);
	Primitive* generateCircle(size_t n = 60, Color* color = Colors::Black(), PoligonPlacing placing = PoligonPlacing::zero_Center, bool isFilled = false);
}