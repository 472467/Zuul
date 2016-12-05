#include "ZuulItem.h"
#ifndef ZUULROOM_H
#define ZUULROOM_H

class ZuulRoom
{
	private:
		char* roomName; //default contructers
		char* description;
		bool canEnter;
		ZuulItem* enterItem;
		ZuulItem* containedItem;
		char* entrances;
		bool winGame;
		
	public:
		ZuulRoom();
		ZuulRoom(char*, char*, bool, ZuulItem*, ZuulItem*, char*);
		ZuulRoom(char*, char*, bool, ZuulItem*, char*);//y
		ZuulRoom(char*, char*, bool, bool, ZuulItem*, char*);//y
		ZuulRoom(char*, char*, ZuulItem*, char*);//y
		ZuulRoom(char*, char*, char*);//y
		ZuulRoom(char*);//y
		
		void setEntrances(char*);
		char* getEntrances();
		char* getDesc();
		char* getName();
		void toString();
	

};

#endif