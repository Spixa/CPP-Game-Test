#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Game.h"
#include "Animation.h"

class Animation;

class PlayerController { 
public: 
	void controlPlayer(sf::Sprite* p,float deltaTime,Animation* anim);
};

#endif // PLAYERCONTROLLER_H
