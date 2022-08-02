
//Configuration class. Loads global settings
//

#pragma once

#include<iostream>

class config
{
	private:
		bool sudo;
		bool clearBeforeExecute;
		bool pauseBeforeContinue;
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

};
