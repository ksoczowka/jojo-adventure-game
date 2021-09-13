#include "../inc/scene.hpp"
#include <iostream>

Map::Map(std::string mapDir) {
    mapDir_ = mapDir;

    std::ifstream mapFileReader;
    mapFileReader.open(mapDir_);
    std::vector<std::string> currMap = readMap(mapFileReader);
    for(int i = 0; i < 20; i++) {
        level_.push_back(std::vector<Tile>(20));
    }
    for(int lineNum = 0; lineNum < 20; lineNum++) {
        for (int tileNum = 0; tileNum < 20; tileNum++) {
            level_.at(lineNum).at(tileNum) = Tile(findCode(currMap.at(lineNum).at(tileNum)));
            level_.at(lineNum).at(tileNum).getShape().setPosition(sf::Vector2f((tileNum * prop::tileSize), (lineNum * prop::tileSize)));
        }
    }
}
void Map::drawMap(sf::RenderTarget* target) {
    for(auto& row : level_) {
        for(auto& tile : row) {
            target->draw(tile.getShape());
        }
    }
}
Tile::Tile(TileEnum code) {
    shape_.setSize(sf::Vector2f(prop::screenHeight / 20, prop::screenHeight / 20));
    switch(code) {
        case TileEnum::ERROR:
            shape_.setFillColor(sfCol(20, 0, 0));
            break;
        case TileEnum::GRASS:
            shape_.setFillColor(sfCol::Green);
            break;
        case TileEnum::WALL:
            shape_.setFillColor(sfCol(100, 100, 100));
    }
}
TileEnum findCode(char tile) {
    for(const auto& [key, value] : tilesCode) {
        if(key == tile)
            return value;
    }
    return TileEnum::ERROR;
}
std::vector<std::string> readMap(std::ifstream& is) {
    std::string buff;
    std::vector<std::string> ret;
    for(int i = 0; i < 20; i++) {
        std::getline(is, buff);
        ret.push_back(buff);
    }
    return ret;
}
