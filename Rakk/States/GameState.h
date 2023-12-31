#pragma once
#include "State.h"

class GameState :
    public State
{
public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    // Functions
    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* targert = nullptr);
};

