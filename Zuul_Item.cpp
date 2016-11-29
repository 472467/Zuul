#include "Zuul_Item.h"

ZuulItem::ZuulItem() {
    char* name = "No Name"; //default contructors
    char* description = "No description";
    char* roomText= "";//displays specific text when it's contained in a room
    bool isItem = false; //checks whether item is a non default item
}

ZuulItem::ZuulItem(char* name, char* desc, char* roomT){
	
	this.name = name;
	description=  desc;
	roomText= roomT;
	isItem = true;
	
}