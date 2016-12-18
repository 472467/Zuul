#include "ZuulRoom.h"

ZuulRoom::ZuulRoom() {
    roomName = "NONE SET"; //default contructers
	
    description = "No desc set somehow";
    canEnter = true;
	
    ZuulItem* enterItem = new ZuulItem();
    ZuulItem* containedItem = new ZuulItem();
	
    entrances = new char[5];// N1, S2, W3, E4 
    winGame = false;
	
	for(int x = 0; x < 4; x++){//initializes arrays 
		entrances[x] = 'x';
	}
}
ZuulRoom::ZuulRoom(char* name, char* desc, bool canEnt, ZuulItem* enter, ZuulItem* contItem, char* ent){//room with all 
	roomName = name;
	description = desc;
	canEnter = canEnt;
	enterItem = enter;
	containedItem = contItem;
	entrances = ent;
        
}
ZuulRoom::ZuulRoom(char* name, char* desc, bool canEnt, ZuulItem* enter, char* ent){//room with item needed to enter
	roomName = name;
	description = desc;
	canEnter = canEnt;
	enterItem = enter;
	containedItem = new ZuulItem();
	entrances = ent;
        
}
ZuulRoom::ZuulRoom(char* name, char* desc, bool wonG, bool canEnt, ZuulItem* enter, char* ent){//boss room
	roomName = name;
	description = desc;
	canEnter = canEnt;
	enterItem = enter;
	containedItem = new ZuulItem();
	entrances = ent;
	winGame = true;
	
}
ZuulRoom::ZuulRoom(char* name, char* desc, ZuulItem* contItem, char* ent){//room with item in it
	roomName = name;
	description = desc;
	containedItem = contItem;
	enterItem = new ZuulItem();
	entrances = ent;
	
}
ZuulRoom::ZuulRoom(char* name, char* desc, char* ent){ //basic room
	roomName = name;
	description = desc;
	entrances= ent;
	containedItem = new ZuulItem();
	enterItem = new ZuulItem();
}
ZuulRoom::ZuulRoom(char* name){//creates placeholder room
	roomName =  name;
}
void ZuulRoom::setEntrances(char* ent){ //sets entrances
	entrances = ent;
}
char* ZuulRoom::getEntrances(){//converts array of entrances to string and returns it
	return entrances;
}
char* ZuulRoom::getDesc(){//gets desc
	return description;
}
char* ZuulRoom::getName(){//gets name
	return roomName;
}
bool ZuulRoom::getCanEnter(){
	return canEnter;
}
ZuulItem* ZuulRoom::getEnterItem(){
	return enterItem;
}

ZuulItem* ZuulRoom::getContainedItem(){
	return containedItem;
}

void ZuulRoom::setContainedItem(ZuulItem* zI){
	containedItem = zI;
}

void ZuulRoom:: setCanEnter(bool canEnt){
	canEnter = canEnt;
}


/*
void ZuulRoom::toString(){ //gives all info about zuulroom in string format for debug
   cout << "Name: " << roomName << "\nCanEnter: " << canEnter << "\nContained Item: " << containedItem.getName() << "\nEntrances: " << getEntrances() << "Game won: " << winGame;
}
*/
