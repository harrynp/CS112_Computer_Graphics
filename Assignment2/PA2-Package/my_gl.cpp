
#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <glut.h>
#include <iostream>

// include declaration ofI_my_gl functions
#include "i_my_gl.h"

// the followings are wrapper functions

//added helper functions
void printMat(GLdouble *m){
	for (GLint i = 0; i < 16; ++i){
		std::cout << m[i] << " ";
	}
	std::cout << std::endl;
}

bool compareMat(GLdouble *m1, GLdouble *m2){
	for (GLint i = 0; i < 16; ++i){
		if (m1[i] != m2[i]){
			return false;
		}
	}
	return true;
}

// synchronize OpenGL's current matrix with i_my_gl's current matrix
void sync_matrix()
{
    GLdouble m[16];
    I_my_glGetMatrixd(m);
    glLoadMatrixd(m);
}

// switching matrix mode for both OpenGL and i_my_gl
void my_glMatrixMode(GLenum mode)
{
    I_my_glMatrixMode(mode);
    glMatrixMode(mode);
    sync_matrix();
}

// all following functions first call corresponding i_my_gl functions and then synchronize current matrix with OpenGL

void my_glLoadIdentity(void)
{
    I_my_glLoadIdentity();

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glLoadIdentity();
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glLoadIdentity();
	//I_my_glGetMatrixd(newmatrix); 
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "LoadIdentiy has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//}
	//std::cout << std::endl;
	//// compareMat raises the flag if the matrices don't match. 
    sync_matrix();
}

void my_glPushMatrix(void)
{
    I_my_glPushMatrix();

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glLoadIdentity();
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glPushMatrix();
	//I_my_glLoadIdentity();
	//I_my_glGetMatrixd(newmatrix);
	//I_my_glPopMatrix();
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "PushMatrix has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

void my_glPopMatrix(void)
{
    I_my_glPopMatrix();

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glLoadIdentity();
	//glPopMatrix();
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//// This uses your my_gl* functions, and will have effect
	//I_my_glPushMatrix();
	//I_my_glLoadIdentity();
	//I_my_glPopMatrix();
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "PopMatrix has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

void my_glLoadMatrixf(const GLfloat *m)
{
    I_my_glLoadMatrixf(m);

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glLoadMatrixf(m);
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glLoadMatrixf(m);
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "LoadMatrixf has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

void my_glLoadMatrixd(const GLdouble *m)
{
    I_my_glLoadMatrixd(m);

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glLoadMatrixd(m);
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glLoadMatrixd(m);
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "LoadMatrixd has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();    
}

void my_glTranslated(GLdouble x, GLdouble y, GLdouble z)
{
    I_my_glTranslated(x, y, z);

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glTranslated(x, y, z);
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glTranslated(x, y, z);
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "Translated has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

void my_glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
    I_my_glTranslatef(x, y, z);

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glTranslatef(x, y, z);
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glTranslatef(x, y, z);
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "Translatef has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

void my_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
    I_my_glRotated(angle, x, y, z);

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glRotated(angle, x, y, z);
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glRotated(angle, x, y, z);
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "Rotated has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

void my_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    I_my_glRotatef(angle, x, y, z);

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glRotatef(angle, x, y, z);
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glRotatef(angle, x, y, z);
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "Rotatef has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

void my_glScaled(GLdouble x, GLdouble y, GLdouble z)
{
    I_my_glScaled(x, y, z);

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glScaled(x, y, z);
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glScaled(x, y, z);
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "Scaled has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

void my_glScalef(GLfloat x, GLfloat y, GLfloat z)
{
    I_my_glScalef(x, y, z);

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glScalef(x, y, z);
	//glGetDoublev(GL_MODELVIEW_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glScalef(x, y, z);
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "Scaled has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

void my_gluLookAt(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ,
    GLdouble centerX, GLdouble centerY, GLdouble centerZ,
    GLdouble upX, GLdouble upY, GLdouble upZ)
{
    I_my_gluLookAt(eyeX, eyeY, eyeZ, 
        centerX, centerY, centerZ,
        upX, upY, upZ);
    sync_matrix();
}

void my_glFrustum(GLdouble left, GLdouble right, 
    GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
    I_my_glFrustum(left, right, bottom, top, zNear, zFar);

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//glFrustum(left, right, bottom, top, zNear, zFar);
	//glGetDoublev(GL_PROJECTION_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_glFrustum(left, right, bottom, top, zNear, zFar);
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "glFrustum has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

void my_gluPerspective(GLdouble fovy, GLdouble aspect,
    GLdouble zNear, GLdouble zFar)
{
    I_my_gluPerspective(fovy, aspect, zNear, zFar);

	//// This operates the OpenGL way, retrieves the result and undoes it
	//GLdouble tempmatrix[16], newmatrix[16];

	//glPushMatrix();
	//gluPerspective(fovy, aspect, zNear, zFar);
	//glGetDoublev(GL_PROJECTION_MATRIX, tempmatrix);
	//glPopMatrix();
	//// This uses your my_gl* functions, and will have effect
	//I_my_gluPerspective(fovy, aspect, zNear, zFar);
	//I_my_glGetMatrixd(newmatrix);
	//if (!compareMat(newmatrix, tempmatrix)){
	//	std::cout << "gluPerspective has wrong matrix" << std::endl;
	//	printMat(newmatrix);
	//	printMat(tempmatrix);
	//	std::cout << std::endl;
	//}
    sync_matrix();
}

//*/