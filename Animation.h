#ifndef ANIMATION_H
#define ANIMATION_H

#include "Game.h"

class Animation {
// Functions:
public:
	Animation(sf::Texture* texture,sf::Vector2u imageCount,float switchTime);
	void update(int row,float deltaTime);


private:


// Variables:
public:
	
	sf::IntRect animRect; // Animation Integer rectangle 

private:
	sf::Vector2u imageCount; // total image {x,y}
	sf::Vector2u currentImage; // image we are currently on {known_x,y}


	float totalTime;  // period of time since last switch was applied.
	float switchTime; // period of time takes to switch to another buffer

};
#endif
