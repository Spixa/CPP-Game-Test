
#include "Player.h"

Player::Player() {
	playerSprite = new sf::Sprite();
	playerTexture = new sf::Texture();
	playerTexture->loadFromFile("pic.png");
	playerSprite->setScale({1.5,1.5});
	playerSprite->setTexture(*playerTexture);
	sf::Vector2f spriteSize(playerSprite->getTexture()->getSize().x * playerSprite->getScale().x, playerSprite->getTexture()->getSize().y * playerSprite->getScale().y);
	
}

Player::~Player() {
	delete playerSprite;
	delete playerTexture;


}

void Player::update() {
	// Player update function 


}

void Player::render(sf::RenderWindow* window) {

	window->draw(*playerSprite);
}
