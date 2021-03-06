#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iterator>
#include <iomanip>

#include "ZuulItem.h"
#include "ZuulRoom.h"
#pragma once

//using namespace std;
bool translateMove(bool**, ZuulRoom**, char*, ZuulItem**);
void printMap(bool**, ZuulRoom**);
bool checkPossible(int, int, char);
bool checkNeighbor(int, int, bool**, bool**);
void createRooms(ZuulRoom**);
ZuulRoom getCurrentRoom(bool**, ZuulRoom**);
void moveRoom(int, int, bool**);
//int translateMove(char* in, std::vector<Media*>* v);