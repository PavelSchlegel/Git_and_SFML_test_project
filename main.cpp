#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
// #include "sources/heros/zombi.hpp"

namespace heros {

    class Zombi {
        private:
            sf::Texture _texture;
        public:
            sf::Sprite _zombi_sprite;
            Zombi(const std::string& image)
            {
                if ( _texture.loadFromFile(image) ) {
                    _zombi_sprite.setTexture(_texture);
                    _zombi_sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
                    _zombi_sprite.setPosition(50, 25);
                    return;
                }
                std::cout << "Some error whit image.png" << std::endl;
            }

            sf::Sprite move_left(float time)
            {
                _zombi_sprite.move(-0.01 * time, 0);
                _zombi_sprite.setTextureRect(sf::IntRect(0, 40, 40, 40));
                return _zombi_sprite;
            }

            sf::Sprite move_right(float time)
            {
                _zombi_sprite.move(0.01 * time, 0);
                _zombi_sprite.setTextureRect(sf::IntRect(0, 83, 40, 40));
                return _zombi_sprite;
            }

            sf::Sprite move_down(float time)
            {
                _zombi_sprite.move(0 , +0.01 * time);
                _zombi_sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
                return _zombi_sprite;
            }

            sf::Sprite move_up(float time)
            {
                _zombi_sprite.move(0, -0.01 * time);
                _zombi_sprite.setTextureRect(sf::IntRect(0, 125, 40, 40));
                return _zombi_sprite;
            }
    };
} // namespace heros

int main()
{
    sf::RenderWindow window(sf::VideoMode(880, 640), "My window");
    heros::Zombi zombi("../../images/zombi_light_position.png");
    sf::Clock clock;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;

        sf::Event event;
        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
            window.draw(zombi.move_left(time));
        }
 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
            window.draw(zombi.move_right(time));
        }
			
			
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) {
            window.draw(zombi.move_up(time));
        }
		
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) {
            window.draw(zombi.move_down(time));
		}

        window.clear(sf::Color::White);
        window.draw(zombi._zombi_sprite);

        // end the current frame
        window.display();
    }
    return 0;
}