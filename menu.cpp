#include "menu.h"
#include "mitem.h"


void menu::addItem(mitem* newItem)
{
	list.push_back(newItem);
	return;
}
mitem* menu::getItem(std::string title)
{
	for(unsigned int i = 0; i < list.size(); i++)
	{
		if(list[i]->getTitle() == title)
		{
			 return list[i];
		}
		else
		{
			continue;
		}
	}
	return NULL;
}
mitem* menu::getItem(unsigned int position)
{
	return list[position];
}
void menu::executeItem(std::string title)
{
	for(unsigned int i = 0; i < list.size(); i++)
	{
		if(list[i]->getTitle() == title)
		{
			list[i]->execute();
			return;
		}
		else
		{
			continue; 
		}
	}
	return;
}
void menu::executeItem(unsigned int position)
{
	list[position]->execute();
	return;
}

