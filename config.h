
//Configuration class. Loads global settings
//

#pragma once

#include<iostream>
#include<string>

class config
{
	private:
		bool sudo;
		bool clearBeforeExecute;
		bool pauseBeforeContinue;
		bool initialize(); // Creates a new configuration file
		std::string configFile();
	public:
		config();
		~config();
		config* getInstance();
		void setSudo(bool set);
		bool isSudo();
		void setClearBeforeExecute(bool set);
		bool isClearBeforeExecute();
		void setPauseBeforeContinue(bool set);
		bool isPauseBeforeContinue();
		void load();
		void write();
};
