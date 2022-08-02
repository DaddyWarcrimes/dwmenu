#pragma once

#include "mitem.h"
#include <string>

class executeItem : public mitem
{
	private:
		std::string command;
	public:
		executeItem();
		~executeItem();
		void setCommand(std::string newCommand);
		std::string getCommand();
		void execute();
};
