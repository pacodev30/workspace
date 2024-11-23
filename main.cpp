#include "Utils/File.h"
#include <string>
#include "Utils/struct.h"

int main()
{
	const utils::struct_file f1{
		"/Users/pascal/dev/projects/cpp/workspace/Ressources/data.txt",
		"Esteban \nStella \n",
		false
	};

	utils::File::Write(f1.pathFile, f1.dataToWrite, f1.readOnly, true);
	utils::File::Read(f1.pathFile);
	return 0;
}
