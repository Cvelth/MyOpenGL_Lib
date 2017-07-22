#include "OpenGL_Mirror\OpenGL_Dependency\OpenGL.h"
#include "FunctionsMirror.hpp"
#include "OpenGL_Mirror\BasicTypes\Color.hpp"
#include "OpenGL_Mirror\BasicTypes\Buffer.hpp"

void mgl::setClearColor(const Color & c) {
	glClearColor(c.r(), c.g(), c.b(), c.a());
}

void mgl::setLineWidth(float w, SmoothMode mode) {
	glLineWidth(w);
	enableLineSmooth(mode);
}

void mgl::setPointSize(float s) {
	glPointSize(s);
}

void mgl::enableBlend(BlendEnum s, BlendEnum d) {
	glBlendFunc(_enumSwitch(s), _enumSwitch(d));
	glEnable(GL_BLEND);
}

void mgl::enableBlend(const Buffer & b, BlendEnum s, BlendEnum d) {
	glBlendFunci(b.id(), _enumSwitch(s), _enumSwitch(d));
}

void mgl::enableLineSmooth(SmoothMode mode) {
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, _enumSwitch(mode));
}

void mgl::enablePolygonSmooth(SmoothMode mode) {
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, _enumSwitch(mode));
}

void mgl::enablePointSmooth(SmoothMode mode) {
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, _enumSwitch(mode));
}

std::string mgl::getError() {
	return (const char*) glewGetErrorString(glGetError());
}

void mgl::clearColorBuffer() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void mgl::viewport(size_t x, size_t y, size_t width, size_t height) {
	glViewport(GLint(x), GLint(y), GLsizei(width), GLsizei(height));
}