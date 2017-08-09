#pragma once

#define MGL_FORCE_NVIDIA_GPU_USAGE extern "C" {_declspec(dllexport) int NvOptimusEnablement = 0x00000001;}

#if defined MGL_INCLUDE_ALL
	#define MGL_INCLUDE_WINDOWS
	#define MGL_INCLUDE_DRAWABLE_OBJECT
	#define MGL_INCLUDE_PRIMITIVES

	#define MGL_INCLUDE_MATH

	#define MGL_INCLUDE_OPENGL_FUNCTIONS_MIRROR
	#define MGL_INCLUDE_OPENGL_EXPERIMENTAL_FUNCTIONS_MIRROR
	#define MGL_INCLUDE_SHADER_PROGRAM_MIRROR
	#define MGL_INCLUDE_OPENGL_ACCESS

	#define MGL_INCLUDE_DEFAULT_COLORS
	#define MGL_INCLUDE_DEFAULT_PRIMITIVES
	#define MGL_INCLUDE_DEFAULT_SHADERS

	#define MGL_INCLUDE_EXCEPTIONS
	#define MGL_INCLUDE_COLOR
#endif

#if defined MGL_DEFAULT_INCLUDE
	#define MGL_INCLUDE_WINDOWS
	#define MGL_INCLUDE_DRAWABLE_OBJECT

	#define MGL_INCLUDE_MATH

	#define MGL_INCLUDE_SHADER_PROGRAM_MIRROR
	#define MGL_INCLUDE_DEFAULT_SHADERS
#endif

#if defined MGL_INCLUDE_WINDOWS
	#if defined MGL_WINDOW_USE_LOOP
		#include "MGL\Windows\AbstractLoopWindow.hpp"
		namespace mgl {
			class Window : public AbstractLoopWindow {
			public:
				using AbstractLoopWindow::AbstractLoopWindow;
			};
		}
	#else
		#include "MGL\Windows\AbstractWindow.hpp"
		namespace mgl {
			class Window : public AbstractWindow {
			public:
				using AbstractWindow::AbstractWindow;
			};
		}
	#endif
#endif
#if defined MGL_INCLUDE_DRAWABLE_OBJECT
	#include "MGL\Primitive\AbstractDrawableObject.hpp"
	#include "MGL\Primitive\Primitive.hpp"
	namespace mgl {
		class DrawableObject : public AbstractDrawableObject {
		public:
			using AbstractDrawableObject::AbstractDrawableObject;
		};
	}
#endif
#if defined MGL_INCLUDE_PRIMITIVES
	#include "MGL\Primitive\Primitive.hpp"
#endif
#if defined MGL_INCLUDE_MATH
	#include "MGL\Math\Matrix.hpp"
	#include "MGL\Math\Vector.hpp"
#endif
#if defined MGL_INCLUDE_OPENGL_FUNCTIONS_MIRROR
	#include "MGL\OpenGL\FunctionsMirror\FunctionsMirror.hpp"
	#define MGL_INCLUDE_OPENGL_BASIC_TYPES_MIRROR
#endif
#if defined MGL_INCLUDE_OPENGL_EXPERIMENTAL_FUNCTIONS_MIRROR
	#include "MGL\OpenGL\FunctionsMirror\ExperimentalFunctionsMirror.hpp"
#endif
#if defined MGL_INCLUDE_SHADER_PROGRAM_MIRROR
	#include "MGL\OpenGL\ClassesMirror\ShaderProgram.hpp"
	#include "MGL\OpenGL\ClassesMirror\ShaderVariable.hpp"
	#include "MGL\OpenGL\ClassesMirror\Shader.hpp"
#endif
#if defined MGL_INCLUDE_OPENGL_ACCESS
	#include "MGL\OpenGL\OpenGL_Dependency\OpenGL.h"
#endif
#if defined MGL_INCLUDE_DEFAULT_COLORS
	#include "MGL\Default\DefaultColors.hpp"
#endif
#if defined MGL_INCLUDE_DEFAULT_PRIMITIVES
	#include "MGL\Default\DefaultPrimitives.hpp"
#endif
#if defined MGL_INCLUDE_DEFAULT_SHADERS
	#include "MGL\Default\DefaultShaders.hpp"
#endif
#if defined MGL_INCLUDE_EXCEPTIONS
	#include "MGL\SharedHeaders\Exceptions.hpp"
#endif
#if defined MGL_INCLUDE_COLOR
	#include "MGL\SharedHeaders\Color.hpp"
#endif