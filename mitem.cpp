//menu item class

#include "mitem.h"

mitem::mitem()
{
	return;
}
mitem::~mitem()
{
	return;
}

std::string mitem::getTitle()
{
	return title;
}

void mitem::setTitle(std::string newTitle)
{
	title = newTitle;
	return;
}

unsigned int mitem::getUses()
{
return uses;
}

void mitem::setUses(unsigned int newUses)
{
	if(newUses > 4000000000 )
	{
		std::cout << "Value out of range; limit is 4 billion" << std::endl;

	}
	else
	{
		uses = newUses;
	}
	return;
}

//scale the number of uses
void mitem::scaleUses(float scalar)
{
	if(scalar < 0 || scalar > 100000 )
	{
		std::cout << "scalar out of range; use a value between 0 and 100000" << std::endl; 
	}
	else
	{
		uses *= scalar; 
	}
	return;
}
