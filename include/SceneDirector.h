#ifndef __SCENE_DIRECTOR_H_DEFINED__
#define __SCENE_DIRECTOR_H_DEFINED__

#include <stack>

#include "vendor/easylogging++.h"

#include "AssetManager.h"
#include "Scene.h"
#include "SceneFactory.h"

class SceneDirector {
public:
        SceneDirector(sf::RenderWindow* window) :
                window_(window)
        {};
        ~SceneDirector() {};

        void run();

        void push(std::string scene);
        bool hasScenes();

protected:
        sf::RenderWindow* window_;
        std::stack<Scene*> scenes_;
        AssetManager image_manager_;
};

#endif
