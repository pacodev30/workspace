#include "Headers/Worker.h"
#include <iostream>
using namespace workspace;

Worker::Worker(std::string  firstName, std::string  lastName, std::string  service)
	: _firsName(std::move(firstName)), _lastName(std::move(lastName)), _service(std::move(service)) { }

std::string Worker::getFirstName() {return _firsName;}
std::string Worker::getLastName() {return _lastName;}
std::string Worker::getService() {return _service;}

void Worker::setFirstName(const std::string &firstName) {_firsName = firstName;}
void Worker::setLastName(const std::string &lastName) {_lastName = lastName;}
void Worker::setService(const std::string &service) {_service = service;}



