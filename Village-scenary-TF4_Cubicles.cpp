/** ========================================**
 ** Bismillahi-Rahamanirahim.
 ** @Author:    Md. Abdullah Ibna Harun (193-15-13426 || Section - || A Batch-54)
 **             Mahade Hasan Forhad (193-15-13355 || Section - A || Batch-54)
/** ========================================**/

/** Open-GL Headers **/
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <random>
#include <stdlib.h>

using namespace std;

#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define endl '\n'
#define TRUE 1
#define FALSE 0
#define sqre(x) ((x)*(x))
#define lli  long long int
#define ull  unsigned long long
typedef long long ll;
const int MOD = 1000000007;
const int MAX = 1001;
const int MAXX = 100005;
const int MAXN = 1e5 + 3;
#define PI 3.1416

float x_position = 0, flyObj = 0, _angle = 0;
int posx = 0, posy = 0;
int day = 1;

//mon
void moon()
{

    int rad, x, y, a, b, h;
    bool SE, E;
    glColor3f(1, 0.95, 0.95);
    a = -100;
    b = 100;
    x = 0;
    rad = 50;
    y = rad;
    h = 1 - rad;

    glVertex3i(x + a, y + b, 0);
    glBegin(GL_POLYGON);
    glVertex3i(x + a, y + b, 0);

    if (h >= 0)
    {
        SE = true;
        E = false;
    }
    else

    {
        E = true;
        SE = false;

    }

    while (y >= x)
    {

        if (SE)
        {
            h = h + 5 + 2 * (x - y);
            if (h >= 0)
            {
                SE = true;
                E = false;
            }
            else
            {
                E = true;
                SE = false;

            }
            x++;
            y--;
            glVertex3f(x + a, y + b, 0.0);
            glVertex3f(y + a, x + b, 0.0);
            glVertex3f(-y + a, x + b, 0.0);
            glVertex3f(-x + a, -y + b, 0.0);
            glVertex3f(-y + a, -x + b, 0.0);
            glVertex3f(y + a, -x + b, 0.0);
            glVertex3f(x + a, -y + b, 0.0);
            glVertex3f(x + a, y + b, 0.0);
            glVertex3f(-x + a, y + b, 0.0);
        }
        if (E)
        {
            h = h + 3 + 2 * x;
            if (h >= 0)
            {
                SE = true;
                E = false;
            }
            else
            {
                E = true;
                SE = false;
            }
            x++;
            glVertex3f(x + a, y + b, 0.0);
            glVertex3i(y + a, x + b, 0.0);
            glVertex3i(-y + a, x + b, 0.0);
            glVertex3i(-x + a, -y + b, 0.0);
            glVertex3i(-y + a, -x + b, 0.0);
            glVertex3i(y + a, -x + b, 0.0);
            glVertex3i(x + a, -y + b, 0.0);
            glVertex3i(x + a, y + b, 0.0);
            glVertex3i(-x + a, y + b, 0.0);
        }
    }
    glEnd();
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3i(601, 980, 0);
    glVertex3i(601, 950, 0);
    glVertex3i(600, 980, 0);
    glVertex3i(600, 950, 0);
    glEnd();
}

//sun
void sun()
{
    glColor3f(1, 0.25, 0);
    int a, b, E, rad, x, y, h, SE;
    a = 200;
    b = 200;
    x = 0;
    rad = 50;
    y = rad;
    h = 1 - rad;
    glBegin(GL_POLYGON);
    glVertex3i(x + b, y + b, 0);

    if (h >= 0)
    {
        SE = true;
        E = false;
    }
    else
    {
        E = true;
        SE = false;

    }
    while (y >= x)
    {
        if (SE)
        {
            h = h + 5 + 2 * (x - y);
            if (h >= 0)
            {
                SE = true;
                E = false;
            }
            else
            {
                E = true;
                SE = false;

            }
            x++;
            y--;
            glVertex3f(x + a, y + b, 0.0);
            glVertex3f(y + a, x + b, 0.0);
            glVertex3f(-y + a, x + b, 0.0);
            glVertex3f(-x + a, -y + b, 0.0);
            glVertex3f(-y + a, -x + b, 0.0);
            glVertex3f(y + a, -x + b, 0.0);
            glVertex3f(x + a, -y + b, 0.0);
            glVertex3f(x + a, y + b, 0.0);
            glVertex3f(-x + a, y + b, 0.0);
        }
        if (E)
        {
            h = h + 3 + 2 * x;
            if (h >= 0)
            {
                SE = true;
                E = false;
            }
            else
            {
                E = true;
                SE = false;

            }
            x++;
            glVertex3f(x + a, y + b, 0.0);
            glVertex3i(y + a, x + b, 0.0);
            glVertex3i(-y + a, x + b, 0.0);
            glVertex3i(-x + a, -y + b, 0.0);
            glVertex3i(-y + a, -x + b, 0.0);
            glVertex3i(y + a, -x + b, 0.0);
            glVertex3i(x + a, -y + b, 0.0);
            glVertex3i(x + a, y + b, 0.0);
            glVertex3i(-x + a, y + b, 0.0);
        }
    }
    glEnd();

    glColor3f(1, 0.5, 0.02);
    glBegin(GL_LINES);
    glVertex3i(400, 400, 0);
    glVertex3i(400, 350, 0);
    glEnd();
}

//background trees
void treeBG(int positionY)
{
    glBegin(GL_POLYGON);
    glColor3ub(193, 163, 157);
    glVertex2d(-400, positionY - 300);
    glVertex2d(-400, positionY - 100);
    glVertex2d(400, positionY - 100);
    glVertex2d(400, positionY - 300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(49, 157, 82);//172, 120, 90
    glVertex2d(-400, positionY - 100);
    glVertex2d(-400, positionY - 40);
    glVertex2d(-380, positionY - 37);
    glVertex2d(-360, positionY - 24);
    glVertex2d(-340, positionY - 5);
    glVertex2d(-320, positionY + 5);
    glVertex2d(-300, positionY + 11);
    glVertex2d(-280, positionY + 18);
    glVertex2d(-260, positionY + 20);
    glVertex2d(-240, positionY + 20);
    glVertex2d(-220, positionY + 15);
    glVertex2d(-200, positionY + 10);
    glVertex2d(-180, positionY + 3);
    glVertex2d(-160, positionY - 9);
    glVertex2d(-140, positionY - 18);
    glVertex2d(-120, positionY - 25);
    glVertex2d(-100, positionY - 30);
    glVertex2d(-80, positionY - 30);
    glVertex2d(-60, positionY - 27);
    glVertex2d(-40, positionY - 21);
    glVertex2d(-20, positionY - 15);
    glVertex2d(0, positionY - 9);
    glVertex2d(20, positionY + 1);
    glVertex2d(40, positionY + 10);
    glVertex2d(60, positionY + 18);
    glVertex2d(80, positionY + 21);
    glVertex2d(100, positionY + 23);
    glVertex2d(120, positionY + 21);
    glVertex2d(140, positionY + 18);
    glVertex2d(160, positionY + 10);
    glVertex2d(180, positionY + 0);
    glVertex2d(200, positionY - 10);
    glVertex2d(220, positionY + 0);
    glVertex2d(240, positionY + 10);
    glVertex2d(260, positionY + 20);
    glVertex2d(280, positionY + 27);
    glVertex2d(300, positionY + 27);
    glVertex2d(320, positionY + 26);
    glVertex2d(340, positionY + 22);
    glVertex2d(360, positionY + 16);
    glVertex2d(380, positionY + 7);
    glVertex2d(400, positionY - 3);
    glVertex2d(400, positionY - 100);

    glEnd();
}

// background windmill
void windmill(int xPos, int yPos)
{
    glColor3ub(85, 85, 127);
    glBegin(GL_POLYGON);
    glVertex2d(xPos - 5, yPos);
    glVertex2d(xPos - 5, yPos - 140);
    glVertex2d(xPos + 5, yPos - 140);
    glVertex2d(xPos + 5, yPos);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(xPos - 20, yPos - 150);
    glVertex2d(xPos + 20, yPos - 150);
    glVertex2d(xPos, yPos - 135);

    glEnd();


    glColor3ub(220, 230, 230);

    glPushMatrix();
    glTranslatef(xPos, yPos, 0);
    glRotatef(_angle, 0, 0, -1);
    glTranslatef(-xPos, -yPos, 0);

    glBegin(GL_POLYGON);
    glVertex2d(xPos - 4, yPos + 10);
    glVertex2f(xPos + 33.33, yPos + 50);
    glVertex2d(xPos + 10, yPos);
    glVertex2d(xPos + 33.33, yPos - 50);
    glVertex2d(xPos - 4, yPos - 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(xPos - 58, yPos);
    glVertex2d(xPos - 4, yPos + 9);
    glVertex2d(xPos - 4, yPos - 9);
    glEnd();

    glPopMatrix();
}

//houses
void house(int xPos, int yPos)
{
    glColor3f(0.51, 0.30, 0.00);
    glBegin(GL_POLYGON);
    glVertex2f(xPos + 0, yPos + 120);
    glVertex2f(xPos - 90, yPos + 80);
    glVertex2f(xPos + 90, yPos + 80);
    glEnd();

    glColor3ub(112, 131, 103);
    glBegin(GL_POLYGON);
    glVertex2f(xPos - 70, yPos + 5);
    glVertex2f(xPos - 70, yPos + 80);
    glVertex2f(xPos + 70, yPos + 80);
    glVertex2f(xPos + 70, yPos + 5);
    glEnd();

    glColor3f(1.0, .5, 0);
    glBegin(GL_POLYGON);
    glVertex2f(xPos - 1, yPos);
    glVertex2f(xPos - 30, yPos);
    glVertex2f(xPos - 30, yPos + 50);
    glVertex2f(xPos - 1, yPos + 50);
    glEnd();

    glColor3f(1., .5, 0);
    glBegin(GL_POLYGON);
    glVertex2f(xPos + 1, yPos);
    glVertex2f(xPos + 30, yPos);
    glVertex2f(xPos + 30, yPos + 50);
    glVertex2f(xPos + 1, yPos + 50);
    glEnd();

    glColor3f(0.51, 0.30, 0.00);
    glBegin(GL_POLYGON);
    glVertex2f(xPos - 80, yPos + 5);
    glVertex2f(xPos + 80, yPos + 5);
    glVertex2f(xPos + 80, yPos + 0);
    glVertex2f(xPos - 80, yPos + 0);
    glEnd();
}

//boat in river
void boat() {

    glColor3ub(17, 53, 35);
    glBegin(GL_TRIANGLES);
    glVertex2d(150, -350);
    glVertex2d(200, -350);
    glVertex2d(200, -380);
    glEnd();

    glColor3ub(17, 53, 35);
    glBegin(GL_POLYGON);
    glVertex2d(200, -350);
    glVertex2d(300, -350);
    glVertex2d(300, -380);
    glVertex2d(200, -380);
    glEnd();

    glColor3ub(17, 53, 35);
    glBegin(GL_POLYGON);
    glVertex2d(300, -350);
    glVertex2d(350, -350);
    glVertex2d(300, -380);
    glEnd();

    glColor3ub(108, 93, 67);
    glBegin(GL_POLYGON);
    glVertex2d(200, -350);
    glVertex2d(220, -320);
    glVertex2d(280, -320);
    glVertex2d(300, -350);
    glEnd();
}

// river
void river() {
    glColor3f(0, 0.67, 1);
    glBegin(GL_QUADS);
    glVertex2d(-390, -340);
    glVertex2d(400, -310);
    glVertex2d(-400, -400);
    glVertex2d(400, -400);
    glEnd();
}

// tree in land
void treeDraw() {
    ///tree1
    glColor3f(0.6156863, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3i(-90, -250, 0);
    glVertex3i(-90, -110, 0);
    glVertex3i(-70, -110, 0);
    glVertex3i(-70, -250, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3i(-150, -110, 0);
    glVertex3i(-85, -40, 0);
    glVertex3i(-15, -110, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3i(-145, -90, 0);
    glVertex3i(-85, -20, 0);
    glVertex3i(-20, -90, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3i(-140, -70, 0);
    glVertex3i(-85, 0, 0);
    glVertex3i(-25, -70, 0);
    glEnd();

    ///tree2
    glColor3f(0.6156863, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3i(190, -250, 0);
    glVertex3i(190, -110, 0);
    glVertex3i(170, -110, 0);
    glVertex3i(170, -250, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3i(250, -110, 0);
    glVertex3i(185, -40, 0);
    glVertex3i(115, -110, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3i(245, -90, 0);
    glVertex3i(185, -20, 0);
    glVertex3i(120, -90, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3i(240, -70, 0);
    glVertex3i(185, 0, 0);
    glVertex3i(125, -70, 0);
    glEnd();

}

//night effect
void night_effect()
{
    glColor3f(0.10, 0.05, 0.10);
    glBegin(GL_POLYGON);
    glVertex3i(-400, -250, 0);
    glVertex3i(-400, 400, 0);
    glVertex3i(400, 400, 0);
    glVertex3i(400, -250, 0);
    glEnd();

}

// line draw for graph
void line() {

    glLineWidth(2.5);
    glColor3f(1.0, 0.5, 0.0);

    glBegin(GL_LINES);
    glVertex3i(-400, 0, 0);
    glVertex3i(400, 0, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3i(0, 400, 0);
    glVertex3i(0, -400, 0);
    glEnd();

}

// function for chose day or night scenario
void draw_object()
{
    if (day == 1)
    {
        glColor3ub(192, 202, 51);
        windmill(-320, -10);
        treeBG(-100);
        house(-240, -300);
        house(60, -290);
        treeDraw();
        sun();
        river();
        boat();
        line();
    }
    else
    {
        night_effect();
        glColor3ub(192, 202, 51);
        windmill(-320, -10);
        treeBG(-100);
        house(-240, -300);
        house(60, -290);
        treeDraw();
        moon();
        river();
        boat();
        line();
        moon();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    draw_object();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}

void init() {
    glClearColor(0, 0.75, 1, 1);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-400, 400, -400, 400);
}

void keyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'n':
        day = 0;
        display();
        break;
    case 'd':
        day = 1;
        display();
        break;
    case 'N':
        day = 0;
        display();
        break;
    case 'D':
        day = 1;
        display();
        break;
    }

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(720, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("193-15-13426 || 193-15-13355");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardFunc);
    init();
    glutMainLoop();
    return 0;
}
