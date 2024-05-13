#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Button {
private:
    RectangleShape m_Button;
    Text m_ButtonText;
    //Font m_Font;
public:
    //std::string m_Text;
   // FloatRect m_Collider;
    //Button(Vector2f position,
     //   float width, float height,
      //  int red, int green, int blue,
       // std::string text);
    //void draw(RenderWindow& window);

    Button(const sf::Vector2f& size, const std::string& label, const sf::Font& font, unsigned int characterSize, const sf::Color& fillColor, const sf::Color& textColor);
    void setPosition(const sf::Vector2f& position);
    bool contains(const sf::Vector2f& point) const;
    void draw(RenderWindow& window);
};
