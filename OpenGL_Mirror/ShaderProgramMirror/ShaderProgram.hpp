#pragma once
#include "OpenGL_Mirror\EnumsMirror\EnumsMirror.hpp"

namespace mgl {
	namespace Exceptions {
		class ProgramException : public AbstractStringException {
			using AbstractStringException::AbstractStringException;
		};
	}
	namespace math {
		class Vector;
		class Matrix;
	}

	class Shader;
	class ShaderProgram;
	class ShaderVariable {
		friend ShaderProgram;
	private:
		std::string m_variable_name;
		ShaderVariableType m_variable_type;
		int m_location;
		ShaderDataType m_data_type;
	protected:
		explicit ShaderVariable(std::string name, ShaderVariableType v_type, int location, ShaderDataType d_type);
	};

	class ShaderProgram {
	protected:
		unsigned int m_id;
	public:
		explicit ShaderProgram();
		explicit ShaderProgram(const std::initializer_list<Shader>& list);
		~ShaderProgram();

		void link(const std::initializer_list<Shader>& list);
		void use();

		bool isLinked();

		ShaderVariable* getUniform(const std::string fieldName);
		ShaderVariable* enableAttribWithNormalization(const std::string fieldName, size_t size = 4,
													  bool normalized = false, size_t stride = 4, size_t shift = 0);
		ShaderVariable* enableAttrib(const std::string fieldName, size_t size = 4,
									 size_t stride = 4, size_t shift = 0);

		void sendUniform(ShaderVariable* variable, const float& data);
		void sendUniform(ShaderVariable* variable, const math::Vector& data);
		void sendUniform(ShaderVariable* variable, const math::Matrix& data);
	};
}