#include<GL/glut.h>
float py = 75, deltay = .1, px = 75;
void display() {
	glClearColor(0, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	bool c = 0;



	for (int j = 0; j < 400; j += 50) {

		for (int i = 0; i < 400; i += 50)
		{
			glBegin(GL_POLYGON);
			glColor3f(c, c, c);
			glVertex2f(i + 50, j + 50);
			glVertex2f(i + 100, j + 50);
			glVertex2f(i + 100, j + 100);
			glVertex2f(i + 50, j + 100);
			glEnd();
			c = !c;

		}

		c = !c;

	}
	glPointSize(50);
	glBegin(GL_POINTS);
	glColor3f(.5, .5, .5);
	glVertex2f(px, py);
	glEnd();


	glFlush();

	glutPostRedisplay();
}

void move_up() {
	if (py < 425)
		py += 50;

}
void move_down() {
	if (py > 75)
		py -= 50;

}
void move_left() {
	if (px > 75)
		px -= 50;

}
void move_right() {
	if (px < 425)
		px += 50;

}

void keyboard(int key, int x, int y) {

	if (key == GLUT_KEY_UP) move_up();
	if (key == GLUT_KEY_DOWN) move_down();
	if (key == GLUT_KEY_LEFT) move_left();
	if (key == GLUT_KEY_RIGHT)move_right();
	glutPostRedisplay();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("points");
	gluOrtho2D(0, 550, 0, 550);
	glutSpecialFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return EXIT_SUCCESS;
}
