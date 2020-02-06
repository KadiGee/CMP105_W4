#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");
	etexture.loadFromFile("gfx/goomba.png");
	e2texture.loadFromFile("gfx/sonic.png");

	//testSprite.setTexture(&texture);
	//testSprite.setSize(sf::Vector2f(100, 100));
	//testSprite.setPosition(100, 100);

	mushroom.setTexture(&texture);
	mushroom.setSize(sf::Vector2f(100, 100));
	mushroom.setPosition(500, 500);
	mushroom.setInput(input);

	goomba.setTexture(&etexture);
	goomba.setSize(sf::Vector2f(100, 100));
	goomba.setPosition(100, 100);
	goomba.setInput(input);

	sonic.setTexture(&e2texture);
	sonic.setSize(sf::Vector2f(100, 100));
	sonic.setPosition(800, 0);
	sonic.setInput(input);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	mushroom.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2f pos = goomba.getPosition();
	sf::Vector2f spos = sonic.getPosition();

	sf::Vector2u winsize = window->getSize();
	goomba.update(dt, pos, winsize);
	sonic.update(dt, spos, winsize);
}

// Render level
void Level::render()
{
	beginDraw();

	//window->draw(testSprite);
	window->draw(mushroom);
	window->draw(goomba);
	window->draw(sonic);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}