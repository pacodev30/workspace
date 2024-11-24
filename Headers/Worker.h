#pragma once
#include <string>
#include <vector>

namespace workspace {

class Worker {
public:
	Worker(std::string  firstName, std::string  lastName, std::string  service);

	std::string getFirstName();
	std::string getLastName();
	std::string getService();

	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setService(const std::string& service);

protected:
	std::string _firsName, _lastName, _service, _worker;
};

} // workspace
