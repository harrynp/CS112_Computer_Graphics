
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>

// define maximum stack capacity
#define STACK_CAP 16
// define pi for converting angles
#define PI 3.14159265359

// structure for the matrix stack, top specifies current top position on the stack, initially zero (which means one matrix in the stack)
struct matrix_stack
{
    GLdouble m[STACK_CAP][16];
    int top;
};

// define a macro for retrieving current matrix from top of current stack
#define current_matrix (current_stack->m[current_stack->top])

// identity matrix constant
const GLdouble identity[16] =
{1, 0, 0, 0,
 0, 1, 0, 0,
 0, 0, 1, 0,
 0, 0, 0, 1};

// the model view matrix stack
struct matrix_stack model_view = {{{0}}, 0};
// the projection matrix stack
struct matrix_stack projection = {{{0}}, 0};
// the current stack pointer that specifies the matrix mode
struct matrix_stack *current_stack = &model_view;

// multiply current matrix with matrix b, put the result in current matrix
// current = current * b
void matrix_multiply(const GLdouble *b)
{
    // ...
	GLdouble result[16] = 
	{0, 0, 0, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0,
	 0, 0, 0, 0};
	
	////calculating each part one at a time
	//result[0] = current_matrix[0] * b[0] + current_matrix[1] * b[4] + current_matrix[2] * b[8] + current_matrix[3] * b[12];
	//result[1] = current_matrix[0] * b[1] + current_matrix[1] * b[5] + current_matrix[2] * b[9] + current_matrix[3] * b[13];
	//result[2] = current_matrix[0] * b[2] + current_matrix[1] * b[6] + current_matrix[2] * b[10] + current_matrix[3] * b[14];
	//result[3] = current_matrix[0] * b[3] + current_matrix[1] * b[7] + current_matrix[2] * b[11] + current_matrix[3] * b[15];

	//result[4] = current_matrix[4] * b[0] + current_matrix[5] * b[4] + current_matrix[6] * b[8] + current_matrix[7] * b[12];
	//result[5] = current_matrix[4] * b[1] + current_matrix[5] * b[5] + current_matrix[6] * b[9] + current_matrix[7] * b[13];
	//result[6] = current_matrix[4] * b[2] + current_matrix[5] * b[6] + current_matrix[6] * b[10] + current_matrix[7] * b[14];
	//result[7] = current_matrix[4] * b[3] + current_matrix[5] * b[7] + current_matrix[6] * b[11] + current_matrix[7] * b[15];

	//result[8] = current_matrix[8] * b[0] + current_matrix[9] * b[4] + current_matrix[10] * b[8] + current_matrix[11] * b[12];
	//result[9] = current_matrix[8] * b[1] + current_matrix[9] * b[5] + current_matrix[10] * b[9] + current_matrix[11] * b[13];
	//result[10] = current_matrix[8] * b[2] + current_matrix[9] * b[6] + current_matrix[10] * b[10] + current_matrix[11] * b[14];
	//result[11] = current_matrix[8] * b[3] + current_matrix[9] * b[7] + current_matrix[10] * b[11] + current_matrix[11] * b[15];

	//result[12] = current_matrix[12] * b[0] + current_matrix[13] * b[4] + current_matrix[14] * b[8] + current_matrix[15] * b[12];
	//result[13] = current_matrix[12] * b[1] + current_matrix[13] * b[5] + current_matrix[14] * b[9] + current_matrix[15] * b[13];
	//result[14] = current_matrix[12] * b[2] + current_matrix[13] * b[6] + current_matrix[14] * b[10] + current_matrix[15] * b[14];
	//result[15] = current_matrix[12] * b[3] + current_matrix[13] * b[7] + current_matrix[14] * b[11] + current_matrix[15] * b[15];

	////old function
	//for (GLint i = 0; i < 16; i += 4){
	//	result[i] = current_matrix[i] * b[0] + current_matrix[i + 1] * b[4] + current_matrix[i + 2] * b[8] + current_matrix[i + 3] * b[12];
	//	result[i + 1] = current_matrix[i] * b[1] + current_matrix[i + 1] * b[5] + current_matrix[i + 2] * b[9] + current_matrix[i + 3] * b[13];
	//	result[i + 2] = current_matrix[i] * b[2] + current_matrix[i + 1] * b[6] + current_matrix[i + 2] * b[10] + current_matrix[i + 3] * b[14];
	//	result[i + 3] = current_matrix[i] * b[3] + current_matrix[i + 1] * b[7] + current_matrix[i + 2] * b[11] + current_matrix[i + 3] * b[15];
	//}

	//shortened
	for (GLint i = 0; i < 16; i += 4){
		for (GLint j = 0; j < 4; ++j){
			result[i + j] = current_matrix[i] * b[j] + current_matrix[i + 1] * b[j + 4] + current_matrix[i + 2] * b[j + 8] + current_matrix[i + 3] * b[j + 12];
		}
	}
	for (GLint i = 0; i < 16; ++i){
		current_matrix[i] = result[i];
	}
}

// calculating cross product of b and c, put the result in a
// a = b x c
void cross_product(GLdouble *ax, GLdouble *ay, GLdouble *az,
    GLdouble bx, GLdouble by, GLdouble bz,
    GLdouble cx, GLdouble cy, GLdouble cz)
{
    // ...
	*ax = by * cz - bz * cy;
	*ay = bz * cx - bx * cz;
	*az = bx * cy - by * cx;
}

// normaliz vector (x, y, z)
void normalize(GLdouble *x, GLdouble *y, GLdouble *z)
{
    // ...
	GLdouble length = sqrt(pow(*x, 2) + pow(*y, 2) + pow(*z, 2));
	*x = *x / length;
	*y = *y / length;
	*z = *z / length;
}

// switch matrix mode by changing the current stack pointer
void I_my_glMatrixMode(GLenum mode)
{
    // ...
	if (mode == GL_MODELVIEW){
		current_stack = &model_view;
	}
	else if (mode == GL_PROJECTION){
		current_stack = &projection;
	}
	//current_stack = mode == GL_MODELVIEW ? &model_view : &projection;
}

// overwrite current matrix with identity matrix
void I_my_glLoadIdentity(void)
{
    // ...
	//I_my_glLoadMatrixd(identity);	//doesn't work
	for (GLint i = 0; i < 16; ++i){
		current_matrix[i] = identity[i];
	}
}

// push current matrix onto current stack, report error if the stack is already full
void I_my_glPushMatrix(void)
{
    // ...
	if (current_stack->top < STACK_CAP){
		GLdouble current[16];
		for (GLint i = 0; i < 16; ++i){
			current[i] = current_matrix[i];
		}
		++current_stack->top;
		for (GLint i = 0; i < 16; ++i){
			current_matrix[i] = current[i];
		}
	}
	else{
		std::cout << (current_stack == &model_view ? "Model View Stack" : "Projection Stack") << "has reached its limit of " << STACK_CAP << "; Cannot push any more matrices" << std::endl;
	}
}

// pop current matrix from current stack, report error if the stack has only one matrix left
void I_my_glPopMatrix(void)
{
    // ...
	if (current_stack->top > 0){
		--current_stack->top;
	}
	else{
		std::cout << (current_stack == &model_view ? "Model View Stack" : "Projection Stack") << "has reached only one matrix left; Cannot pop any more matrices" << std::endl;
	}
}

// overwrite currentmatrix with m
void I_my_glLoadMatrixf(const GLfloat *m)
{
    // ...
	for (GLint i = 0; i < 16; ++i){
		current_matrix[i] = (GLdouble)m[i];
	}
}

void I_my_glLoadMatrixd(const GLdouble *m)
{
    // ...
	for (GLint i = 0; i < 16; ++i){
		current_matrix[i] = m[i];
	}
}

void I_my_glTranslated(GLdouble x, GLdouble y, GLdouble z)
{
    // ...
	GLdouble translation_matrix[16] = 
	{1, 0, 0, 0,
	 0, 1, 0, 0,
	 0, 0, 1, 0,
	 x, y, z, 1};
	matrix_multiply(translation_matrix);
}

void I_my_glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
	    I_my_glTranslated((GLdouble)x, (GLdouble)y, (GLdouble)z);
}

// remember to normalize vector (x, y, z), and to convert angle from degree to radius before calling sin and cos
void I_my_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
    // ...
	normalize(&x, &y, &z);
	GLdouble theta = angle * PI / 180;
	GLdouble rotation_matrix[16] = 
	{x * x * (1 - cos(theta)) + cos(theta), y * x * (1 - cos(theta)) + z * sin(theta), x * z * (1 - cos(theta)) - y * sin(theta), 0,
	 x * y * (1 - cos(theta)) - z * sin(theta), y * y * (1 - cos(theta)) + cos(theta), y * z * (1 - cos(theta)) + x * sin(theta), 0,
	 x * z * (1 - cos(theta)) + y * sin(theta), y * z * (1 - cos(theta)) - x * sin(theta), z * z * (1 -cos(theta)) + cos(theta), 0,
	 0, 0, 0, 1};

	//for (GLint i = 0; i < 16; ++i){
	//	std::cout << current_matrix[i] << " ";
	//}
	//std::cout << std::endl;
	//for (GLint i = 0; i < 16; ++i){
	//	std::cout << rotation_matrix[i] << " ";
	//}
	//std::cout << std::endl;
	//matrix_multiply(rotation_matrix);
	//for (GLint i = 0; i < 16; ++i){
	//	std::cout << current_matrix[i] << " ";
	//}
	GLdouble current[16];
	for (int i = 0; i < 16; ++i){
		current[i] = current_matrix[i];
	}
	I_my_glLoadMatrixd(rotation_matrix);
	matrix_multiply(current);
	//for (GLint i = 0; i < 16; ++i){
	//	std::cout << current_matrix[i] << " ";
	//}
}

void I_my_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    I_my_glRotated((GLdouble)angle, (GLdouble)x, (GLdouble)y, (GLdouble)z);
}

void I_my_glScaled(GLdouble x, GLdouble y, GLdouble z)
{
    // ...
	GLdouble scale_matrix[16] = 
	{x, 0, 0, 0,
	 0, y, 0, 0,
	 0, 0, z, 0,
	 0, 0, 0, 1};
	matrix_multiply(scale_matrix);
}

void I_my_glScalef(GLfloat x, GLfloat y, GLfloat z)
{
    I_my_glScaled((GLdouble)x, (GLdouble)y, (GLdouble)z);
}

// copy current matrix to m
void I_my_glGetMatrixf(GLfloat *m)
{
    // ...
	const GLdouble *current = current_matrix;
	for (int i = 0; i < 16; ++i){
		m[i] = (GLfloat) current[i];
	}
}

void I_my_glGetMatrixd(GLdouble *m)
{
    // ...
	const GLdouble *current = current_matrix;
	for (int i = 0; i < 16; ++i){
		m[i] = current[i];
	}
}

// remember to normalize vectors
void I_my_gluLookAt(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, 
    GLdouble centerX, GLdouble centerY, GLdouble centerZ, 
    GLdouble upX, GLdouble upY, GLdouble upZ)
{
    // ...
	//f
	GLdouble fx = centerX - eyeX;
	GLdouble fy = centerY - eyeY;
	GLdouble fz = centerZ - eyeZ;
	normalize(&fx, &fy, &fz);

	//up
	GLdouble upx = upX;
	GLdouble upy = upY;
	GLdouble upz = upZ;
	normalize(&upx, &upy, &upz);

	//s = f * up
	GLdouble sx, sy, sz;
	cross_product(&sx, &sy, &sz, fx, fy, fz, upx, upy, upz);

	//u = s x f
	GLdouble ux, uy, uz;
	cross_product(&ux, &uy, &uz, sx, sy, sz, fx, fy, fz);
	
	GLdouble look_at_Matrix[16] = 
	{sx, ux, -fx, 0,
	 sy, uy, -fy, 0,
	 sz, uz, -fz, 0,
	 0, 0, 0, 1};

	matrix_multiply(look_at_Matrix);
	//translate eye to origin
	I_my_glTranslated(-eyeX, -eyeY, -eyeZ);
}

void I_my_glFrustum(GLdouble left, GLdouble right, GLdouble bottom,
    GLdouble top, GLdouble zNear, GLdouble zFar)
{
    // ...
	////D(n,f)
	//GLdouble d[16] = {
	//zNear, 0, 0, 0,
	//0, zNear, 0, 0,
	//0, 0, -((zFar + zNear) / (zFar - zNear)), -1,
	//0, 0, -(2 * zNear * zFar / (zFar - zNear)), 0};

	////Shear
	//GLdouble sh[16] = {
	//2 / (right - left), 0, 0, 0,
	//0, 2 / (top - bottom), 0, 0,
	//0, 0, 1, 0,
	//0, 0, 0, 1};

	////Scale
	//GLdouble sc[16] = {
	//1, 0, 0, 0,
	//0, 1, 0, 0,
	//(right + left) / (2 * zNear), (top + bottom) / (2  * zNear), 1, 0,
	//0, 0, 0, 1};

	//matrix_multiply(d);
	//matrix_multiply(sc);
	//matrix_multiply(sh);

	GLdouble a = (right + left) / (right -left);
	GLdouble b = (top + bottom) / (top - bottom);
	GLdouble c = -((zFar + zNear) / (zFar - zNear));
	GLdouble d = -((2 * zFar * zNear) / (zFar - zNear));


	GLdouble frustum_matrix[16] = {
	2 * zNear / (right - left), 0, 0, 0,
	0, 2 * zNear / (top - bottom), 0, 0,
	a, b, c, -1,
	0, 0, d, 0};
	matrix_multiply(frustum_matrix);
}

// remember to convert fovy from degree to radius before calling tan
void I_my_gluPerspective(GLdouble fovy, GLdouble aspect, 
    GLdouble zNear, GLdouble zFar)
{
    // ...
	GLdouble left, right, top, bottom;

	top = zNear * tan(fovy * PI / 360);
	bottom = -top;
	left = bottom * aspect;
	right = top * aspect;

	I_my_glFrustum(left, right, bottom, top, zNear, zFar);
}
