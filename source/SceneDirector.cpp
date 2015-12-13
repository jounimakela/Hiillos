#include "SceneDirector.h"

/* @todo: Here we probably need the factory! */
void SceneDirector::push(std::string scene_name)
{
        LOG(DEBUG) << "Creating new scene.";
        Scene* scene = SceneFactory::Get()->CreateScene(scene_name);
        scenes_.push(scene);
}

void SceneDirector::run()
{
        while(hasScenes()) {
                sf::Event event;

                while (window_->pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                                window_->close();
                        }
                }

                Scene *currentScene = scenes_.top();
                currentScene->update();

                switch(currentScene->status().code) {
                        case STATUS_CODES::STAY:
                                break;

                        case STATUS_CODES::EXIT:
                                LOG(DEBUG) << "Exiting current scene.";
                                scenes_.pop();
                                break;

                        case STATUS_CODES::PREPEND_DYNAMIC:
                                break;

                        case STATUS_CODES::PREPEND_STATIC:
                                break;

                        default:
                                break;
                }

                image_manager_.resetReferences();

                /* @todo: Isolate this */
                std::vector<sf::Sprite> group;

                for (auto &file : currentScene->drawable()) {
                        sf::Sprite sprite;
                        sprite.setTexture(image_manager_.fetch(file).data());
                        group.push_back(sprite);
                }

                window_->clear();

                for(std::vector<sf::Sprite>::iterator it = group.begin();
                                it != group.end();
                                it++)
                {
                        window_->draw(*it);
                }

                window_->display();

                /* @todo: This should be done automatically */
                image_manager_.cleanup();
        }
}

bool SceneDirector::hasScenes()
{
        return !scenes_.empty();
}
