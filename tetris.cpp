//
//  tetris.cpp
//  Tetris
//
//  Created by Robert Overs on 9/10/20.
//  Copyright © 2020 Robert Overs. All rights reserved.
//

#include "tetris.hpp"


void Tetris::initPieces()
{
    for (int i=0; i<4; i++) {
        next[i] = rand() % 7;
    }
}

void Tetris::resetPiece()
{
    n = next[0];
    
    for (int i=0; i<3; i++) {
        next[i] = next[i+1];
    }
    next[3] = rand() % 7;
    
    y = 0;
    x = 3;
    dx = 0;
    r = 0;
}

void Tetris::fillBoard()
{
    for (int i=0; i<20; i++) {
        for (int j=0; j<10; j++) {
            array[i][j] = -1;
        }
    }
}

void Tetris::drawPiece(int n)
{
    for (int i=0; i<4; i++) {
        tile.setFillColor(colors[n]);
        tile.setOutlineThickness(-0.1*tileWidth);
        tile.setOutlineColor(sf::Color(250, 250, 250));
        
        xPos = x+pieces[n][r][i][0];
        yPos = y+pieces[n][r][i][1];
        
        tile.setPosition((xPos*tileWidth)+offset, (yPos*tileWidth)+topOffset);
        window.draw(tile);
    }
}

void Tetris::drawNextPieces()
{
    int nextP;
    
    for (int n=0; n<4; n++) {
        
        nextP = next[n];
        
        for (int i=0; i<4; i++) {
            tileN.setFillColor(colors[nextP]);
            tileN.setOutlineThickness(-0.1*tileWidthS);
            tileN.setOutlineColor(sf::Color(250, 250, 250));
            
            xPos = pieces[nextP][0][i][0];
            yPos = pieces[nextP][0][i][1]+4*n;
            
            switch (nextP) {
                case 0:
                    tileN.setPosition((width-topOffset-4*tileWidth+0.2*tileWidth+xPos*tileWidthS),
                                      (topOffset+yPos*tileWidthS+0.25*tileWidth));
                    break;
                
                case 1:
                    tileN.setPosition((width-4*tileWidth-0.3*tileWidth+xPos*tileWidthS),
                                      (topOffset+yPos*tileWidthS+0.25*tileWidth));
                    break;
                
                case 2:
                    tileN.setPosition((width-4*tileWidth-0.3*tileWidth+xPos*tileWidthS),
                                      (0.65*tileWidth+topOffset+yPos*tileWidthS+0.25*tileWidth));
                    break;
                
                case 3:
                    tileN.setPosition((width-4*tileWidth-0.3*tileWidth+xPos*tileWidthS),
                                      (0.65*tileWidth+topOffset+yPos*tileWidthS+0.25*tileWidth));
                    break;
                
                case 4:
                    tileN.setPosition((width-4*tileWidth-0.3*tileWidth+xPos*tileWidthS),
                                      (1.1*tileWidth+topOffset+yPos*tileWidthS+0.25*tileWidth));
                    break;
                
                case 5:
                    tileN.setPosition((width-4*tileWidth-0.3*tileWidth+xPos*tileWidthS),
                                      (1.1*tileWidth+topOffset+yPos*tileWidthS+0.25*tileWidth));
                    break;
                
                case 6:
                    tileN.setPosition((width-topOffset-4*tileWidth+0.25*tileWidth+xPos*tileWidthS),
                                      (1.1*tileWidth+topOffset+yPos*tileWidthS+0.25*tileWidth));
                    break;
                    
                default:
                    break;
            }
            
            window.draw(tileN);
        }
    }
}

void Tetris::drawHeldPiece(int n)
{
    for (int i=0; i<4; i++) {
        tileS.setFillColor(colors[held]);
        tileS.setOutlineThickness(-0.1*tileWidthS);
        tileS.setOutlineColor(sf::Color(250, 250, 250));
        
        xPos = pieces[held][0][i][0];
        yPos = pieces[held][0][i][1];
        
        switch (held) {
            case 0:
                tileS.setPosition((0.2*tileWidth+topOffset+xPos*tileWidthS),
                                  (topOffset+yPos*tileWidthS));
                break;
            
            case 1:
                tileS.setPosition((0.65*tileWidth+topOffset+xPos*tileWidthS),
                                  (topOffset+yPos*tileWidthS));
                break;
            
            case 2:
                tileS.setPosition((0.65*tileWidth+topOffset+xPos*tileWidthS),
                                  (0.65*tileWidth+topOffset+yPos*tileWidthS));
                break;
            
            case 3:
                tileS.setPosition((0.65*tileWidth+topOffset+xPos*tileWidthS),
                                  (0.65*tileWidth+topOffset+yPos*tileWidthS));
                break;
            
            case 4:
                tileS.setPosition((0.65*tileWidth+topOffset+xPos*tileWidthS),
                                  (1.1*tileWidth+topOffset+yPos*tileWidthS));
                break;
            
            case 5:
                tileS.setPosition((0.65*tileWidth+topOffset+xPos*tileWidthS),
                                  (1.1*tileWidth+topOffset+yPos*tileWidthS));
                break;
            
            case 6:
                tileS.setPosition((0.25*tileWidth+topOffset+xPos*tileWidthS),
                                  (1.1*tileWidth+topOffset+yPos*tileWidthS));
                break;
            
            default:
                break;
        }
        
        window.draw(tileS);
    }
}

void Tetris::drawBoard()
{
    backdrop.setFillColor(sf::Color(39, 44, 55));
    backdrop.setPosition(offset, topOffset);
    backdrop.setOutlineColor(sf::Color(250, 250, 250));
    backdrop.setOutlineThickness(0.1*tileWidth);
    window.draw(backdrop);
    
    holdWindow.setFillColor(sf::Color(39, 44, 55));
    holdWindow.setPosition(topOffset, topOffset);
    holdWindow.setOutlineColor(sf::Color(250, 250, 250));
    holdWindow.setOutlineThickness(0.1*tileWidth);
    window.draw(holdWindow);
    
    nextWindow.setFillColor(sf::Color(39, 44, 55));
    nextWindow.setPosition(width-topOffset-4*tileWidth, topOffset);
    nextWindow.setOutlineColor(sf::Color(250, 250, 250));
    nextWindow.setOutlineThickness(0.1*tileWidth);
    window.draw(nextWindow);
    
    for (int i=0; i<20; i++) {
        for (int j=0; j<10; j++) {
            int n = array[i][j];
            if (n >= 0) {
                tile.setFillColor(colors[n]);
                tile.setOutlineThickness(-0.1*tileWidth);
                tile.setOutlineColor(sf::Color(250, 250, 250));
                
                tile.setPosition((j*tileWidth)+offset, (i*tileWidth)+topOffset);
                window.draw(tile);
            }
        }
    }
}

bool Tetris::checkCollisionsY()
{
    for (int i=0; i<4; i++) {
        xPos = x+pieces[n][r][i][0];
        yPos = y+pieces[n][r][i][1];
        
        if (yPos == 19 || array[yPos+1][xPos] >= 0) {
            for (int i=0; i<4; i++) {
                xPos = x+pieces[n][r][i][0];
                yPos = y+pieces[n][r][i][1];
                array[yPos][xPos] = n;
            }
            y = 0;
            x = 3;
            dx = 0;
            r = 0;
            return false;
        }
    }
    return true;
}

bool Tetris::checkCollisionsXL()
{
    for (int i=0; i<4; i++) {
        xPos = x+pieces[n][r][i][0];
        yPos = y+pieces[n][r][i][1];
        
        if (array[yPos][xPos-1] >= 0 || xPos-1 < 0)
                return false;
    }
    return true;
}

bool Tetris::checkCollisionsXR()
{
    for (int i=0; i<4; i++) {
        xPos = x+pieces[n][r][i][0];
        yPos = y+pieces[n][r][i][1];
        
        if (array[yPos][xPos+1] >= 0 || xPos+1 > 9)
                return false;
    }
    return true;
}

vector<int> Tetris::checkLines()
{
    bool full;
    vector<int> lines;
    for (int i=0; i<20; i++) {
        full = true;
        for (int j=0; j<10; j++) {
            if (array[i][j] == -1) {
                full = false;
                break;
            }
        }
        if (full) {
            lines.push_back(i);
        }
    }
    return lines;
}

void Tetris::shiftLines(vector<int> lines)
{
    int next, row;
    int n = lines.size();
    
    linesCleared += n;
    
    switch (n) {
        case 1:
            score += 100;
            break;
        
        case 2:
            score += 300;
            break;
        
        case 3:
            score += 500;
            break;
        
        case 4:
            score += 800;
            break;
            
        default:
            break;
    }
    
    for (int i=0; i<n; i++) {
        row = lines[i];
        for (int j=row; j>0; j--) {
            for (int v=0; v<10; v++) {
                next = array[j-1][v];
                array[j][v] = next;
            }
        }
    }
}

void Tetris::colourLines(vector<int> lines)
{
    int row;
    int n = lines.size();
    
    for (int i=0; i<n; i++) {
        row = lines[i];
        for (int v=0; v<10; v++) {
            array[row][v] = 7;
        }
    }
}

void Tetris::drawText()
{
    // lines
    linesText.setFont(font);
    linesText.setPosition(gameWidth+offset+tileWidth, gameHeight-84);
    linesText.setCharacterSize(26);
    linesText.setFillColor(sf::Color(250, 250, 250));
    
    linesTextString = string("Lines: \n") + to_string(linesCleared);
    linesText.setString(linesTextString);
    
    // score
    scoreText.setFont(font);
    scoreText.setPosition(gameWidth+offset+tileWidth, gameHeight-20);
    scoreText.setCharacterSize(26);
    scoreText.setFillColor(sf::Color(250, 250, 250));
    
    scoreTextString = string("Score: \n") + to_string(score);
    scoreText.setString(scoreTextString);
    
    window.draw(linesText);
    window.draw(scoreText);
}
