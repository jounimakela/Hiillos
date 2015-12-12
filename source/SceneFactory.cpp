#include "SceneFactory.h"

/*
 * @todo: Names to camelCase
 */

/* @todo: This is probably useless?
 * We will register scenes at main.
 */
SceneFactory::SceneFactory()
{
        //Register("Horse", &Horse::Create);
        //Register("Cat", &Cat::Create);
        //Register("Dog", &Dog::Create);
}

void SceneFactory::Register(const std::string &SceneName, CreateSceneFn pfnCreate)
{
        factories_[SceneName] = pfnCreate;
}

Scene *SceneFactory::CreateScene(const std::string &SceneName)
{
        FactoryMap::iterator it = factories_.find(SceneName);
        if( it != factories_.end() )
                return it->second();
        return NULL;
}
