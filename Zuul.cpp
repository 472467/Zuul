#include "Zuul.h"
/*
 	CREATED BY THE WONDEROUS BRENDAN
  A PORT OF THE JAVA ZUUL I MADE LAST YEAR
	PREPARE FOR THE HORRORS OF PORTING STRINGS TO CHAR ARRAYS
	*cries softly*
 */


int main() {
	bool** inRoom = new bool*[3];//default variables 6x3
	bool** neighbors = new bool*[3]; //6x3
	ZuulRoom** zuulRooms = new ZuulRoom*[3];//6x3
	bool gameWon = false;
	ZuulItem* test = new ZuulItem;
	ZuulItem* inventory = new ZuulItem[6];//6

	system("clear");
	for (int i = 0; i < 6; i++) {
		inventory[i] = new ZuulItem("Lol", "XDDD", "Sup");
	}
	createRooms(zuulRooms);

	for (int i = 0; i < 6; i++) {//sets all rooms to false
		for (int j = 0; j < 3; j++) {
			inRoom[i][j] = false;
		}
	}

	
	inRoom[0][1] = true;//sets current room to true
	

	std::cout << "Greetings adventurer, you wake up in the castle of Neet, ruled by the most"
			<<" dangerous being in the universe, Neet the Dark Sorcerer! To escape you must defeat him."
			<< "\nGood luck laddie!";
	printMap(inRoom);

}

void printMap(bool** inRoom){
	char charMap[6][3];
	for(int x = 0; x < 6; x++){
		for(int y = 0; y < 3; y++){
			if(inRoom){
				charMap[x][y] = 'X';
			}else{
				charMap[x][y] = ' ';
			}
			
		}
	}
	std::cout<< "\n"
	<< '[' <<inRoom[0][0] << ']' << '[' <<inRoom[1][0] << ']' << '[' <<inRoom[2][0] << ']' << '[' << inRoom[3][0] << ']' << '[' <<inRoom[4][0] << ']' << '[' <<inRoom[5][0] << ']' << "\n"
	<< '[' <<inRoom[0][1] << ']' << '[' <<inRoom[1][1] << ']' << '[' <<inRoom[2][1] << ']' << '[' << inRoom[3][1] << ']' << '[' <<inRoom[4][1] << ']' << '[' <<inRoom[5][1] << ']' << "\n"
	<< '[' <<inRoom[0][2] << ']' << '[' <<inRoom[1][2] << ']' << '[' <<inRoom[2][2] << ']' << '[' << inRoom[3][2] << ']' << '[' <<inRoom[4][2] << ']' << '[' <<inRoom[5][2] << ']' ;
	
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
	char* west = "WEST";
	char* east = "EAST";
	char* north = "NORTH";
	char* south = "SOUTH";
	char entrance[] = {'w', 'e', 's'};
	//entrance = ;
	char* entrances = entrance;
	std::string tmp = "Hallway 1";
	char* h1 = new char[500];
	strcpy(h1, tmp.c_str());
	
	ZuulRoom* hall1 = new ZuulRoom(h1, "Your average hallway,	floor, tiles, ceiling etc. To the WEST you can see a janitors closet, to the EAST you see a lovely pink room, to the SOUTH you see another stretch of hallway.\n"
			,entrances);
	zuulRooms[0][1] = hall1;
	
	char entrance1[] = {'w'};
	char* entrances1 = entrance;
	
	ZuulRoom pinkRoom = new ZuulRoom("Pink Room", "This room is covered in pink things; pink umbrellas, pink apples, pink napkins, it even smells pink. Nothing useful seems to be in here unless you're looking for some pink underwear.\n",
			entrances1);
	zuulRooms[0][2] = pinkRoom;
	ZuulRoom hall2 = new ZuulRoom("Hallway 2", "Another hallway, exciting stuff. To the WEST is a bland looking office, to the EAST is the Girls Bathroom, unfortunately some girls seem to be in there already.\n",
			new char{'n', 'w', 'e', 's'});
	zuulRooms[1][1] = hall2;
	ZuulRoom hall3 = new ZuulRoom("Hallway 3", "Wow this is also a hallway, fun stuff. To the WEST is a dangerous looking copyroom, to the EAST is the Boys Bathroom, and to the SOUTH is you guessed it, another hallway.\n", new char{'n', 'w', 'e', 's'});
	zuulRooms[2][1] = hall3;
	ZuulRoom hall4 = new ZuulRoom("Hallway 4", "This hallway is great actually, the tiles are solid gold and the lights above head are now crystal chandeliers. To the WEST is small dungeon, however there is guard blocking the entrance. You'll need some sort of dungeon membership to pass through. To the EAST is a room used for torture, to the SOUTH is what looks like a menacing hallway.\n", new char{'n', 'w', 'e', 's'});
	zuulRooms[3][1] = hall4;
	ZuulRoom hall5 = new ZuulRoom("Hallway 5", "As you enter this hallway the lights turn off completely. Then torches along the wall magically turn light up, and a voice shouts out,'puny human, do you dare to face the might of Neet????', 'if so please find the key tothe door to the SOUTH. Thanks :)' To the SOUTH is a massive door made of bones and souls of defeated challengers, to the WEST is an armory filled with all sorts of dangerous objects, to the SOUTH is the legal department, the most vile room of them all.\n",
			new char{'n', 'w', 'e', 's'});
	zuulRooms[4][1] = hall5;
	
	ZuulItem jKey = new ZuulItem("Janitor's Key",
			"I think you can figure out what this is for.", "You can see a key on top of one of the desks.");
	ZuulRoom blandOffice = new ZuulRoom("Bland Office", "This is, without a doubt, the blandest office you have ever endured. Beige surrounds you. Beige watches. You never felt so bored yet intimidated at the same time. The room smells faintly of cleaning supplies and paper.\n", jKey, new char{'e'});
	ZuulItem hammer = new ZuulItem("Battered Hammer", 
			"A hammer worn down over by years of use. Looks strong enough to break a weak lock.", "You can see a shabby looking hammer under a few sketchy magazines.");
	ZuulRoom janitorC = new ZuulRoom("Janitor's Closet", "A closet that is used by a janitor, full of exciting cleaning supplies and dirty rags.", false, jKey, hammer, {'e'});
	zuulRooms[0][0] = janitorC;
	ZuulItem disguise = new ZuulItem("Woman's Disguise", "A lovely wig along with a makeup kit. Has potential to transform you into a pretty lady!", "You can see a wig next to some makeup. Looks like some unfortunate person forget it here. Might be useful when getting into the Girl's Bathroom.");
	ZuulRoom copyR = new ZuulRoom("Copyroom", "A copyroom with a basic copier. Exciting stuff.", false,
	hammer, disguise, new char{'e'});
	zuulRooms[2][0] = copyR;
	zuulRooms[1][0] = blandOffice;
	ZuulRoom boysB = new ZuulRoom("Boys Bathroom", "Your average boys bathroom, full of filth and dirt everywhere. Unfortunately there isn't anything or anyone in here.", new char{'w'});
	zuulRooms[2][2] = boysB;
	ZuulItem dungeonM = new ZuulItem("Dungeon Membership", "A Membership to enter the modernized, Neet's dungeon!", "You can see a membership card to something on the ground.");
	ZuulRoom girlsB = new ZuulRoom("Girls Bathroom", "The dreaded girls bathroom. The girls in here look at you suspiciously but they don't say anything. ",
			false, disguise, dungeonM, {'w'});
	zuulRooms[1][2] = girlsB;
	ZuulItem legalKey = new ZuulItem("Legal D. Key", "A key used to unlock the legal department. It is covered in blood.", "You can see a key in here, unfortunately for you it is covered in blood. :(");
	ZuulRoom sDungeon = new ZuulRoom("Small Dungeon", "A lovely dungeon installed with the latest tools for torturing you enemies! It has beautiful wooden floors and a futuristic torture instruments that are coated in a thick layer of blood." ,false,
			dungeonM, legalKey, {'e'});
	zuulRooms[3][0] = sDungeon;
	ZuulRoom legalD = new ZuulRoom("Legal Department", "The most despicable room in the dungeon by far. This room is filled with lawyers who all keep trying to buy your soul from you. Strange. There seems to be a large door towards the SOUTH that leads to the bosses office.", false, legalKey, new char{'w'});
	zuulRooms[4][2] = legalD;
	ZuulItem armoryKey = new ZuulItem("Armory Key", "Hmm I wonder what this could be for.", "You should probably grab the key from this guy.");
	ZuulRoom legalD2 = new ZuulRoom("Big Lawyer's Domain", "There is a very big lawyer in here unfortunately. He says, 'Hey there, you seem new to these parts. You must be an adventurer right? Well I'm tired of that guy Neet,  he keeps getting in the way of some important business deals of mine. Here GRAB this key and use it to get some weapons from the armory. I'm sure that'll be plenty to get rid of him.'", armoryKey, new String[]{"NORTH"});
	zuulRooms[5][2] = legalD2;
	ZuulRoom tRoom = new ZuulRoom("Torture Room", "This is a very bizarre torture room. Instead of torture instruments there are fluffy stuffed animals instead. There doesn't seem to be anything in here.", new char{'w'});
	zuulRooms[3][2] = tRoom;
	ZuulRoom armory = new ZuulRoom("Armory", "An armory, how cool! Looks like all the items in here are guarded by stern looking soldiers. Maybe, you'll have better luck in the office to the SOUTH?", false, armoryKeya
	, new char{'e'});
	
	zuulRooms[4][0] = armory;
	ZuulItem bigZ = new ZuulItem("Big Z", "A massive rocket launcher, that should be able to pierce its way into Neet's throneroom.", "You should probably pick that rocket launcher up.");
	ZuulRoom armory2 = new ZuulRoom("Armory Office", "There are weapons in here! From assault rifles to rocket launchers, this room has it all! However, the most dangerous looking one is a massive rocket launcher called the BIG Z. This should get the job done.", bigZ, new char{'n'});
	zuulRooms[5][0] = armory2;
	
	ZuulRoom bRoom = new ZuulRoom("THE BOSS"), "The door explodes into a heap of rotting  and you enter the throne room. The lights suddenly turn on overhead. 'FOOL YOU THINK YOU CAN CHALLENGE ME?? MHUAHAHUUAHAHHAUA PREPARE TO DIE.' The fight commences and you launch a rocket at the Great Neet. He dies instantly. Wow that was easy. You pat yourself on the back and go out the back door. You begin heading home.",true, false, bigZ, new char{'n'});
	zuulRooms[5][1] = bRoom;

}
ZuulRoom getCurrentRoom(bool** inRoom, ZuulRoom** zuulRooms){
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			if(inRoom[i][j]){
				return zuulRooms[i][j];
			}
		}
	}
	return NULL; //if this runs yah fucked up somewhere
}
