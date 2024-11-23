#include "Utils/File.h"
#include <string>
#include "Utils/struct.h"

int main()
{
	const utils::struct_file f1{
		"/Users/pascal/dev/projects/cpp/workspace/Ressources/data.txt",
		"Esteban \nStella \nMaria",
		false

	};

	utils::File::Write(f1.pathFile, f1.dataToWrite);
	const std::string f1data(utils::File::Read(f1.pathFile));

	std::cout << f1data << std::endl;
	return 0;
}
