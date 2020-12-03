#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h" 		// Includes Game.h which includes all SFML and C++ libraries needed to consturct this class

class Game;

class Player {
// Functions
public:	
	Player();
	virtual ~Player(); // dang im an idiot actually
	void update();
	void render(sf::RenderWindow* window);

// Variables
public:
	sf::Sprite* playerSprite;
	sf::Texture* playerTexture;
	// Public for now until we make  getters for them
private:
	

};
/// IT DOESNT EVEN HAVE 28 LINES WHAT
#endif
