#include "Button.h"

Button::Button(const sf::Vector2f& size, const std::string& label, const sf::Font& font, unsigned int characterSize, const sf::Color& fillColor, const sf::Color& textColor) {
    m_Button.setSize(size);
    m_Button.setFillColor(fillColor);

    m_ButtonText.setFont(font);
    m_ButtonText.setString(label);
    m_ButtonText.setCharacterSize(characterSize);
    m_ButtonText.setFillColor(textColor);

    //Center the text within the button
    sf::FloatRect textBounds = m_ButtonText.getLocalBounds();
    m_ButtonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    m_ButtonText.setPosition(m_Button.getPosition() + m_Button.getSize() / 2.0f);
}

void Button::setPosition(const sf::Vector2f& position) {
    m_Button.setPosition(position);
    m_ButtonText.setPosition(position + m_Button.getSize() / 2.0f);
}

bool Button::contains(const sf::Vector2f& point) const {
    return m_Button.getGlobalBounds().contains(point);
}


void Button::draw(RenderWindow& window){
    window.draw(m_Button);
    window.draw(m_ButtonText);
}