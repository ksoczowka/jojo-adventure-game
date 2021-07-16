#pragma once

#include "properties.hpp"

#include <array>
#include <map>
#include <string>

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
    std::array<std::array<Tile, 20>, 20> level_;
    std::string mapDir_;
};
class Tile {
public:
    Tile(){}
    Tile(TileEnum code);
private:
    sf::RectangleShape shape_;
};
