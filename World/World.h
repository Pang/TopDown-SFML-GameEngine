#pragma once

#include "../TileMap/TileMap.h"

class World
{
public:
	void loadTileMaps();
	void renderTileMaps(sf::RenderWindow& window);
private:
	std::vector<int> loadCSV(unsigned& outWidth, unsigned& outHeight, const std::string& fileName);
	void loadSpecificMap(TileMap& tileMap, sf::Texture& texture, const std::string& textureFile, const std::string& csvFile);
private:
	sf::Texture m_floorTileset;
	sf::Texture m_dungeonTileset;
	TileMap m_floorsTileMap;
	TileMap m_dungeonTileMap;
};

