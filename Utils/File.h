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
			const bool fileIsReadOnly,
			const bool append = true
			)
		{
			if (!fileIsReadOnly)
			{
				try
				{
					std::fstream f;
					if (append)
						f.open(pathFile, std::ios::app);
					else
						f.open(pathFile, std::ios::out);

					if (f.is_open())
					{
						f << dataToWrite;
						std::cout << "=> file is writen on '" << pathFile << "' :)" << std::endl;
						f.close();
					}
					else
						throw std::runtime_error("=> File could not be opened :(");

				} catch (std::exception& e)
				{
					std::cout << "" << e.what() << std::endl;
				}
			}
			else std::cout << "=> File is readonly :o" << std::endl;
		}

		static void Read(const std::string &pathFile)
		{
			try
			{
				std::fstream f;
				std::string result;
				f.open(pathFile, std::ios::in);
				if (f.is_open())
					std::cout <<"=> Read on " << pathFile << "\n" << f.rdbuf() << "---" << std::endl;
				else
					throw std::runtime_error("=> File could not be opened :(");
			} catch (std::runtime_error& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	};
} // utils

#endif //FILE_H
