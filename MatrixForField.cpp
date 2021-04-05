#include "MatrixForField.h"
#include <fstream>
#include <stdlib.h>

MatrixForField::MatrixForField(int height, int length, int radius_)
{
    radius = radius_;
    column = height / (2 * radius);
    row = length / (2 * radius);
    data.resize(row);
    for (int i = 0; i < row; ++i)
    {
        data[i].resize(column);
    }
    setSomeData();
}

void MatrixForField::setSomeData()
{
    for (int i = 50; i < column / 2 + 50; ++i)
    {
        data[70][i] = alive;
    }
}

void MatrixForField::set(int i, int j, State t)
{
    data[i][j] = t;
}

State MatrixForField::get(int i, int j) const
{
    return data[i][j];
}

int MatrixForField::checkNeighbours(const vector2d & tmp, int i, int j) const
{
    int result = 0;
    for (int k = -1; k < 2; ++k)
    {
        for (int h = -1; h < 2; ++h)
        {
            int xpos = i + k;
            int ypos = j + h;

            if (xpos < 0)
                xpos = row - 1;
            else if (xpos > row - 1)
                xpos = 0;

            if (ypos > column - 1)
                ypos = 0;
            else if (ypos < 0)
                ypos = column - 1;

            if (tmp[xpos][ypos] == alive && !(xpos == i && ypos == j))
                ++result;
        }
    }
    return result;
}

void MatrixForField::printData(const vector2d & a) const
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void MatrixForField::applyRules()
{
    int neighbours = 0;
    vector2d tmpData(data);
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            neighbours = checkNeighbours(tmpData, i, j);
            if (neighbours > 0)
            {
                if (tmpData[i][j] == dead && neighbours == 3)
                    data[i][j] = alive;
                else if (tmpData[i][j] == alive && (neighbours < 2 || neighbours > 3))
                    data[i][j] = dead;
            }
        }
    }
}
