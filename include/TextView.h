#ifndef PACMAN_TEXTVIEW_H
#define PACMAN_TEXTVIEW_H

#include "Application.h"

class TextView {
public:
    TextView(string, sf::Vector2f);

    ~TextView();

    void setFontSize(int);

    void setTextColor(const sf::Color &color);

    void update(sf::RenderTarget *);

    void render(sf::RenderTarget *);

    sf::Vector2f getPosition() const;

private:
    sf::Vector2f position;

    sf::Text *txtView;
    sf::Font font;
    sf::Color textColor = sf::Color::White;
};


#endif //PACMAN_TEXTVIEW_H
