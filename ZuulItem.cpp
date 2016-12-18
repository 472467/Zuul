#include "ZuulItem.h"

ZuulItem::ZuulItem() {
    name = "No Name"; //default contructors
	//strcpy(name, "No Name");
    
	description = "No Description";
	//strcpy(description, "No description");
	
    roomText =  "No RoomText";//displays specific text when it's contained in a room
	//strcpy(roomText, "No RoomText");
	
    isItem = false; //checks whether item is a non default item
}

ZuulItem::ZuulItem(char* n, char* desc, char* roomT){
	
	n = name;
	description=  desc;
	roomText= roomT;
	isItem = true;
	
}

char* ZuulItem::getDesc(){
	return description;
}

char* ZuulItem::getRoomText(){
	return roomText;
}

bool ZuulItem::checkValid(){
	return isItem;
}

char* ZuulItem::getName(){
	return name;
}