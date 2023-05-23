
#include "StudentWorld.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Actor.h"
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
    return new StudentWorld(assetDir);
    
}

StudentWorld::StudentWorld(std::string assetDir) : GameWorld(assetDir)
{
}

void StudentWorld::removeEarthObjectIfExistsAt(int xx, int yy)
{
    if (xx < VIEW_WIDTH && yy < VIEW_HEIGHT - SPRITE_HEIGHT && xx >= 0 && yy >= 0) {
        if (EarthObj[yy][xx] != nullptr) {
        delete EarthObj[yy][xx];
        EarthObj[yy][xx] = nullptr;
        }
    }
}

int StudentWorld::init()
{
    if (TunnelManObj == nullptr) {
        TunnelManObj = new TunnelMan(this);
    }

    for (int i = 0; i < VIEW_HEIGHT-SPRITE_HEIGHT; i++) {
        for (int j = 0; j < VIEW_WIDTH; j++) {
            if (i > 3 && (j >= 30 and j <= 33))
            ;
            else
                EarthObj[i][j] = new Earth(this,j,i);
        }
     }
    return GWSTATUS_CONTINUE_GAME;
}

 int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    
    setDisplayText();
    TunnelManObj->doSomething();
    return GWSTATUS_CONTINUE_GAME;
}


 void StudentWorld::setDisplayText() {
     int level = getLevel();
     int lives = getLives();
     int health = ((TunnelManObj->gethitPoints())/10)*100;
     int squirts = (TunnelManObj->getwaterSquirts());
     int gold = (TunnelManObj->getgoldNuggets());
     int barrelsLeft = min(2 + level, 21);
     int sonar = (TunnelManObj->getsonarCharge());
     unsigned int sc = getScore();

     string displayText = formatDisplayString(level, lives, health, squirts, gold, barrelsLeft, sonar, sc);
     setGameStatText(displayText);
 }

 string StudentWorld::formatDisplayString(int level, int lives, int health, int squirts, int gold, int barrelsLeft, int sonar, unsigned int sc) {
     ostringstream oss;
     oss.fill(' ');
     oss << "Lvl: " << setw(2) << level << "  " << "Lives: " << setw(1) << lives << "  " << "Hlth: "<< setw(3) << health << "%  "
         << "Wtr: " << setw(2) << squirts << "  Gld: " << setw(2) << gold << "  Oil Left: " << setw(2) << barrelsLeft <<
         "  Sonar: " << setw(2) << sonar << "  Scr: " << setw(6) << sc;
     string formattedString = oss.str();
     return formattedString;
 }

 void StudentWorld::cleanUp()
 {
     for (int i = 0; i < VIEW_HEIGHT - SPRITE_HEIGHT; i++) {
         for (int j = 0; j < VIEW_WIDTH; j++) {
             if (EarthObj[i][j] != nullptr)
                 delete EarthObj[i][j];
         }
     }
     if (TunnelManObj != nullptr)
       delete TunnelManObj;
    
 }

 StudentWorld::~StudentWorld()
 {
 }

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp

