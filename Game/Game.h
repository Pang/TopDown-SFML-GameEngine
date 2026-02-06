#pragma once
#include "../Enums/GameState.h"
#include "../Enums/GameLevel.h"
#include "../Enums/NpcType.h"
#include "../Player/Player.h"
#include "../Npc/Npc.h"
#include <vector>

class Game {
public:
	Game(Player& player);
	void setupLevel();
	void runLevel(float dt, int frame, std::vector<WorldEntities>& worldEntities);
	void render(sf::RenderWindow& window);

private:
	GameState m_gameState;
	GameLevel m_gameLevel;

	std::vector<Npc> m_npcs;
};