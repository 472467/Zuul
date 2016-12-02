#include "ZuulItem.h"

ZuulItem::ZuulItem() {
    char* name = "No Name"; //default contructors
    char* description = "No description";
    char* roomText= " ";//displays specific text when it's contained in a room
    bool isItem = false; //checks whether item is a non default item
}

ZuulItem::ZuulItem(char* n, char* desc, char* roomT){
	n = name;
	description=  desc;
	roomText= roomT;
	isItem = true;
	
}