#include "../inc/player.hpp"

void Player::move(DirEnum direction) {
    switch(direction) {
        case DirEnum::LEFT:
            shape_.setPosition(sf::Vector2f(shape_.getPosition().x - moveSpeed_, shape_.getPosition().y));
            break;
        case DirEnum::RIGHT:
            shape_.setPosition(sf::Vector2f(shape_.getPosition().x + moveSpeed_, shape_.getPosition().y));
            break;
        case DirEnum::UP:
            shape_.setPosition(sf::Vector2f(shape_.getPosition().x, shape_.getPosition().y - moveSpeed_));
            break;
        case DirEnum::DOWN:
            shape_.setPosition(sf::Vector2f(shape_.getPosition().x, shape_.getPosition().y + moveSpeed_));
            break;
    }
}