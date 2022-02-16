#ifndef GAME_H_
#define GAME_H_

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

void iniGame(sf::RenderWindow* window);
void generateTetromino(void);
void processKey(sf::Keyboard::Key keyCode);
void checkTetrominoDrop(void);
void drawGameState(void);

#endif