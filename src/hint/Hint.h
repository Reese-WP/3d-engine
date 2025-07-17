#ifndef HINT_H
#define HINT_H

#include "raylib.h"
#include <string>

class Hint {
private:
    Vector3 position; // Position of the hint in 3D space
    std::string text;    // Hint text
    float range;         // Range of the hint

public:
    // Constructor with default range value
    Hint(float x, float y, float z, const std::string& text, float range = 5.0f);
    Hint(Vector3 position, const std::string& text, float range = 5.0f);
    
    //display hint
    void displayHint();

    // Method to delete the hint
    void deleteHint();

    // Getters for hint properties (optional, if needed)
    float getX() const;
    float getY() const;
    float getZ() const;
    std::string getText() const;
    float getRange() const;

    // Setters for hint properties (optional, if needed)
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void setText(const std::string& text);
    void setRange(float range);
};

#endif // HINT_H