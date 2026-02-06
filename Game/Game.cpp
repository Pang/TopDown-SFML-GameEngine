#include "game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window, Player& player) : font("Assets/Fonts/pixantiqua.ttf"), overlayText(font), m_player(player)
{
	m_gameState = GS_Playing;
	m_gameLevel = GL_One;

	m_player.onExitReached.subscribe([this]() {
		std::cout << "Exit reached! Game over.\n";
		m_gameState = GS_LevelComplete;
	});

	overlay.setFillColor(sf::Color(0, 0, 0, 150));
	overlay.setSize(sf::Vector2f(window.getSize()));
}

void Game::setupLevel()
{
	m_npcs.clear();

	switch (m_gameLevel)
	{
		case GL_None:
			break;
		case GL_One:
			m_npcs.resize(3);
			m_npcs[0] = Npc(NpcType::Goblin, { 3, 3 }, { 7, 3 });
			m_npcs[1] = Npc(NpcType::Goblin, { 5, 4 }, { 5, 7 });
			m_npcs[2] = Npc(NpcType::Goblin, { 4, 7 }, { 4, 7 });
			m_npcs[2].faceDirection(LookLeft);

			for (Npc& npc : m_npcs) {
				npc.onPlayerFound.subscribe([this]() {
					std::cout << "Player found! Game over.\n";
					m_gameState = GS_GameOver;

					for (Npc& n : m_npcs)
						n.onPlayerFound.unsubscribeAll();
				});
			}
			break;
		case GL_Two:
			break;
		case GL_Three:
			break;
		case GL_Four:
			break;
		case GL_Five:
			break;
	}
}

void Game::runLevel(float dt, int frame, std::vector<WorldEntities>& worldEntities)
{
	switch (m_gameState)
	{
		case GS_MainMenu:
			break;
		case GS_Playing:
			m_player.update(dt, worldEntities);
			for (Npc& npc : m_npcs) {
				npc.update(dt, frame, worldEntities);
			}
			break;
		case GS_PauseMenu:
			break;
		case GS_GameOver:
			m_npcs.clear();
			break;
	}
}

void Game::render(sf::RenderWindow& window)
{
	switch (m_gameState)
	{
	case GS_MainMenu:
		break;
	case GS_Playing:
		for (Npc& npc : m_npcs) {
			npc.draw(window);
		}
		break;
	case GS_LevelComplete:
		window.setView(window.getDefaultView());
		setOverlayText("Level complete!");
		window.draw(overlay);
		window.draw(overlayText);
		break;
	case GS_GameOver:
		window.setView(window.getDefaultView());
		setOverlayText("Game over!");
		window.draw(overlay);
		window.draw(overlayText);
		break;
	}
}

void Game::setOverlayText(const std::string& text) {
	overlayText.setString(text);
	overlayText.setCharacterSize(32);
	overlayText.setFillColor(sf::Color::White);

	sf::FloatRect bounds = overlayText.getLocalBounds();
	overlayText.setOrigin({ bounds.position.x + bounds.size.x / 2.f, bounds.position.y + bounds.size.y / 2.f });
	overlayText.setPosition({ overlay.getSize().x / 2.f, overlay.getSize().y / 2.f });
}

