#define ELPP_NO_DEFAULT_LOG_FILE

#include "SFML/Window.hpp"
#include "vendor/easylogging++.h"

#include "AssetManager.h"
#include "SceneDirector.h"
#include "SceneFactory.h"
#include "Scene.h"
#include "Configuration.h"

INITIALIZE_EASYLOGGINGPP


int main(int argc, char* args[])
{
        el::Configurations conf("./config/logger.conf");
        el::Loggers::reconfigureAllLoggers(conf);
        LOG(INFO) << "Starting application.";

        sf::RenderWindow window(sf::VideoMode(800, 600), "Hiillos - development");
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);

        Configuration config("./config/test.json");
        auto name = config.find("name");
        if (name != config.end()) {
                LOG(DEBUG) << "Name of the game is " << *name;
        }

        /*
        SceneFactory::Get()->Register("GameScene", &GameScene::Create);
        SceneDirector director(&window);
        director.push("GameScene");
        */

//        director.run();

        return 0;
}
