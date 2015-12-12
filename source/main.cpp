#include <iostream>

#include "SFML/Window.hpp"

#include "vendor/easylogging++.h"
#include "AssetManager.h"
#include "SceneDirector.h"
#include "SceneFactory.h"
#include "Scene.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char* args[])
{
        /* Logger configuration */
        el::Configurations conf("./config/logger.conf");
        el::Loggers::reconfigureAllLoggers(conf);
        LOG(INFO) << "Starting application.";

        sf::RenderWindow window(sf::VideoMode(800, 600), "Hiillos - development");

        SceneFactory::Get()->Register("GameScene", &GameScene::Create);
        SceneDirector director(&window);
        director.push("GameScene");

        director.run();

        /*
        ImageAsset texture = ImageManager.fetch("asset.png");

        sf::Sprite sprite;
        sprite.setTexture(texture.data());
        sprite.setPosition(0, 0);
        */

        return 0;
}
