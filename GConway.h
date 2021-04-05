#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "MatrixForField.h"
class GConway : public MatrixForField
{
private:
    int width;
    int height;

public:
    GConway(int height, int width, int rad);

    void drawCell(int i, int j);
    void drawAlive(int i, int j);
    void drawField();

    int getWidth() const { return width; }
    int getHeight() const { return height; }
};
