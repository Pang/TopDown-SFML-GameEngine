#pragma once
#include "../Enums/GameState.h"
#include "../Enums/GameLevel.h"
#include "../Enums/NpcType.h"
#include "../Player/Player.h"
#include "../Npc/Npc.h"
#include <vector>

class Game {
public:
	Game(sf::RenderWindow& window, Player& player);
	void setupLevel();
	void runLevel(float dt, int frame, std::vector<WorldEntities>& worldEntities);
	void render(sf::RenderWindow& window);

private:
	void setOverlayText(const std::string& text);

private:
	sf::RectangleShape overlay;
	sf::Font font;
	sf::Text overlayText;

	GameState m_gameState;
	GameLevel m_gameLevel;

	Player& m_player;
	std::vector<Npc> m_npcs;
};