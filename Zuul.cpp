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
		inventory[i] = ZuulItem("Lol", "XDDD", "Sup");
	}

	

	createRooms(zuulRooms);

	for (int i = 0; i < 3; i++) {//sets all rooms to false
		zuulRooms[i]= new ZuulRoom();
		for (int j = 0; j < 6; j++) {
			inRoom[i][j] = false;
		}
	}

	
	inRoom[0][1] = true;//sets current room to true
	
	std::cout << "Greetings adventurer, you wake up in the castle of Neet, ruled by the most"
			<<" dangerous being in the universe, Neet the Dark Sorcerer! To escape you must defeat him."
			<< "\nGood luck laddie!";
	printMap(inRoom, zuulRooms);

}

void printMap(bool** inRoom, ZuulRoom** zR){
	char charMap[3][6];
	for(int x = 0; x < 3; x++){
		ZuulRoom* tmp = zR[x];
		for(int y = 0; y < 6; y++){
			if(inRoom[x][y]){
				
				std::cout << (tmp[y])->getName();
				std::cout << inRoom[x][y];
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

bool checkPossible(int loc, int math, char plane) { //checks if location is within grid
	int kappa = loc + math;
	int axisNum;
	if ('y' == plane) {//checks if plane is y or x
		std::cout << plane;
		axisNum = 3;
	} else {
		axisNum = 6;
	}
	if (kappa >= axisNum || kappa < 0 == true) {
		return false;
	}
	return true;
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
	strcpy(b, "Your average hallway,	floor, tiles, ceiling etc. To the WEST you can see a janitors closet, to the EAST you see a lovely pink room, to the SOUTH you see another stretch of hallway.\n");
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
	
	ZuulRoom z1[6] = {*janitorC, *blandOffice, *copyR, *sDungeon, *armory, *armory2};
	ZuulRoom* zz1 = z1;
	
	zuulRooms[0] = zz1;//finally fixed it, assigns arrays to the correct zRooms position
	
	ZuulRoom z2[6] = {*hall1, *hall2, *hall3, *hall4, *hall5, *bRoom};
	ZuulRoom* zz2 = z2;
	zuulRooms[1] = zz2;
	
	ZuulRoom z3[6] = {*pinkRoom, *girlsB, *boysB, *tRoom, *legalD, *legalD2};
	ZuulRoom* zz3 = z3;
	zuulRooms[2] = zz3;

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
