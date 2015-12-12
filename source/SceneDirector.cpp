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

                DrawableGroup group;
                /*
                DrawableGroup group = image_manager_.fetch(
                        currentScene->drawable()
                );
                */

                window_->clear();
                group.render(window_);
                window_->display();
        }
}

bool SceneDirector::hasScenes()
{
        return !scenes_.empty();
}
