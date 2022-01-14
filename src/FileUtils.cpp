//
// Created by killian on 08/01/2022.
//

#include <stdexcept>
#include "../include/FileUtils.hpp"
namespace Scop
{
	std::string ReadFile(const char* fileName)
	{
		std::FILE *fp = std::fopen(fileName, "rb");
		if (fp)
		{
			std::string contents;
			std::fseek(fp, 0, SEEK_END);
			contents.resize(std::ftell(fp));
			std::rewind(fp);
			std::fread(&contents[0], 1, contents.size(), fp);
			std::fclose(fp);
			return(contents);
		}
		throw(std::runtime_error("Fail to open file"));
	}
}
