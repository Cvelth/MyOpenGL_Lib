#pragma once
#include <list>
#include "SharedHeaders\Exceptions.hpp"
#include "OpenGL_Mirror\EnumsMirror\EnumsMirror.hpp"

namespace mgl {
	class Buffer;
	class Color;
	namespace math {
		class Vector;
		class Matrix;
	}
	class Vertex;

	namespace Exceptions {
		class PrimitiveException : public AbstractStringException {
			using AbstractStringException::AbstractStringException;
		};
	}

	class Primitive {
	protected:
		std::list<Vertex*> m_data;
		Buffer* m_buffer;
		VertexConnectionType m_connection;
		Color* m_default_color;
	public:
		Primitive(VertexConnectionType type = VertexConnectionType::Points, Color* defaultColor = nullptr);
		Primitive(VertexConnectionType type, Color* defaultColor, const float* array, size_t size, size_t COORDS_POINT_NUMBER = 3, size_t COLOR_POINT_NUMBER = 3);
		Primitive(VertexConnectionType type, Color* defaultColor, math::Vector* coords_array, size_t size);
		Primitive(VertexConnectionType type, Color* defaultColor, math::Vector* coords_array, Color* colors_array, size_t size);
		Primitive(VertexConnectionType type, Color* defaultColor, const std::initializer_list<math::Vector*>& coords_list);
		Primitive(VertexConnectionType type, Color* defaultColor, const std::initializer_list<math::Vector*>& coords_list, const std::initializer_list<Color*>& color_list);
		Primitive(VertexConnectionType type, Color* defaultColor, const std::list<math::Vector*>& coords_list);
		Primitive(VertexConnectionType type, Color* defaultColor, const std::list<math::Vector*>& coords_list, const std::list<Color*>& color_list);
		~Primitive();
		
		virtual size_t getSize() const;
		virtual size_t getNumber() const;

		virtual Color* getDefaultColor() const;
		virtual void setDefaultColor(Color* color);
		virtual void setDefaultColor(float r = 0.f, float g = 0.f, float b = 0.f, float a = 1.f);
		
		virtual void insert(math::Vector* v);
		virtual void insert(math::Vector* v, Color* c);
		virtual void send(DataUsage u);
		virtual void draw();
		virtual void clean();
		
		std::list<Vertex*>& operator*();
		const std::list<Vertex*>& operator*() const;
	};
}