#include "Location.h"
#include "Scene.h"

Location::Location(std::shared_ptr<sf::RenderWindow> wind, std::shared_ptr<Scene> scene) {
    window = wind;
    currentScene = scene;
    scenes["Default"] = scene;
}

Location::Location(std::shared_ptr<sf::RenderWindow> wind, std::shared_ptr<Scene> scene, const std::string& name) {
    window = wind;
    currentScene = scene;
    scenes[name] = currentScene;
}

void Location::addScene(const std::string& name, std::shared_ptr<Scene> scene) {
    scenes[name] = scene;
}

void Location::changeCurrentScene(const std::string& name) {
    if (scenes.count(name) == 1) {

        currentScene = scenes[name];
    }
    else std::cout << "Error: Scene with name '" << name << "' not exist!" << std::endl;
}

std::vector<std::string> Location::getNames() {
    std::vector<std::string> arrScenes;
    for (auto element : scenes)
        arrScenes.push_back(element.first);
    return arrScenes;
}

void Location::changeName(std::string& oldName, std::string& newName) {
    if (scenes.count(oldName) == 0) {
        std::cout << "Error: Scene with name '" << oldName << "' not exist!" << std::endl;
        return;
    }
    auto ptr = scenes[oldName];
    scenes[newName] = ptr;
    scenes.erase(oldName);
}

std::shared_ptr<Scene> Location::getCurrentScene() {
    if (currentScene != nullptr) {
        return currentScene;
    }
    return nullptr;
}

std::shared_ptr<Scene> Location::getScene(std::string& name) {
    if (scenes.count(name) == 1) {
        return scenes[name];
    }
    return nullptr;
}

void Location::deleteScene(std::string& name) {
    if (scenes.count(name) == 1) {
        if (scenes[name] == currentScene)
        {
            std::cout << "Error: This is current scene!" << std::endl;
            return;
        }
        scenes.erase(name);
    }
    else std::cout << "Error: Scene with name '" << name << "' not exist!" << std::endl;
}