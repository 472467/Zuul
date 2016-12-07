#pragma warning
#ifndef ZUULITEM_H
#define ZUULITEM_H

#include <string.h>

class ZuulItem
{
	private:
		char* name;
		char* description;
		char* roomText;//displays specific text when it's(the item) contained in a room
		bool isItem;//checks whether item is a non default item
	public:
		ZuulItem();
		ZuulItem(char*, char*, char*);
		char* getName();
		char* getRoomText();
		char* getDesc();
		bool checkValid();
};
#endif
/*
 Refrigerator()
    :amountOfEggs(0)
    {
    };
  // Custom constructor
  Refrigerator(int amountOfEggs)
    :amountOfEggs(amountOfEggs)
    {
    };





*/