//
// Created by killian on 02/01/2022.
//

#include <iostream>
#include <fstream>
#include <ShaderProgram.hpp>
#include <FileUtils.hpp>
#include "Shader.hpp"

namespace Scop
{
	ShaderProgram::ShaderProgram()
	{
		std::cout << "HERE" << std::endl;
		id = glCreateProgram();
		std::cout << "HERE2" << std::endl;
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(id);
	}

	void ShaderProgram::Activate() const
	{
		glUseProgram(id);
	}

	void ShaderProgram::SetBoolean(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(id, name.c_str()), value);
	}

	void ShaderProgram::SetInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(id, name.c_str()), value);
	}

	void ShaderProgram::SetFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(id, name.c_str()), value);
	}

	void	ShaderProgram::CheckLinkingErrors() const
	{
		int32_t success = 1;
		char infoLog[1024];

		glGetShaderiv(id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(id, 1024, nullptr, infoLog);
			std::cerr << "ERROR::PROGRAM_LINKING::ERROR" << std::endl << '"' << infoLog << '"' << std::endl;
		}
	}

	void ShaderProgram::SetVertexShader(const std::string& fileName) const
	{
		std::string fileContent = ReadFile(fileName.c_str());
		Shader vertexShader(fileContent, GL_VERTEX_SHADER);
		glAttachShader(id, vertexShader.GetId());
		glLinkProgram(id);
		CheckLinkingErrors();
	}

	void ShaderProgram::SetFragmentShader(const std::string& fileName) const
	{
		std::string fileContent = ReadFile(fileName.c_str());
		Shader fragmentShader(fileContent, GL_VERTEX_SHADER);
		glAttachShader(id, fragmentShader.GetId());
		glLinkProgram(id);
		CheckLinkingErrors();
	}

	u_int32_t ShaderProgram::GetId() const
	{
		return id;
	}
}
