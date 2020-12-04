//
//  main.cpp
//  Tetris
//
//  Created by Robert Overs on 5/10/20.
//  Copyright © 2020 Robert Overs. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "tetris.hpp"
#include <iostream>


int main()
{
    Tetris t;

    sf::Clock cl;
    
    t.fillBoard();
    
    if (!t.font.loadFromFile("res/3270Medium.ttf"))
    {
        std::cout << "Font failed to load" << "\n";
    }
    
    bool play = false;
    
    while (t.window.isOpen()) {
        
        t.window.setFramerateLimit(100);
        
        float time = cl.getElapsedTime().asSeconds();
        
        cl.restart();
        
        t.timer += time;
        
        t.delay = 0.5;
        
        sf::Event event;
        
        while (t.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                t.window.close();
                    break;
            }
            if (event.type == sf::Event::KeyPressed) {
                
                if (event.key.code == sf::Keyboard::S) {
                    t.initPieces();
                    play = true;
                }
                else if (event.key.code == sf::Keyboard::Left) {
                    if (t.checkCollisionsXL())
                        t.dx = -1;
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    if (t.checkCollisionsXR())
                        t.dx = 1;
                }
                else if (event.key.code == sf::Keyboard::Up) {
                    if (t.n == 6)
                        break;
                    else if (t.n == 4 || t.n == 5)
                        t.r = (t.r + 1) % 2;
                    else
                        t.r = (t.r + 1) % 4;
                }
                else if (event.key.code == sf::Keyboard::Space && play) {
                    while (t.checkCollisionsY()) {
                        t.y++;
                    }
                    t.resetPiece();
                }
                else if (event.key.code == sf::Keyboard::C)
                {
                    swap(t.held, t.n);
                }
                else if (event.key.code == sf::Keyboard::Escape) {
                    t.fillBoard();
                    t.resetPiece();
                    t.linesCleared = 0;
                    t.score = 0;
                    play = false;
                }
            }
            if (event.key.code == sf::Keyboard::Down)
                t.delay = 0.03;
        }
        
        t.window.clear(sf::Color(59, 64, 75));
        
        if (play)
        {
            if (t.timer > t.delay) {
                
                if (not t.checkCollisionsY()) {
                    t.resetPiece();
                }
                
                t.y++;
                for (int i=0; i<4; i++) {
                    t.yPos = t.y+t.pieces[t.n][t.r][i][1];
                    t.tile.setPosition(t.x, t.yPos*t.tileWidth);
                }
                
                t.timer = 0;
            }
            
            t.x += t.dx;
            t.dx = 0;
            
            t.cleared = t.checkLines();
            if (t.cleared.size() > 0) {
                
                t.colourLines(t.cleared);
                t.drawBoard();
                t.drawText();
                t.drawHeldPiece(t.held);
                t.drawNextPieces();
                
                t.window.setFramerateLimit(5);
                t.window.display();
                t.window.setFramerateLimit(100);
                
                t.shiftLines(t.cleared);
                t.cleared.clear();
            }
        }
        
        if (play)
        {
            t.drawBoard();
            t.drawText();
            
            t.drawPiece(t.n);
            t.drawHeldPiece(t.held);
            t.drawNextPieces();
        }
        
        t.window.display();
        
    }
}


