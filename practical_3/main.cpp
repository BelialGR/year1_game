#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"

using namespace sf;
using namespace std;


//Main.cpp
sf::Texture spritesheet;
sf::Sprite invader;
std::vector<Ship *> ships;

void Load() {
  if (!spritesheet.loadFromFile("res/invaders_sheet.png")) {
    cerr << "Failed to load spritesheet!" << std::endl;
  }
  invader.setTexture(spritesheet);
  invader.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(32, 32)));
}

void Render(RenderWindow &window) {
  window.draw(invader);
}

int main(){
  RenderWindow window(VideoMode(600, 600), "Space Invader");
    Load();
    while (window.isOpen()) {
        window.clear();
        Render(window);
        window.display();
    }
  return 0;
}