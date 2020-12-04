#ifndef GAME_H
#define GAME_H
/*
 *	Game.h 			-- 	Game Engine File
 *	
 *
 *	Licensed under {license_name}				-
 *	Do not distribute!					-
 *
 *
 * */

// SFML liraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
// C++ official libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
// C official libraries
#include <stdio.h>

/*
 *	Dungeons And Dragons classes 
 *	#include "eg.class"
 */

#include "Player.h"
#include "PlayerController.h"
#include "Animation.h"

/*	 Class re-defeition to prevent circular class collision
 * C++ classes if are included circularly will be defined ambigiuously and are inacccessible
 *
 */
class Player;
class PlayerController;
class Animation;

class Game {
// Functions:
public:
	void run();


	float getDeltaTime(); 			// Returns Game.deltaTime
	int exitLog = 0;
private: 		// Intializers
	void initWindow();


	// void initExampleObject ..

protected:
	void construct();			// Constructs game window, characters, master font and more when Game.begin
	void loop();				// Game Loop 		- Calculates, renders, initializes and updates per frame
	void update();				// Updates after 1 frame
	void render();				// Renders (RenderWindow.draw , Object.Render, Drawable.Render, RenderWindow< clear buffer, display> )
	void updateEvent();
	void findDeltaTime(); 			// Finds Delta Time

// Variables:

public:


private:
	sf::Clock deltaTimeClock;
	float deltaTime;

	/*
	 * Self-made classes
	 */
	// Cozy place for classes:
	Player* pl;   				//Renderable:    Player
	PlayerController* pl_c;			//Updatable: 	 PlayerController
	Animation* p_a;				//Bifunctional:  Animation
protected:					
	/*
	 *	SFML classes 
	 */
	sf::RenderWindow* rw;			// Renderwindow
	sf::View* view;				// View
	sf::Sprite* bg;				// Background sprite
	sf::Texture* bgT;			// Background texture

};


#endif
