#include <GL/glut.h>
#include <cmath>
#include <iostream>

const int WIDTH = 512, HEIGHT = 512;
unsigned char texture[WIDTH][HEIGHT][3];

void generateTexture() {
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            float value = 0.5f + 0.5f * std::sin(x * 0.1f) * std::cos(y * 0.1f);
            unsigned char intensity = static_cast<unsigned char>(value * 255);
            texture[x][y][0] = intensity; // Red
            texture[x][y][1] = intensity; // Green
            texture[x][y][2] = intensity; // Blue
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, texture);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    generateTexture();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Procedural Texture Generation");
    glRasterPos2i(-1, -1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
