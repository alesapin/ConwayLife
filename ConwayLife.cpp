#include "ConwayLife.h"
#include <memory>

ConwayLife::ConwayLife(int length_, int height_, int radius_)
    : conway(length_, height_, radius_)
    , length(length_)
    , height(height_)
{
}

void ConwayLife::render()
{
    conway.drawField();
    glutSwapBuffers();
}

void ConwayLife::update()
{
    conway.applyRules();
    glutPostRedisplay();
}

void ConwayLife::initGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel(GL_SMOOTH);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glOrtho(0, length, height, 0, 1, -1);
    glMatrixMode(GL_MODELVIEW);
}

void ConwayLife::initGlut(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(length, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Conway's game of life");
}

std::unique_ptr<ConwayLife> conway_life;

void render()
{
    conway_life->render();
}

void update()
{
    conway_life->update();
}

int main(int argc, char ** argv)
{
    int l, h, r;
    std::cout << "Введите длинну: ";
    std::cin >> l;
    std::cout << "Введите ширину: ";
    std::cin >> h;
    std::cout << "Введите радиус: ";
    std::cin >> r;

    conway_life = std::make_unique<ConwayLife>(l, h, r);
    conway_life->initGlut(argc, argv);
    conway_life->initGL();

    glutDisplayFunc(render);
    glutIdleFunc(update);
    glutMainLoop();
    return 0;
}
