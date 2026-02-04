#pragma once

#include "../TileMap/TileMap.h"

class World
{
public:
	TileMap buildWorld();
private:
	std::vector<int> loadCSV(unsigned& outWidth, unsigned& outHeight);
private:
	sf::Texture m_tileset;
};

