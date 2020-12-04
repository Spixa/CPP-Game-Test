#include "Game.h"


void Game::run() {
	construct();
	loop();

}
float Game::getDeltaTime() {

	return deltaTime;
}


// Initializers
void Game::initWindow() {
	this->rw = new sf::RenderWindow(sf::VideoMode(928,480),"Window",sf::Style::Close | sf::Style::Resize); // Initalize window

	bg = new sf::Sprite(); // Background sprite
	bgT = new sf::Texture(); // Background texture
	bgT->loadFromFile("bg.png"); // Loading background texture
	bg->setTexture(*bgT); // Setting background texture
	bg->setScale({4,4}); // Scaling the picture 4 times bigger (Prototype)
}


// Consturctor
void Game::construct() {
	initWindow();
	view = new sf::View(sf::Vector2f(0,0),sf::Vector2f(927,480)); // View is a camera that follows its center around, it is also bound to a renderable window and can make game run on any screen resolution
	pl = new ::Player(); // Main player
 	pl_c = new ::PlayerController(); // Player controller	
	p_a = new ::Animation(pl->playerTexture,sf::Vector2u(4,4),0.1); // Player Animation		ARG1: Texture	ARG2: Amount of pictures x: column, y:row	ARG3: Update time

	pl->playerSprite->setPosition(rw->getSize().x / 0.5,rw->getSize().y / 0.5); //  Sets the position of player sprite to the middle of screen
}
// Game loop
void Game::loop() {
	while (this->rw->isOpen()) {
		render();		// Render:  	Drawables
		update();		// Update:  	PlayerController, Viewport
		findDeltaTime();	// Delta Time:	Gets delta time after updating and rendering a frame


	}

}
// Render and updates functions
void Game::update() {
	
	pl_c->controlPlayer(pl->playerSprite,deltaTime,p_a);    // Tells playercontroller to update which ::Player and gets the delta time and player animation to synchronize the speed in every computer
	view->setSize(sf::Vector2f(rw->getSize()));	       // Sets the view size to the screen resolution, this makes the game look the same in every resolution
	view->setCenter(pl->playerSprite->getPosition());     // Sets the center of the view to the player so the camera follows the player
	updateEvent(); // updates sf::Event

}
void Game::updateEvent() {
	sf::Event evnt;
	while (rw->pollEvent(evnt)) {
		if (evnt.type == evnt.Closed) { // OnClose function
			rw->close();
			
		}
	}

}
void Game::render() {
	rw->clear(); // clears previous shown buffer

	// Background layer:
	rw->draw(*bg); // Background picture

	// Player layer:
	pl->render(rw); // render player
	pl->playerSprite->setTextureRect(p_a->animRect); // set the image that animation class crops to the playersprite's texture rectangle (type: sf::IntRect, uvRect)

	rw->setView(*view);   // binds the view to this screen
	rw->display();	// displays this image buffer

}
void Game::findDeltaTime() {
	deltaTime = deltaTimeClock.restart().asSeconds(); // restarts the clock that began when update and rendering started and finished when they were over


}


