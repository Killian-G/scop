//
// Created by killian on 02/01/2022.
//

#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include <cstdlib>
extern "C" {
	#include "GL/glew.h"
};
#include <string>

namespace Scop
{
	class ShaderProgram
	{
	public:
		ShaderProgram();
		~ShaderProgram();
		void Activate() const;
		void SetBoolean(const std::string& name, bool value) const;
		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;
		void SetVertexShader(const std::string& fileName) const;
		void SetFragmentShader(const std::string& fileName) const;
		[[nodiscard]] u_int32_t GetId() const;

	private:
		u_int32_t id;

		void CheckLinkingErrors() const;
	};
}


#endif //SHADERPROGRAM_HPP
