#include <iostream>
#include <vector>

enum State
{
    dead,
    alive
};

using vector2d = std::vector<std::vector<State>>;

class MatrixForField
{
protected:
    int column;
    int row;
    int radius;
    vector2d data;

    int checkNeighbours(const vector2d & tmp, int i, int j) const;
public:
    MatrixForField(int height, int length, int radius_);
    void set(int i, int j, State t);
    State get(int i, int j) const;

    int getRows() const { return row; }
    int getColumns() const { return column; }

    void applyRules();

    void setDataFromFile();
    void setSomeData();
    void printData(const vector2d & a) const;
};
