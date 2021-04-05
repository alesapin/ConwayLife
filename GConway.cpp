#include "GConway.h"
GConway::GConway(int height, int width, int radius)
    : MatrixForField(height, width, radius)
    , width(width)
    , height(height)
{
}

void GConway::drawCell(int i, int j)
{
    int y = i * 2 * radius + radius;
    int x = j * 2 * radius + radius;
    glBegin(GL_QUADS);
    glVertex2d(x - radius, y + radius);
    glVertex2d(x + radius, y + radius);
    glVertex2d(x + radius, y - radius);
    glVertex2d(x - radius, y - radius);
    glEnd();
}

void GConway::drawAlive(int i, int j)
{
    glColor3d(1, 1, 1);
    drawCell(i, j);
}

void GConway::drawField()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            if (data[i][j] == alive)
                drawAlive(i, j);
        }
    }
}
