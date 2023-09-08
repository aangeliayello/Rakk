#include "Game.h"

void Game::initWindow()
{
    std::ifstream windowConfigFile("Config/window.ini", std::ifstream::binary);

    std::string screenTitle = "None";
    sf::VideoMode windowBounds(800, 600);
    unsigned frameRateLimit = 120;
    bool verticalSyncEnable = false;

    //if(windowConfigFile.is_open()){
    //    Json::Value windowConfig;
    //    windowConfigFile >> windowConfig;
    //    screenTitle = windowConfig["ScreenTitle"].asString();
    //    frameRateLimit = windowConfig["FrameRateLimit"].asInt();
    //    verticalSyncEnable = windowConfig["VerticalSyncEnable"].asBool();
    //    int screenSizeWidth = windowConfig["ScreenSizeWidth"].asInt();
    //    int screenSizeHeight = windowConfig["ScreenSizeHeight"].asInt();
    //    windowBounds = sf::VideoMode(screenSizeWidth, screenSizeHeight);
    //}

    // Creates a SFML window using options fro a window.ini file.
    this->window = new sf::RenderWindow(windowBounds, screenTitle);
    this->window->setFramerateLimit(frameRateLimit);
    this->window->setVerticalSyncEnabled(verticalSyncEnable);
}

void Game::initStates()
{
    this->states.push(new GameState(this->window));
}

Game::Game()
{
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    delete this->window;
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }

}

void Game::updateDt()
{   
    // Updates the 'dt' variable with the time it takes to render one frame.

    this->dt = this->dtClock.restart().asSeconds();
    system("cls");
    std::cout << this->dt << "\n";
}

void Game::updateSfmlEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSfmlEvents();

    if (!this->states.empty()) {
        this->states.top()->update(this->dt);
    }
}

void Game::render()
{
    this->window->clear();
    if (!this->states.empty()) {
        this->states.top()->render(this->window);
    }
    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
