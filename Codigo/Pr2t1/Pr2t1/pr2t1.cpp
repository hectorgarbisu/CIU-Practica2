#include <stdio.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

float red = 1.0, green = 1.0, blue = 1.0;

void InitGlew(){
		// para poder utilizar transparentemente todas las extensiones OpenGL
	GLenum glew_init = glewInit();
	if (glew_init != GLEW_OK)
	{
		// Problem: glewInit failed, something is seriously wrong.
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_init));
	}
	else
		fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
}

void Init(){
	glClearColor(0.0, 0.0, 0.0, 0.0); //fondo negro
	// TO DO
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
}
void Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	// TO DO
	glColor3f(red, green, blue);
	glutWireTeapot(0.5);
	glFlush(); // actualiza el framebuffer
}


void Teclado1(unsigned char key, int x, int y){
	switch (key){
	case '1':
		red = 1.0;
		green = 0.0;
		blue = 0.0;
		break;
	case '2':
		red = 0.0;
		green = 1.0;
		blue = 0.0;
		break;
	case '3':
		red = 0.0;
		green = 0.0;
		blue = 1.0;
		break;
	case '4':
		red = 1.0;
		green = 1.0;
		blue = 0.0;
		break;
	}
	glutPostRedisplay();
}

void Teclado2(int key, int x, int y){
	if (key == GLUT_KEY_F1){
		red = 1.0;
		green = 1.0;
		blue = 1.0;
	}
	glutPostRedisplay();
}


int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 300);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutCreateWindow("OpenGL Practica 2_1");
	glutSetCursor(GLUT_CURSOR_WAIT); // cursor especial de la ventana 
	InitGlew(); 
	Init(); 
	glutDisplayFunc(Display); // define la funcion de rendering 
	glutKeyboardFunc(Teclado1);
	glutSpecialFunc(Teclado2);
	glutMainLoop(); // bucle principal 
	return 0;
}



