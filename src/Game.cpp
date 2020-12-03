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
	this->rw = new sf::RenderWindow(sf::VideoMode(928,480),"Window",sf::Style::Close | sf::Style::Resize);

	bg = new sf::Sprite();
	bgT = new sf::Texture();
	bgT->loadFromFile("bg.png");
	bg->setTexture(*bgT);
	bg->setScale({4,4});
}


// Consturctor
void Game::construct() {
	initWindow();
	view = new sf::View(sf::Vector2f(0,0),sf::Vector2f(927,480));
	pl = new ::Player();
 	pl_c = new ::PlayerController();	
	p_a = new ::Animation(pl->playerTexture,sf::Vector2u(4,4),0.1);
}
// Game loop
void Game::loop() {
	while (this->rw->isOpen()) {
		render();
		update();
		findDeltaTime();


	}

}
// Render and updates functions
void Game::update() {
	
	pl_c->controlPlayer(pl->playerSprite,deltaTime,p_a);
	view->setCenter(pl->playerSprite->getPosition());
	updateEvent();

}
void Game::updateEvent() {
	sf::Event evnt;
	while (rw->pollEvent(evnt)) {
		if (evnt.type == evnt.Closed) {
			rw->close();
			
		}
	}

}
void Game::render() {
	rw->clear();
	// Background layer stuff:
	rw->draw(*bg); // Background picture


	pl->render(rw);
	pl->playerSprite->setTextureRect(p_a->animRect);

	rw->setView(*view);
	rw->display();

}
void Game::findDeltaTime() {
	deltaTime = deltaTimeClock.restart().asSeconds();


}


