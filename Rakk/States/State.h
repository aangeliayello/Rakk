#pragma once

#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void endState() = 0;

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* targert = nullptr) = 0;
};

