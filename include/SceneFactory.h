#ifndef __SCENE_FACTORY_H_DEFINED__
#define __SCENE_FACTORY_H_DEFINED__

#include <string>
#include <map>

#include "Scene.h"

// Create function pointer
typedef Scene* (*CreateSceneFn)(void);

/* @todo: Clean this up, method bodies to .cpp file */
// Factory for creating instances of Scene
class SceneFactory
{
public:
        ~SceneFactory() {
                factories_.clear();
        }

        static SceneFactory *Get()
        {
                static SceneFactory instance;
                return &instance;
        }

        void Register(const std::string &SceneName, CreateSceneFn pfnCreate);
        Scene *CreateScene(const std::string &SceneName);

private:
        SceneFactory();
        SceneFactory(const SceneFactory &) {}
        SceneFactory &operator=(const SceneFactory &)
        {
                return *this;
        }

        typedef std::map<std::string, CreateSceneFn> FactoryMap;
        FactoryMap factories_;
};

#endif
