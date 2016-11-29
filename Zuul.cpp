/*
 	CREATED BY THE WONDEROUS BRENDAN
  A PORT OF THE JAVA ZUUL I MADE LAST YEAR
	PREPARE FOR THE HORRORS OF PORTING STRINGS TO CHAR ARRAYS
	*cries softly*
 */
public class Zuul {

    bool[][] inRoom = new boolean[6][3];//default variables
    bool[][] neighbors = new boolean[6][3];
    ZuulRoom[][] zuulRooms = new ZuulRoom[6][3];
    bool gameWon = false;
    ZuulItem[] inventory = new ZuulItem[6];
	
	int main() {
		System("clear");
        for (int i = 0; i < inventory.length; i++) {
            inventory[i] = new ZuulItem();
        }
        createRooms();

        for (int i = 0; i < rooms.length; i++) {//sets all rooms to false
            for (int j = 0; j < rooms[0].length; j++) {
                inRoom[i][j] = false;
            }
        }


        inRoom[0][1] = true;//sets current room to true
        rooms[0][1].setBackground(Color.pink);//current room indicator
        rooms[0][1].setText("Hallway 1");//starting rooms next to you
        rooms[0][0].setText("Janitor's Closet");
        rooms[0][2].setText("Pink Room");
        rooms[1][1].setText("Hallway 2");

        cout << "Greetings adventurer, you wake up in the castle of Neet, ruled by the most"
                + " dangerous being in the universe, Neet the Dark Sorcerer! To escape you must defeat him."
                + "\nGood luck laddie!";

    }
    
    public Zuul() {
        
    }

    public static boolean checkNeighbor(int clickedX, int clickedY) {//checks if given location is a neighbor
        int x = 0;
        int y = 0;
        int count = 0;
        for (int i = 0; i < inRoom.length; i++) {
            for (int j = 0; j < inRoom[0].length; j++) {
                neighbors[i][j] = false;
                count++;

                if (inRoom[i][j]) {
                    x = i;
                    y = j;
                }
            }
        }
        if (checkPossible(x, 1, "x")) {//x+1
            neighbors[x + 1][y] = true;
        }
        if (checkPossible(y, 1, "y")) {//y+1
            neighbors[x][y + 1] = true;
        }
        if (checkPossible(x, -1, "x")) {//x-1
            neighbors[x - 1][y] = true;
        }
        if (checkPossible(y, -1, "y")) {//y-1
            neighbors[x][y - 1] = true;
        }
        neighbors[x][y] = true;
        if (neighbors[clickedX][clickedY]) {
            return true;
        }
        return false;
    }

    public static boolean checkPossible(int loc, int math, String plane) { //checks if location is within grid
        int kappa = loc + math;
        int axisNum;
        if (plane.equals("y")) {//checks if plane is y or x
            axisNum = 3;
        } else {
            axisNum = 6;
        }
        if (kappa >= axisNum || kappa < 0 == true) {
            return false;
        }
        return true;
    }

    

    public void createRooms() {//creates rooms and adds them to zuulRooms array
        ZuulRoom hall1 = new ZuulRoom("Hallway 1", "Your average hallway, floor, tiles, ceiling etc. "
                + " to the WEST you can see a janitors closet" + ", to the EAST you see a lovely pink room,"
                + "to the SOUTH you see another stretch of hallway.\n",
                new String[]{"WEST", "EAST", "SOUTH"});
        zuulRooms[0][1] = hall1;
        
        ZuulRoom pinkRoom = new ZuulRoom("Pink Room", "This room is covered in pink things; "
                + "pink umbrellas, pink apples, pink napkins, it even smells pink. "
                + "Nothing useful seems to be in here unless you're looking for some pink underwear.\n",
                new String[]{"WEST"});
        zuulRooms[0][2] = pinkRoom;
        ZuulRoom hall2 = new ZuulRoom("Hallway 2", "Another hallway, exciting stuff. To the WEST is "
                + "a bland looking office, to the EAST is the Girls Bathroom, unfortunately"
                + " some girls seem to be in there already.\n",
                new String[]{"NORTH", "WEST", "EAST", "SOUTH"});
        zuulRooms[1][1] = hall2;
        ZuulRoom hall3 = new ZuulRoom("Hallway 3", "Wow this is also a hallway, fun stuff. To the WEST"
                + " is a dangerous looking copyroom, to the EAST is the Boys Bathroom, and to the SOUTH is"
                + "you guessed it, another hallway.\n", new String[]{"NORTH", "WEST", "EAST", "SOUTH"});
        zuulRooms[2][1] = hall3;
        ZuulRoom hall4 = new ZuulRoom("Hallway 4", "This hallway is great actually, the tiles are solid"
                + " gold and the lights above head are now crystal chandeliers. To the WEST is small "
                + "dungeon, however there is guard blocking the entrance. You'll"
                + " need some sort of dungeon membership to pass through."
                + "To the EAST is a room used for torture, to the SOUTH is what looks like a "
                + "menacing hallway.\n", new String[]{"NORTH", "WEST", "EAST", "SOUTH"});
        zuulRooms[3][1] = hall4;
        ZuulRoom hall5 = new ZuulRoom("Hallway 5", "As you enter this hallway the lights turn off completely."
                + " Then torches along the wall magically turn light up, and a voice shouts out,'puny"
                + " human, do you dare to face the might of Neet????', 'if so please find the key to"
                + " the door to the SOUTH. Thanks :)' To the SOUTH is a massive door made of bones and "
                + "souls of defeated challengers, to the WEST is an armory filled with all sorts of dangerous"
                + " objects, to the SOUTH is the legal department, the most vile room of them all.\n",
                new String[]{"NORTH", "WEST", "EAST", "SOUTH"});
        zuulRooms[4][1] = hall5;
        
        ZuulItem jKey = new ZuulItem("Janitor's Key",
                "I think you can figure out what this is for.", "You can see a key on top of one"
                + " of the desks.");
        ZuulRoom blandOffice = new ZuulRoom("Bland Office", "This is, without a doubt, the blandest"
                + " office you have ever endured. Beige surrounds you. Beige watches. "
                + " You never felt so bored yet intimidated at the same time."
                + "  The room smells faintly of cleaning supplies and paper.\n", jKey, new String[]{"EAST"});
        ZuulItem hammer = new ZuulItem("Battered Hammer", 
                "A hammer worn down over by years of use. Looks strong enough "
                + "to break a weak lock.", "You can see a shabby looking hammer "
                + "under a few sketchy magazines.");
        ZuulRoom janitorC = new ZuulRoom("Janitor's Closet", "A closet that is used by a ja"
                + "nitor, full of exciting"
                + " cleaning supplies and dirty rags.", false, jKey, hammer, new String[]{"EAST"});
        zuulRooms[0][0] = janitorC;
        ZuulItem disguise = new ZuulItem("Woman's Disguise", "A lovely wig along with a makeup kit. Has"
                + " potential to transform you into a pretty lady!", "You can see a wig next to some "
                        + "makeup. Looks like some unfortunate person forget it here."
                        + " Might be useful when getting into the Girl's Bathroom.");
        ZuulRoom copyR = new ZuulRoom("Copyroom", "A copyroom with a basic copier. Exciting stuff.", false,
        hammer, disguise, new String[]{"EAST"});
        zuulRooms[2][0] = copyR;
        zuulRooms[1][0] = blandOffice;
        ZuulRoom boysB = new ZuulRoom("Boys Bathroom", "Your average boys bathroom, full of filth and "
                + "dirt everywhere. Unfortunately there isn't anything or "
                + "anyone in here.", new String[]{"WEST"});
        zuulRooms[2][2] = boysB;
        ZuulItem dungeonM = new ZuulItem("Dungeon Membership", "A Membership "
                + "to enter the modernized, Neet's dungeon!", "You can see a"
                        + " membership card on the ground.");
        ZuulRoom girlsB = new ZuulRoom("Girls Bathroom", "The dreaded girls bathroom, the girls "
                + "in here look at you suspiciously but they don't say anything. ",
                false, disguise, dungeonM, new String[]{"WEST"});
        zuulRooms[1][2] = girlsB;
        ZuulItem legalKey = new ZuulItem("Legal D. Key", "A key used to unlock"
                + " the legal department. It is covered in blood.", "You can "
                + "see a key in here, unfortunately for you it is covered in "
                        + "blood. :(");
        ZuulRoom sDungeon = new ZuulRoom("Small Dungeon", "A lovely dungeon"
                + " installed with the latest tools for torturing you enemies!"
                + " It has beautiful wooden floors and a futuristic torture "
                + "instruments that are coated in a thick layer of blood." ,false,
                dungeonM, legalKey, new String[]{"EAST"});
        zuulRooms[3][0] = sDungeon;
        ZuulRoom legalD = new ZuulRoom("Legal Department", "The most despicable "
                + "room in the dungeon by far. This room is filled with lawyers "
                + "who all keep trying to buy your soul from you. Strange. There"
                + " seems to be a large door towards the SOUTH that leads to the"
                + " bosses office.", false, legalKey, new String[]{"WEST"});
        zuulRooms[4][2] = legalD;
        ZuulItem armoryKey = new ZuulItem("Armory Key", "Hmm I wonder what this could"
                + " be for.", "You should probably grab the key from this guy.");
        ZuulRoom legalD2 = new ZuulRoom("Big Lawyer's Domain", "There is a very"
                + "big lawyer in here unfortunately. He says, 'Hey there,"
                + "you seem new to these parts. You must be an adventurer right? "
                + "Well I'm tired of that guy Neet,  he keeps getting in the way"
                + " of some important business deals of mine. Here GRAB this key "
                + "and use it to get some weapons from the armory. I'm sure that'll"
                + " be plenty to get rid of him.'", armoryKey, new String[]{"NORTH"});
        zuulRooms[5][2] = legalD2;
        ZuulRoom tRoom = new ZuulRoom("Torture Room", "This is a very bizarre torture room."
                + " Instead of torture instruments there are fluffy stuffed animals instead."
                + "There doesn't seem to be anything in here.", new String[]{"WEST"});
        zuulRooms[3][2] = tRoom;
        ZuulRoom armory = new ZuulRoom("Armory", "An armory, how cool! Looks like all the items "
                + "in here are guarded by stern looking soldiers. Maybe, you'll h"
                + "ave better luck in the office to the SOUTH?", false, armoryKey
        , new String[]{"EAST"});
        
        zuulRooms[4][0] = armory;
        ZuulItem bigZ = new ZuulItem("Big Z", "A massive rocket launcher, that "
                + "should be able to pierce its way into Neet's throneroom.", "You"
                        + " should probably pick that rocket launcher up.");
        ZuulRoom armory2 = new ZuulRoom("Armory Office", "There are weapons in here! "
                + "From assault rifles to rocket launchers, this room has it all! However, the most"
                + "dangerous looking one is a massive rocket launcher called the BIG Z. This should get the job"
                + " done.", bigZ, new String[]{"NORTH"});
        zuulRooms[5][0] = armory2;
        
        ZuulRoom bRoom = new ZuulRoom("THE BOSS", "The door explodes into a heap "
                + "of rotting  and you enter the throne room. The lights suddenly"
                + " turn on overhead. 'FOOL YOU THINK YOU CAN CHALLENGE ME?? "
                + "MHUAHAHUUAHAHHAUA PREPARE TO DIE.' The fight commences and you"
                + "launch a rocket at the Great Neet. He dies instantly. Wow that"
                + " was easy. You pat yourself on the back and go out the back"
                + " door. You begin heading home.",true, false, bigZ, new String[]{
                    "NORTH"});
        zuulRooms[5][1] = bRoom;

    }
    public static ZuulRoom getCurrentRoom(){
        for (int i = 0; i < inRoom.length; i++) {
            for (int j = 0; j < inRoom[0].length; j++) {
                if(inRoom[i][j]){
                    return zuulRooms[i][j];
                }
            }
        }
        return null; //if this runs yah fucked up somewhere
    }

}
