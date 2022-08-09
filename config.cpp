/* Config.cpp 
Configuration settings 
implement as singleton pattern
Always invoke using the getInstance function
*/
#define DEBUG

#include "config.h"
#include <iostream>
//#include <sys/stat.h>
#include <filesystem>
#include <cstdlib>
#include <fstream>
#include "compileOptions.h"

namespace fs = std::filesystem;


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
// Create default settings file
bool config::initialize()
{
	//Generate string for config directory
	std::string file = getenv("HOME");
	file = file + "/" + CONFIG_DIRECTORY +  "/" + CONFIG_SUBDIRECTORY;
	// Checks if config directory exists, and creates if needed
	while(!fs::exists(file) )
	{
#ifdef DEBUG
		printf("%sConfig directory not found\n","---DEBUG---");
#endif
		 if(!fs::create_directory(file) )
		 {
#ifdef DEBUG
			 printf("%sUnable to create directory \n","---DEBUG---");
#endif
			  return false;
		 }
		 else
		 {
#ifdef DEBUG
			printf("%sConfig directory created\n","---DEBUG---");
#endif
			
		 }
		 
	}
// Set default settings and write to file
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

//TODO: read file contents and set paramaters
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
//Generates a string the full path to the config file
std::string config::configFile()
{
	std::string file = getenv("HOME");
	file = file + "/" + CONFIG_DIRECTORY + "/" + CONFIG_SUBDIRECTORY + "/settings.cfg";
	return file;
}
