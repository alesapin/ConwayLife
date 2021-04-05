#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "MatrixForField.h"
class GConway
{
private:
    MatrixForField data;

    int width;
    int height;
    int radius;

    void drawCell(int i, int j);
    void drawAlive(int i, int j);

public:
    GConway(int height_, int width_, int radius_);

    void drawField();
    void applyRules() { data.applyRules(); }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
};
