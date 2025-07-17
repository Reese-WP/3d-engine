#include "hint.h"
#include "raylib.h"
#include "functions/Functions.h"
#include <string>

// Constructor with default range value
Hint::Hint(float x, float y, float z, const std::string& text, float range)
    {
        this->position = {x, y, z}; // Initialize position using Vector3
        this->text = text;
        this->range = range;
    }
Hint::Hint(Vector3 position, const std::string& text, float range)
    {
        this->position = position; // Initialize position using Vector3
        this->text = text;
        this->range = range;
    }

// Method to display the hint
void Hint::displayHint() {
    DrawBillboard(Camera(), Functions::CreateTextTexture("test", 5, Color{255, 255, 255, 255}, Color{0,0,0,0}), Vector3{0,0,0}, 50, WHITE);
}
// Method to delete the hint
void Hint::deleteHint() {
    this->position.x = 0.0f;  // Reset coordinates
    this->position.y = 0.0f; // Reset coordinates
    this->position.z = 0.0f; // Reset coordinates
    this->text.clear(); // Clear the hint text
    this->range = 0.0f; // Reset range
}

// Getters for hint properties
float Hint::getX() const {
    return position.x;
}

float Hint::getY() const {
    return position.y;
}

float Hint::getZ() const {
    return position.z;
}

std::string Hint::getText() const {
    return text;
}

float Hint::getRange() const {
    return range;
}

// Setters for hint properties
void Hint::setX(float x) {
    this->position.x = x;
}

void Hint::setY(float y) {
    this->position.y = y;
}

void Hint::setZ(float z) {
    this->position.z = z;
}

void Hint::setText(const std::string& text) {
    this->text = text;
}

void Hint::setRange(float range) {
    this->range = range;
}