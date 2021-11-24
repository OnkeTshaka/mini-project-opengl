//Apple
#ifdef __APPLE__
#include <GL/glut.h>
#else
#include <GL/glut.h>
#endif

#include<windows.h>
#include <stdlib.h>
#include<math.h>
#include <iostream>
#pragma comment(lib, "Winmm.lib")
#include <mmsystem.h>

static float	tp3 = 0;
static float	pm = 300.0;
static float	bm = 350.0;
static float	tm = 300.0;
static float	cm = -300.0;
double var = -6;
float spin = 0.0;
GLfloat	tx = 5;
GLfloat	ty = 5;
double rainX = -6;
double rainY;
bool NightRain = false;
double SpeedUp;
bool freeze = false;
bool VelocityUp = false;
float _angle = 0.0;
double carex = 0;






// Colours
double PavementColor[3] = { 105,105,105 };
double sunlight[3] = { 219,230,21 };
double cloudColor[3] = { 255,255,255 };
double windowColor[3] = { 0,0,0 };
double buildingColor[3] = { 147,112,219 };
double buildingColor2[3] = { 184,134,11 };
double buildingUnitColor1[3] = { 184,134,11 };
double buildingUnitColor2[3] = { 248,248,255 };
double buildingUnitColor3[3] = { 65,105,225 };
double grassColor[3] = { 34,139,34 };
double tankColor[3] = { 139,69,9 };
double bulbColor[3] = { 255,255,255 };

bool night = false;
bool sunrise = false;

//Abstract functions
void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
	int i;
	float rad = 0;
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	for (i = 0; i <= 360; i++) {
		rad = i * (3.1416 / 180);
		glVertex2f(x + rx * cos(rad), y + ry * sin(rad));

	}
	glEnd();


}
void drawstring(float x, float y, float z, const char* string)
{
	const char* ct;
	glRasterPos3f(x, y, z);

	for (ct = string; *ct != '\0'; ct++)
	{
		glColor3f(0.0, 0.0, 0.0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *ct);
	}
}
void star(float x1, float y1, float distance, float height)
{
	float x2 = x1 + distance, y2 = y1, x3 = x2, y3 = y2 + distance, x4 = x1, y4 = y3;


	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);

	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
	glBegin(GL_TRIANGLES);
	//bottom
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1 + (distance / 2), y2 - height);
	//right
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x2 + height, y2 + (distance / 2));
	//top
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glVertex2f(x1 + (distance / 2), y4 + height);
	//left
	glVertex2f(x4, y4);
	glVertex2f(x1, y1);
	glVertex2f(x1 - height, y1 + (distance / 2));
	glEnd();

}
void rectangle(int x, int y, int x1, int y1)
{
	//GL_QUADS - connected group of 4 VERTICES AS A QUAD
	glBegin(GL_QUADS);
	//2nd quad
	glVertex2d(x, y);
	//3rd quad
	glVertex2d(x, y1);
	//4th quad
	glVertex2d(x1, y1);
	//1st quad
	glVertex2d(x1, y);


	glEnd();
}
void triangle(int x, int y, int x1, int x2, int y1)
{
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

void update(int value)
{

	if (freeze == true) {
		_angle += 0.0f;
	}
	else if (sunrise == true) {

		if (VelocityUp == true) {
			_angle -= 0.01f;
		}
		else {
			_angle -= 0.001f;
		}

		if (_angle < 0.0f) {

			sunrise = false;
		}
	}
	else if (VelocityUp == false) {
		_angle += 0.001f;

	}
	else if (VelocityUp == true) {
		_angle += 0.01f;
	}



	if (_angle > 2.27f) {
		sunrise = true;


	}



	glutPostRedisplay(); //Tell GLUT that the display has changed

						 //Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

double setUpSpeed(double z) {

	if (freeze == true) {

		return 0.0;
	}

	else if (freeze == false) {

		if (VelocityUp == true) {
			double x = 0.2f;

			return x;

		}

		if (VelocityUp == false)
		{

			return z;

		}
	}
}

bool Rain = false;
double rain = 0;

double car1 = 0;


void make_cloud(int x, int y)
{

	glColor3ub(cloudColor[0], cloudColor[1], cloudColor[2]);
	//glColor3f(1.0, 1.0, 1.0);
	circle(10, 10, x, y);
	circle(10, 10, x + 10, y);
	circle(10, 10, x + 30, y);
	circle(10, 10, x + 5, y - 10);
	circle(10, 10, x + 20, y - 10);
	circle(10, 10, x + 5, y + 10);
	circle(10, 10, x + 20, y + 10);

}
void sun()
{
	glPushMatrix();
	glTranslated(240, 260, 0);
	glColor3ub(sunlight[0], sunlight[1], sunlight[2]);
	circle(15, 30, 0, 0);
	glPopMatrix();
}
void cloud_move_right(GLfloat t) {
	tp3 = tp3 + t;
	if (tp3 > 600)
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


	glColor3ub(tankColor[0], tankColor[1], tankColor[2]);
	rectangle1(10, -130, 30, -130, 10, -30, 30, -30);
	rectangle1(10, -30, 17, -30, 5, 0, 5, 0);
	rectangle1(17, -30, 22, -30, 19, 0, 19, 0);
	rectangle1(22, -30, 30, -30, 35, 0, 35, 0);
	rectangle1(30, -90, 30, -100, 55, -70, 55, -75);



}
void soil()
{
	glColor3f(0.75, 0.75, 0.75);
	rectangle(-300, -10, 300, 130);
}


void ground()
{
	glColor3ub(grassColor[0], grassColor[1], grassColor[2]);
	//glColor3f(0.3, 1.0, 0.53);
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
	//glColor3f(0.957, 0.643, 0.376);
	glColor3ub(PavementColor[0], PavementColor[1], PavementColor[2]);
	glVertex2d(-300, -170);
	glVertex2d(-300, -185);
	glVertex2d(300, -185);
	glVertex2d(300, -170);
	glEnd();
	glLineWidth(1);

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2d(-300, -170);
	glVertex2d(300, -170);
	glEnd();

	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2d(-300, -180);
	glVertex2d(300, -180);
	glEnd();


	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2d(-300, -175);
	glVertex2d(300, -175);
	glEnd();

	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2d(-300, -185);
	glVertex2d(300, -185);
	glEnd();

	for (int i = -300; i < 300; i = i + 8)
	{
		glLineWidth(1);
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2d(i, -175);
		glVertex2d(i, -180);
		glEnd();
	}

}

void fence() {

	glBegin(GL_QUADS);
	glColor3f(0.941, 0.973, 1.000);

	glVertex2d(-300, -80);

	glVertex2d(-300, -150);
	glVertex2d(-200, -150);
	glVertex2d(-200, -80);
	glEnd();
	glColor3f(0, 0, 0);
	drawstring(-290, -120, 0.0, "Ritson Campus");


	glBegin(GL_LINE);
	glColor3f(0, 0, 0);
	glVertex2d(-20, -40);
	glVertex2d(20, -40);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.941, 0.973, 1.000);

	glVertex2d(20, -40);
	glVertex2d(20, -110);
	glVertex2d(35, -110);
	glVertex2d(35, -40);

	glEnd();

	// small wall
	glBegin(GL_POLYGON);
	glColor3f(0.941, 0.973, 1.000);

	glVertex2d(35, -75);
	glVertex2d(35, -110);
	glVertex2d(60, -110);
	glVertex2d(60, -75);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.941, 0.973, 1.000);

	glVertex2d(60, -40);
	glVertex2d(60, -110);
	glVertex2d(100, -150);
	glVertex2d(100, -80);
	glEnd();
	//shadow
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2d(60, -40);
	glVertex2d(70, -40);
	glVertex2d(100, -70);
	glVertex2d(100, -80);

	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.941, 0.973, 1.000);

	glVertex2d(300, -80);
	glVertex2d(300, -150);
	glVertex2d(100, -150);
	glVertex2d(100, -80);
	glEnd();
	//shadow
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);

	glVertex2d(300, -70);

	glVertex2d(300, -80);
	glVertex2d(100, -80);
	glVertex2d(100, -70);
	glEnd();
}
//Stairs
void steps() {
	glColor3f(0.941, 0.973, 1.000);
	rectangle(-150, -75, -125, -110);

	glColor3f(0.941, 0.973, 1.000);
	rectangle(-125, -40, -110, -110);

	glBegin(GL_QUADS);
	glColor3f(0.941, 0.973, 1.000);

	glVertex2d(-200, -80);
	glVertex2d(-200, -150);
	glVertex2d(-150, -110);
	glVertex2d(-150, -40);

	glEnd();

	//shadow
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);

	glVertex2d(-200, -70);
	glVertex2d(-200, -80);
	glVertex2d(-150, -40);
	glVertex2d(-163, -40);
	glEnd();

	//shadow
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);

	glVertex2d(-300, -70);

	glVertex2d(-300, -80);
	glVertex2d(-200, -80);
	glVertex2d(-200, -70);
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2d(-90, -60);
	glVertex2d(-90, -75);
	glVertex2d(0, -75);
	glVertex2d(0, -60);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2d(-70, -45);
	glVertex2d(-70, -60);
	glVertex2d(10, -60);
	glVertex2d(10, -45);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
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



//First building on the left
void hall()
{
	glColor3ub(buildingColor[0], buildingColor[1], buildingColor[2]);
	rectangle(-240, 130, -160, -10);
	//Door
	glColor3f(0, 0, 0);
	rectangle(-210, 30, -190, -10);

	//Strip
	glColor3f(0.824, 0.706, 0.549);
	rectangle(-240, 100, -160, 90);
	//Strip
	glColor3f(0.824, 0.706, 0.549);
	rectangle(-240, 80, -160, 70);

	//Strip
	glColor3f(0.824, 0.706, 0.549);
	rectangle(-240, 60, -160, 50);
}
//building in the middle 
void building() {
	glBegin(GL_POLYGON);
	glColor3ub(buildingColor2[0], buildingColor2[1], buildingColor2[2]);
	rectangle(-60, 100, 50, -10);

	glColor3f(1, 1, 1);
	rectangle(-70, 105, 60, 100);

	glColor3ub(buildingColor2[0], buildingColor2[1], buildingColor2[2]);
	rectangle(-60, 130, 50, 105);

	glBegin(GL_TRIANGLES);
	glColor3f(0.737, 0.561, 0.561);
	glVertex2d(-5, 160);
	glVertex2d(-70, 130);
	glVertex2d(60, 130);
	glEnd();

	//inner house
	glColor3f(0, 0, 0);
	rectangle(-20, 50, 10, -10);

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);
	glVertex2d(-5, 65);
	glVertex2d(-25, 50);
	glVertex2d(15, 50);
	glEnd();

	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(-50, 50, -30, 15);

	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(-50, 90, -30, 60);

	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(40, 90, 20, 60);

	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(40, 50, 20, 15);
}
//last building on the right
void lectureRoom()
{
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2d(145, 73);
	glVertex2d(145, -65);
	glVertex2d(155, -65);
	glVertex2d(155, 85);
	glEnd();


	glColor3ub(buildingUnitColor1[0], buildingUnitColor1[1], buildingUnitColor1[2]);
	rectangle(155, 85, 200, -65);

	glColor3ub(buildingUnitColor2[0], buildingUnitColor2[1], buildingUnitColor2[2]);
	rectangle(200, 85, 245, -65);

	glColor3ub(buildingUnitColor3[0], buildingUnitColor3[1], buildingUnitColor3[2]);
	rectangle(245, 85, 290, -65);

	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(165, 65, 185, 35);

	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(165, 25, 185, -5);

	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(165, -15, 185, -42);

	//second set of windows
	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(210, 65, 230, 35);

	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(210, 25, 230, -5);

	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(210, -15, 230, -42);

	//Final set of windows
	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(255, 65, 275, 35);

	//window
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(255, 25, 275, -5);

	//window
	glBegin(GL_POLYGON);
	glColor3ub(windowColor[0], windowColor[1], windowColor[2]);
	rectangle(255, -15, 275, -42);
}

//function for the gate
void gate() {
	//bars on the left
	for (int i = -150; i < -125; i = i + 6)
	{
		glLineWidth(3);
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2d(i, -75);
		glVertex2d(i, -40);
		glEnd();
	}
	//bars on left
	for (int i = 35; i < 60; i = i + 6)
	{

		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2d(i, -75);
		glVertex2d(i, -40);
		glEnd();
	}
	glBegin(GL_POLYGON);
	glColor3f(0.863, 0.078, 0.235);
	//2nd Quad
	glVertex2d(-110, -40);
	//3rd Quad
	glVertex2d(-110, -110);
	//4th Quad
	glVertex2d(-90, -90);
	//1st Quad
	glVertex2d(-90, -30);

	glEnd();


	//Main gate
	glLineWidth(4);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2d(-50, -110);
	glVertex2d(-50, -40);
	glVertex2d(20, -40);
	glVertex2d(20, -110);
	glEnd();
	for (int i = -50; i < 20; i = i + 6)
	{

		glLineWidth(2);
		glBegin(GL_LINES);


		glColor3f(0, 0, 0);
		glVertex2d(i, -110);
		glVertex2d(i, -40);
		glEnd();
	}
}
void road()
{

	//Road Area
	//glColor3f(0.3, 0.3, 0.3);
	glColor3ub(30, 40, 50);
	rectangle(-300, -300, 300, -185);

	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(-290, -235, -260, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(-250, -235, -220, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(-210, -235, -180, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(-170, -235, -140, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(-130, -235, -100, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(-90, -235, -60, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(-50, -235, -20, -245);

	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(-10, -235, 20, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(30, -235, 60, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(70, -235, 100, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(110, -235, 140, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(150, -235, 180, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(190, -235, 220, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(230, -235, 260, -245);
	//divider
	glColor3f(1.0, 1.0, 1.0);
	rectangle(270, -235, 296, -245);


}

// functions for the bus
void busmake()
{
	glColor3f(0.9, 0.72, 0.0);
	rectangle(-60, -15, 0, 15);
	rectangle(-80, -15, -60, 25);
	glColor3f(0, 0, 0);
	rectangle(-60, 15, -2, 50);
	rectangle(-70, 25, -60, 50);
	glColor3f(0.76, 0.84, 0.84);
	rectangle1(-2, 50, -70, 50, -7, 55, -76, 55);

	glColor3f(0.2, 0.8, 1.0);
	rectangle1(-70, 25, -74, 25, -70, 50, -76, 55);

	glColor3f(1, 1, 1.0);
	rectangle(-58, 0, -50, 35);
	glColor3f(0.2, 0.8, 1.0);
	rectangle(-45, 30, -40, 40);
	rectangle(-35, 30, -30, 40);
	rectangle(-25, 30, -20, 40);
	rectangle(-15, 30, -10, 40);


	glColor3f(0.9, 0.72, 0.0);
	circle(3, 15, 0, 0);
	circle(3, 20, -80, 5);

	glColor3f(0, 0, 0);
	circle(8, 16, -10, -15);
	circle(8, 16, -70, -15);

	glColor3f(1, 1, 1);
	circle(6, 12, -10, -15);
	circle(6, 12, -70, -15);

}

void busMove() {
	bm = bm - .4;
	if (bm < -350)
		bm = 350;

	glutPostRedisplay();
}

void bus()
{
	glPushMatrix();
	glTranslatef(bm, -185, 0);
	busmake();
	glPopMatrix();
}
void wheel(float k, float m, float rad)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++)
	{
		glColor3f(1.0, 1.0, 1.0);
		float pi = 3.1416;
		float A = (i * 2 * pi) / 100;
		float r = rad - 0.25; //1.5
		float x = k + r * cos(A);
		float y = m + r * sin(A);
		glVertex3f(x, y, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++)
	{
		glColor3f(0.0, 0.0, 0.0);
		float pi = 3.1416;
		float A = (i * 2 * pi) / 100;
		float r = rad;
		float x = k + r * cos(A);
		float y = m + r * sin(A);
		glVertex3f(x, y, 0);
	}
	glEnd();
}

//Callback function
void dayMode()
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
	hall();
	building();
	lectureRoom();
	steps();
	gate();
	fence();
	//lamppost();
	pavement();
	road();

	bus();
	//Display frame buffer
	glFlush();
	glutSwapBuffers();

}


//changes windows size
//Viewport initialization
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










//Keyboard Function
void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

	case 'w':
		glutIdleFunc(busMove);
		VelocityUp = false;

		break;
	case 'b':
		glutIdleFunc(NULL);
		break;
	case 'v':
		VelocityUp = true;
		break;

	case 'n':
		night = true;
		if (night) {
			glClearColor(0.412, 0.412, 0.412, 1.0);
			cloudColor[0] = 125;
			cloudColor[1] = 125;
			cloudColor[2] = 125;
			sunlight[0] = 255;
			sunlight[1] = 255;
			sunlight[2] = 255;
			buildingColor[0] = 25;
			buildingColor[1] = 25;
			buildingColor[2] = 112;
			buildingColor2[0] = 25;
			buildingColor2[1] = 25;
			buildingColor2[2] = 112;

			buildingUnitColor1[0] = 25;
			buildingUnitColor1[1] = 25;
			buildingUnitColor1[2] = 112;
			buildingUnitColor2[0] = 25;
			buildingUnitColor2[1] = 25;
			buildingUnitColor2[2] = 112;
			buildingUnitColor3[0] = 25;
			buildingUnitColor3[1] = 25;
			buildingUnitColor3[2] = 112;
			grassColor[0] = 85;
			grassColor[1] = 107;
			grassColor[2] = 47;

			tankColor[0] = 47;
			tankColor[1] = 79;
			tankColor[2] = 79;
			PavementColor[0] = 68;
			PavementColor[1] = 142;
			PavementColor[2] = 201;
			windowColor[0] = 237;
			windowColor[1] = 237;
			windowColor[2] = 187;

			bulbColor[0] = 219;
			bulbColor[1] = 230;
			bulbColor[2] = 21;
			star(5, 97, 0.4, 0.8);
			star(10, 66, 0.4, 0.8);
			star(25, 90, 0.4, 0.8);
			star(30, 71, 0.4, 0.8);
			star(45, 95, 0.4, 0.8);
			star(60, 75, 0.4, 0.8);
			star(76, 65, 0.4, 0.8);
			star(86, 85, 0.4, 0.8);

			PlaySound(TEXT("night.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

		}

		break;


	case 'd':
		sunrise = true;
		if (sunrise) {
			glClearColor(0.3, .65, 1, 1.0);
			cloudColor[0] = 255;
			cloudColor[1] = 255;
			cloudColor[2] = 255;
			sunlight[0] = 219;
			sunlight[1] = 230;
			sunlight[2] = 21;
			bulbColor[0] = 255;
			bulbColor[1] = 255;
			bulbColor[2] = 255;
			buildingColor[0] = 147;
			buildingColor[1] = 112;
			buildingColor[2] = 219;
			buildingColor2[0] = 184;
			buildingColor2[1] = 134;
			buildingColor2[2] = 11;
			buildingUnitColor1[0] = 184;
			buildingUnitColor1[1] = 134;
			buildingUnitColor1[2] = 11;
			buildingUnitColor2[0] = 248;
			buildingUnitColor2[1] = 248;
			buildingUnitColor2[2] = 255;
			buildingUnitColor3[0] = 65;
			buildingUnitColor3[1] = 105;
			buildingUnitColor3[2] = 225;
			tankColor[0] = 139;
			tankColor[1] = 69;
			tankColor[2] = 9;
			grassColor[0] = 34;
			grassColor[1] = 139;
			grassColor[2] = 34;
			PavementColor[0] = 105;
			PavementColor[1] = 105;
			PavementColor[2] = 105;
			windowColor[0] = 0;
			windowColor[1] = 0;
			windowColor[2] = 0;

			PlaySound(TEXT("sun.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

		}

		break;

	default:
		break;
	}
}
void spe_key(int key, int x, int y)
{

	switch (key) {

	case GLUT_KEY_UP:
		ty += 5;
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN:

		ty -= 5;
		glutPostRedisplay();
		break;

	case GLUT_KEY_RIGHT:
		tx += 5;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		tx -= 5;
		glutPostRedisplay();
		break;



	default:
		break;
	}
}
void init()
{
	//Default background color RGB
	glClearColor(0.3, .65, 1, 1.0);
}
//Entry function
int main(int argc, char** argv) {
	// Startup freeglut
	glutInit(&argc, argv);
	//single buffer 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//Window Size
	glutInitWindowSize(1000, 650);
	// screen coordinates in pixels
	glutInitWindowPosition(0, 0);

	//Creates the window
	glutCreateWindow("OpenGL mini Project: Group 8");
	init();
	//Display Callback function every time we render the display/ draw a frame
	glutDisplayFunc(dayMode);
	glutSpecialFunc(spe_key);
	glutKeyboardFunc(my_keyboard);
	//Any the window changes size
	//Viewport initialization
	glutReshapeFunc(reshape);
	// prevents window from closing
	//Keeps the program running
	glutMainLoop();

	return 0;
}

