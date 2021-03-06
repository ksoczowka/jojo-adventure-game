#pragma once

#include "properties.hpp"

#include <fstream>
#include <map>
#include <string>
#include <vector>

enum class TileEnum {
    ERROR,
    GRASS,
    WALL
};

const std::unordered_map<char, TileEnum> tilesCode = {{'+', TileEnum::GRASS},
                                                      {'-', TileEnum::WALL}};
std::vector<std::string> readMap(std::ifstream& is);
TileEnum findCode(char tile);

class Tile {
public:
    Tile(){}
    Tile(TileEnum code);

    sf::RectangleShape& getShape() { return shape_; }
    std::string getPath() { return txtPath_; }
private:
    sf::RectangleShape shape_;
    std::string txtPath_;
};
class Map {
public:
    Map(){}
    Map(std::string mapDir);

    void drawMap(sf::RenderTarget* target);
private:
    std::vector<std::vector<Tile>> level_;
    std::vector<std::vector<sf::Texture>> tileTextures_;
    std::string mapDir_;
};
