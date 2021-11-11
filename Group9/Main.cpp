//Apple
#ifdef __APPLE__
#include <GL/glut.h>
#else
#include <GL/glut.h>
#endif

#include<windows.h>
#include <stdlib.h>
#include<math.h>

static float	tp3 = 0;
static float	pm = 300.0;
static float	bm = 350.0;
static float	tm = 300.0;
static float	cm = -300.0;
double var = -6;
float spin = 0.0;
GLfloat	tx = 5;
GLfloat	ty = 5;


void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
	int i;
	float rad = 0;
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	for (i = 0; i <= 360; i++) {
		rad = i*(3.1416 / 180);
		glVertex2f(x + rx*cos(rad), y + ry*sin(rad));

	}
	glEnd();


}

void sun()
{
	glPushMatrix();
	glTranslated(240, 260, 0);
	glColor3f(1.0, 0.76, 0.3);
	circle(15, 30, 0, 0);
	glPopMatrix();
}
void make_cloud(int x, int y)
{

	glColor3f(1.0, 1.0, 1.0);
	circle(10, 10, x, y);
	circle(10, 10, x + 10, y);
	circle(10, 10, x + 30, y);
	circle(10, 10, x + 5, y - 10);
	circle(10, 10, x + 20, y - 10);
	circle(10, 10, x + 5, y + 10);
	circle(10, 10, x + 20, y + 10);

}

void cloud_move_right(GLfloat t) {
	tp3 = tp3 + t;
	if (tp3>600)
		tp3 = -300;
	glutPostRedisplay();
}


void cloud()
{
	glPushMatrix();
	glTranslatef(tp3, 0, 0);
	make_cloud(-300, 280);
	make_cloud(-500, 280);
	make_cloud(-200, 250);
	make_cloud(-400, 250);
	make_cloud(200, 250);
	make_cloud(-100, 250);
	make_cloud(-350, 230);
	glPopMatrix();
	cloud_move_right(.1);

	glEnd();
}
void rectangle1(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	//GL_QUADS - connected group of 4 VERTICES AS A QUAD
	glBegin(GL_QUADS);
	glVertex2d(x1, y1);
	glVertex2d(x3, y3);
	glVertex2d(x4, y4);
	glVertex2d(x2, y2);
	glEnd();
}
void make_tree2()
{
	glColor3f(0.0, 0.6, 0.0);
	circle(20, 30, 0, 0);
	circle(20, 30, 20, 0);
	circle(20, 30, 40, 0);
	circle(20, 30, 30, 30);
	circle(20, 30, 10, 30);
	circle(20, 30, 10, -30);
	circle(20, 30, 30, -30);

	circle(10, 20, 50, -70);
	circle(10, 20, 60, -60);
	circle(10, 20, 60, -80);


	glColor3f(0.75, 0.5, 0.25);
	rectangle1(10, -130, 30, -130, 10, -30, 30, -30);
	rectangle1(10, -30, 17, -30, 5, 0, 5, 0);
	rectangle1(17, -30, 22, -30, 19, 0, 19, 0);
	rectangle1(22, -30, 30, -30, 35, 0, 35, 0);
	rectangle1(30, -90, 30, -100, 55, -70, 55, -75);



}
void rectangle(int x, int y, int x1, int y1)
{
	//GL_QUADS - connected group of 4 VERTICES AS A QUAD
	glBegin(GL_QUADS);
	glVertex2d(x, y);
	glVertex2d(x, y1);
	glVertex2d(x1, y1);
	glVertex2d(x1, y);


	glEnd();
}
void soil()
{
	glColor3f(0.75, 0.75, 0.75);
	rectangle(-300, -10, 300, 130);
}


void ground()
{
	glColor3f(0.3, 1.0, 0.53);
	rectangle(-300, -300, 300, -10);

}
void tree2()
{
	glPushMatrix();
	glTranslated(-320, 120, 0);
	make_tree2();
	glPopMatrix();

	glPushMatrix();
	glTranslated(270, 120, 0);
	make_tree2();
	glPopMatrix();

	glPushMatrix();
	glTranslated(100, 120, 0);
	make_tree2();
	glPopMatrix();

}

void triangle(int x, int y, int x1, int x2, int y1)
{
	// the primitive or primirives that will be created

	//GL_POINTS - vertex as A single point

	//GL_LINES - pair of vertices as line segement

	//GL_LINE_STRIP - connected group of line segments

	//GL_LINE_LOOP - connected group of line segments

	//GL_TRIANGLES - TRIPLET OF VERTICES AS A TRIANGLE

	//GL_TRIANGLE_STRIP - group of TRIANGLES

	//GL_TRIANGLE_FAN - connected group of line segments

	//GL_QUADS - connected group of 4 VERTICES AS A QUAD

	//GL_QUAD_STRIP - connected group of QUADS

	//GL_POLYGON - conVEX POLYGON
	glBegin(GL_POLYGON);
	// x and y coordinates
	glVertex2d(x, y);
	glVertex2d(x1, y);

	glVertex2d(x1, y);
	glVertex2d(x2, y1);

	glVertex2d(x2, y1);
	glVertex2d(x, y);
	glEnd();
}
void tree(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
	glColor3f(0.25, 0.25, 0.25);
	//base of the tree
	rectangle(a, b, c, d);
	glColor3f(0.0, 0.3, 0.0);
	// branches of the tree
	triangle(e, f, g, h, i);

}
// Small trees 
void tree1()
{
	tree(-200, 110, -202, 140, -195, 140, -205, -200, 170); //1
	tree(-300, 110, -298, 140, -305, 140, -293, -299, 170); //2
	tree(-270, 110, -268, 140, -275, 140, -263, -269, 170); //3
	tree(-240, 110, -238, 140, -245, 140, -233, -239, 170); //4
	tree(-210, 110, -208, 140, -215, 140, -203, -209, 170); //5
	tree(-180, 110, -178, 140, -185, 140, -173, -179, 170); //6
	tree(-150, 110, -148, 140, -155, 140, -143, -149, 170); //7
	tree(-120, 110, -118, 140, -125, 140, -113, -119, 170); //8
	tree(-90, 110, -88, 140, -95, 140, -83, -89, 170); //9
	tree(-60, 110, -58, 140, -65, 140, -53, -59, 170); //10
	tree(-30, 110, -28, 140, -35, 140, -23, -29, 170); //11
	tree(0, 110, 2, 140, -5, 140, 7, 1, 170); //12
	tree(30, 110, 32, 140, 25, 140, 37, 31, 170); //13
	tree(60, 110, 62, 140, 55, 140, 67, 61, 170); //14
	tree(90, 110, 92, 140, 85, 140, 97, 91, 170);
	tree(120, 110, 122, 140, 115, 140, 127, 121, 170);
	tree(150, 110, 152, 140, 145, 140, 157, 151, 170);
	tree(180, 110, 182, 140, 175, 140, 187, 181, 170);
	tree(210, 110, 212, 140, 205, 140, 217, 211, 170);
	tree(240, 110, 242, 140, 235, 140, 247, 241, 170);
	tree(270, 110, 272, 140, 265, 140, 277, 271, 170);
	tree(300, 110, 302, 140, 295, 140, 307, 301, 170);
	tree(330, 110, 332, 140, 325, 140, 337, 331, 170);


}

void pavement()
{
	glBegin(GL_POLYGON);
	glColor3f(0.957, 0.643, 0.376);

	glVertex2d(-300, -175);
	glVertex2d(-300, -205);
	glVertex2d(300, -205);
	glVertex2d(300, -175);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2d(-300, -195);
	glVertex2d(300, -195);
	glEnd();



	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2d(-300, -185);
	glVertex2d(300, -185);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2d(-300, -175);
	glVertex2d(300, -175);
	glEnd();

	for (int i = -300; i<300; i = i + 12)
	{
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2d(i, -185);
		glVertex2d(i, -195);
		glEnd();
	}

}

void road()
{
	//Main area of the road
	glBegin(GL_QUADS);
	//Color is assigned to each vertices
	//integer 0 -255
	// float and double 0 -1.0
	//glColor3f(0.3, 1.0, 0.53);
	glColor3f(0.3, 0.3, 0.3);
	//Anti clockwise (front-side) top (2nd Quad), Left (3rd Quad) ,bottom (4th Quad) ,right (1st Quad)
	//glVertex2d(-250, 250);
	glVertex2d(-300, -205);
	//glVertex2d(-250, -250);
	glVertex2d(-300, -300);
	//glVertex2d(250,-250);
	glVertex2d(300, -300);
	//glVertex2d(250, 250);
	glVertex2d(300, -205);

	glEnd();

	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(-290, -255);
	glVertex2d(-290, -265);
	glVertex2d(-260, -265);
	glVertex2d(-260, -255);
	glEnd();

	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(-220, -255);
	glVertex2d(-220, -265);
	glVertex2d(-250, -265);
	glVertex2d(-250, -255);
	glEnd();
	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(-180, -255);
	glVertex2d(-180, -265);
	glVertex2d(-210, -265);
	glVertex2d(-210, -255);
	glEnd();
	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(-140, -255);
	glVertex2d(-140, -265);
	glVertex2d(-170, -265);
	glVertex2d(-170, -255);
	glEnd();
	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(-100, -255);
	glVertex2d(-100, -265);
	glVertex2d(-130, -265);
	glVertex2d(-130, -255);
	glEnd();

	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(-60, -255);
	glVertex2d(-60, -265);
	glVertex2d(-90, -265);
	glVertex2d(-90, -255);
	glEnd();
	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(-20, -255);
	glVertex2d(-20, -265);
	glVertex2d(-50, -265);
	glVertex2d(-50, -255);
	glEnd();


	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(20, -255);
	glVertex2d(20, -265);
	glVertex2d(-10, -265);
	glVertex2d(-10, -255);
	glEnd();
	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(60, -255);
	glVertex2d(60, -265);
	glVertex2d(30, -265);
	glVertex2d(30, -255);
	glEnd();

	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(100, -255);
	glVertex2d(100, -265);
	glVertex2d(70, -265);
	glVertex2d(70, -255);
	glEnd();
	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(140, -255);
	glVertex2d(140, -265);
	glVertex2d(110, -265);
	glVertex2d(110, -255);
	glEnd();
	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(180, -255);
	glVertex2d(180, -265);
	glVertex2d(150, -265);
	glVertex2d(150, -255);
	glEnd();
	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(220, -255);
	glVertex2d(220, -265);
	glVertex2d(190, -265);
	glVertex2d(190, -255);
	glEnd();
	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(260, -255);
	glVertex2d(260, -265);
	glVertex2d(230, -265);
	glVertex2d(230, -255);
	glEnd();
	//divider
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2d(296, -255);
	glVertex2d(296, -265);
	glVertex2d(270, -265);
	glVertex2d(270, -255);
	glEnd();


}
void fence() {
	glBegin(GL_QUADS);
	glVertex2d(-300,-80);
	glVertex2d(-300, -150);
	glVertex2d(-200, -150);
	glVertex2d(-200, -80);
	glEnd();

	glBegin(GL_LINE);
	glColor3f(0, 0, 0);
	glVertex2d(-200, -150);
	glVertex2d(-200, -80);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2d(-200, -80);
	glVertex2d(-200, -150);
	glVertex2d(-150, -110);
	glVertex2d(-150, -40);

	glEnd();
	// small wall
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2d(-150, -75);
	glVertex2d(-150, -110);
	glVertex2d(-125, -110);
	glVertex2d(-125, -75);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2d(-125, -40);
	glVertex2d(-125, -110);
	glVertex2d(-110, -110);
	glVertex2d(-110, -40);

	glEnd();
	//Gate
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex2d(-20, -110);
	glVertex2d(-20, -40);
	glVertex2d(20, -40);
	glVertex2d(20, -110);

	glEnd();
	glBegin(GL_LINE);
	glColor3f(0, 0, 0);
	glVertex2d(-20, -40);
	glVertex2d(20, -40);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2d(20, -40);
	glVertex2d(20, -110);
	glVertex2d(35, -110);
	glVertex2d(35, -40);

	glEnd();

	// small wall
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2d(35, -75);
	glVertex2d(35, -110);
	glVertex2d(60, -110);
	glVertex2d(60, -75);

	glEnd();

	glBegin(GL_QUADS);
	glVertex2d(60, -40);
	glVertex2d(60, -110);
	glVertex2d(100, -150);
	glVertex2d(100, -80);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2d(300, -80);
	glVertex2d(300, -150);
	glVertex2d(100, -150);
	glVertex2d(100, -80);
	glEnd();
}

//Steps/ Stairs
void steps() {
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2d(- 90, -60);
	glVertex2d(-90, -75);
	glVertex2d(20, -75);
	glVertex2d(20, -60);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2d(-70, -45);
	glVertex2d(-70, -60);
	glVertex2d(20, -60);
	glVertex2d(20, -45);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2d(-50, -30);
	glVertex2d(-50, -45);
	glVertex2d(20, -45);
	glVertex2d(20, -30);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2d(-30, -15);
	glVertex2d(-30, -30);
	glVertex2d(40, -30);
	glVertex2d(40, -15);
	glEnd();
}

//Main building 
void building() {
	glBegin(GL_POLYGON);
	glColor3f(0.482, 0.408, 0.933);
	glVertex2d(-60, 100);
	glVertex2d(-60, -10);
	glVertex2d(50, -10);
	glVertex2d(50, 100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2d(-70, 105);
	glVertex2d(-70, 100);
	glVertex2d(60, 100);
	glVertex2d(60, 105);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.482, 0.408, 0.933);
	glVertex2d(-60, 130);
	glVertex2d(-60, 105);
	glVertex2d(50, 105);
	glVertex2d(50, 130);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.737, 0.561, 0.561);
	glVertex2d(-5, 160);
	glVertex2d(-70, 130);
	glVertex2d(60, 130);
	glEnd();
}
//Callback function
void display()
{
	//Tells OpenGL to use default color
	//Clear frame buffer
	glClear(GL_COLOR_BUFFER_BIT);
	//Reset transformations, rotations, coordinate system
	glLoadIdentity();
	//draw
	sun();
	cloud();
	soil();
	ground();
	tree1();
	tree2();
	building();
	steps();
	fence();
	pavement();

	road();
	//Display frame buffer
	glutSwapBuffers();
	//glFlush();
}
void reshape(int w, int h)
{
	//lower left corner to right and the top
	glViewport(0, 0, w, h);
	//Projection -Default matrix ModelViewMitrix
	// Projection specifies how vertices are displayed on the screen
	glMatrixMode(GL_PROJECTION);
	//Reset matrix
	glLoadIdentity();
	glOrtho(-300, 300, -300, 300, -150, 500);
	glMatrixMode(GL_MODELVIEW);
}
void init()
{
	// Only set the color but doesn't tell OpenGL to use it
	//Default background color RGB
	glClearColor(0.3, .65, 1, 1.0);
}

int main(int argc, char **argv) {
	// Startup freeglut
	glutInit(&argc, argv);

	//single buffer 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//Window Size
	glutInitWindowSize(500, 500);

	// from top left
	// screen coordinates in pixels
	glutInitWindowPosition(0, 0);

	//Creates the window
	glutCreateWindow("Computer Graphics Project: Group 8");

	init();

	//Display Callback function every time we render the display/ draw a frame
	glutDisplayFunc(display);
	glutIdleFunc(display);
	//Any the window changes size
	//Viewport initialization
	glutReshapeFunc(reshape);

	// prevents window from closing
	//Keeps the program running
	glutMainLoop();

	return 0;
}

