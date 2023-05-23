
#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>

class Actor;
class TunnelMan;


// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir);
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    void removeEarthObjectIfExistsAt(int x, int y);
    ~StudentWorld();

private:
    TunnelMan* TunnelManObj;
    Actor* EarthObj[VIEW_HEIGHT - SPRITE_HEIGHT][VIEW_WIDTH];

    void setDisplayText();
    std::string formatDisplayString(int level, int lives, int health, int squirts, int gold,
        int barrelsLeft, int sonar, unsigned int sc);
};
#endif // STUDENTWORLD_H_

