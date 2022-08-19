#ifndef PACMAN_GAMEFORM_H
#define PACMAN_GAMEFORM_H

#include <algorithm>
#include <array>
#include <list>
#include "Wall.h"
#include "TextView.h"
#include "MainForm.h"
#include "Form.h"
#include "File.h"
#include "ButtonView.h"
#include "Fruit.h"

using namespace std;

class Pacman;

class Ghost;

class GameForm : public Form {
public:
    //initializes base class context property
    GameForm(Application &);

    ~GameForm();

    list<Snack *> &getSnacks();

    list<Ghost *> &getGhosts();

    //raising score if pacman eats fruits
    void raiseScore(int);

    void lose();

    unsigned getLevel() const;

private:

    void pollEvents(sf::Event &, sf::RenderWindow *) override;

    void update(sf::RenderWindow *, const sf::Time &) override;

    void render(sf::RenderWindow *) override;

    void initGame();

    void initSprites();

    //resetting when gameover/new level
    void resetBoard();


    //read/write record from txt file in assets
    void readRecord();

    void storeRecord();

    //handling fruit visiblity duration
    float fruitTimer = 0;
    bool isFruitVisible = false;
    unsigned level = 1;
    long int score = 0;
    //to know which time user eats all candies:)
    unsigned fruitsCount = 0;
    unsigned eatenSnacks = 0;
    unsigned snacksCount = 0;
    long int highScore = 0;
    sf::Vector2f pacmanPosition;

    //a list of ghosts and snacks
    list<Snack *> snacks;
    list<Ghost *> ghosts;
    vector<sf::Sprite> hearts;
    Pacman *pacman;
    TextView *txtScore;
    TextView *txtRecord;
    //back/pause to menu buttons
    TextView *txtLevel;
    sf::Sprite btnBackIc;
    sf::Texture *heartTexture;

    void updateFruits(const sf::Time &dt);
};

#endif //PACMAN_GAMEFORM_H
