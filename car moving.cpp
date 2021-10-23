#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
float C = 0;

typedef struct star {
    float x;
    float y;
}STAR;
#define STARS_NUM 200
STAR s[STARS_NUM];


float RandomNumber(float Min, float Max)
{
    return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}
void init_Pos_Stars() {


    for (int i = 0; i < STARS_NUM; i++) {
        s[i].x = RandomNumber(0, 700);
        s[i].y = RandomNumber(300, 500);
    }
}



void moveX() {

    for (int i = 0; i < STARS_NUM; i++) {
        if (s[i].x > 700)
            s[i].x = 0;
        else
            s[i].x += 0.1;
    }
}


void road() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2f(-100, 25);
    glVertex2f(-100, 100);
    glVertex2f(1000, 100);
    glVertex2f(1000, 25);
    glEnd();


    glLineWidth(20);
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex2f(-100, 62);
    glVertex2f(700, 62);
    glEnd();


}

void car() {

    glColor3f(0.9, 0.1, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(-300 + C, 100);
    glVertex2f(-300 + C, 160);
    glVertex2f(-50 + C, 160);
    glVertex2f(-50 + C, 100);



    glBegin(GL_POLYGON);
    glVertex2f(-280 + C, 160);
    glVertex2f(-250 + C, 200);
    glVertex2f(-150 + C, 200);
    glVertex2f(-100 + C, 160);
    glEnd();
}




void wheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 20 * cos(th), y + 20 * sin(th));
    }

    glBegin(GL_POLYGON);
    glColor3f(.8, 0.8, 0.8);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 10 * cos(th), y + 10 * sin(th));
    }

    glEnd();
}


void star() {
    glBegin(GL_POINTS);
    for (int i = 0; i < STARS_NUM; i++) {
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(s[i].x, s[i].y);

    }
    glEnd();
}

void display()
{


    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.1, 0.2, 1.0);
    star();

    moveX();
    glutPostRedisplay();

    car();
    road();

    wheel(-250 + C, 100);
    wheel(-100 + C, 100);
    glutSwapBuffers();


}

void timer(int a) {

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    if (C > 1000)
        C = -100;
    else
        C += 3;

}




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Car Moving");
    gluOrtho2D(0, 700, 0, 500);

    glPointSize(3);
    init_Pos_Stars();
    glutDisplayFunc(display);
    glutTimerFunc(200, timer, 0);

    glutMainLoop();
    return EXIT_SUCCESS;
}