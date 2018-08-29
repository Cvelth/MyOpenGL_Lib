#include "mgl/dependencies/OpenGL_Dependency/opengl_dependency.hpp"
#include "ShaderProgram.hpp"
#include "Shader.hpp"
#include "ShaderVariable.hpp"
mgl::ShaderProgram::ShaderProgram(uint32_t id) : m_is_linked(false) {
	if (id == 0 || !glIsProgram(id)) throw Exceptions::ProgramCreationError();
}
mgl::ShaderProgram::ShaderProgram() : ShaderProgram(glCreateProgram()) {}
mgl::ShaderProgram::ShaderProgram(std::initializer_list<Shader> const& list) : ShaderProgram() {
	link(list);
}
mgl::ShaderProgram::~ShaderProgram() {
	glDeleteProgram(m_id);
}

void mgl::ShaderProgram::link(std::initializer_list<Shader> const& shaders) {
	if (shaders.size() == 0u)
		throw Exceptions::ProgramLinkageError("There are no shaders to attach.");

	for (auto &shader : shaders)
		glAttachShader(m_id, shader.m_id);

	glLinkProgram(m_id);

	GLint isLinked;
	glGetProgramiv(m_id, GL_LINK_STATUS, &isLinked);
	if (!isLinked) {
		GLsizei len;
		glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &len);

		GLchar* log = new GLchar[len + 1];
		glGetProgramInfoLog(m_id, len, &len, log);
		throw Exceptions::ProgramLinkageError(("Program linking error: " + std::string(log)).c_str());
		delete[] log;
	}
	m_is_linked = true;
}
bool mgl::ShaderProgram::is_linked() const {
	if (m_is_linked)
		return true;
	else if (glIsProgram(m_id)) {
		GLint isLinked;
		glGetProgramiv(m_id, GL_LINK_STATUS, &isLinked);
		return m_is_linked = bool(isLinked);
	} else
		return false;
}

#include "mgl/EnumConverter/enum_converter.hpp"
std::list<mgl::ShaderVariable> mgl::ShaderProgram::getUniforms() {
	GLint uniforms_number, max_uniform_length, name_length, size;
	GLenum type;
	GLchar* name;

	std::list<mgl::ShaderVariable> ret;

	glGetProgramiv(m_id, GL_ACTIVE_UNIFORMS, &uniforms_number);
	glGetProgramiv(m_id, GL_ACTIVE_UNIFORM_MAX_LENGTH, &max_uniform_length);
	for (int i = 0; i < uniforms_number; i++) {
		name = new GLchar[max_uniform_length];
		glGetActiveUniform(m_id, i, max_uniform_length, &name_length, &size, &type, name);
		ret.push_back(ShaderVariable(name, ShaderVariableType::Uniform, i, enum_converter::convert_to_ShaderVariableDataType(type)));
	}
	return std::move(ret);
}

#include "mgl/GlobalStateController/GlobalStateController.hpp"
void mgl::ShaderProgram::use() {
	GlobalStateController::use_shader_program(this);
}