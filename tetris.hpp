//
//  tetris.hpp
//  Tetris
//
//  Created by Robert Overs on 9/10/20.
//  Copyright © 2020 Robert Overs. All rights reserved.
//

#ifndef tetris_hpp
#define tetris_hpp

#include <stdio.h>
#include <string>
#include <SFML/Graphics.hpp>


using namespace std;

class Tetris
{
public:
    
    void drawBoard();
    
    void drawPiece(int n);
    
    void drawHeldPiece(int n);
    
    void drawNextPieces();
    
    vector<int> checkLines();
    
    vector<int> cleared;
    
    void shiftLines(vector<int> lines);
    
    void colourLines(vector<int> lines);
    
    void fillBoard();
    
    void resetPiece();
    
    void drawText();
    
    void initPieces();

    bool checkCollisionsY();

    bool checkCollisionsXL();

    bool checkCollisionsXR();
    
    float timer=0, delay=0.5;
    
    int x=3, y=0, dx=0;
    
    int xPos=0, yPos=0;
    
    int n=next[0], r=0, held=0;
    
    int linesCleared=0, score=0;
    
    int array[20][10];
    
    int next[4];
    
    const int width = 800;
    
    const int height = 800;
    
    const int gameWidth = (height / 2) * 0.9;
    
    const int gameHeight = (height) * 0.9;
    
    const int tileWidth = (gameHeight / 20);
    
    const int tileWidthS = (gameHeight / 20) * 0.9;
    
    const int offset = (11 * width) / 40;
    
    const int topOffset = 0.1 * gameWidth;
    
    int pieces[7][4][4][2] =
    {
        {
            {{0,2}, {1,2}, {2,2}, {3,2}}, // I
            {{2,0}, {2,1}, {2,2}, {2,3}},
            {{0,2}, {1,2}, {2,2}, {3,2}},
            {{1,0}, {1,1}, {1,2}, {1,3}}
        },
        {
            {{0,1}, {1,1}, {2,1}, {1,2}}, // T
            {{0,1}, {1,0}, {1,1}, {1,2}},
            {{0,1}, {1,1}, {2,1}, {1,0}},
            {{2,1}, {1,0}, {1,1}, {1,2}}
        },
        {
            {{0,1}, {1,1}, {2,1}, {0,2}}, // L
            {{0,0}, {1,0}, {1,1}, {1,2}},
            {{0,1}, {1,1}, {2,1}, {2,0}},
            {{1,0}, {1,1}, {1,2}, {2,2}}
        },
        {
            {{0,1}, {1,1}, {2,1}, {2,2}}, // J
            {{1,0}, {1,1}, {1,2}, {0,2}},
            {{0,0}, {0,1}, {1,1}, {2,1}},
            {{1,0}, {1,1}, {1,2}, {2,0}}
        },
        {
            {{1,0}, {2,0}, {0,1}, {1,1}}, // S
            {{0,0}, {0,1}, {1,1}, {1,2}},
            {{0,2}, {1,2}, {1,1}, {2,1}},
            {{1,0}, {2,0}, {0,1}, {1,1}}
        },
        {
            {{0,0}, {1,0}, {1,1}, {2,1}}, // Z
            {{2,0}, {1,1}, {2,1}, {1,2}},
            {{0,1}, {1,1}, {1,2}, {2,2}},
            {{0,0}, {1,0}, {1,1}, {2,1}}
        },
        {
            {{1,0}, {2,0}, {1,1}, {2,1}}, // O
            {{1,0}, {2,0}, {1,1}, {2,1}},
            {{1,0}, {2,0}, {1,1}, {2,1}},
            {{1,0}, {2,0}, {1,1}, {2,1}}
        }
    };
    
    sf::Color colors[8] = {
        sf::Color(255, 131, 96), // I
        sf::Color(232, 226, 136), // T
        sf::Color(125, 206, 130), // L
        sf::Color(60, 219, 211), // J
        sf::Color(0, 161, 228), // S
        sf::Color(221, 61, 112), // T
        sf::Color(90, 40, 95), // O
        sf::Color(250, 250, 250) // Cleared
    };
    
    sf::RectangleShape tile{sf::Vector2f(tileWidth, tileWidth)};
    
    sf::RectangleShape tileS{sf::Vector2f(tileWidthS, tileWidthS)};
    
    sf::RectangleShape tileN{sf::Vector2f(tileWidthS, tileWidthS)};
    
    sf::RectangleShape backdrop{sf::Vector2f(gameWidth, gameHeight)};
    
    sf::RectangleShape holdWindow{sf::Vector2f(4*tileWidth, 4*tileWidth)};
    
    sf::RectangleShape nextWindow{sf::Vector2f(4*tileWidth, 16*tileWidth)};
    
    sf::RenderWindow window{sf::VideoMode(width, height), "Tetris"};
    
    sf::Font font;
    
    sf::Text linesText;
    
    string linesTextString;
    
    sf::Text scoreText;
    
    string scoreTextString;

};

#endif /* tetris_hpp */
