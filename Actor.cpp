
#include "Actor.h"


Actor::Actor(StudentWorld* sWorld,int imageID, int startX, int startY, GraphObject:: Direction startDirection, float size, unsigned int depth)
:GraphObject(imageID, startX, startY, startDirection, size, depth)
{
    sWorldPtr = sWorld;
}

Actor::~Actor() {
}

StudentWorld* Actor::getWorld()
{
    return sWorldPtr;
}


void Actor::doSomething()
{
    ;

}

Earth::Earth(StudentWorld* sWorld, int startX, int startY):Actor(sWorld, TID_EARTH, startX, startY, right,  EARTH_IMAGE_SIZE, EARTH_IMAGE_DEPTH)
{
    setVisible(true);
}

Earth::~Earth()
{
}

void Earth::doSomething()
{
    ;
}
TunnelMan::TunnelMan(StudentWorld* sWorld):Actor(sWorld,TID_PLAYER, TUNNELMAN_START_X, TUNNELMAN_START_Y, right, TUNNELMAN_IMAGE_SIZE, TUNNELMAN_IMAGE_DEPTH)
{
    setVisible(true);
    hitPoints = TUNNELMAN_INIT_HITPOINTS;
    sonarCharge = TUNNELMAN_INIT_SONAR;
    goldNuggets = TUNNELMAN_INIT_GOLD;
    waterSquirts = TUNNELMAN_INIT_WATER;
}

TunnelMan::~TunnelMan()
{
}

int TunnelMan::getsonarCharge() {
    return sonarCharge;
}

int TunnelMan::getwaterSquirts() {
    return waterSquirts;
}

int TunnelMan::getgoldNuggets() {
    return goldNuggets;
}

int TunnelMan::gethitPoints() {
    return hitPoints;
}

bool TunnelMan::checkBounds(int col, int row)
{
    if (col >= 0 && col <= VIEW_HEIGHT - SPRITE_HEIGHT && row >= 0 and row <= VIEW_WIDTH - SPRITE_WIDTH)
        return true;
    else
        return false;
}
void TunnelMan::doSomething()
{
    int ch;
    if (getWorld()->getKey(ch) == true)
    {
        // user hit a key this tick!
        switch (ch)
        {
        case KEY_PRESS_LEFT:
            if (getDirection() == left && checkBounds(getX() - 1, getY())) {
                moveTo(getX() - 1, getY());
                removeEarthObjectsOverlap4x4();
                getWorld()->playSound(SOUND_DIG);
            }
            else
                setDirection(left);
            break;
        case KEY_PRESS_RIGHT:
            if (getDirection() == right && checkBounds(getX() + 1, getY())) {
                moveTo(getX() + 1, getY());
                removeEarthObjectsOverlap4x4();
                getWorld()->playSound(SOUND_DIG);
            }
            else
                setDirection(right);
            break;
        case KEY_PRESS_UP:
            if (getDirection() == up && checkBounds(getX(), getY() + 1)) {
                moveTo(getX(), getY() + 1);
                removeEarthObjectsOverlap4x4();
                getWorld()->playSound(SOUND_DIG);
            }
            else
                setDirection(up);

            break;
        case KEY_PRESS_DOWN:
            if (getDirection() == down && checkBounds(getX(), getY() - 1)) {
                moveTo(getX(), getY() - 1);
                removeEarthObjectsOverlap4x4();
                getWorld()->playSound(SOUND_DIG);
            }
            else
                setDirection(down);
            break;
        case KEY_PRESS_SPACE:
            ; break;

        }
    }
}

    void TunnelMan::removeEarthObjectsOverlap4x4()
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                getWorld()->removeEarthObjectIfExistsAt(getX() + i, getY() + j);
            }
        }
    }

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
