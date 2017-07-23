#include "BasicColors.hpp"
#include "Color.hpp"

mgl::Color* mgl::Colors::Black() {
	return new mgl::Color(0.f, 0.f, 0.f, 1.f);
}
mgl::Color* mgl::Colors::White() {
	return new mgl::Color(1.f, 1.f, 1.f, 1.f);
}
mgl::Color* mgl::Colors::Red() {
	return new mgl::Color(1.f, 0.f, 0.f, 1.f);
}
mgl::Color* mgl::Colors::Green() {
	return new mgl::Color(0.f, 1.f, 0.f, 1.f);
}
mgl::Color* mgl::Colors::Blue() {
	return new mgl::Color(0.f, 0.f, 1.f, 1.f);
}