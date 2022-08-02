/* Config.cpp 
Configuration settings 
implement as singleton pattern
Always invoke using the getInstance function
*/

#include "config.h"
#include <iostream>

config::config()
{
	return;
}
config::~config()
{
	return;
}
config* config::getInstance()
{
	static config* instance = NULL;
	if(instance == NULL )
	{
		 instance = new config();
	}
	else
	{
		std::cout << "cofnig instance already exists\n"; 
	}
	return instance;
}
void config::setSudo(bool set)
{
	sudo = set;
	return;
}
bool config::isSudo()
{
	return sudo;
}


