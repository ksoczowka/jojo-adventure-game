#pragma once

#include <SFML/Graphics.hpp>

using sfEv = sf::Event; 
using sfKb = sf::Keyboard;
using sfCol = sf::Color;

namespace prop {
    auto screenWidth = sf::VideoMode::getDesktopMode().width;    
    auto screenHeight = sf::VideoMode::getDesktopMode().height;  
}
