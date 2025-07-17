#ifndef GUI_H
#define GUI_H

#include "raylib.h"
#include <string>
#include <vector>

class Gui
{
    private:
        //vector of string pointers
        std::vector<std::pair<std::string, Vector2>> texts; // Pair of text and its position
        std::vector<std::tuple<int, int, int, int, Color>> rectangles; // Tuple of position (x, y), size (width, height), and color
        std::vector<std::tuple<int, int, int, int, Color>> rectangleLines; // Tuple of position (x, y), size (width, height), and color for rectangle lines
        std::vector<std::tuple<Texture2D, int, int, Color>> textures;  // Tuple of texture, position (x, y), and tint color
    public:
        Gui() = default;
        ~Gui() = default;

        void draw();
        void addText(const char* text, int posX, int posY, int fontSize, Color color);
        void addRectangle(int posX, int posY, int width, int height, Color color);
        void addRectangleLines(int posX, int posY, int width, int height, Color color);
        void addTexture(Texture2D texture, int posX, int posY, Color tint);
}