
#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "StudentWorld.h"

const int TUNNELMAN_START_X = 30;
const int TUNNELMAN_START_Y = 60;
const unsigned int TUNNELMAN_IMAGE_DEPTH = 0;
const float TUNNELMAN_IMAGE_SIZE = 1.0;
const int TUNNELMAN_INIT_HITPOINTS = 10;
const int TUNNELMAN_INIT_GOLD = 0;
const int TUNNELMAN_INIT_WATER = 5;
const int TUNNELMAN_INIT_SONAR = 1;

const float EARTH_IMAGE_SIZE = 0.25;
const unsigned int EARTH_IMAGE_DEPTH = 3;

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Actor : public GraphObject {
public:
    Actor(StudentWorld* sWorld, int imageID, int startX, int startY, GraphObject::Direction startDirection, float size, unsigned int depth);
    virtual ~Actor();
    virtual void doSomething();
    StudentWorld* getWorld();
private:
    StudentWorld* sWorldPtr;
};

class Earth : public Actor {
public:
    Earth(StudentWorld* sWorld,int startX, int startY);
    virtual ~Earth();
    virtual void doSomething();
};

class TunnelMan : public Actor {
public:
    TunnelMan(StudentWorld* sWorld);
    virtual ~TunnelMan();
    virtual void doSomething();
    int getsonarCharge();
    int getgoldNuggets();
    int getwaterSquirts();
    int gethitPoints();
private:
    bool checkBounds(int col, int row);
    void removeEarthObjectsOverlap4x4();
    int waterSquirts;
    int sonarCharge;
    int hitPoints;
    int goldNuggets;
};
#endif // ACTOR_H_

