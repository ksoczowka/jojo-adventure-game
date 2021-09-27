#include "../inc/player.hpp"
#include "../inc/scene.hpp"
#include "../inc/properties.hpp"

#include <chrono>
#include <iostream>
#include <queue>

#define KEY(KEY_CODE) sfKb::isKeyPressed(KEY_CODE)
int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(prop::screenWidth, prop::screenHeight, 32),
                            "JOJO tututu tu tu tu", sf::Style::Fullscreen, settings);
    window.display();

    sfEv event;

    Player player;
    Map map("../level.txt");

    std::queue<DirEnum> movementQueue;
    bool pressed = false;
    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if(event.type = sfEv::Closed) {
                window.close();
            } else if(event.type = sfEv::KeyPressed) {
                if(KEY(sfKb::Escape)) {
                    window.close(); 
                }
                if(!pressed) {
                    if(KEY(sfKb::A)) {
                        movementQueue.push(DirEnum::LEFT);
                        pressed = true;
                    } else if(KEY(sfKb::D)) {
                        movementQueue.push(DirEnum::RIGHT);
                        pressed = true;
                    } else if(KEY(sfKb::W)) {
                        movementQueue.push(DirEnum::UP);
                        pressed = true;
                    } else if(KEY(sfKb::S)) {
                        movementQueue.push(DirEnum::DOWN);
                        pressed = true;
                    }
                }
            }
        }
        pressed = false;
        while(!movementQueue.empty()) {
            player.move(movementQueue.front());
            movementQueue.pop();
        }
        window.clear(sfCol::Black);
        map.drawMap(&window);
        window.draw(player.shape_);
        window.display();
    }
    return 0;
}
