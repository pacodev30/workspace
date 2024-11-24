#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace utils {
	class File
	{
	public :
		static void Write(const std::string& pathFile, const std::string& dataToWrite, const bool append = true)
		{
			std::fstream outFile;
			if (append == true)
				outFile.open(pathFile, std::ios::app);
			else
				outFile.open(pathFile, std::ios::out | std::ios::trunc);

			if (outFile.is_open())
			{
				outFile << dataToWrite;
				std::cout << "=> Write \t'" << pathFile << "'" << std::endl;
				outFile.close();
			}
		}

		static void Clear(const std::string& pathFile)
		{
			std::fstream outFile;
			outFile.open(pathFile, std::ios::out | std::ios::trunc);

			if (outFile.is_open())
			{
				outFile << "";
				std::cout << "=> Clear \t'" << pathFile << "'" << std::endl;
				outFile.close();
			}
		}

		static std::string Read(const std::string& pathFile)
		{
			std::ifstream ifs;
			ifs.open(pathFile, std::ios::in);
			if (ifs.is_open())
			{
				std::string dataRead;
				std::string line;
				std::cout << "=> Read \t'" << pathFile << "\n---" << std::endl;
				while (std::getline(ifs, line))
				{
					dataRead += line + "\n";
				}
				return dataRead;
			}
			throw std::runtime_error("Could not open file " + pathFile);
		}
	};
} // utils
