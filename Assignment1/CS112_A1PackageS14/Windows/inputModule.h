/*
 * OpenGL demonstration program for UCI ICS Computer Graphics courses
 * inputModule.h,v 2.1 2013/01/10 11:38 pm Shan Jiang
 *
 */

#include <glut.h>

/*---------------external entities from sceneModule-----------------*/
extern GLfloat angley;   
extern GLfloat anglex;  
extern GLfloat distanceX;
extern GLfloat distanceY;
extern GLfloat distanceZ;

/*---------------external entities from main-------------------------*/
extern void cleanup();

void readKeyboard( unsigned char key, int x, int y );
void readSpecialKeys( int key, int x, int y );
void mouseButtHandler( int button, int state, int x, int y );
void mouseMoveHandler( int x, int y );