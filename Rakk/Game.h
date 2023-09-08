#pragma once

#include "States/GameState.h"
#include "json/value.h"

class Game
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	// Initialization
	void initWindow();
	void initStates();

public:

	// Constructurs/Destructors
	Game();
	virtual ~Game();

	// Functions
	void updateDt();

	void updateSfmlEvents();

	void update();

	void render();

	void run();
};