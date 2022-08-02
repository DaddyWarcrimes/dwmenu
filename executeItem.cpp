// subclass for execute item
//
#include "executeItem.h"
#include <iostream>

executeItem::executeItem()
{
	return;
}
executeItem::~executeItem()
{
	return;
}
void executeItem::setCommand(std::string newCommand)
{
	command = newCommand;
	return;
}
std::string getCommand()
{
	return "hi";
}

void executeItem::execute()
{
	system(command.c_str());
	return;
}

