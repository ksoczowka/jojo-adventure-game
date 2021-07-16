#pragma once

#include "properties.hpp"

#include <map>
#include <string>
#include <vector>

enum class TileEnum {
    GRASS,
    WALL
};

std::unordered_map<char, TileEnum> tilesCode = {{'+', TileEnum::GRASS},
                                                {'-', TileEnum::WALL}};

class Map {
public:
    Map(){}
    Map(std::string mapDir);

    void setMapDir(std::string mapDir) { mapDir_ = mapDir; }
    void drawMap(sf::RenderTarget target);
private:
    std::vector<std::vector<sf::RectangleShape>> map_;
    std::string mapDir_;
};