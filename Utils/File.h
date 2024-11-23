#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string>

namespace utils {
	class File
	{
	public :
		static void Write(
			const std::string& pathFile,
			const std::string& dataToWrite,
			const bool fileIsReadOnly = false,
			const bool append = true
			)
		{
			if (!fileIsReadOnly)
			{
				std::fstream outFile;
				if (append == true)
					outFile.open(pathFile, std::ios::app);
				else
					outFile.open(pathFile, std::ios::out | std::ios::trunc);

				if (outFile.is_open())
				{
					outFile << dataToWrite;
					std::cout << "=> file is writen on '" << pathFile << "' :)" << std::endl;
					outFile.close();
				}
			}
			else
				std::cout << "=> File is readonly :o" << std::endl;
		}

		static std::string Read(const std::string& pathFile)
		{
			std::ifstream ifs;
			ifs.open(pathFile, std::ios::in);
			if (ifs.is_open())
			{
				std::string dataRead;
				std::string line;
				std::cout << "=> Read on '" << pathFile << std::endl;
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

#endif //FILE_H
