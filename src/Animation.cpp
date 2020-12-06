#include "Animation.h"


Animation::Animation(sf::Texture* texture,sf::Vector2u imageCount,float switchTime) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	
	animRect.width = texture->getSize().x / float(imageCount.x);
	animRect.height = texture->getSize().y / float(imageCount.y);
	
	
	
	
}
void Animation::update(int row,float deltaTime) {

	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
		
		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;

		}
	}

	animRect.left = currentImage.x * animRect.width;
	animRect.top = currentImage.y * animRect.height;
	
}
