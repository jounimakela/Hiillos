#ifndef __SCENE_H_DEFINED__
#define __SCENE_H_DEFINED__

#include <vector>
#include <string>

#include "SFML/System.hpp"
#include "vendor/easylogging++.h"

enum STATUS_CODES {
        STAY,
        EXIT,
        PREPEND_STATIC,
        PREPEND_DYNAMIC
};

struct SceneStatus {
        STATUS_CODES code;
};

class Scene
{
public:
        virtual void update() = 0;
        virtual std::vector<std::string> drawable() = 0;

        SceneStatus status()
        {
                return status_;
        }

protected:
        SceneStatus status_;
};

// Create function pointer
typedef Scene* (*CreateSceneFn)(void);

class GameScene : public Scene
{
public:
        void update()
        {
                status_.code = STATUS_CODES::STAY;
        };

        std::vector<std::string> drawable()
        {
                std::vector<std::string> drawables;

                // @note: This comes from Entity->draw();
                if (asset_lifetime.getElapsedTime().asSeconds() < 2) {
                        drawables.push_back("asset.png");
                }
                // returns ImageAsset
                // which contains what asset it wants
                // and who it wants?
                return drawables;
        };

        /* @FIXME: I don't like this */
        static Scene * Create() { return new GameScene(); }
private:
        sf::Clock asset_lifetime;
};

#endif
