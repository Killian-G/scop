//
// Created by killian on 08/01/2022.
//

#include <iostream>
#include "Shader.hpp"


namespace Scop
{
	void	Shader::CheckCompileErrors(GLenum type) const
	{
		int32_t success = 1;
		char infoLog[1024];

		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(id, 1024, nullptr, infoLog);
			if (type == GL_VERTEX_SHADER)
				std::cerr << "ERROR::SHADER::VERTEX::COMPILATION::ERROR" << std::endl << infoLog << std::endl;
			else if (type == GL_FRAGMENT_SHADER)
				std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION::ERROR" << std::endl << infoLog << std::endl;
		}
	}

	Shader::Shader(const std::string& shaderCode, GLenum type)
	{
		id = glCreateShader(type);
		const char* strShaderCode = shaderCode.c_str();
		glShaderSource(id, 1, &strShaderCode, nullptr);
		glCompileShader(id);
		CheckCompileErrors(type);
	}

	Shader::~Shader()
	{
		glDeleteShader(id);
	}

	u_int32_t Shader::GetId() const
	{
		return id;
	}
}
