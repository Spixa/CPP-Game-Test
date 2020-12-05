#include "PlayerController.h"

void PlayerController::controlPlayer(sf::Sprite* p,float deltaTime,Animation* anim) {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ) { // Left
		p->move(-0.5f,0.0f);
		anim->update(2,deltaTime);
	}
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))&& (!sf::Keyboard::isKeyPressed(sf::Keyboard::S))) { // Right
		p->move(0.5f,0.0f);
		anim->update(3,deltaTime);
	
	}




	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))&& (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ) { // Up
		p->move(0.0f,-0.5f);
		anim->update(1,deltaTime);
        }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {  		// Diagonal: Up-Left
                 p->move(-0.5f,-0.5f);
                anim->update(2,deltaTime);

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::S))) { 		// Diagonal: Up-Right
                p->move(0.5f,-0.5f);
                anim->update(3,deltaTime);

        }






	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))&& (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))) { //Down
		p->move(0.0f,0.5f);
		anim->update(0,deltaTime);
        }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::W))) { 		// Diagonal: Down-Left
		 p->move(-0.5f,0.5f);
                anim->update(2,deltaTime);

	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::W))) { 		// Diagonal: Down-Right
		p->move(0.5f,0.5f);
                anim->update(3,deltaTime);

	}

	
	
	// Logic:
	// 	Left:	 -X 	Right:	 +X 
	// 	Up:	 -Y	Down:	 +Y



}
