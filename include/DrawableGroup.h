#ifndef DRAWABLE_GROUP_INCLUDED_HPP
#define DRAWABLE_GROUP_INCLUDED_HPP

#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class DrawableGroup {
public:
        DrawableGroup();
        ~DrawableGroup();

        std::vector<sf::Drawable*> drawables;

        void render(sf::RenderWindow* window) const;
};

#endif
