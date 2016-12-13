#include "Zuul.h"
/*
 	CREATED BY THE WONDEROUS BRENDAN
  A PORT OF THE JAVA ZUUL I MADE LAST YEAR
	PREPARE FOR THE HORRORS OF PORTING STRINGS TO CHAR ARRAYS
	*cries softly*
 */


int main() {
	
	bool** inRoom = new bool*[6];//default variables 6x3
	bool** neighbors = new bool*[6]; //6x3
	ZuulRoom** zuulRooms =new ZuulRoom*[6];//6x 3y
	bool gameWon = false;
	ZuulItem* inventory = new ZuulItem[6];//6

	system("clear");//runs for sure
	for (int i = 0; i < 6; i++) {
		ZuulItem* z = new ZuulItem();	
		inventory[i] = *z;
	}

	

	createRooms(zuulRooms);

	for (int i = 0; i < 3; i++) {//sets all rooms to false
		//zuulRooms[i]= new ZuulRoom();
		for (int j = 0; j < 6; j++) {
			inRoom[i][j] = false;
		}
	}

	
	inRoom[1][1] = true;//sets current room to true
	
	std::cout << "Greetings adventurer, you wake up in the castle of Neet, ruled by the most"
			<<" dangerous being in the universe, Neet the Dark Sorcerer! To escape you must defeat him."
			<< "\nGood luck laddie!" << std::endl;
	
	while(true){
		
		printMap(inRoom, zuulRooms);
		
		std::cout << std::endl << "What do you want to do?" << std::endl;
		
		char* input = new char[20];
		std::cin.getline(input, 20);
		
		translateMove(inRoom, zuulRooms, input, inventory);
	}

}

bool translateMove(bool** inRoom, ZuulRoom** zR, char* input, ZuulItem* inv){
	ZuulRoom currentR = getCurrentRoom(inRoom, zR);
	int originX = 0;
	int originY = 0;
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 6; y++){
			if(zR[x][y].getName() == currentR.getName()){
				
				originX = x;
				originY = y;
			}
		}
	}
	
	if(strcasecmp(input, "help") == 0){//help, finished
	
		std::cout << std::endl << std::endl << "\e[1m List of Commands and Descriptions \e[0m" << std::endl; 
		std::cout << "All these commands are case insensitive." << std::endl << std::endl;
		std::cout << "West, North, East, South: type these to move the player in the corresponding direction. The arrow keys can also be used to accomplish this." << std::endl;
		std::cout << "Inv: Prints the inventory of the player. You can also press 'i' to accomplish this."<< std::endl;
		std::cout << "Exit: Exits the game."<< std::endl;
		std::cout << "___________________________________________" << std::endl;
		std::cin.ignore();
		
	}else if(strcasecmp(input, "west") == 0){//add maps at somepoint
		if(checkPossible(originX, -1, 'x')){//checks if the location you want to move to is valid
			
			bool passed = false;
			
			for(int x = 0; x < 4; x++){
				if(zR[originX - 1][originY].getEntrances()[x] == 'e'){
					passed = true;
					break;
				}else if(zR[originX - 1][originY].getEntrances()[x] == '\0'){
					break;
				}
			}
			bool passedAgain = false;//checks if the 
			
			if(passed){//checks if you can enter the room from this way
			std::cout<< "true";
				if(currentR.getCanEnter()){
					passedAgain = true;
				}else{
					for(int x = 0; x < 6; x++){
						if(inv[x].getName() ==  (currentR.getEnterItem())->getName()){
							passedAgain = true;
							ZuulItem* tmp = new ZuulItem();
							inv[x] = *tmp;
							zR[originX - 1][originY].setCanEnter(true);
						}
					}
				}
			}
			
			if(passedAgain){//if you dont need an item to enter or have the item to enter
				moveRoom(originX - 1, originY, inRoom);
			}
		}
	}else if(strcasecmp(input, "east") == 0){
		if(checkPossible(originX, 1, 'x')){
			bool passed = false;
			
			for(int x = 0; x < 4; x++){
				if(zR[originX + 1][originY].getEntrances()[x] == 'w'){//change this 
					passed = true;
					break;
				}else if(zR[originX + 1][originY].getEntrances()[x] == '\0'){//change this
					break;
				}
			}
			bool passedAgain = false;//checks if the 
			
			if(passed){//checks if you can enter the room from this way
				if(currentR.getCanEnter()){
					passedAgain = true;
				}else{
					for(int x = 0; x < 6; x++){
						if(inv[x].getName() ==  (currentR.getEnterItem())->getName()){
							passedAgain = true;
							ZuulItem* tmp = new ZuulItem();
							inv[x] = *tmp;
							zR[originX + 1][originY].setCanEnter(true);// cahnge this
						}
					}
				}
			}
			
			if(passedAgain){//if you dont need an item to enter or have the item to enter
				moveRoom(originX + 1, originY, inRoom);//cahnge this
			}
		}
	}else if(strcasecmp(input, "north") == 0){
		if(checkPossible(originY, -1, 'y')){
			bool passed = false;
			
			for(int x = 0; x < 4; x++){
				if(zR[originX][originY -1].getEntrances()[x] == 's'){//change this 
					passed = true;
					break;
				}else if(zR[originX][originY - 1].getEntrances()[x] == '\0'){//change this
					break;
				}
			}
			bool passedAgain = false;//checks if the 
			
			if(passed){//checks if you can enter the room from this way
				if(currentR.getCanEnter()){
					passedAgain = true;
				}else{
					for(int x = 0; x < 6; x++){
						if(inv[x].getName() ==  (currentR.getEnterItem())->getName()){
							passedAgain = true;
							ZuulItem* tmp = new ZuulItem();
							inv[x] = *tmp;
							zR[originX][originY -1 ].setCanEnter(true);// cahnge this
						}
					}
				}
			}
			
			if(passedAgain){//if you dont need an item to enter or have the item to enter
				moveRoom(originX, originY - 1, inRoom);//cahnge this
			}
		}
	}else if(strcasecmp(input, "south") == 0){
		if(checkPossible(originY, 1, 'y')){
			bool passed = false;
			
			for(int x = 0; x < 4; x++){
				if(zR[originX][originY +1].getEntrances()[x] == 'n'){//change this 
					passed = true;
					break;
				}else if(zR[originX][originY + 1].getEntrances()[x] == '\0'){//change this
					break;
				}
			}
			bool passedAgain = false;//checks if the 
			
			if(passed){//checks if you can enter the room from this way
				if(currentR.getCanEnter()){
					passedAgain = true;
				}else{
					for(int x = 0; x < 6; x++){
						if(inv[x].getName() ==  (currentR.getEnterItem())->getName()){
							passedAgain = true;
							ZuulItem* tmp = new ZuulItem();
							inv[x] = *tmp;
							zR[originX][originY + 1].setCanEnter(true);// cahnge this
						}
					}
				}
			}else{
				std::cout << "Can't enter this way.";
			}
			
			if(passedAgain){//if you dont need an item to enter or have the item to enter
				
				moveRoom(originX, originY + 1, inRoom);//cahnge this
			}else{
				std::cout << "You don't have the necessary item to open this room!";
			}
		}
	}else if(strcasecmp(input, "inv") == 0){//finished
	
		bool ranOnce = false;
		for(int x = 0; x < 6; x++){
			if(inv[x].checkValid()){//checks if item is an item
				ranOnce =true;
				std::cout << inv[x].getName() << std::endl << inv[x].getDesc() << std::endl;
				
			}
		}
		if(!ranOnce){
			std::cout<< "No items." << std::endl;
		}
		std::cin.ignore();
		
	}else if(strcasecmp(input, "exit") == 0){//finished
		exit(0);
	}
}

void printMap(bool** inRoom, ZuulRoom** zR){
	char charMap[3][6];
	for(int x = 0; x < 3; x++){
		ZuulRoom* tmp = zR[x];//gets the array of with a specific x coordinate(0, 1, 2)
		for(int y = 0; y < 6; y++){
			if(inRoom[x][y]){//moves to the correct room by going through y values of the x list
				std::cout << std::endl << "Current Room: "<< "\e[1m"<<(tmp[y]).getName() << "\e[0m" << ", Type 'help' the list of commands" << std::endl;
				
				std::cout << std::endl << tmp[y].getDesc() << std::endl;
				charMap[x][y] = 'X';
			}else{
				charMap[x][y] = ' ';
			}
			
		}
	}
	std::cout<< "\n"
	<< '[' << charMap[0][0] << ']' << '[' << charMap[1][0] << ']' << '[' << charMap[2][0] << ']' << std::endl
	<< '[' << charMap[0][1] << ']' << '[' << charMap[1][1] << ']' << '[' << charMap[2][1] << ']' << std::endl
	<< '[' << charMap[0][2] << ']' << '[' << charMap[1][2] << ']' << '[' << charMap[2][2] << ']' << std::endl
	<< '[' << charMap[0][3] << ']' << '[' << charMap[1][3] << ']' << '[' << charMap[2][3] << ']' << std::endl
	<< '[' << charMap[0][4] << ']' << '[' << charMap[1][4] << ']' << '[' << charMap[2][4] << ']' << std::endl
	<< '[' << charMap[0][5] << ']' << '[' << charMap[1][5] << ']' << '[' << charMap[2][5] << ']' << std::endl;
	
	
}

void moveRoom(int changeX, int changeY, bool** inRoom){
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 6; y++){
			if(inRoom[x][y]){
				inRoom[x][y] = false;
			}
		}
	}
	
	inRoom[changeX][changeY] = true;
	std::cout <<  "inRoom[" << changeX << ']' << '[' << changeY << "] = " << inRoom[changeX][changeY];
}


bool checkPossible(int loc, int math, char plane) { //checks if location is within grid
	int newLoc = loc + math;//this is the wanted location
	int axisNum; //axis num is the max of the plane given
	if ('y' == plane) {//checks if plane is y or x, plane is the plane the player is located
		std::cout << plane;
		axisNum = 3;
	} else {
		axisNum = 6;
	}
	if (newLoc > axisNum || newLoc < 0 == true) {
		return false;
	}
	return true;
}

ZuulRoom getCurrentRoom(bool** inRoom, ZuulRoom** zuulRooms){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 6; j++) {
			if(inRoom[i][j]){
				return zuulRooms[i][j];
			}
		}
	}
	return NULL; //if this runs yah fucked up somewhere
}

bool checkNeighbor(int locX, int locY, bool** inRoom, bool** neighbors) {//checks if given location is a neighbor
	int x = 0;
	int y = 0;
	int count = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			neighbors[i][j] = false;
			count++;

			if (inRoom[i][j]) {
				x = i;
				y = j;
			}
		}
	}
	if (checkPossible(x, 1, 'x')) {//x+1
		neighbors[x + 1][y] = true;
	}
	if (checkPossible(y, 1, 'y')) {//y+1
		neighbors[x][y + 1] = true;
	}
	if (checkPossible(x, -1, 'x')) {//x-1
		neighbors[x - 1][y] = true;
	}
	if (checkPossible(y, -1, 'y')) {//y-1
		neighbors[x][y - 1] = true;
	}
	neighbors[x][y] = true;
	if (neighbors[locX][locY]) {
		return true;
	}
	return false;
}





void createRooms(ZuulRoom** zuulRooms) {//creates rooms and adds them to zuulRooms array
	
	
	char entrance[] = {'w', 'e', 's'};
	char* entrances = entrance;
	char* a = new char[300];
	char* b = new char[300];
	strcpy(a, "Hallway 1");
	strcpy(b, "Your average hallway, floor, tiles, ceiling etc. To the WEST you can see a janitors closet, to the EAST you see a lovely pink room, to the SOUTH you see another stretch of hallway.\n");
	ZuulRoom *hall1 = new ZuulRoom(a, b, entrances);
	
	
	char entrance1[] = {'w'};
	char* entrances1 = entrance1;
	char* c = new char[300];
	char* d = new char[300];
	strcpy(c, "Pink Room");
	strcpy(d, "This room is covered in pink things; pink umbrellas, pink apples, pink napkins, it even smells pink. Nothing useful seems to be in here unless you're looking for some pink underwear.\n");
	ZuulRoom *pinkRoom = new ZuulRoom(c, d, entrances1);
	
	
	char entrance2[] = {'n', 'w', 'e', 's'};
	char* entrances2 = entrance2;
	char* e = new char[300];
	char* f = new char[300];
	strcpy(e, "Hallway 2");
	strcpy(f, "Another hallway, exciting stuff. To the WEST is a bland looking office, to the EAST is the Girls Bathroom, unfortunately some girls seem to be in there already.\n");
	ZuulRoom* hall2 = new ZuulRoom(e, f, entrances2);
	
	
	char entrance3[] = {'n', 'w', 'e', 's'};
	char* entrances3 = entrance3;
	char* g = new char[300];
	char* h = new char[300];
	strcpy(g, "Hallway 3");
	strcpy(h, "Wow this is also a hallway, fun stuff. To the WEST is a dangerous looking copyroom, to the EAST is the Boys Bathroom, and to the SOUTH is you guessed it, another hallway.\n");
	ZuulRoom* hall3 = new ZuulRoom(g, h, entrances3);
	

	char entrance4[] = {'n', 'w', 'e', 's'};
	char* entrances4 = entrance4;
	char* i = new char[300];
	char* j = new char[400];
	strcpy(i, "Hallway 4");
	strcpy(j, "This hallway is great actually, the tiles are solid gold and the lights above head are now crystal chandeliers. To the WEST is small dungeon, however there is guard blocking the entrance. You'll need some sort of dungeon membership to pass through. To the EAST is a room used for torture, to the SOUTH is what looks like a menacing hallway.\n");
	ZuulRoom* hall4 = new ZuulRoom(i, j,entrances4);
	
	
	
	char entrance5[] = {'n', 'w', 'e', 's'};
	char* entrances5 = entrance5;
	
	ZuulRoom* hall5 = new ZuulRoom("Hallway 5", "As you enter this hallway the lights turn off completely. Then torches along the wall magically turn light up, and a voice shouts out,'puny human, do you dare to face the might of Neet?', 'if so please find the key to the door to the SOUTH. Thanks :)' To the SOUTH is a massive door made of bones and souls of defeated challengers, to the WEST is an armory filled with all sorts of dangerous objects, to the SOUTH is the legal department, the most vile room of them all.\n"
	, entrances5);

	
	char entrance6[] = {'e'};
	char* entrances6 = entrance6;
	
	ZuulItem* jKey = new ZuulItem("Janitor's Key",
			"I think you can figure out what this is for.", "You can see a key on top of one of the desks.");
	ZuulRoom* blandOffice = new ZuulRoom("Bland Office", "This is, without a doubt, the blandest office you have ever endured. Beige surrounds you. Beige watches. You never felt so bored yet intimidated at the same time. The room smells faintly of cleaning supplies and paper.\n",
	jKey, entrances6);
	
	ZuulItem* hammer = new ZuulItem("Battered Hammer", 
			"A hammer worn down over by years of use. Looks strong enough to break a weak lock.", "You can see a shabby looking hammer under a few sketchy magazines.");
	
	char entrance7[] = {'e'};
	char* entrances7 = entrance7;		
			
	ZuulRoom* janitorC = new ZuulRoom("Janitor's Closet", "A closet that is used by a janitor, full of exciting cleaning supplies and dirty rags.",
	false, jKey, hammer, entrances7);
	
	
	char entrance8[] = {'e'};
	char* entrances8 = entrance8;
	
	ZuulItem* disguise = new ZuulItem("Woman's Disguise", "A lovely wig along with a makeup kit. Has potential to transform you into a pretty lady!", "You can see a wig next to some makeup. Looks like some unfortunate person forget it here. Might be useful when getting into the Girl's Bathroom.");
	ZuulRoom* copyR = new ZuulRoom("Copyroom", "A copyroom with a basic copier. Exciting stuff.", false,
	hammer, disguise, entrances8);
	
	
	
	char entrance9[] = {'w'};
	char* entrances9 = entrance9;		
	
	ZuulRoom* boysB = new ZuulRoom("Boys Bathroom", "Your average boys bathroom, full of filth and dirt everywhere. Unfortunately there isn't anything or anyone in here.",
	entrances9);
	
	ZuulItem* dungeonM = new ZuulItem("Dungeon Membership", "A Membership to enter the modernized, Neet's dungeon!", "You can see a membership card to something on the ground.");
	
	char entrance10[] = {'w'};
	char* entrances10 = entrance10;		
	
	ZuulRoom* girlsB = new ZuulRoom("Girls Bathroom", "The dreaded girls bathroom. The girls in here look at you suspiciously but they don't say anything. ",
			false, disguise, dungeonM, entrances10);
			
	
	ZuulItem* legalKey = new ZuulItem("Legal D. Key", "A key used to unlock the legal department. It is covered in blood.", "You can see a key in here, unfortunately for you it is covered in blood. :(");
	
	char entrance11[] = {'e'};
	char* entrances11 = entrance11;		
	
	ZuulRoom* sDungeon = new ZuulRoom("Small Dungeon", "A lovely dungeon installed with the latest tools for torturing you enemies! It has beautiful wooden floors and a futuristic torture instruments that are coated in a thick layer of blood." 
	,false, dungeonM, legalKey, entrances11);
			
	
	
	char entrance12[] = {'w'};
	char* entrances12 = entrance12;		
	
	ZuulRoom* legalD = new ZuulRoom("Legal Department", "The most despicable room in the dungeon by far. This room is filled with lawyers who all keep trying to buy your soul from you. Strange. There seems to be a large door towards the SOUTH that leads to the bosses office.",
	false, legalKey, entrances12);
	
	
	ZuulItem* armoryKey = new ZuulItem("Armory Key", "Hmm I wonder what this could be for.", "You should probably grab the key from this guy.");
	
	char entrance13[] = {'n'};
	char* entrances13 = entrance13;		
	
	ZuulRoom* legalD2 = new ZuulRoom("Big Lawyer's Domain", "There is a very big lawyer in here unfortunately. He says, 'Hey there, you seem new to these parts. You must be an adventurer right? Well I'm tired of that guy Neet,  he keeps getting in the way of some important business deals of mine. Here GRAB this key and use it to get some weapons from the armory. I'm sure that'll be plenty to get rid of him.'",
	armoryKey, entrances13);
	
	
	
	char entrance14[] = {'w'};
	char* entrances14 = entrance14;		
	
	ZuulRoom* tRoom = new ZuulRoom("Torture Room", "This is a very bizarre torture room. Instead of torture instruments there are fluffy stuffed animals instead. There doesn't seem to be anything in here.",
	entrances14);
	
	
	char entrance15[] = {'e'};
	char* entrances15 = entrance15;		
	
	ZuulRoom* armory = new ZuulRoom("Armory", "An armory, how cool! Looks like all the items in here are guarded by stern looking soldiers. Maybe, you'll have better luck in the office to the SOUTH?",
	false, armoryKey, entrances15);
	
	
	ZuulItem* bigZ = new ZuulItem("Big Z", "A massive rocket launcher, that should be able to pierce its way into Neet's throneroom.", "You should probably pick that rocket launcher up.");
	
	char entrance16[] = {'n'};
	char* entrances16 = entrance16;		
	
	ZuulRoom* armory2 = new ZuulRoom("Armory Office", "There are weapons in here! From assault rifles to rocket launchers, this room has it all! However, the most dangerous looking one is a massive rocket launcher called the BIG Z. This should get the job done.",
	bigZ, entrances16);
	
	
	char entrance17[] = {'n'};
	char* entrances17 = entrance17;		
	
	ZuulRoom* bRoom = new ZuulRoom("THE BOSS", "The door explodes into a heap of rotting  and you enter the throne room. The lights suddenly turn on overhead. 'FOOL YOU THINK YOU CAN CHALLENGE ME?? MHUAHAHUUAHAHHAUA PREPARE TO DIE.' The fight commences and you launch a rocket at the Great Neet. He dies instantly. Wow that was easy. You pat yourself on the back and go out the back door. You begin heading home.",
	true, false, bigZ, entrances17);
	
	//ZuulRoom z1[6] = {*janitorC, *blandOffice, *copyR, *sDungeon, *armory, *armory2};
	ZuulRoom* z1 = new ZuulRoom[6];
	z1[0] = *janitorC;
	z1[1] = *blandOffice;
	z1[2] = *copyR;
	z1[3] = *sDungeon;
	z1[4] = *armory;
	z1[5] = *armory2;
	//ZuulRoom* zz1 = z1;
	
	zuulRooms[0] = z1;//finally fixed it, assigns arrays to the correct zRooms position
	
	//ZuulRoom z2[6] = {*hall1, *hall2, *hall3, *hall4, *hall5, };
	ZuulRoom* z2 = new ZuulRoom[6];
	z2[0] = *hall1;
	z2[1] = *hall2;
	z2[2] = *hall3;
	z2[3] = *hall4;
	z2[4] = *hall5;
	z2[5] = *bRoom;
	
	//ZuulRoom* zz2 = z2;
	zuulRooms[1] = z2;
	
	//ZuulRoom z3[6] = {*pinkRoom, *girlsB, *boysB, *tRoom, *legalD, *legalD2};
	ZuulRoom* z3 = new ZuulRoom[6];
	z3[0] = *pinkRoom;
	z3[1] = *girlsB;
	z3[2] = *boysB;
	z3[3] = *tRoom;
	z3[4] = *legalD;
	z3[5] = *legalD2;
	
	//ZuulRoom* zz3 = z3;
	zuulRooms[2] = z3;

}
