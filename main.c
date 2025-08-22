#include <stdio.h>      // Standard Input/Output functions
#include <stdlib.h>     // Standard Library functions: memory allocation, process control, conversions, etc.
#include <math.h>       // Math functions: sqrt, pow, sin, cos, etc.

#include <GL/gl.h>      // Core OpenGL functions and constants
#include <GL/glu.h>     // OpenGL Utility Library functions: higher-level drawing routines
#include <GL/glut.h>    // OpenGL Utility Toolkit: functions for windowing, input handling, and more



void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);      // Switch to projection matrix
    glLoadIdentity();
    //left,right,bottom,top
    gluOrtho2D(0.0, 1200.0, 0.0, 600.0); // Define the viewing area in the 2D space
}
void river(){
    glColor3f(0.53f, 0.85f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.0,0.0);
        glVertex2f(1200.0,0.0);
        glVertex2f(1200.0,145.0);
        glVertex2f(0.0,145.0);
    glEnd();

}
void background(){

    glBegin(GL_QUADS);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.0,165.0);
    glVertex2f(1200.0,165.0);

    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(1200.0,600.0);
    glVertex2f(0.0,600.0);
    glEnd();
}

void grass(){

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);
     glVertex2f(0.0,145.0);
     glVertex2f(400.0,145.0);
     glVertex2f(400.0,360.0);
     glVertex2f(0.0,300.0);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);
     glVertex2f(400.0,145.0);
     glVertex2f(550.0,145.0);
     glVertex2f(550.0,330.0);
     glVertex2f(400.0,360.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);
     glVertex2f(550.0,145.0);
     glVertex2f(600.0,145.0);
     glVertex2f(600.0,300.0);
     glVertex2f(550.0,330.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);
     glVertex2f(600.0,145.0);
     glVertex2f(750.0,145.0);
     glVertex2f(750.0,270.0);
     glVertex2f(600.0,300.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.39f, 0.0f);
     glVertex2f(750.0,145.0);
     glVertex2f(1200.0,145.0);
     glVertex2f(1200.0,290.0);
     glVertex2f(750.0,270.0);
    glEnd();

}
void tree(float x, float y) {
    // Stem
    glColor3f(0.65f, 0.16f, 0.16f);
    glBegin(GL_QUADS);
    glVertex2f(x + 60.0f, y + 250.0f);
    glVertex2f(x + 80.0f, y + 250.0f);
    glVertex2f(x + 80.0f, y + 400.0f);
    glVertex2f(x + 60.0f, y + 400.0f);
    glEnd();

    // Leaves 1
    glColor3f(0.0f, 0.70f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 10.0f, y + 350.0f);
    glVertex2f(x + 150.0f, y + 350.0f);
    glVertex2f(x + 70.0f, y + 450.0f);
    glEnd();

    // Leaves 2
    glBegin(GL_POLYGON);
    glVertex2f(x + 0.0f, y + 400.0f);
    glVertex2f(x + 140.0f, y + 400.0f);
    glVertex2f(x + 70.0f, y + 500.0f);
    glEnd();

    // Leaves 3
    glBegin(GL_POLYGON);
    glVertex2f(x + 10.0f, y + 450.0f);
    glVertex2f(x + 130.0f, y + 450.0f);
    glVertex2f(x + 70.0f, y + 550.0f);
    glEnd();
}

void home1(float x, float y, float r1, float g1, float b1, float r2, float g2, float b2, float r3, float g3, float b3) {
    // Base of the house
    glBegin(GL_QUADS);
    glColor3f(r1, g1, b1);  // Color for the base
    glVertex2f(x, y);
    glVertex2f(x + 110.0f, y);
    glVertex2f(x + 110.0f, y + 100.0f);
    glVertex2f(x, y + 100.0f);
    glEnd();

    // Roof of the house
    glBegin(GL_QUADS);
    glColor3f(r2, g2, b2);  // Color for the roof
    glVertex2f(x - 20.0f, y + 100.0f);
    glVertex2f(x + 130.0f, y + 100.0f);
    glVertex2f(x + 90.0f, y + 130.0f);
    glVertex2f(x + 20.0f, y + 130.0f);
    glEnd();

    // Door of the house
    glBegin(GL_QUADS);
    glColor3f(r3, g3, b3);  // Color for the door
    glVertex2f(x + 35.0f, y);
    glVertex2f(x + 75.0f, y);
    glVertex2f(x + 75.0f, y + 70.0f);
    glVertex2f(x + 35.0f, y + 70.0f);
    glEnd();
}


float horseX = 0.0f;
float tailAngle = 0.0f;
float horseRotation = 0.0f;
void horse(){

    glPushMatrix();  // Save the current state of transformations

    glTranslatef(horseX, 0.0f, 0.0f);
    glTranslatef(550.0f, 225.0f, 0.0f);  // Move the origin to the center of the horse
    glRotatef(horseRotation, 1.0f, 1.0f, 0.0f);  // Rotate the horse
    glTranslatef(-550.0f, -225.0f, 0.0f);  // Move the origin back


//face
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.4f, 0.0f);
     glVertex2f(460.0,230.0);
     glVertex2f(510.0,190.0);
     glVertex2f(483.0,280.0);
     glEnd();

//hair
     glBegin(GL_POLYGON);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(500.0,210.0);
     glVertex2f(530.0,210.0);
     glVertex2f(483.0,280.0);
     glEnd();



//body
      glBegin(GL_QUADS);
     glColor3f(0.8f, 0.4f, 0.0f);
     glVertex2f(490.0,185.0);
     glVertex2f(550.0,185.0);
     glVertex2f(550.0,225.0);
     glVertex2f(490.0,225.0);
    glEnd();

    //tail

    glPushMatrix();
    glTranslatef(550.0f, 225.0f, 0.0f);  // Move to the tail's pivot point
    glRotatef(tailAngle, 0.0f, 0.0f, 1.0f);  // Rotate the tail
    glTranslatef(-550.0f, -225.0f, 0.0f);  // Move back after rotation

     glBegin(GL_POLYGON);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(550.0,225.0);
     glVertex2f(560.0,225.0);
     glVertex2f(555.0,180.0);
     glEnd();

     glPopMatrix();
//legs
    glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(490.0,185.0);
     glVertex2f(490.0,165.0);
     glVertex2f(495.0,165.0);
     glVertex2f(495.0,185.0);
    glEnd();

     glBegin(GL_QUADS);
     glColor3f(1.0f, 1.0f, 1.0f);
     glVertex2f(545.0,185.0);
     glVertex2f(545.0,165.0);
     glVertex2f(550.0,165.0);
     glVertex2f(550.0,185.0);
    glEnd();

//mouth
     glBegin(GL_QUADS);
     glColor3f(0.8f, 0.4f, 0.0f);
     glVertex2f(460.0,227.0);
     glVertex2f(467.0,227.0);
     glVertex2f(467.0,239.0);
     glVertex2f(460.0,239.0);
    glEnd();

    glPopMatrix();


}

float fishScale = 1.0f;
void fish1(float x, float y) {

    glPushMatrix();
    glTranslatef(x, y, 0.0f);  // Move to the fish's position
    glScalef(fishScale, fishScale, 1.0f);  // Scale the fish
    glTranslatef(-x, -y, 0.0f);  // Move back after scaling

    glColor3f(1.0,1.0,0.0);

//body
    glBegin(GL_QUADS);
    glVertex2f(x+40.0, y+60.0);
    glVertex2f(x+60.0 , y+50.0);
    glVertex2f(x + 80.0, y+60.0);
    glVertex2f(x+60.0, y + 70.0);
    glEnd();

     glColor3f(1.0,0.0,0.0);


    glBegin(GL_POLYGON);
    glVertex2f(x+20.0, y+50.0);
    glVertex2f(x+40.0 , y+60.0);
    glVertex2f(x + 20.0, y+70.0);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(x+50.0, y+65.0);
    glVertex2f(x+60.0 , y+70.0);
    glVertex2f(x+45.0, y+80.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x+45.0, y+40.0);
    glVertex2f(x+60.0 , y+50.0);
    glVertex2f(x+50.0, y+55.0);
    glEnd();

    glPopMatrix();
}

void fish2(float x, float y) {

    glColor3f(0.0,0.4,1.0);


    glBegin(GL_QUADS);
    glVertex2f(x+40.0, y+60.0);
    glVertex2f(x+60.0 , y+50.0);
    glVertex2f(x + 80.0, y+60.0);
    glVertex2f(x+60.0, y + 70.0);
    glEnd();

     glColor3f(0.9,0.0,0.7);


    glBegin(GL_POLYGON);
    glVertex2f(x+20.0, y+50.0);
    glVertex2f(x+40.0 , y+60.0);
    glVertex2f(x + 20.0, y+70.0);
    glEnd();

     glBegin(GL_POLYGON);
    glVertex2f(x+50.0, y+65.0);
    glVertex2f(x+60.0 , y+70.0);
    glVertex2f(x+45.0, y+80.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x+45.0, y+40.0);
    glVertex2f(x+60.0 , y+50.0);
    glVertex2f(x+50.0, y+55.0);
    glEnd();
}

float boatX = 0.0f;
float paddleAngle = 0.0f;
void manWithBoat(){
    glPushMatrix();  // Save the current state of transformations
    glTranslatef(boatX, 0.0f, 0.0f);
    //boat
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex2f(400.0,50.0);
    glVertex2f(500.0,50.0);
    glVertex2f(530.0,80.0);
    glVertex2f(370.0,80.0);
    glEnd();

   //body
     glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(395.0,80.0);
    glVertex2f(435.0,80.0);
    glVertex2f(425.0,100.0);
    glVertex2f(395.0,100.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(395.0,100.0);
    glVertex2f(415.0,100.0);
    glVertex2f(440.0,120.0);
    glVertex2f(395.0,120.0);
    glEnd();

        //face
    glBegin(GL_QUADS);
    glColor3f(0.82f, 0.71f, 0.55f);
    glVertex2f(400.0,120.0);
    glVertex2f(425.0,120.0);
    glVertex2f(425.0,150.0);
    glVertex2f(400.0,150.0);
    glEnd();

    //nose
    glBegin(GL_POLYGON);
    glColor3f(0.82f, 0.71f, 0.55f);
    glVertex2f(425.0 , 135.0);
    glVertex2f(428.0 , 135.0);
    glVertex2f(425.0,143.0);
    glEnd();



    //hair
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(400.0,150.0);
    glVertex2f(425.0,150.0);
    glVertex2f(430.0,165.0);
    glVertex2f(400.0,160.0);
    glEnd();

    //boat paddle
    glPushMatrix();
    glTranslatef(425.0f, 100.0f, 0.0f);  // Move to the paddle's pivot point
    glRotatef(paddleAngle, 0.0f, 0.0f, 1.0f);  // Rotate the paddle
    glTranslatef(-425.0f, -100.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(380.0,40.0);
    glVertex2f(390.0 , 40.0);
    glVertex2f(428.0 , 100.0);
    glVertex2f(425.0, 100.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
// sun

float sunX = 0.0f;     // Initial X position of the sun
void sun(void) {
    float x, y;
    int triangleAmount = 200; // Number of triangles to form the circle
    float radius = 50.0f; // Radius of the sun
    float twicePi = 2.0f * 3.1416;

    glPushMatrix();  // Save the current state of transformations

    // Apply translation and scaling to the sun
    glTranslatef(sunX, 0.0f, 0.0f);  // Move the sun to its current X position

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.5, 0.0); // Orange color for the sun

    // Center of the sun at the top-right corner
    float centerX = 1130.0f; // Adjusted X to be close to the right edge
    float centerY = 520.0f; // Adjusted Y to be close to the top edge

    glVertex2f(centerX, centerY); // Center of the sun

    for (int i = 0; i <= triangleAmount; i++) {
        x = radius * cos(i * twicePi / triangleAmount);
        y = radius * sin(i * twicePi / triangleAmount);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
    glPopMatrix();
}

//  circle
void circle(float centerX, float centerY, float radius, float red, float green, float blue) {
    float x, y;
    int triangleAmount = 200; // Number of triangles to form the circle
    float twicePi = 2.0f * 3.1416;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue);

    glVertex2f(centerX, centerY);

    for (int i = 0; i <= triangleAmount; i++) {
        x = radius * cos(i * twicePi / triangleAmount);
        y = radius * sin(i * twicePi / triangleAmount);
        glVertex2f(x + centerX, y + centerY);
    }

    glEnd();
}

//cherry
void cherry(float x,float y){
 glBegin(GL_QUADS);
 glColor3f(0.0f,0.0f,0.0f);
 glVertex2f(x + 33 , y-30 );
 glVertex2f(x + 35 , y - 30 );
 glVertex2f(x + 35 , y );
 glVertex2f(x + 33 , y );
 glEnd();
 glColor3f(1.0f,0.0f,0.0f);
 circle(x + 35 , y - 30 , 7.0, 1.0, 0.0, 0.0);
}

//vase
float vaseScale = 1.0f;
void vase(float x, float y) {

    glPushMatrix();
    glTranslatef(x, y, 0.0f);  // Move to the vase's position
    glScalef(vaseScale, vaseScale, 1.0f);  // Scale the vase
    glTranslatef(-x, -y, 0.0f);  // Move back after scaling

    // bottom part of the vase
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(x + 120.0, y + 180.0);
    glVertex2f(x + 130.0, y + 180.0);
    glVertex2f(x + 135.0, y + 190.0);
    glVertex2f(x + 115.0, y + 190.0);
    glEnd();

    // middle part of the vase
    glBegin(GL_POLYGON);
    glColor3f(0.65f, 0.16f, 0.16f);
    glVertex2f(x + 123.0, y + 190.0);
    glVertex2f(x + 127.0, y + 190.0);
    glVertex2f(x + 127.0, y + 210.0);
    glVertex2f(x + 123.0, y + 210.0);
    glEnd();

    // first line on the vase
    glBegin(GL_LINES);
    glColor3f(0.65f, 0.16f, 0.16f);
    glVertex2f(x + 127.0, y + 203.0);
    glVertex2f(x + 137.0, y + 213.0);
    glEnd();

    // second line on the vase
    glBegin(GL_LINES);
    glColor3f(0.65f, 0.16f, 0.16f);
    glVertex2f(x + 115.0, y + 200.0);
    glVertex2f(x + 125.0, y + 195.0);
    glEnd();

    // circles on the vase
    circle(x + 142.0, y + 215.0, 7.0, 0.5f, 0.0f, 0.5f);
    circle(x + 110.0, y + 202.0, 7.0, 1.0f, 0.0f, 0.0f);
    circle(x + 125.0, y + 217.0, 7.0, 1.0f, 0.75f, 0.8f);

     glPopMatrix();
}
void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'B' || key == 'b') {  // Check if the "B" key is pressed
        boatX += 10.0f;  // Move the boat right by 10 units
        if (boatX > 800.0f) {  // Reset the boat if it moves off the screen
            boatX = -400.0f;  // Start again from the left side (outside of the screen)
        }
          // Request to redraw the screen with the new position
    }

        if (key == 'W' || key=='w') {  // Check if the "W" key is pressed
        paddleAngle -= 10.0f;
        boatX += 10.0f;  // Move the boat right by 10 units
        if (boatX > 800.0f) {  // Reset the boat if it moves off the screen
            boatX = -400.0f;  // Start again from the left side (outside of the screen)
        }
          // Rotate the paddle backward by 10 degrees
        if (paddleAngle <= -45.0f) {  // Reset the angle after a full rotation
            paddleAngle += 150.0f;
        }
    }

    if (key == 'F' || key == 'f') {  // Move the horse left when "F" is pressed
        horseX -= 10.0f;  // Move the horse left by 10 units
        if (horseX < -450.0f) {  // Reset the horse if it moves off the screen
            horseX = 800.0f;
        }
    }

    if (key == 'R' || key == 'r') {  // Rotate the tail when "R" is pressed
        tailAngle += 10.0f;
        horseX -= 10.0f;  // Move the horse left by 10 units
        if (horseX < -500.0f) {  // Reset the horse if it moves off the screen
            horseX = 800.0f;
        }

        if (tailAngle >= 360.0f) {  // Reset the angle after a full rotation
            tailAngle -= 360.0f;
        }
    }

    if (key == 'Q' || key == 'q') {  // Rotate the horse 180 degrees and move right when "Q" is pressed
        horseRotation += 360.0f;  // Rotate the horse 180 degrees
        horseX += 10.0f;  // Move the horse right by 10 units
        if (horseX > 1200.0f) {  // Reset the horse if it moves off the screen
            horseX = -200.0f;
        }
    }


     if (key == ' ') {  // Move the sun left when the space bar is pressed
        sunX -= 10.0f;  // Move the sun left by 10 units
        if (sunX < -1200.0f) {  // Reset the sun if it moves off the screen
            sunX = 100.0f;  // Start again from the right side
        }

     }
int i;
      if (key == 'U' || key == 'u') {  // Scale up objects when "U" is pressed
            for(i=0;i< vaseScale;i++){

        vaseScale += 0.1f * vaseScale;  // Scale up vases by half of the current factor
        fishScale += 0.1f * fishScale;// Scale up fish by half of the current factor

            }

        }


    glutPostRedisplay();
      }




void display(){
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen

    river();
    background();
    grass();
    tree(0,0);
    tree(500,50);
    tree(925,20);
    cherry(490.0,400.0);
    cherry(580.0,400.0);
    cherry(920.0,370.0);
    cherry(1005.0,370.0);
    home1(330.0f, 330.0f, 0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.0f);
    horse();
    fish1(0.0,0.0);
    fish2(700.0,0);
    fish2(950.0,30.0f);
    manWithBoat();
    sun();
    home1(820.0f,250.0f,0.85f, 0.2f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.0f);
    vase(60.0f, 10.0f);
    vase(120.0f, 30.0f);
    vase(920.0f, 5.0f);
    vase(1020.0f, 10.0f);


    glFlush();

    // Draw the mirrored fish1
    glPushMatrix();
    glScalef(-1.0f, 1.0f, 1.0f); // Mirror across the y-axis
    glTranslatef(-300.0f, 40.0f, 0.0f); // Shift to the new location
    fish1(0.0,0.0);
    glPopMatrix();



    glutSwapBuffers();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Village Scene");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();

    return 0;
}


