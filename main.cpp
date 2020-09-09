#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <math.h>
#define SPEED 30.0

float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0;
static GLfloat t = 0.0,b_r_v=-0.0,t_r_v= 0.0;
int p=1,day=1,plane=0,comet=0, l;
char ch;

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 1500.0, 0.0, 700.0);
}

void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void draw_pixel(GLint cx, GLint cy)
{
	glBegin(GL_POINTS);
    glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

void objects(void)
{
    if(day==1)
    {
    //sky
    glColor3ub(138, 173, 242);
    glBegin(GL_POLYGON);
    glVertex2f(0,380);
    glVertex2f(0,700);
    glVertex2f(1500,700);
    glVertex2f(1500,380);
    glEnd();

    //sun
    for(l=0;l<=30;l++)
    {
        glColor3f(1.0,0.9,0.0);
        draw_circle(100,625,l);
        draw_circle(105,625,l);
    }

    // plane
    if(plane==1)
    {
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(1325+n,625+o);
        glVertex2f(1350+n,640+o);
        glVertex2f(1415+n,640+o);
        glVertex2f(1430+n,650+o);
        glVertex2f(1450+n,650+o);
        glVertex2f(1410+n,625+o);
        glEnd();

        glColor3f(0.8,0.8,0.8);
        glBegin(GL_LINE_LOOP);
        glVertex2f(1325+n,625+o);
        glVertex2f(1350+n,640+o);
        glVertex2f(1415+n,640+o);
        glVertex2f(1430+n,650+o);
        glVertex2f(1450+n,650+o);
        glVertex2f(1410+n,625+o);
        glEnd();

    }
        //cloud 1
        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(160+m,625,l);
        }
        for(l=0;l<=35;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(200+m,625,l);
            draw_circle(225+m,625,l);
        }
        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(265+m,625,l);
        }

        //cloud 2
        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(370+m,615,l);
        }
        for(l=0;l<=35;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(410+m,615,l);
            draw_circle(435+m,615,l);
            draw_circle(470+m,615,l);
        }
        for(l=0;l<=20;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(500+m,615,l);
        }
    }
    else
    {
        //sky
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,380);
        glVertex2f(0,700);
        glVertex2f(1500,700);
        glVertex2f(1500,380);
        glEnd();

        //moon
        for(l=0;l<=30;l++)
        {
            glColor3f(1.0,1.0,1.0);
            draw_circle(100,625,l);
            draw_circle(105,625,l);
        }

        //star1
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(575,653);
        glVertex2f(570,645);
        glVertex2f(580,645);
        glVertex2f(575,642);
        glVertex2f(570,650);
        glVertex2f(580,650);
        glEnd();

        //star2
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(975,643);
        glVertex2f(970,635);
        glVertex2f(980,635);
        glVertex2f(975,632);
        glVertex2f(970,640);
        glVertex2f(980,640);
        glEnd();

        //star3
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(875,543);
        glVertex2f(870,535);
        glVertex2f(880,535);
        glVertex2f(875,532);
        glVertex2f(870,540);
        glVertex2f(880,540);
        glEnd();

        //star4
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(375,598);
        glVertex2f(370,590);
        glVertex2f(380,590);
        glVertex2f(375,587);
        glVertex2f(370,595);
        glVertex2f(380,595);
        glEnd();

        //star5
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(750,628);
        glVertex2f(745,620);
        glVertex2f(755,620);
        glVertex2f(750,618);
        glVertex2f(745,625);
        glVertex2f(755,625);
        glEnd();

        //star6
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(200,628);
        glVertex2f(195,620);
        glVertex2f(205,620);
        glVertex2f(200,618);
        glVertex2f(195,625);
        glVertex2f(205,625);
        glEnd();

        //star7
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(100,528);
        glVertex2f(95,520);
        glVertex2f(105,520);
        glVertex2f(100,518);
        glVertex2f(95,525);
        glVertex2f(105,525);
        glEnd();

        //star8
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(300,468);
        glVertex2f(295,460);
        glVertex2f(305,460);
        glVertex2f(300,458);
        glVertex2f(295,465);
        glVertex2f(305,465);
        glEnd();

        //star9
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(500,543);
        glVertex2f(495,535);
        glVertex2f(505,535);
        glVertex2f(500,532);
        glVertex2f(495,540);
        glVertex2f(505,540);
        glEnd();

        //comet
        if(comet==1)
        {
            for(l=0;l<=7;l++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(300+c,675,l);
            }

            glColor3f(1.0,1.0,1.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(200+c,675);
            glVertex2f(300+c,682);
            glVertex2f(300+c,668);
            glEnd();
        }

        //Plane
        if(plane==1)
        {
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_POLYGON);
            glVertex2f(1325+n,625+o);
            glVertex2f(1350+n,640+o);
            glVertex2f(1415+n,640+o);
            glVertex2f(1430+n,650+o);
            glVertex2f(1450+n,650+o);
            glVertex2f(1410+n,625+o);
            glEnd();

            glColor3f(0.8,0.8,0.8);
            glBegin(GL_LINE_LOOP);
            glVertex2f(1325+n,625+o);
            glVertex2f(1350+n,640+o);
            glVertex2f(1415+n,640+o);
            glVertex2f(1430+n,650+o);
            glVertex2f(1450+n,650+o);
            glVertex2f(1410+n,625+o);
            glEnd();
        }
    }

    //green background
	glColor3f(0.6,0.8,0.196078);
	glBegin(GL_QUADS);
    glVertex2i(0,380);
    glVertex2i(1500,380);
    glVertex2i(1500,425);
    glVertex2i(0,425);
    glEnd();
}

void building(void)
{
    // Building 1
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2i(170,380);
    glVertex2i(170,460);
    glVertex2i(270,460);
    glVertex2i(270,380);
    glEnd();

    // Black lines
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2i(210,380);
    glVertex2i(210,460);
    glVertex2i(230,460);
    glVertex2i(230,380);

    glVertex2i(170,400);
    glVertex2i(170,420);
    glVertex2i(270,420);
    glVertex2i(270,400);

    glVertex2i(170,440);
    glVertex2i(170,455);
    glVertex2i(270,455);
    glVertex2i(270,440);
    glEnd();

    // Building 2
    glColor3f(0.6,0.7,0.6);
    glBegin(GL_QUADS);
    glVertex2i(275,380);
    glVertex2i(275,465);
    glVertex2i(470,465);
    glVertex2i(470,380);
    glEnd();

    //door
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(350,380);
    glVertex2i(350,415);
    glVertex2i(395,415);
    glVertex2i(395,380);
    glEnd();

    // bottom black border
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(275,464);
    glVertex2i(275,465);
    glVertex2i(470,465);
    glVertex2i(470,464);
    glEnd();

    //f2
    glColor3f(0.6,0.7,0.6);
    glBegin(GL_QUADS);
    glVertex2i(310,465);
    glVertex2i(310,515);
    glVertex2i(435,515);
    glVertex2i(435,465);
    glEnd();

    // top black border
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(275,515);
    glVertex2i(275,517);
    glVertex2i(470,517);
    glVertex2i(470,515);
    glEnd();

    //w1
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(355,485);
    glVertex2i(355,500);
    glVertex2i(390,500);
    glVertex2i(390,485);
    glEnd();

    // Building 3
    glColor3f(0.5,0.5,1);
    glBegin(GL_QUADS);
    glVertex2i(690,380);
    glVertex2i(690,560);
    glVertex2i(910,560);
    glVertex2i(910,380);
    glEnd();

    //door
    glColor3f(0,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(770,380);
    glVertex2i(770,425);
    glVertex2i(810,425);
    glVertex2i(810,380);
    glEnd();

    //side
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(908,380);
    glVertex2i(908,560);
    glVertex2i(910,560);
    glVertex2i(910,380);
    glEnd();

    //b1
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(690,545);
    glVertex2i(690,560);
    glVertex2i(910,560);
    glVertex2i(910,545);
    glEnd();

    //b2
    glColor3f(0.5,0.5,.5);
    glBegin(GL_QUADS);
    glVertex2i(690,500);
    glVertex2i(690,515);
    glVertex2i(910,515);
    glVertex2i(910,500);
    glEnd();

    //b3
    glColor3f(0.5,0.5,.5);
    glBegin(GL_QUADS);
    glVertex2i(690,455);
    glVertex2i(690,470);
    glVertex2i(910,470);
    glVertex2i(910,455);
    glEnd();

    //backward
    glColor3f(0.5,0.5,1);
    glBegin(GL_QUADS);
    glVertex2i(910,380);
    glVertex2i(910,560);
    glVertex2i(970,590);
    glVertex2i(970,425);
    glEnd();

    //b1
    glColor3f(0.5,0.5,.5);
    glBegin(GL_QUADS);
    glVertex2i(910,545);
    glVertex2i(910,560);
    glVertex2i(970,590);
    glVertex2i(970,575);
    glEnd();

    //b2
    glColor3f(0.5,0.5,.5);
    glBegin(GL_QUADS);
    glVertex2i(910,500);
    glVertex2i(910,515);
    glVertex2i(970,545);
    glVertex2i(970,530);
    glEnd();

    //b3
    glColor3f(0.5,0.5,.5);
    glBegin(GL_QUADS);
    glVertex2i(910,455);
    glVertex2i(910,470);
    glVertex2i(970,500);
    glVertex2i(970,485);
    glEnd();

    //up
    glColor3f(0.5,0.5,1);
    glBegin(GL_QUADS);
    glVertex2i(690,560);
    glVertex2i(750,590);
    glVertex2i(970,590);
    glVertex2i(910,560);
    glEnd();

    // Building 4
    glColor3f(0.8,0.2,0);
    glBegin(GL_QUADS);
    glVertex2i(980,380);
    glVertex2i(980,560);
    glVertex2i(1195,560);
    glVertex2i(1195,380);
    glEnd();

   //door
    glColor3f(.8,.8,.8);
    glBegin(GL_QUADS);
    glVertex2i(1050,380);
    glVertex2i(1050,425);
    glVertex2i(1130,425);
    glVertex2i(1130,380);
    glEnd();

    glColor3f(.5,.5,.5);
    glBegin(GL_QUADS);
    glVertex2i(1089,380);
    glVertex2i(1089,425);
    glVertex2i(1091,425);
    glVertex2i(1091,380);
    glEnd();

    //w1
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(990,515);
    glVertex2i(990,545);
    glVertex2i(1010,545);
    glVertex2i(1010,515);
    glEnd();

     //w2
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1020,515);
    glVertex2i(1020,545);
    glVertex2i(1040,545);
    glVertex2i(1040,515);
    glEnd();

     //w3
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1050,515);
    glVertex2i(1050,545);
    glVertex2i(1070,545);
    glVertex2i(1070,515);
    glEnd();

     //w4
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1080,515);
    glVertex2i(1080,545);
    glVertex2i(1100,545);
    glVertex2i(1100,515);
    glEnd();

     //w5
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1110,515);
    glVertex2i(1110,545);
    glVertex2i(1130,545);
    glVertex2i(1130,515);
    glEnd();

      //w6
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1140,515);
    glVertex2i(1140,545);
    glVertex2i(1160,545);
    glVertex2i(1160,515);
    glEnd();

      //w5
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1170,515);
    glVertex2i(1170,545);
    glVertex2i(1190,545);
    glVertex2i(1190,515);
    glEnd();

      //row2
     //w1
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(990,455);
    glVertex2i(990,485);
    glVertex2i(1010,485);
    glVertex2i(1010,455);
    glEnd();

      //w2
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1020,455);
    glVertex2i(1020,485);
    glVertex2i(1040,485);
    glVertex2i(1040,455);
    glEnd();

     //w3
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1050,455);
    glVertex2i(1050,485);
    glVertex2i(1070,485);
    glVertex2i(1070,455);
    glEnd();

     //w4
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1080,455);
    glVertex2i(1080,485);
    glVertex2i(1100,485);
    glVertex2i(1100,455);
    glEnd();

     //w5
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1110,455);
    glVertex2i(1110,485);
    glVertex2i(1130,485);
    glVertex2i(1130,455);
    glEnd();

      //w6
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1140,455);
    glVertex2i(1140,485);
    glVertex2i(1160,485);
    glVertex2i(1160,455);
    glEnd();

      //w7
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1170,455);
    glVertex2i(1170,485);
    glVertex2i(1190,485);
    glVertex2i(1190,455);
    glEnd();

    //row3
    //w1
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(990,395);
    glVertex2i(990,425);
    glVertex2i(1010,425);
    glVertex2i(1010,395);
    glEnd();

      //w2
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1020,395);
    glVertex2i(1020,425);
    glVertex2i(1040,425);
    glVertex2i(1040,395);
    glEnd();

       //w3
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1140,395);
    glVertex2i(1140,425);
    glVertex2i(1160,425);
    glVertex2i(1160,395);
    glEnd();

      //w4
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1170,395);
    glVertex2i(1170,425);
    glVertex2i(1190,425);
    glVertex2i(1190,395);
    glEnd();

    // top board
    glColor3f(.5,.5,.5);
    glBegin(GL_QUADS);
    glVertex2i(1040,555);
    glVertex2i(1040,580);
    glVertex2i(1140,580);
    glVertex2i(1140,555);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(1045,560);
    declare("College");

    // Building 5
    glColor3f(0.6,0.7,0.6);
    glBegin(GL_QUADS);
    glVertex2i(1200,380);
    glVertex2i(1200,600);
    glVertex2i(1400,600);
    glVertex2i(1400,380);
    glEnd();

    //w1
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1210,525);
    glVertex2i(1210,545);
    glVertex2i(1230,545);
    glVertex2i(1230,525);
    glEnd();

    //w2
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1240,525);
    glVertex2i(1240,545);
    glVertex2i(1260,545);
    glVertex2i(1260,525);
    glEnd();

    //w3
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1270,525);
    glVertex2i(1270,545);
    glVertex2i(1290,545);
    glVertex2i(1290,525);
    glEnd();
    //w4
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1320,525);
    glVertex2i(1320,545);
    glVertex2i(1340,545);
    glVertex2i(1340,525);
    glEnd();

    //w5
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1350,525);
    glVertex2i(1350,545);
    glVertex2i(1370,545);
    glVertex2i(1370,525);
    glEnd();

    //w6
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1378,525);
    glVertex2i(1378,545);
    glVertex2i(1398,545);
    glVertex2i(1398,525);
    glEnd();

    //w1
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1210,565);
    glVertex2i(1210,585);
    glVertex2i(1230,585);
    glVertex2i(1230,565);
    glEnd();

    //w2
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1240,565);
    glVertex2i(1240,585);
    glVertex2i(1260,585);
    glVertex2i(1260,565);
    glEnd();

    //w3
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1270,565);
    glVertex2i(1270,585);
    glVertex2i(1290,585);
    glVertex2i(1290,565);
    glEnd();

    //w4
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1320,565);
    glVertex2i(1320,585);
    glVertex2i(1340,585);
    glVertex2i(1340,565);
    glEnd();

    //w5
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1350,565);
    glVertex2i(1350,585);
    glVertex2i(1370,585);
    glVertex2i(1370,565);
    glEnd();

    //w6
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1378,565);
    glVertex2i(1378,585);
    glVertex2i(1398,585);
    glVertex2i(1398,565);
    glEnd();

    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1295,380);
    glVertex2i(1295,600);
    glVertex2i(1315,600);
    glVertex2i(1315,380);
    glEnd();

    glColor3f(0.8,0.6,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1240,380);
    glVertex2i(1240,510);
    glVertex2i(1260,510);
    glVertex2i(1260,380);
    glEnd();

    glColor3f(0.8,0.6,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1200,500);
    glVertex2i(1260,500);
    glVertex2i(1260,515);
    glVertex2i(1200,515);
    glEnd();

    //w1
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1210,385);
    glVertex2i(1210,395);
    glVertex2i(1230,395);
    glVertex2i(1230,385);
    glEnd();

    //w2
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1210,405);
    glVertex2i(1210,415);
    glVertex2i(1230,415);
    glVertex2i(1230,405);
    glEnd();

    //w3
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1210,425);
    glVertex2i(1210,435);
    glVertex2i(1230,435);
    glVertex2i(1230,425);
    glEnd();

    //w4
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1210,445);
    glVertex2i(1210,455);
    glVertex2i(1230,455);
    glVertex2i(1230,445);
    glEnd();

    //w5
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1210,465);
    glVertex2i(1210,475);
    glVertex2i(1230,475);
    glVertex2i(1230,465);
    glEnd();

    //w6
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1210,485);
    glVertex2i(1210,495);
    glVertex2i(1230,495);
    glVertex2i(1230,485);
    glEnd();

    glColor3f(0.8,0.6,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1340,380);
    glVertex2i(1340,510);
    glVertex2i(1360,510);
    glVertex2i(1360,380);
    glEnd();

    glColor3f(0.8,0.6,0.5);
    glBegin(GL_QUADS);
    glVertex2i(1340,500);
    glVertex2i(1400,500);
    glVertex2i(1400,515);
    glVertex2i(1340,515);
    glEnd();

    //w1
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1370,385);
    glVertex2i(1370,395);
    glVertex2i(1390,395);
    glVertex2i(1390,385);
    glEnd();

    //w2
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1370,405);
    glVertex2i(1370,415);
    glVertex2i(1390,415);
    glVertex2i(1390,405);
    glEnd();

    //w3
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1370,425);
    glVertex2i(1370,435);
    glVertex2i(1390,435);
    glVertex2i(1390,425);
    glEnd();

    //w4
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1370,445);
    glVertex2i(1370,455);
    glVertex2i(1390,455);
    glVertex2i(1390,445);
    glEnd();

    //w5
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1370,465);
    glVertex2i(1370,475);
    glVertex2i(1390,475);
    glVertex2i(1390,465);
    glEnd();

    //w6
    glColor3f(0.9,0.9,0.7);
    glBegin(GL_QUADS);
    glVertex2i(1370,485);
    glVertex2i(1370,495);
    glVertex2i(1390,495);
    glVertex2i(1390,485);
    glEnd();
}

void tree(void)
{
    glColor3f(0.36,0.5,0.20); // tree 1
    glBegin(GL_POLYGON);
    glVertex2f(100,380);
    glVertex2f(100,420);
    glVertex2f(120,420);
    glVertex2f(120,380);
    glEnd();

    for(l=0;l<=30;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(90,440,l);
        draw_circle(130,440,l);
    }

    for(l=0;l<=25;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(100,480,l);
        draw_circle(120,480,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(110,505,l);
    }

    // tree 2
    glColor3f(0.36,0.5,0.20);
    glBegin(GL_POLYGON);
    glVertex2f(520,380);
    glVertex2f(520,420);
    glVertex2f(540,420);
    glVertex2f(540,380);
    glEnd();

    for(l=0;l<=30;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(510,440,l);
        draw_circle(550,440,l);
    }

    for(l=0;l<=25;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(520,480,l);
        draw_circle(540,480,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(530,505,l);
    }

    // tree 3
    glColor3f(0.36,0.5,0.20);
    glBegin(GL_POLYGON);
    glVertex2f(1430,380);
    glVertex2f(1430,420);
    glVertex2f(1450,420);
    glVertex2f(1450,380);
    glEnd();

    for(l=0;l<=30;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(1420,440,l);
        draw_circle(1460,440,l);
    }

    for(l=0;l<=25;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(1430,480,l);
        draw_circle(1450,480,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(1440,505,l);
    }
}

void road(void)
{
    // green side
    glColor3f(0.0,0.8,0.0);
    glBegin(GL_QUADS);
    glVertex2i(0,0);
    glVertex2i(1500,0);
    glVertex2i(1500,15);
    glVertex2i(0,15);
    glEnd();

    // foot path
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2i(0,15);
    glVertex2i(1500,15);
    glVertex2i(1500,45);
    glVertex2i(0,45);
    glEnd();

    // white line
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2i(10,20);
    glVertex2i(20,20);
    glVertex2i(20,40);
    glVertex2i(10,40);

    glVertex2i(40,20);
    glVertex2i(50,20);
    glVertex2i(50,40);
    glVertex2i(40,40);

    glVertex2i(70,20);
    glVertex2i(80,20);
    glVertex2i(80,40);
    glVertex2i(70,40);

    glVertex2i(100,20);
    glVertex2i(110,20);
    glVertex2i(110,40);
    glVertex2i(100,40);

    glVertex2i(130,20);
    glVertex2i(140,20);
    glVertex2i(140,40);
    glVertex2i(130,40);

    glVertex2i(160,20);
    glVertex2i(170,20);
    glVertex2i(170,40);
    glVertex2i(160,40);

    glVertex2i(190,20);
    glVertex2i(200,20);
    glVertex2i(200,40);
    glVertex2i(190,40);

    glVertex2i(220,20);
    glVertex2i(230,20);
    glVertex2i(230,40);
    glVertex2i(220,40);

    glVertex2i(250,20);
    glVertex2i(260,20);
    glVertex2i(260,40);
    glVertex2i(250,40);

    glVertex2i(280,20);
    glVertex2i(290,20);
    glVertex2i(290,40);
    glVertex2i(280,40);

    glVertex2i(310,20);
    glVertex2i(320,20);
    glVertex2i(320,40);
    glVertex2i(310,40);

    glVertex2i(340,20);
    glVertex2i(350,20);
    glVertex2i(350,40);
    glVertex2i(340,40);

    glVertex2i(370,20);
    glVertex2i(380,20);
    glVertex2i(380,40);
    glVertex2i(370,40);

    glVertex2i(400,20);
    glVertex2i(410,20);
    glVertex2i(410,40);
    glVertex2i(400,40);

    glVertex2i(430,20);
    glVertex2i(440,20);
    glVertex2i(440,40);
    glVertex2i(430,40);

    glVertex2i(460,20);
    glVertex2i(470,20);
    glVertex2i(470,40);
    glVertex2i(460,40);

    glVertex2i(490,20);
    glVertex2i(500,20);
    glVertex2i(500,40);
    glVertex2i(490,40);

    glVertex2i(520,20);
    glVertex2i(530,20);
    glVertex2i(530,40);
    glVertex2i(520,40);

    glVertex2i(550,20);
    glVertex2i(560,20);
    glVertex2i(560,40);
    glVertex2i(550,40);

    glVertex2i(580,20);
    glVertex2i(590,20);
    glVertex2i(590,40);
    glVertex2i(580,40);

    glVertex2i(610,20);
    glVertex2i(620,20);
    glVertex2i(620,40);
    glVertex2i(610,40);

    glVertex2i(640,20);
    glVertex2i(650,20);
    glVertex2i(650,40);
    glVertex2i(640,40);

    glVertex2i(680,20);
    glVertex2i(690,20);
    glVertex2i(690,40);
    glVertex2i(680,40);

    glVertex2i(710,20);
    glVertex2i(720,20);
    glVertex2i(720,40);
    glVertex2i(710,40);

    glVertex2i(740,20);
    glVertex2i(750,20);
    glVertex2i(750,40);
    glVertex2i(740,40);

    glVertex2i(770,20);
    glVertex2i(780,20);
    glVertex2i(780,40);
    glVertex2i(770,40);

    glVertex2i(800,20);
    glVertex2i(810,20);
    glVertex2i(810,40);
    glVertex2i(800,40);

    glVertex2i(830,20);
    glVertex2i(840,20);
    glVertex2i(840,40);
    glVertex2i(830,40);

    glVertex2i(860,20);
    glVertex2i(870,20);
    glVertex2i(870,40);
    glVertex2i(860,40);

    glVertex2i(890,20);
    glVertex2i(900,20);
    glVertex2i(900,40);
    glVertex2i(890,40);

    glVertex2i(920,20);
    glVertex2i(930,20);
    glVertex2i(930,40);
    glVertex2i(920,40);

    glVertex2i(950,20);
    glVertex2i(960,20);
    glVertex2i(960,40);
    glVertex2i(950,40);

    glVertex2i(980,20);
    glVertex2i(990,20);
    glVertex2i(990,40);
    glVertex2i(980,40);

    glVertex2i(1010,20);
    glVertex2i(1020,20);
    glVertex2i(1020,40);
    glVertex2i(1010,40);

    glVertex2i(1040,20);
    glVertex2i(1050,20);
    glVertex2i(1050,40);
    glVertex2i(1040,40);

    glVertex2i(1070,20);
    glVertex2i(1080,20);
    glVertex2i(1080,40);
    glVertex2i(1070,40);

    glVertex2i(1100,20);
    glVertex2i(1110,20);
    glVertex2i(1110,40);
    glVertex2i(1100,40);

    glVertex2i(1130,20);
    glVertex2i(1140,20);
    glVertex2i(1140,40);
    glVertex2i(1130,40);

    glVertex2i(1160,20);
    glVertex2i(1170,20);
    glVertex2i(1170,40);
    glVertex2i(1160,40);

    glVertex2i(1190,20);
    glVertex2i(1200,20);
    glVertex2i(1200,40);
    glVertex2i(1190,40);

    glVertex2i(1220,20);
    glVertex2i(1230,20);
    glVertex2i(1230,40);
    glVertex2i(1220,40);

    glVertex2i(1250,20);
    glVertex2i(1260,20);
    glVertex2i(1260,40);
    glVertex2i(1250,40);

    glVertex2i(1280,20);
    glVertex2i(1290,20);
    glVertex2i(1290,40);
    glVertex2i(1280,40);

    glVertex2i(1310,20);
    glVertex2i(1320,20);
    glVertex2i(1320,40);
    glVertex2i(1310,40);

    glVertex2i(1340,20);
    glVertex2i(1350,20);
    glVertex2i(1350,40);
    glVertex2i(1340,40);

    glVertex2i(1370,20);
    glVertex2i(1380,20);
    glVertex2i(1380,40);
    glVertex2i(1370,40);

    glVertex2i(1400,20);
    glVertex2i(1410,20);
    glVertex2i(1410,40);
    glVertex2i(1400,40);

    glVertex2i(1430,20);
    glVertex2i(1440,20);
    glVertex2i(1440,40);
    glVertex2i(1430,40);

    glVertex2i(1460,20);
    glVertex2i(1470,20);
    glVertex2i(1470,40);
    glVertex2i(1460,40);
    glEnd();

    // white border
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2i(0,48);
    glVertex2i(1500,48);
    glVertex2i(1500,50);
    glVertex2i(0,50);
    glEnd();

    //bottom road
    glColor3f(0.25,0.25,0.25);
    glBegin(GL_QUADS);
    glVertex2i(0,50);
    glVertex2i(1500,50);
    glVertex2i(1500,150);
    glVertex2i(0,150);
    glEnd();

    // Yellow lines
    glColor3f(0.9,1.0,0.0);
    glBegin(GL_QUADS);
    glVertex2i(0,55);
    glVertex2i(1500,55);
    glVertex2i(1500,58);
    glVertex2i(0,58);

    glVertex2i(0,145);
    glVertex2i(1500,145);
    glVertex2i(1500,148);
    glVertex2i(0,148);
    glEnd();

    // white strip
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2i(5,95);
    glVertex2i(80,95);
    glVertex2i(80,100);
    glVertex2i(5,100);

    glVertex2i(100,95);
    glVertex2i(170,95);
    glVertex2i(170,100);
    glVertex2i(100,100);

    glVertex2i(190,95);
    glVertex2i(260,95);
    glVertex2i(260,100);
    glVertex2i(190,100);

    glVertex2i(280,95);
    glVertex2i(350,95);
    glVertex2i(350,100);
    glVertex2i(280,100);

    glVertex2i(370,95);
    glVertex2i(440,95);
    glVertex2i(440,100);
    glVertex2i(370,100);

    glVertex2i(460,95);
    glVertex2i(520,95);
    glVertex2i(520,100);
    glVertex2i(460,100);

    glVertex2i(540,95);
    glVertex2i(600,95);
    glVertex2i(600,100);
    glVertex2i(540,100);

    glVertex2i(620,95);
    glVertex2i(690,95);
    glVertex2i(690,100);
    glVertex2i(620,100);

    glVertex2i(710,95);
    glVertex2i(770,95);
    glVertex2i(770,100);
    glVertex2i(710,100);

    glVertex2i(790,95);
    glVertex2i(850,95);
    glVertex2i(850,100);
    glVertex2i(790,100);

    glVertex2i(870,95);
    glVertex2i(940,95);
    glVertex2i(940,100);
    glVertex2i(870,100);

    glVertex2i(960,95);
    glVertex2i(1020,95);
    glVertex2i(1020,100);
    glVertex2i(960,100);

    glVertex2i(1040,95);
    glVertex2i(1100,95);
    glVertex2i(1100,100);
    glVertex2i(1040,100);

    glVertex2i(1120,95);
    glVertex2i(1190,95);
    glVertex2i(1190,100);
    glVertex2i(1120,100);

    glVertex2i(1210,95);
    glVertex2i(1270,95);
    glVertex2i(1270,100);
    glVertex2i(1210,100);

    glVertex2i(1290,95);
    glVertex2i(1350,95);
    glVertex2i(1350,100);
    glVertex2i(1290,100);

    glVertex2i(1370,95);
    glVertex2i(1440,95);
    glVertex2i(1440,100);
    glVertex2i(1370,100);

    glVertex2i(1460,95);
    glVertex2i(1490,95);
    glVertex2i(1490,100);
    glVertex2i(1460,100);
    glEnd();

    // top road
    glColor3f(0.25,0.25,0.25);
    glBegin(GL_QUADS);
    glVertex2i(0,300);
    glVertex2i(1500,300);
    glVertex2i(1500,380);
    glVertex2i(0,380);
    glEnd();

    // Yellow lines
    glColor3f(0.9,1.0,0.0);
    glBegin(GL_QUADS);

    glVertex2i(0,375);
    glVertex2i(1500,375);
    glVertex2i(1500,378);
    glVertex2i(0,378);
    glEnd();

    // white strip
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2i(5,338);
    glVertex2i(80,338);
    glVertex2i(80,342);
    glVertex2i(5,342);

    glVertex2i(100,338);
    glVertex2i(170,338);
    glVertex2i(170,342);
    glVertex2i(100,342);

    glVertex2i(190,338);
    glVertex2i(260,338);
    glVertex2i(260,342);
    glVertex2i(190,342);

    glVertex2i(280,338);
    glVertex2i(350,338);
    glVertex2i(350,342);
    glVertex2i(280,342);

    glVertex2i(370,338);
    glVertex2i(440,338);
    glVertex2i(440,342);
    glVertex2i(370,342);

    glVertex2i(460,338);
    glVertex2i(520,338);
    glVertex2i(520,342);
    glVertex2i(460,342);

    glVertex2i(540,338);
    glVertex2i(600,338);
    glVertex2i(600,342);
    glVertex2i(540,342);

    glVertex2i(620,338);
    glVertex2i(690,338);
    glVertex2i(690,342);
    glVertex2i(620,342);

    glVertex2i(710,338);
    glVertex2i(770,338);
    glVertex2i(770,342);
    glVertex2i(710,342);

    glVertex2i(790,338);
    glVertex2i(850,338);
    glVertex2i(850,342);
    glVertex2i(790,342);

    glVertex2i(870,338);
    glVertex2i(940,338);
    glVertex2i(940,342);
    glVertex2i(870,342);

    glVertex2i(960,338);
    glVertex2i(1020,338);
    glVertex2i(1020,342);
    glVertex2i(960,342);

    glVertex2i(1040,338);
    glVertex2i(1100,338);
    glVertex2i(1100,342);
    glVertex2i(1040,342);

    glVertex2i(1120,338);
    glVertex2i(1190,338);
    glVertex2i(1190,342);
    glVertex2i(1120,342);

    glVertex2i(1210,338);
    glVertex2i(1270,338);
    glVertex2i(1270,342);
    glVertex2i(1210,342);

    glVertex2i(1290,338);
    glVertex2i(1350,338);
    glVertex2i(1350,342);
    glVertex2i(1290,342);

    glVertex2i(1370,338);
    glVertex2i(1440,338);
    glVertex2i(1440,342);
    glVertex2i(1370,342);

    glVertex2i(1460,338);
    glVertex2i(1490,338);
    glVertex2i(1490,342);
    glVertex2i(1460,342);
    glEnd();
}

void zebra_crossing(void)
{
    // Left side
    glColor3ub(217, 215, 210);
    glBegin(GL_QUADS);
    glVertex2i(540,60);
    glVertex2i(600,60);
    glVertex2i(600,65);
    glVertex2i(540,65);

    glVertex2i(540,75);
    glVertex2i(600,75);
    glVertex2i(600,80);
    glVertex2i(540,80);

    glVertex2i(540,110);
    glVertex2i(600,110);
    glVertex2i(600,115);
    glVertex2i(540,115);

    glVertex2i(540,125);
    glVertex2i(600,125);
    glVertex2i(600,130);
    glVertex2i(540,130);

    glVertex2i(540,140);
    glVertex2i(600,140);
    glVertex2i(600,145);
    glVertex2i(540,145);

    glVertex2i(540,200);
    glVertex2i(600,200);
    glVertex2i(600,205);
    glVertex2i(540,205);

    glVertex2i(540,215);
    glVertex2i(600,215);
    glVertex2i(600,220);
    glVertex2i(540,220);

    glVertex2i(540,230);
    glVertex2i(600,230);
    glVertex2i(600,235);
    glVertex2i(540,235);

    glVertex2i(540,245);
    glVertex2i(600,245);
    glVertex2i(600,250);
    glVertex2i(540,250);

    glVertex2i(540,260);
    glVertex2i(600,260);
    glVertex2i(600,265);
    glVertex2i(540,265);

    glVertex2i(540,275);
    glVertex2i(600,275);
    glVertex2i(600,280);
    glVertex2i(540,280);

    glVertex2i(540,290);
    glVertex2i(600,290);
    glVertex2i(600,295);
    glVertex2i(540,295);

    glVertex2i(540,305);
    glVertex2i(600,305);
    glVertex2i(600,310);
    glVertex2i(540,310);

    glVertex2i(540,320);
    glVertex2i(600,320);
    glVertex2i(600,325);
    glVertex2i(540,325);

    glVertex2i(540,340);
    glVertex2i(600,340);
    glVertex2i(600,345);
    glVertex2i(540,345);

    glVertex2i(540,355);
    glVertex2i(600,355);
    glVertex2i(600,360);
    glVertex2i(540,360);

    glVertex2i(540,370);
    glVertex2i(600,370);
    glVertex2i(600,375);
    glVertex2i(540,375);

    // Right side
    glVertex2i(870,60);
    glVertex2i(940,60);
    glVertex2i(940,65);
    glVertex2i(870,65);

    glVertex2i(870,75);
    glVertex2i(940,75);
    glVertex2i(940,80);
    glVertex2i(870,80);

    glVertex2i(870,110);
    glVertex2i(940,110);
    glVertex2i(940,115);
    glVertex2i(870,115);

    glVertex2i(870,125);
    glVertex2i(940,125);
    glVertex2i(940,130);
    glVertex2i(870,130);

    glVertex2i(870,140);
    glVertex2i(940,140);
    glVertex2i(940,145);
    glVertex2i(870,145);

    glVertex2i(870,200);
    glVertex2i(940,200);
    glVertex2i(940,205);
    glVertex2i(870,205);

    glVertex2i(870,215);
    glVertex2i(940,215);
    glVertex2i(940,220);
    glVertex2i(870,220);

    glVertex2i(870,230);
    glVertex2i(940,230);
    glVertex2i(940,235);
    glVertex2i(870,235);

    glVertex2i(870,245);
    glVertex2i(940,245);
    glVertex2i(940,250);
    glVertex2i(870,250);

    glVertex2i(870,260);
    glVertex2i(940,260);
    glVertex2i(940,265);
    glVertex2i(870,265);

    glVertex2i(870,275);
    glVertex2i(940,275);
    glVertex2i(940,280);
    glVertex2i(870,280);

    glVertex2i(870,290);
    glVertex2i(940,290);
    glVertex2i(940,295);
    glVertex2i(870,295);

    glVertex2i(870,305);
    glVertex2i(940,305);
    glVertex2i(940,310);
    glVertex2i(870,310);

    glVertex2i(870,320);
    glVertex2i(940,320);
    glVertex2i(940,325);
    glVertex2i(870,325);

    glVertex2i(870,340);
    glVertex2i(940,340);
    glVertex2i(940,345);
    glVertex2i(870,345);

    glVertex2i(870,355);
    glVertex2i(940,355);
    glVertex2i(940,360);
    glVertex2i(870,360);

    glVertex2i(870,370);
    glVertex2i(940,370);
    glVertex2i(940,375);
    glVertex2i(870,375);
    glEnd();
}

void top_road_vehicle(void)
{
    //  bus 1
    glBegin(GL_QUADS);
		glColor3f(1.0,0.0,0.0); // bus side body
		glVertex2f(1420.0,347.0);
		glVertex2f(1480.0,347.0);
		glVertex2f(1480.0,356.0);
		glVertex2f(1420.0,356.0);

		glVertex2f(1420.0,356.0);  // bus roof
		glVertex2f(1480.0,356.0);
		glVertex2f(1480.0,376.0);
		glVertex2f(1420.0,376.0);

		glColor3f(0.0,0.0,0.0);  // bus black roof
		glVertex2f(1430.0,360.0);
		glVertex2f(1470.0,360.0);
		glVertex2f(1470.0,370.0);
		glVertex2f(1430.0,370.0);

		glColor3f(1.0,0.0,0.0);  // bus front
		glVertex2f(1400.0,348.0);
		glVertex2f(1420.0,357.0);
		glVertex2f(1420.0,375.0);
		glVertex2f(1400.0,365.0);
		glVertex2f(1400.0,348.0);
	glEnd();

	glBegin(GL_QUADS); // horizontal black line
        glColor3f(0.0,0.0,0.0);
		glVertex2f(1420.0,356.0);
        glVertex2f(1480.0,356.0);
        glVertex2f(1480.0,358.0);
		glVertex2f(1420.0,358.0);
	glEnd();

	glBegin(GL_QUADS);  // Vertical black line
        glColor3f(0.0,0.0,0.0);
		glVertex2f(1420.0,356.0);
        glVertex2f(1422.0,356.0);
        glVertex2f(1422.0,376.0);
		glVertex2f(1420.0,376.0);
	glEnd();

	// front corner
	glBegin(GL_TRIANGLES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1400.0,348.0);
		glVertex2f(1420.0,348.0);
		glVertex2f(1420.0,356.0);
		glVertex2f(1400.0,348.0);
	glEnd();

	glBegin(GL_TRIANGLES);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(1400.0,366.0);
		glVertex2f(1420.0,366.0);
		glVertex2f(1420.0,376.0);
		glVertex2f(1400.0,366.0);
	glEnd();

	// wheel
	for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(1430,348,l);
        }

    for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(1463,348,l);
        }

    // bus on down 1
    glBegin(GL_QUADS);
		glColor3f(0.2,0.4,0.4); // bus side body
		glVertex2f(1250.0,310.0);
		glVertex2f(1270.0,310.0);
		glVertex2f(1270.0,330.0);
		glVertex2f(1250.0,330.0);

		glVertex2f(1270.0,310.0);
		glVertex2f(1330.0,310.0);
		glVertex2f(1330.0,340.0);
		glVertex2f(1270.0,340.0);
        glEnd();

		glColor3f(0.1,1.0,1.0);   // bus front
		glBegin(GL_TRIANGLES);
		glVertex2f(1250.0,330.0);
		glVertex2f(1270.0,330.0);
		glVertex2f(1270.0,340.0);
	glEnd();

    // middle blue rectangular
	glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
		glVertex2f(1273.0,320.0);
        glVertex2f(1325.0,320.0);
        glVertex2f(1325.0,335.0);
		glVertex2f(1273.0,335.0);

		glColor3f(0.1,1.0,1.0);
		glVertex2f(1275.0,325.0);
        glVertex2f(1285.0,325.0);
        glVertex2f(1285.0,330.0);
		glVertex2f(1275.0,330.0);

		glColor3f(1.0,1.0,1.0);
		glVertex2f(1290.0,315.0);
        glVertex2f(1300.0,315.0);
        glVertex2f(1300.0,330.0);
		glVertex2f(1290.0,330.0);

		glColor3f(0.1,1.0,1.0);
		glVertex2f(1305.0,325.0);
        glVertex2f(1315.0,325.0);
        glVertex2f(1315.0,330.0);
		glVertex2f(1305.0,330.0);
	glEnd();

	// wheel
	for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(1270,312,l);
        }

    for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(1310,312,l);
        }

    //  bus 2
    glBegin(GL_QUADS);
		glColor3f(0.0,0.5,0.0); // bus side body
		glVertex2f(1120.0,347.0);
		glVertex2f(1180.0,347.0);
		glVertex2f(1180.0,356.0);
		glVertex2f(1120.0,356.0);

		glVertex2f(1120.0,356.0);  // bus roof
		glVertex2f(1180.0,356.0);
		glVertex2f(1180.0,376.0);
		glVertex2f(1120.0,376.0);

		glColor3f(0.0,0.0,0.0);  // bus black roof
		glVertex2f(1130.0,360.0);
		glVertex2f(1170.0,360.0);
		glVertex2f(1170.0,370.0);
		glVertex2f(1130.0,370.0);

		glColor3f(0.0,0.5,0.0);  // bus front
		glVertex2f(1100.0,348.0);
		glVertex2f(1120.0,357.0);
		glVertex2f(1120.0,375.0);
		glVertex2f(1100.0,365.0);
		glVertex2f(1100.0,348.0);
	glEnd();

    // horizontal black line
	glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.0);
		glVertex2f(1120.0,356.0);
        glVertex2f(1180.0,356.0);
        glVertex2f(1180.0,358.0);
		glVertex2f(1120.0,358.0);
	glEnd();

	// Vertical black line
	glBegin(GL_QUADS);
        glColor3f(0.0,0.0,0.0);
		glVertex2f(1120.0,356.0);
        glVertex2f(1122.0,356.0);
        glVertex2f(1122.0,376.0);
		glVertex2f(1120.0,376.0);
	glEnd();

	// front corner
	glBegin(GL_TRIANGLES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1100.0,348.0);
		glVertex2f(1120.0,348.0);
		glVertex2f(1120.0,356.0);
		glVertex2f(1100.0,348.0);
	glEnd();

	glBegin(GL_TRIANGLES);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(1100.0,366.0);
		glVertex2f(1120.0,366.0);
		glVertex2f(1120.0,376.0);
		glVertex2f(1100.0,366.0);
	glEnd();

	// wheel
	for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(1130,348,l);
        }

    for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(1163,348,l);
        }

    // bus on down 2
    glBegin(GL_QUADS);
		glColor3f(0.2,0.8,0.6); // bus side body
		glVertex2f(950.0,310.0);
		glVertex2f(970.0,310.0);
		glVertex2f(970.0,330.0);
		glVertex2f(950.0,330.0);

		glVertex2f(970.0,310.0);
		glVertex2f(1030.0,310.0);
		glVertex2f(1030.0,340.0);
		glVertex2f(970.0,340.0);
        glEnd();

		glColor3f(0.1,1.0,1.0);   // bus front
		glBegin(GL_TRIANGLES);
		glVertex2f(950.0,330.0);
		glVertex2f(970.0,330.0);
		glVertex2f(970.0,340.0);
	glEnd();

    // middle blue rectangular
	glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
		glVertex2f(973.0,320.0);
        glVertex2f(1025.0,320.0);
        glVertex2f(1025.0,335.0);
		glVertex2f(973.0,335.0);

		glColor3f(0.1,1.0,1.0);
		glVertex2f(975.0,325.0);
        glVertex2f(985.0,325.0);
        glVertex2f(985.0,330.0);
		glVertex2f(975.0,330.0);

		glColor3f(1.0,1.0,1.0);
		glVertex2f(990.0,315.0);
        glVertex2f(1000.0,315.0);
        glVertex2f(1000.0,330.0);
		glVertex2f(990.0,330.0);

		glColor3f(0.1,1.0,1.0);
		glVertex2f(1005.0,325.0);
        glVertex2f(1015.0,325.0);
        glVertex2f(1015.0,330.0);
		glVertex2f(1005.0,330.0);
	glEnd();

	// wheel
	for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(970,312,l);
        }

    for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(1010,312,l);
        }
}

void bottom_road_vehicle(void)
{
    // bus 1
    glBegin(GL_QUADS);
		glColor3f(1.0,0.0,0.0); // bus side body
		glVertex2f(20.0,60.0);
		glVertex2f(80.0,60.0);
		glVertex2f(80.0,90.0);
		glVertex2f(20.0,90.0);

		glVertex2f(80.0,60.0);
		glVertex2f(100.0,60.0);
		glVertex2f(100.0,80.0);
		glVertex2f(80.0,80.0);
        glEnd();

		glColor3f(0.1,1.0,1.0);   // bus front
		glBegin(GL_TRIANGLES);
		glVertex2f(80.0,80.0);
		glVertex2f(100.0,80.0);
		glVertex2f(80.0,90.0);
	glEnd();

    // middle blue rectangular
	glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
		glVertex2f(25.0,70.0);
        glVertex2f(75.0,70.0);
        glVertex2f(75.0,85.0);
		glVertex2f(25.0,85.0);

		glColor3f(0.1,1.0,1.0);
		glVertex2f(30.0,75.0);
        glVertex2f(40.0,75.0);
        glVertex2f(40.0,80.0);
		glVertex2f(30.0,80.0);

		glVertex2f(45.0,75.0);
        glVertex2f(55.0,75.0);
        glVertex2f(55.0,80.0);
		glVertex2f(45.0,80.0);

		glColor3f(1.0,1.0,1.0);
		glVertex2f(60.0,65.0);
        glVertex2f(70.0,65.0);
        glVertex2f(70.0,80.0);
		glVertex2f(60.0,80.0);
	glEnd();

	// wheel
	for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(40,62,l);
        }

    for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(80,62,l);
        }

    // bus on top 1
    glBegin(GL_QUADS);
		glColor3f(1.0,0.0,1.0); // bus side body
		glVertex2f(150.0,110.0);
		glVertex2f(210.0,110.0);
		glVertex2f(210.0,140.0);
		glVertex2f(150.0,140.0);

		glVertex2f(210.0,110.0);
		glVertex2f(230.0,110.0);
		glVertex2f(230.0,130.0);
		glVertex2f(210.0,130.0);
        glEnd();

		glColor3f(0.1,1.0,1.0);   // bus front
		glBegin(GL_TRIANGLES);
		glVertex2f(210.0,130.0);
		glVertex2f(230.0,130.0);
		glVertex2f(210.0,140.0);
	glEnd();

    // middle blue rectangular
	glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
		glVertex2f(155.0,120.0);
        glVertex2f(205.0,120.0);
        glVertex2f(205.0,135.0);
		glVertex2f(155.0,135.0);

		glColor3f(0.1,1.0,1.0);
		glVertex2f(160.0,125.0);
        glVertex2f(170.0,125.0);
        glVertex2f(170.0,130.0);
		glVertex2f(160.0,130.0);

		glVertex2f(175.0,125.0);
        glVertex2f(185.0,125.0);
        glVertex2f(185.0,130.0);
		glVertex2f(175.0,130.0);

		glColor3f(1.0,1.0,1.0);
		glVertex2f(190.0,115.0);
        glVertex2f(200.0,115.0);
        glVertex2f(200.0,130.0);
		glVertex2f(190.0,130.0);
	glEnd();

	// wheel
	for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(170,112,l);
        }

    for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(210,112,l);
        }

    //  bus 2
    glBegin(GL_QUADS);
		glColor3f(0.0,0.5,0.0); // bus side body
		glVertex2f(320.0,60.0);
		glVertex2f(380.0,60.0);
		glVertex2f(380.0,90.0);
		glVertex2f(320.0,90.0);

		glVertex2f(380.0,60.0);
		glVertex2f(400.0,60.0);
		glVertex2f(400.0,80.0);
		glVertex2f(380.0,80.0);
        glEnd();

		glColor3f(0.1,1.0,1.0);   // bus front
		glBegin(GL_TRIANGLES);
		glVertex2f(380.0,80.0);
		glVertex2f(400.0,80.0);
		glVertex2f(380.0,90.0);
	glEnd();

    // middle blue rectangular
	glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
		glVertex2f(325.0,70.0);
        glVertex2f(375.0,70.0);
        glVertex2f(375.0,85.0);
		glVertex2f(325.0,85.0);

		glColor3f(0.1,1.0,1.0);
		glVertex2f(330.0,75.0);
        glVertex2f(340.0,75.0);
        glVertex2f(340.0,80.0);
		glVertex2f(330.0,80.0);

		glVertex2f(345.0,75.0);
        glVertex2f(355.0,75.0);
        glVertex2f(355.0,80.0);
		glVertex2f(345.0,80.0);

		glColor3f(1.0,1.0,1.0);
		glVertex2f(360.0,65.0);
        glVertex2f(370.0,65.0);
        glVertex2f(370.0,80.0);
		glVertex2f(360.0,80.0);
	glEnd();

	// wheel
	for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(340,62,l);
        }

    for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(380,62,l);
        }
    // bus on top 2
    glBegin(GL_QUADS);
		glColor3f(0.3,0.1,0.1); // bus side body
		glVertex2f(450.0,110.0);
		glVertex2f(510.0,110.0);
		glVertex2f(510.0,140.0);
		glVertex2f(450.0,140.0);

		glVertex2f(510.0,110.0);
		glVertex2f(530.0,110.0);
		glVertex2f(530.0,130.0);
		glVertex2f(510.0,130.0);
        glEnd();

		glColor3f(0.1,1.0,1.0);   // bus front
		glBegin(GL_TRIANGLES);
		glVertex2f(510.0,130.0);
		glVertex2f(530.0,130.0);
		glVertex2f(510.0,140.0);
	glEnd();

    // middle blue rectangular
	glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
		glVertex2f(455.0,120.0);
        glVertex2f(505.0,120.0);
        glVertex2f(505.0,135.0);
		glVertex2f(455.0,135.0);

		glColor3f(0.1,1.0,1.0);
		glVertex2f(460.0,125.0);
        glVertex2f(470.0,125.0);
        glVertex2f(470.0,130.0);
		glVertex2f(460.0,130.0);

		glVertex2f(475.0,125.0);
        glVertex2f(485.0,125.0);
        glVertex2f(485.0,130.0);
		glVertex2f(475.0,130.0);

		glColor3f(1.0,1.0,1.0);
		glVertex2f(490.0,115.0);
        glVertex2f(500.0,115.0);
        glVertex2f(500.0,130.0);
		glVertex2f(490.0,130.0);
	glEnd();

	// wheel
	for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(470,112,l);
        }

    for(l=0;l<=5;l++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(510,112,l);
        }
}

void bridge(void)
{
    // free space of bridge
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2i(0,150);
    glVertex2i(1500,150);
    glVertex2i(1500,300);
    glVertex2i(0,300);
    glEnd();

    // down of bridge
    glBegin(GL_QUADS);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(0,150);
    glVertex2f(150,150);
    glVertex2f(150,170);
    glVertex2f(0,170);

    glVertex2f(150,150);
    glVertex2f(450,150);
    glVertex2f(450,170);
    glVertex2f(150,170);

    glVertex2f(1050,150);
    glVertex2f(1300,150);
    glVertex2f(1300,170);
    glVertex2f(1050,170);

    glVertex2f(1350,150);
    glVertex2f(1500,150);
    glVertex2f(1500,170);
    glVertex2f(1350,170);

    glColor3f(0.25,0.25,0.25); // middle of bridge=> down
    glVertex2f(500,150);
    glVertex2f(1000,150);
    glVertex2f(1000,300);
    glVertex2f(500,300);

    glColor3ub(217, 215, 210); // zebra crossing 6-8 (left)
    glVertex2i(540,155);
    glVertex2i(600,155);
    glVertex2i(600,160);
    glVertex2i(540,160);

    glVertex2i(540,170);
    glVertex2i(600,170);
    glVertex2i(600,175);
    glVertex2i(540,175);

    glVertex2i(540,185);
    glVertex2i(600,185);
    glVertex2i(600,190);
    glVertex2i(540,190);

    glVertex2i(870,155);  // zebra crossing 6-8 (right)
    glVertex2i(940,155);
    glVertex2i(940,160);
    glVertex2i(870,160);

    glVertex2i(870,170);
    glVertex2i(940,170);
    glVertex2i(940,175);
    glVertex2i(870,175);

    glVertex2i(870,185);
    glVertex2i(940,185);
    glVertex2i(940,190);
    glVertex2i(870,190);
    glEnd();

    // 1st beam
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex2f(100,150);
    glVertex2f(100,170);
    glVertex2f(150,170);
    glVertex2f(150,150);
    glEnd();

    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
    glVertex2f(100,170);
    glVertex2f(80,200);
    glVertex2f(170,200);
    glVertex2f(150,170);
    glEnd();

    // 2nd beam
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex2f(450,150);
    glVertex2f(450,170);
    glVertex2f(500,170);
    glVertex2f(500,150);
    glEnd();

    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
    glVertex2f(450,170);
    glVertex2f(430,200);
    glVertex2f(520,200);
    glVertex2f(500,170);
    glEnd();

    // 3rd beam
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex2f(1000,150);
    glVertex2f(1000,170);
    glVertex2f(1050,170);
    glVertex2f(1050,150);
    glEnd();

    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
    glVertex2f(1000,170);
    glVertex2f(980,200);
    glVertex2f(1070,200);
    glVertex2f(1050,170);
    glEnd();

    // 4th beam
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
    glVertex2f(1300,150);
    glVertex2f(1300,170);
    glVertex2f(1350,170);
    glVertex2f(1350,150);
    glEnd();

    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
    glVertex2f(1300,170);
    glVertex2f(1280,200);
    glVertex2f(1370,200);
    glVertex2f(1350,170);
    glEnd();

    // black border
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(0,200);
    glVertex2i(1500,200);
    glVertex2i(1500,205);
    glVertex2i(0,205);
    glEnd();

    // top of bridge border
    glColor3f(0.8,0.7,1);
    glBegin(GL_QUADS);
    glVertex2i(0,295);
    glVertex2i(1500,295);
    glVertex2i(1500,300);
    glVertex2i(0,300);
    glEnd();

    // bridge
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(0,205);
    glVertex2i(1500,205);
    glVertex2i(1500,295);
    glVertex2i(0,295);
    glEnd();

}

void rail_track(void)
{
    // track
    glColor3f(0.0,0.2,0.4);
    glBegin(GL_QUADS);
    glVertex2i(0,215);
    glVertex2i(1500,215);
    glVertex2i(1500,220);
    glVertex2i(0,220);

    glVertex2i(0,255);
    glVertex2i(1500,255);
    glVertex2i(1500,260);
    glVertex2i(0,260);
    glEnd();

    // track
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(10,215);
    glVertex2i(10,260);
    glVertex2i(50,215);
    glVertex2i(50,260);
    glVertex2i(100,215);
    glVertex2i(100,260);
    glVertex2i(150,215);
    glVertex2i(150,260);
    glVertex2i(200,215);
    glVertex2i(200,260);
    glVertex2i(250,215);
    glVertex2i(250,260);
    glVertex2i(300,215);
    glVertex2i(300,260);
    glVertex2i(350,215);
    glVertex2i(350,260);
    glVertex2i(400,215);
    glVertex2i(400,260);
    glVertex2i(450,215);
    glVertex2i(450,260);
    glVertex2i(500,215);
    glVertex2i(500,260);
    glVertex2i(550,215);
    glVertex2i(550,260);
    glVertex2i(600,215);
    glVertex2i(600,260);
    glVertex2i(650,215);
    glVertex2i(650,260);
    glVertex2i(700,215);
    glVertex2i(700,260);
    glVertex2i(750,215);
    glVertex2i(750,260);
    glVertex2i(800,215);
    glVertex2i(800,260);
    glVertex2i(850,215);
    glVertex2i(850,260);
    glVertex2i(900,215);
    glVertex2i(900,260);
    glVertex2i(950,215);
    glVertex2i(950,260);
    glVertex2i(1000,215);
    glVertex2i(1000,260);
    glVertex2i(1050,215);
    glVertex2i(1050,260);
    glVertex2i(1100,215);
    glVertex2i(1100,260);
    glVertex2i(1150,215);
    glVertex2i(1150,260);
    glVertex2i(1200,215);
    glVertex2i(1200,260);
    glVertex2i(1250,215);
    glVertex2i(1250,260);
    glVertex2i(1300,215);
    glVertex2i(1300,260);
    glVertex2i(1350,215);
    glVertex2i(1350,260);
    glVertex2i(1400,215);
    glVertex2i(1400,260);
    glVertex2i(1450,215);
    glVertex2i(1450,260);
    glVertex2i(1490,215);
    glVertex2i(1490,260);
    glEnd();
}

void metro_rail(void)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(805,230);
    glVertex2f(820,230);
    glVertex2f(820,250);
    glVertex2f(805,250);
    glEnd();

    // Engine
    glColor3ub(193, 219, 214);
    glBegin(GL_POLYGON);
    glVertex2f(820,220);
    glVertex2f(1050,220);
    glVertex2f(1050,320);
    glVertex2f(890,320);
    glVertex2f(820,280);
    glVertex2f(820,220);
    glEnd();

    // left-top
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(820,220);
    glVertex2f(840,235);
    glVertex2f(840,280);
    glVertex2f(820,280);
    glVertex2f(820,220);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(820,280);
    glVertex2f(840,280);
    glVertex2f(890,310);
    glVertex2f(890,320);
    glVertex2f(820,280);
    glEnd();

    // top
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(890,310);
    glVertex2f(1050,310);
    glVertex2f(1050,320);
    glVertex2f(890,320);
    glEnd();

    // top to top
    glColor3f(0.2,2.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(920,320);
    glVertex2f(1020,320);
    glVertex2f(1000,330);
    glVertex2f(940,330);
    glVertex2f(920,320);
    glEnd();

    // Front Window
    glColor3f(0.1,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(855,250);
    glVertex2f(935,250);
    glVertex2f(935,295);
    glVertex2f(885,295);
    glVertex2f(855,275);
    glVertex2f(855,250);
    glEnd();

    // Back Window
    glColor3f(0.1,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(1020,260);
    glVertex2f(1040,260);
    glVertex2f(1040,290);
    glVertex2f(1020,290);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(1020,270);
    glVertex2f(1040,270);
    glVertex2f(1020,280);
    glVertex2f(1040,280);
    glVertex2f(1030,260);
    glVertex2f(1030,290);
    glEnd();

    // door
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(950,220);
    glVertex2f(1010,220);
    glVertex2f(1010,300);
    glVertex2f(950,300);

    glColor3f(0.1,1.0,1.0); // left glass
    glVertex2f(955,230);
    glVertex2f(970,230);
    glVertex2f(970,280);
    glVertex2f(955,280);

    glVertex2f(990,230);  // right glass
    glVertex2f(1005,230);
    glVertex2f(1005,280);
    glVertex2f(990,280);

    glColor3f(1.0,0.0,0.0); // door opener
    glVertex2f(975,220);
    glVertex2f(985,220);
    glVertex2f(985,300);
    glVertex2f(975,300);
    glEnd();

    // middle of the door circles
    for(l=0;l<5;l++)
       {
        glColor3f(0.9,0.9,1.0);
        draw_circle(980,260,l);
       }

    // Down Black border
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(820,220);
    glVertex2f(950,220);
    glVertex2f(950,235);
    glVertex2f(840,235);
    glVertex2f(820,220);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(1010,220);
    glVertex2f(1050,220);
    glVertex2f(1050,235);
    glVertex2f(1010,235);
    glEnd();

    // Engine 3 Wheels

    for(l=0;l<10;l++)
       {
        glColor3ub(119, 149, 181);
        draw_circle(870,225,l);
       }

    for(l=0;l<10;l++)
       {
        glColor3ub(119, 149, 181);
        draw_circle(930,225,l);
       }

    for(l=0;l<10;l++)
       {
        glColor3ub(119, 149, 181);
        draw_circle(1030,225,l);
       }

    // connector 1
    glBegin(GL_QUADS);
    glColor3ub(89, 65, 10);
    glVertex2f(1050,250);
    glVertex2f(1080,250);
    glVertex2f(1080,280);
    glVertex2f(1050,280);
    glEnd();

    // Career 1
    glColor3ub(193, 219, 214);
    glBegin(GL_QUADS);
    glVertex2f(1080,220);
    glVertex2f(1260,220);
    glVertex2f(1260,320);
    glVertex2f(1080,320);
    glEnd();

    //top
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(1080,310);
    glVertex2f(1260,310);
    glVertex2f(1260,320);
    glVertex2f(1080,320);
    glEnd();

    // Front Window
    glColor3f(0.1,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(1090,260);
    glVertex2f(1130,260);
    glVertex2f(1130,290);
    glVertex2f(1090,290);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(1090,270);
    glVertex2f(1130,270);
    glVertex2f(1090,280);
    glVertex2f(1130,280);
    glVertex2f(1100,260);
    glVertex2f(1100,290);
    glVertex2f(1110,260);
    glVertex2f(1110,290);
    glVertex2f(1120,260);
    glVertex2f(1120,290);
    glEnd();

    // Back Window
    glColor3f(0.1,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(1210,260);
    glVertex2f(1250,260);
    glVertex2f(1250,290);
    glVertex2f(1210,290);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(1210,270);
    glVertex2f(1250,270);
    glVertex2f(1210,280);
    glVertex2f(1250,280);
    glVertex2f(1220,260);
    glVertex2f(1220,290);
    glVertex2f(1230,260);
    glVertex2f(1230,290);
    glVertex2f(1240,260);
    glVertex2f(1240,290);
    glEnd();

    // door
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(1140,220);
    glVertex2f(1200,220);
    glVertex2f(1200,300);
    glVertex2f(1140,300);

    glColor3f(0.1,1.0,1.0); // left glass
    glVertex2f(1145,230);
    glVertex2f(1160,230);
    glVertex2f(1160,280);
    glVertex2f(1145,280);

    glVertex2f(1180,230);  // right glass
    glVertex2f(1195,230);
    glVertex2f(1195,280);
    glVertex2f(1180,280);

    glColor3f(1.0,0.0,0.0); // door opener
    glVertex2f(1165,220);
    glVertex2f(1175,220);
    glVertex2f(1175,300);
    glVertex2f(1165,300);
    glEnd();

    // middle of the door circles
    for(l=0;l<5;l++)
       {
        glColor3f(0.9,0.9,1.0);
        draw_circle(1170,260,l);
       }

    // Down Black border
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(1080,220);
    glVertex2f(1140,220);
    glVertex2f(1140,235);
    glVertex2f(1080,235);

    glVertex2f(1200,220);
    glVertex2f(1260,220);
    glVertex2f(1260,235);
    glVertex2f(1200,235);
    glEnd();

    // Career 1 Wheels

    for(l=0;l<10;l++)
       {
        glColor3ub(119, 149, 181);
        draw_circle(1110,225,l);
       }

    for(l=0;l<10;l++)
       {
        glColor3ub(119, 149, 181);
        draw_circle(1230,225,l);
       }

    // connector 2
    glBegin(GL_QUADS);
    glColor3ub(89, 65, 10);
    glVertex2f(1260,250);
    glVertex2f(1290,250);
    glVertex2f(1290,280);
    glVertex2f(1260,280);
    glEnd();

    // Career 2
    glColor3ub(193, 219, 214);
    glBegin(GL_QUADS);
    glVertex2f(1290,220);
    glVertex2f(1500,220);
    glVertex2f(1500,320);
    glVertex2f(1290,320);
    glEnd();

    //top
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(1290,310);
    glVertex2f(1500,310);
    glVertex2f(1500,320);
    glVertex2f(1290,320);
    glEnd();

    // Front Window
    glColor3f(0.1,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(1300,260);
    glVertex2f(1340,260);
    glVertex2f(1340,290);
    glVertex2f(1300,290);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(1300,270);
    glVertex2f(1340,270);
    glVertex2f(1300,280);
    glVertex2f(1340,280);
    glVertex2f(1310,260);
    glVertex2f(1310,290);
    glVertex2f(1320,260);
    glVertex2f(1320,290);
    glVertex2f(1330,260);
    glVertex2f(1330,290);
    glEnd();

    // Back Window
    glColor3f(0.1,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2f(1450,260);
    glVertex2f(1490,260);
    glVertex2f(1490,290);
    glVertex2f(1450,290);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(1450,270);
    glVertex2f(1490,270);
    glVertex2f(1450,280);
    glVertex2f(1490,280);
    glVertex2f(1460,260);
    glVertex2f(1460,290);
    glVertex2f(1470,260);
    glVertex2f(1470,290);
    glVertex2f(1480,260);
    glVertex2f(1480,290);
    glEnd();

    // door
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(1350,220);
    glVertex2f(1440,220);
    glVertex2f(1440,300);
    glVertex2f(1350,300);

    glColor3f(0.1,1.0,1.0); // left glass
    glVertex2f(1360,230);
    glVertex2f(1380,230);
    glVertex2f(1380,280);
    glVertex2f(1360,280);

    glVertex2f(1410,230);  // right glass
    glVertex2f(1430,230);
    glVertex2f(1430,280);
    glVertex2f(1410,280);

    glColor3f(1.0,0.0,0.0); // door opener
    glVertex2f(1390,220);
    glVertex2f(1400,220);
    glVertex2f(1400,300);
    glVertex2f(1390,300);
    glEnd();

    // middle of the door circles
    for(l=0;l<5;l++)
       {
        glColor3f(0.9,0.9,1.0);
        draw_circle(1395,260,l);
       }

    // Down Black border
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(1290,220);
    glVertex2f(1350,220);
    glVertex2f(1350,235);
    glVertex2f(1290,235);

    glVertex2f(1440,220);
    glVertex2f(1500,220);
    glVertex2f(1500,235);
    glVertex2f(1440,235);
    glEnd();

    // Career 2 Wheels

    for(l=0;l<10;l++)
       {
        glColor3ub(119, 149, 181);
        draw_circle(1320,225,l);
       }

    for(l=0;l<10;l++)
       {
        glColor3ub(119, 149, 181);
        draw_circle(1470,225,l);
       }
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)

    exit(0);
}

void keyboardFunc( unsigned char key, int x, int y )
{
  switch( key )
    {
    case 'd':
        case 'D':
            day=1;
            break;

    case 'n':
        case 'N':
            day=0;
            break;
    };
}

void main_menu(int index)
{
	switch(index)
	{
	case 1:
	if(index==1)
	 {
        plane=1;
		o=n=0.0;
	 }
	break;

	case 2:
	if(index==2)
	 {
		comet=1;
		c=0.0;
	 }
	}
}

void animate()
{
    // train moving
    t = t -4;
    if (t <-1500)
        t = 1200;

    // bottom road vehicle moving
    b_r_v = b_r_v + 2;
    if (b_r_v > 1550)
        b_r_v = -550;

    // top road vehicle moving
    t_r_v = t_r_v - 2;
    if (t_r_v <-1500)
        t_r_v = 550;

    if(p==0)
     {
         i=i;
         m+=SPEED/150;
         n-=2;
         o+=0.2;
         c+=2;
     }
    else
     {
         i+=SPEED/10;
         m+=SPEED/150;
         n-=2;
         o+=0.2;
         c+=2;
     }
    if(m>1500)
         m=0.0;
    if(o>75)
     {
        plane=0;
     }
    if(c>500)
     {
        comet=0;
     }
    glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	objects();
    tree();
    building();
    road();
    zebra_crossing();

    glPushMatrix();
    glTranslatef(t_r_v,0,0);
    top_road_vehicle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(b_r_v,0,0);
    bottom_road_vehicle();
    glPopMatrix();

    bridge();
    rail_track();

    glPushMatrix();
    glTranslatef(t,0,0);
    metro_rail();
    glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

int main(int argc,char *argv[])
{
    printf(" ******** Project by Group: Squad_5 ********\n");
    printf("---------------------------------------------------\n");
    printf("        Metro Rail and Moving Vehicles             \n");
    printf("---------------------------------------------------\n\n");
    printf("######## Read the Command Carefully. ########\n\n");
    printf("Press 'd' or 'D' to make in day mode. \n\n");
	printf("Press 'n' or 'N' to make in night mode. \n\n");
	printf("Press RIGHT MOUSE BUTTON to display menu. \n\n");
	printf("Press LEFT MOUSE BUTTON to quit the program. \n\n\n");
//    printf("Press any key and Hit ENTER to open the project.\n");
//	scanf("%s",&ch);

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (1500, 690);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Metro Rail and Moving Vehicles");
	init2D(1,1,1);
	glutDisplayFunc(display);
	glutIdleFunc(animate);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	glutCreateMenu(main_menu);
	glutAddMenuEntry("Airplane",1);
	glutAddMenuEntry("Comet",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
