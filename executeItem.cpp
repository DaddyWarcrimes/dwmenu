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
std::string executeItem::getCommand()
{
	return command;
}

void executeItem::execute()
{
	system(command.c_str());
	return;
}

