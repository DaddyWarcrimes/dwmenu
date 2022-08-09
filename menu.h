// Menu aggregates menu items. 
// Each menu should be instaniated only once

#pragma once

#include <string>
#include <vector>
#include "mitem.h"

class menu
{
	private:
		vector<mitem*> list; 
	public:
		void addItem(mitem* newItem);
		mitem* getItem(std::string title);
		mitem* getItem(unsigned int position);
		void executeItem(std::string title);
		void executeItem(unsigned int position);
};
