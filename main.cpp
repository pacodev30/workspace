#include "Headers/Worker.h"
#include "utils/File.h"
#include <iostream>
#include <vector>

int main()
{
	// INIT
	const std::string PATHFILE("/Users/pascal/dev/projects/workspace/Ressources/data.txt");

	workspace::Worker ppe("PERROT", "Pascal", "Developer");
	workspace::Worker tro("ROUILLE", "Thomas", "Designer");
	workspace::Worker ami("MINOTTI", "Alex", "Lead designer");

	ppe.setService("Designer/developer");

	std::vector<workspace::Worker> workers =
		{
			ppe,
			tro,
			ami
		};

	// OUTPUT
	utils::File::Clear(PATHFILE);

	for (workspace::Worker& w: workers)
	{
		const std::string DATA = w.getFirstName() + " " + w.getLastName() + " \t| " + w.getService() + "\n";
		utils::File::Write(PATHFILE, DATA, true);
	}

	std::cout << utils::File::Read(PATHFILE) << std::endl;

	return 0;
}
