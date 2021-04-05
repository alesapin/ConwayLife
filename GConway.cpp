#include "GConway.h"

static double doubleRandom(double min, double max)
{
    double f = static_cast<double>(rand()) / RAND_MAX;
    return min + f * (max - min);
}

GConway::GConway(int height_, int width_, int radius_)
    : data(height_, width_, radius_)
    , width(width_)
    , height(height_)
    , radius(radius_)
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
    for (int i = 0; i < data.getRows(); ++i)
    {
        for (int j = 0; j < data.getColumns(); ++j)
        {
            if (data.get(i, j) == alive)
                drawAlive(i, j);
        }
    }
}
