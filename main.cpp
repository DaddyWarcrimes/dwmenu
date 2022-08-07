
//Included headers
#include <iostream>
#include <string.h>
#include "mitem.h"
#include "executeItem.h"
#include "config.h"
#include "menu.h"

int main()
{
	//mitem and executeItem tests
	executeItem fitem;
	fitem.setTitle("This is a title");
	fitem.setUses(5);
	std::cout << fitem.getTitle() << fitem.getUses() << std::endl;
	fitem.scaleUses(500);
	std::cout << "scaled * 500 " << fitem.getUses() << std::endl;
	fitem.scaleUses(0.02);
	std::cout << "scaled * .02 " << fitem.getUses() << std::endl;
	fitem.setCommand("pwd");
	fitem.execute();
	executeItem gitem;
	gitem.setTitle("smork");
	gitem.setCommand("echo smork");
	gitem.execute();
	
	//menu test
	menu a;
	a.addItem(&fitem);
	a.addItem(&gitem);
	a.executeItem(0);
	a.executeItem(1);
	a.executeItem("This is a title");
	a.executeItem("smork");


	// config tests
	config* c = c->getInstance();
	c->setSudo(true);
	if(c->isSudo() )
	{
		std::cout << "sudo worked \n";
	}
	c->load();

	return 0;
}





