#include<windows.h>
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

float r = 1, g = 0, b = 0;
double rt = 0, gt = 0, bt = 0.9;
bool stc = true;
bool gameStarted = false;
void display();
void move();
float manX = 600;
float manY = 20;
float manSpeed = 18.0;
bool over = false;
bool ss=false;

void text(float x, float y, float z, char* stringToDisplay) {
    glRasterPos3f(x, y, z);
    for (char* c = stringToDisplay; *c != '\0'; c++) {
        rt += 0.1;
        gt += 0.1;
        bt += 0.1;
        if (rt > 1) rt = 0;
        if (bt > 1) bt = 0;
        if (gt > 1) gt = 0;
        glColor3d(rt, gt, bt);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void front() {
    if (!gameStarted) {
        glColor3d(1, 0, 0);
        text(525, 500, 0, "ROAD CROSSING GAME");
        text(550, 400, 0, "Press SPACE to Start");

        text(800, 200, 0, "DEVELOPED BY ");
        glColor3d(255, 215, 0);
        text(1000,200,0,"\"TECHNOCRATZ\"");
        glColor3d(1, 1, 1);
        text(900, 150, 0, "VIJAY D");
        glColor3d(1, 1, 1);
        text(900, 130, 0, "HARIKESAN D J");
    }

    glFlush();
    glutSwapBuffers();
}


void world() {
    //glutSwapBuffers();
    if(!ss)
    {
        glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    int laneSpacing = 60;

    glColor3d(1, 1, 1);
    glLineWidth(2.0);
    for (int i = 1; i <= 5; i++) {
        glBegin(GL_LINES);
        glVertex2d(0, i * laneSpacing);
        glVertex2d(1200, i * laneSpacing);
        glEnd();
    }
    glLineWidth(1.0);

    // Draw the road
    glColor3d(0, 0, 0);
    glBegin(GL_LINES);
    for (int i = 0; i < 1200; i += laneSpacing) {
        for (int j = 0; j < 600; j++) {
            glVertex2d(i, j);
            glVertex2d(i + laneSpacing, j + laneSpacing);
        }
    }
    glEnd();

    glColor3d(1, 0, 0);
    glBegin(GL_LINES);
    for (int i = 0; i < 1200; i += 50) {
        for (int j = 70; j < 550; j += 50) {
            glVertex2d(i, j);
            glVertex2d(i + 30, j);
        }
    }
    glEnd();
    glColor3f(0,0.8,0);
    glBegin(GL_QUADS);
    glVertex2d(1200,600);
    glVertex2d(1200,550);
    glVertex2d(1100,550);
    glVertex2d(1100,600);
    glEnd();



    }

    glFlush();
    glutSwapBuffers();
}

void man(int manX,int manY)
{
      // Draw a stick figure man
        glColor3d(1.0, 1.0, 1.0);

        // Head
        glPointSize(8);
        glBegin(GL_POINTS);
        glVertex2d(manX, manY + 30);
        glEnd();
        glPointSize(1);

        // Body
        glBegin(GL_LINES);
        glVertex2d(manX, manY + 30);
        glVertex2d(manX, manY + 10);
        glEnd();

        // Arms
        glBegin(GL_LINES);
        glVertex2d(manX, manY + 20);
        glVertex2d(manX + 10, manY + 25);
        glEnd();

        glBegin(GL_LINES);
        glVertex2d(manX, manY + 20);
        glVertex2d(manX - 10, manY + 25);
        glEnd();

        // Legs
        glBegin(GL_LINES);
        glVertex2d(manX, manY + 10);
        glVertex2d(manX + 10, manY);
        glEnd();

        glBegin(GL_LINES);
        glVertex2d(manX, manY + 10);
        glVertex2d(manX - 10, manY);
        glEnd();

}


void polo(int x,int y)
{
    // Body of the vehicle
    glColor3d(0.5,1,0.2);
    glBegin(GL_QUADS);
    glVertex2d(x, y);
    glVertex2d(x, y+10);
    glVertex2d(x-50, y+10);
    glVertex2d(x-50, y);
    glEnd();
    glColor3d(1,1,1);
    glBegin(GL_QUADS);
    glVertex2d(x-10, y+10);
    glVertex2d(x-10, y+20);
    glVertex2d(x-50, y+20);
    glVertex2d(x-50, y+10);
    glEnd();
    glColor3d(0,0,0);
    glBegin(GL_QUADS);
    glVertex2d(x-20, y+12);
    glVertex2d(x-20, y+18);
    glVertex2d(x-28, y+18);
    glVertex2d(x-28, y+12);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2d(x-35, y+12);
    glVertex2d(x-35, y+18);
    glVertex2d(x-43, y+18);
    glVertex2d(x-43, y+12);
    glEnd();
    glColor3d(1,1,1);
    glBegin(GL_QUADS);
    glVertex2d(x-10, y-5);
    glVertex2d(x-10, y);
    glVertex2d(x-18, y);
    glVertex2d(x-18, y-5);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2d(x-35, y-5);
    glVertex2d(x-35, y);
    glVertex2d(x-43, y);
    glVertex2d(x-43, y-5);
    glEnd();

    glFlush();
}
void car(int x, int y) {
    int carWidth = 80;
    int carHeight = 20;
    int roofHeight = 15;
    int wheelRadius = 15;
    int wheelOffsetX = 10;
    int wheelOffsetY = -10;

    int x1 = x - carWidth / 2;
    int y1 = y;

    int x2 = x + carWidth / 2;
    int y2 = y + carHeight;

    glColor3d(0.5, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2d(x1, y1);
    glVertex2d(x1, y2);
    glVertex2d(x2, y2);
    glVertex2d(x2, y1);
    glEnd();

    glColor3d(0.0, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex2d(x1, y2);
    glVertex2d(x1, y2 + roofHeight);
    glVertex2d(x2, y2 + roofHeight);
    glVertex2d(x2, y2);
    glEnd();

    glColor3d(0.0, 0.0, 0.5);
    glBegin(GL_QUADS);
    glVertex2d(x1 + 10, y2 + 5);
    glVertex2d(x1 + 10, y2 + roofHeight - 5);
    glVertex2d(x2 - 10, y2 + roofHeight - 5);
    glVertex2d(x2 - 10, y2 + 5);
    glEnd();

    glColor3d(0.0, 0.0, 0.0);

}

int carX = 50;
int carY = 70;
int car1x = 50;
int car1y = 170;
int car2x = 50;
int car2y = 270;
int car3x = -100;
int car3y = 370;
int po1x = 80;

int po1y = 140;
int po2x = 180;
int po2y = 240;
int po3x = 180;
int po3y = 340;
int laneCount = 0;
void gameOver()
{
    glClearColor(0,0,0,1);
    gameStarted=false;
    over=true;
     manX = 600;
manY = 20;
    if (!gameStarted) {

        glColor3d(1, 0, 0);
        text(525, 500, 0, "GAME OVER");
        text(550, 400, 0, "Press SPACE to Start");

    }

    glFlush();
    glutSwapBuffers();

}
void success(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,1);gameStarted=false;
     manX = 600;
manY = 20;
    if (!gameStarted) {

        glColor3d(1, 0, 0);
        text(525, 500, 0, "YOU HAVE WON THE GAME");

        text(550, 400, 0, "Press S to Restart");

    }
    glFlush();
    glutSwapBuffers();
}
void move(int value) {
    carX += 2;
    car1x += 3;
    car2x+=1;
    car3x+=2;
    po1x+=1;
    po2x+=2;
    po3x+=1;
    if (gameStarted) {
        glColor3d(rt, gt, bt);
        world();


        if (carX > 1200) {
            carX = -80;
            carY+=50;
            if(carY>550 ) // Start the car from the left edge when it goes off the screen
            {
                carY=70;
            }


        }
        if (car1x > 1200) {

            car1x=-80;
            car1y+=50;

        }
        if(car1y>550 ) // Start the car from the left edge when it goes off the screen
            {
                car1y=170;
            }
        if (car2x > 1200) {

            car2x=-80;
            car3y-=50;

        }
        if(car2y>550 ) // Start the car from the left edge when it goes off the screen
            {
                car2y=270;
            }
        if (car3x > 1200) {

            car3x=-200;
            car2y+=50;

        }
        if(car3y>550 ) // Start the car from the left edge when it goes off the screen
            {
                car3y=120;
            }
        if (po1x > 1200) {

            po1x=-80;
            po1y+=50;

        } if(po1y>500 ) // Start the car from the left edge when it goes off the screen
            {
                po1y=80;
            }
        if (po2x > 1200) {

            po2x=-580;
            po2y+=50;

        }if(po2y>450 ) // Start the car from the left edge when it goes off the screen
            {
                po2y=180;
            }
        if (po3x > 1200) {

            po3x=-180;
            po3y+=50;

        }if(po3y>450 ) // Start the car from the left edge when it goes off the screen
            {
                po3y=80;
            }
        car(carX, carY);
        car(car1x, car1y);
        car(car2x, car2y);
        car(car3x, car3y);
        polo(po1x,po1y);
        polo(po2x,po2y);
        polo(po3x,po3y);
         man(manX,manY);
     }

     //For normal cars

    if((manX==carX+50 && ((manY >= carY-10 && manY <=carY+10)|| (manY+30 >= carY && manY-30 <=carY))))
            {
                gameOver();
            }
    if((manX==car1x+50 && ((manY >= car1y-10 && manY <=car1y+10)|| (manY+30 >= car1y && manY-30 <=car1y))))
            {
                gameOver();
            }
    if((manX==car2x+50 && ((manY >= car2y-10 && manY <=car2y+10)|| (manY+30 >= car2y && manY-30 <=car2y))))
            {
                gameOver();
            }
    if((manX==car3x+50 && ((manY >= car3y-10 && manY <=car3y+10)|| (manY+30 >= car3y && manY-30 <=car3y))))
            {
                gameOver();
            }

    //For polo cars

    if(((manX<=po1x+10 && manX>=po1x-60)&& ((manY >= po1y-10 && manY <=po1y+10)|| (manY+30 >= po1y && manY-20 <=po1y))))
            {
                gameOver();
            }

    if((manX==po2x+10 && ((manY >= po2y-10 && manY <=po2y+10)|| (manY+30 >= po2y && manY-20 <=po2y))))
            {
                gameOver();
            }
    if(((manX<=po3x+10 && manX>=po3x-60) && ((manY >= po3y-10 && manY <=po3y+10)|| (manY+30 >= po3y && manY-20 <=po3y))))
            {
                gameOver();
            }
   if(((manX>=1100 && manX<= 1200) && ((manY <= 600 && manY >=550))))
            {
                success();
            }




    glFlush();
    glutTimerFunc(10, move, 0);
}
 void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (gameStarted) {

        glColor3d(rt, gt, bt);
        world();
        move(0); // Move the car

    }
    if(!over)
    {
        front();
    }


    glFlush();
    glutSwapBuffers();
}
void key(unsigned char key, int x, int y) {
    if (!gameStarted && (key == ' ' || key == 's' || key == 'S')) {
        gameStarted = true;
    }
     if (gameStarted) {

        switch (key) {
            case 'w':
            case 'W':
                manY += manSpeed; // Move up
                break;
            case 's':
            case 'S':
                manY -= manSpeed; // Move down
                break;
            case 'a':
            case 'A':
                manX -= manSpeed; // Move left
                break;

            case 'd':
            case 'D':
                manX += manSpeed; // Move right
                break;
        }
    }
    glutPostRedisplay();
}
static void specialKey(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            manY += manSpeed;
            break;

        case GLUT_KEY_DOWN:
            manY -= manSpeed;
            break;
        case GLUT_KEY_RIGHT:
            manX += manSpeed;
            break;

        case GLUT_KEY_LEFT:
            manX -= manSpeed;
            break;
    }
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            stc = false;
        }
    }
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            stc = false;
            cout << stc;
        }
    }
    glutPostRedisplay();
}
void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 1200, 0, 600);
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glutSpecialFunc(specialKey);

}
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Road Crossing Game");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
