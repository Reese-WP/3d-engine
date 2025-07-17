#include "raylib.h"
#include "Functions.h"

Texture2D CreateTextTexture(const char* text, int fontSize, Color color, Color backgroundColor) 
{
    //makes a texture from text
    // Measure the text dimensions
    int textWidth = MeasureText(text, fontSize);
    int textHeight = fontSize;

    // Create an image with the background color
    Image textImage = GenImageColor(textWidth, textHeight, backgroundColor);

    // Draw the text onto the image
    ImageDrawText(&textImage, text, 0, 0, fontSize, color);

    // Convert the image to a texture
    Texture2D textTexture = LoadTextureFromImage(textImage);

    // Unload the image from memory
    UnloadImage(textImage);

    return textTexture;
}