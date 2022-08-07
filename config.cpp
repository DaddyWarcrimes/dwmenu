/* Config.cpp 
Configuration settings 
implement as singleton pattern
Always invoke using the getInstance function
*/
#define DEBUG

#include "config.h"
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include "compileOptions.h"


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
bool config::initialize()
{
	std::string file = getenv("HOME");
	std::string file2 = "/.config/dwmenu";
	file = file + file2;
	if(!mkdir(file.c_str(),0777))
	{
#ifdef DEBUG
		printf("%s\n","directory not created ---DEBUG---");
#endif
		

		return false;
	}
	std::ofstream outfile;
	sudo = DEFAULT_SUDO;
	clearBeforeExecute = DEFAULT_CLEAR;
	pauseBeforeContinue = DEFAULT_PAUSE;

	this->write();
	return true;
}
void config::write()
{
	std::ofstream outfile;
	outfile.open(this->configFile());
	if(!outfile )
	{
		this->configFile();
		return; 
	}
	outfile << "sudo=" << sudo << std::endl;
	outfile << "clearBeforeExecute=" << clearBeforeExecute << std::endl;
	outfile << "pauseBeforeContinue=" << pauseBeforeContinue<< std::endl;
	outfile.close();
	return;

}
void config::load()
{
	std::ifstream infile;
	infile.open(this->configFile());
	if(!infile )
	{
		std::cout << "Unable to open configuration file: " << this->configFile() << std::endl; 
		std::cout << "Creating configuration file\n";
		this->initialize();
		return;
	}
}
std::string config::configFile()
{
	std::string file = getenv("HOME");
	file = file + "/.config/dwmenu/settings.cfg";
	return file;
}
