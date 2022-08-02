
//Included headers
#include <iostream>
#include <string.h>
#include "mitem.h"

int main()
{
	mitem fitem;
	fitem.setTitle("This is a title");
	fitem.setUses(5);
	std::cout << fitem.getTitle() << fitem.getUses() << std::endl;
	fitem.scaleUses(500);
	std::cout << "scaled * 500 " << fitem.getUses() << std::endl;
	fitem.scaleUses(0.02);
	std::cout << "scaled * .02 " << fitem.getUses() << std::endl;
	return 0;
}





