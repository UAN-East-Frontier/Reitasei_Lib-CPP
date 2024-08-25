#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <memory>
#include <map>
#include <iostream>
#include <vector>



class Location {
public:
    Location(std::shared_ptr<sf::RenderWindow> wind, std::shared_ptr<Scene> scene);
    Location(std::shared_ptr<sf::RenderWindow> wind, std::shared_ptr<Scene> scene, const std::string& name);

    std::shared_ptr<sf::RenderWindow> window;

    void addScene(const std::string&, std::shared_ptr<Scene> scene);
    void changeCurrentScene(const std::string& name);
    void deleteScene(std::string& name);
    std::shared_ptr<Scene> getCurrentScene();
    std::shared_ptr<Scene> getScene(std::string& name);
    std::vector<std::string> getNames();
    void changeName(std::string& oldName, std::string& newName);
private:
    std::map<std::string, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> currentScene;

};