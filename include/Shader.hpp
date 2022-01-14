//
// Created by killian on 08/01/2022.
//

#ifndef SHADER_HPP
#define SHADER_HPP

#include <cstdlib>
extern "C" {
	#include "GL/glew.h"
};
#include <string>

namespace Scop
{
	class Shader
	{
	public:
		Shader(const std::string& shaderCode, GLenum type);
		~Shader();
		[[nodiscard]] u_int32_t GetId() const;

	private:
		u_int32_t id;

		void CheckCompileErrors(GLenum type) const;
	};
}


#endif //SHADER_HPP
