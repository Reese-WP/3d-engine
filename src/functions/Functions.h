#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "raylib.h"

// Function to create a texture from text
Texture2D CreateTextTexture(const char* text, int fontSize, Color color, Color backgroundColor = Color{ 0, 0, 0, 0 });

#endif