#pragma once
#include "Shader.hpp"

namespace mgl {
	class ProgramException : public AbstractStringException {
		using AbstractStringException::AbstractStringException;
	};

	class Vector;
	class Matrix;

	class Program {
	protected:
		unsigned int m_id;
	public:
		explicit Program();
		explicit Program(const std::initializer_list<Shader>& list);
		~Program();

		void link(const std::initializer_list<Shader>& list);
		void use();
		void sendUniform(const std::string fieldName, const float& data);
		void sendUniform(const std::string fieldName, const Vector& data);
		void sendUniform(const std::string fieldName, const Matrix& data);
		void enableAttrib(const std::string fieldName, size_t size = 4, 
						 bool normalized = false, size_t stride = 4, size_t shift = 0);
	};

	using CustomProgram = Program;
}