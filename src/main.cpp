#include "../inc/player.hpp"
#include "../inc/properties.hpp"

#include <iostream>

#define KEY(KEY_CODE) sfKb::isKeyPressed(KEY_CODE)

int main() {  
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(prop::screenWidth, prop::screenHeight, 32),
                            "JOJO tututu tu tu tu", sf::Style::Fullscreen, settings);
    window.display();

    sfEv event;

    Player player;

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if(event.type = sfEv::Closed)
                window.close();
            if(event.type = sfEv::KeyPressed) {
                if(KEY(sfKb::Escape)) {
                    window.close();
                } else if (KEY(sfKb::A)) {
                    player.move(DirEnum::LEFT);
                } else if (KEY(sfKb::D)) {
                    player.move(DirEnum::RIGHT);
                } else if (KEY(sfKb::W)) {
                    player.move(DirEnum::UP);
                } else if (KEY(sfKb::S)) {
                    player.move(DirEnum::DOWN);
                }
            } 
        }
        window.clear(sfCol::Black);
        window.draw(player.shape_);
        window.display();
    }

    return 0;
}