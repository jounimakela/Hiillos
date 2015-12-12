#ifndef __SCENE_H_DEFINED__
#define __SCENE_H_DEFINED__

#include <vector>
#include <string>

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
                drawables.push_back("asset.png");
                return drawables;
        };

        static Scene * Create() { return new GameScene(); }
};

#endif
