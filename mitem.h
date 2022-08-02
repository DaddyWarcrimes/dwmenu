/* Menu item class */

#pragma once

#include <string>
#include <iostream>

using namespace std;

class mitem
{
private:
	std::string title; //Name of the menu item
	unsigned int uses; //Number of times the menu item has been used
public:
	mitem();
	~mitem();
	void setTitle(std::string newTitle);
	std::string getTitle();
	virtual void execute()// execute function should increment the uses
	{
		std::cout << "mitem virtual function execute" << std::endl;
	};
	unsigned int getUses();
	void setUses(unsigned int newUses);
	void scaleUses(float scalar);
	
};

