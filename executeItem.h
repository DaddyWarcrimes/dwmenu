#pragma once

#include "mitem.h"
#include <string>

using namespace std;

class executeItem : public mitem
{
	private:
		int test;
		string command;
	public:
		executeItem();
		~executeItem();
		void setCommand(std::string newCommand);
		std::string getCommand();
		void execute();
};
