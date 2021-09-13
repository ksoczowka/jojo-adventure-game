#pragma once

#include "properties.hpp"

enum class DirEnum {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Player {
public:
    Player() : moveSpeed_(prop::tileSize), HP_(100), attackPower_(10), boostPower_(2) {
        shape_.setSize(sf::Vector2f(prop::tileSize, prop::tileSize));
        shape_.setFillColor(sfCol::White);
        shape_.setPosition(sf::Vector2f(0, 0));
    }
    void move(DirEnum direction);
    sf::RectangleShape shape_;
private:
    unsigned short int moveSpeed_;
    unsigned short int HP_;
    unsigned int attackPower_;
    unsigned int boostPower_;
};
