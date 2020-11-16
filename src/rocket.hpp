#ifndef ROCKET_HPP
#define ROCKET_HPP
#include <SFML/Graphics.hpp>
#include <cmath>

#define SHIP_HEIGHT 100
#define SHIP_WIDTH 40

static const sf::Color SPACE_ORANGE(sf::Color(250, 145, 5));

class Rocket : public sf::Drawable, public sf::Transformable {
private:
    sf::ConvexShape nose;
    sf::RectangleShape fuselage;
    sf::ConvexShape eTop;
    sf::ConvexShape eBottom;

public:
    Rocket() :
    nose(sf::ConvexShape(3)),
    fuselage(sf::RectangleShape(sf::Vector2f(SHIP_WIDTH, SHIP_HEIGHT))),
    eTop(sf::ConvexShape(3)),
    eBottom(sf::ConvexShape(3)) {
        // nose
        nose.setPoint(0, sf::Vector2f(SHIP_WIDTH/2.0, 0));
        nose.setPoint(1, sf::Vector2f(0.0, SHIP_WIDTH));
        nose.setPoint(2, sf::Vector2f(SHIP_WIDTH, SHIP_WIDTH));
        nose.setFillColor(SPACE_ORANGE);
        // fuselage
        fuselage.move(sf::Vector2f(0, SHIP_WIDTH));
        fuselage.setFillColor(sf::Color(20, 20, 20));
        // engine top
        eTop.setPoint(0, sf::Vector2f(0.0, 0.0));
        eTop.setPoint(1, sf::Vector2f(SHIP_WIDTH, 0.0));
        eTop.setPoint(2, sf::Vector2f(SHIP_WIDTH/2.0, SHIP_WIDTH));
        eTop.move(sf::Vector2f(0, SHIP_WIDTH+SHIP_HEIGHT));
        eTop.setFillColor(sf::Color(0, 0, 0));
        // engine bottom
        eBottom.move(sf::Vector2f(0, SHIP_WIDTH+SHIP_HEIGHT+SHIP_WIDTH-1));
        eBottom.setFillColor(sf::Color(0, 0, 0));
    }
    ~Rocket() {}
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(nose);
        target.draw(fuselage);
        target.draw(eTop);
    }

};
#endif
