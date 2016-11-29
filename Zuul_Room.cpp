#include "Zuul_Room.h"

ZuulRoom::ZuulRoom() {
    char* roomName = "NONE SET"; //default contructers
    char* description = "No desc set somehow";
    bool canEnter = true;
    ZuulItem enterItem = new ZuulItem();
    ZuulItem containedItem = new ZuulItem();
    char* entrances = new char[4][15];
    bool winGame = false;
}
ZuulRoom::ZuulRoom(String name, char* desc, bool canEnt, ZuulItem enter, ZuulItem contItem, char* ent){//room with all 
        roomName = name;
        description = desc;
        canEnter = canEnt;
        enterItem = enter;
        containedItem = contItem;
        entrances = ent;
        
    }
    public ZuulRoom(String name, String desc, boolean canEnt, ZuulItem enter, String[] ent){//room with item needed to enter
        roomName = name;
        description = desc;
        canEnter = canEnt;
        enterItem = enter;
        entrances = ent;
        
    }
    public ZuulRoom(String name, String desc,boolean wonG, boolean canEnt, ZuulItem enter, String[] ent){//boss room
        roomName = name;
        description = desc;
        canEnter = canEnt;
        enterItem = enter;
        entrances = ent;
        winGame = true;
        
    }
    public ZuulRoom(String name, String desc, ZuulItem contItem, String[] ent){//room with item in it
        roomName = name;
        description = desc;
        containedItem = contItem;
        entrances = ent;
        
    }
    public ZuulRoom(String name, String desc, String[] ent){ //basic room
        roomName = name;
        description = desc;
        entrances= ent;
    }
    public ZuulRoom(String name){//creates placeholder room
        roomName =  name;
    }
    public void setEntrances(String[] ent){ //sets entrances
        entrances = ent;
    }
    public String getEntrances(){//converts array of entrances to string and returns it
        String entString = "";
        for(int x = 0; x < entrances.length; x++){
            if (x == entrances.length - 1){
                entString+= entrances[x];
            }
            else{
                entString+= entrances[x] + ", ";
            }
        }
        String type = "Entrances: " + entString;
        return type;
    }
    public String getDesc(){//gets desc
        return description;
    }
    public String getName(){//gets name
        return roomName;
    }
    @Override
    public String toString(){ //gives all info about zuulroom in string format for debug
       String dank = "Name: " + roomName +
               "\nCanEnter: " + canEnter +
               "\nEnter Item: " + enterItem.name +
               "\nContained Item: " + containedItem.name +
               "\nEntrances: " + getEntrances() +
               "Game won: " + winGame;
       return dank;
    }
}
