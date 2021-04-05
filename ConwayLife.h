#include "GConway.h"
class ConwayLife
{
private:
    GConway conway;
    int length;
    int height;

public:
    ConwayLife(int lenght_, int height_, int radius_);

    void render();
    void update();
    void initGL();
    void initGlut(int argc, char ** argv);
};
