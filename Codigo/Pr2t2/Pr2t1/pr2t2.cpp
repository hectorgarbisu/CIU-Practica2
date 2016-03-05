#include <stdio.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

int win1, win2;

void InitGlew(){
	GLenum glew_init = glewInit();
	if (glew_init != GLEW_OK)
	{
		// Problem: glewInit failed, something is seriously wrong.
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_init));
	}
	else
		fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
}

void Init1(){
	glClearColor(1.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
}

void Init2(){
	glClearColor(0.0, 0.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
}

void Display1(){
	glClear(GL_COLOR_BUFFER_BIT); //fondo negro
	glFlush();
}

void Display2(){
	glClear(GL_COLOR_BUFFER_BIT); //fondo negro
	glFlush();
}

void MouseVentana1(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		printf("Ventana1, boton izquierdo presionado\n");
}
void MouseVentana2(int button, int state, int x, int y){
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
		printf("Ventana2, boton derecho liberado\n");
}


int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 300);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	win1 = glutCreateWindow("OpenGL Practica 2_2. Ventana1");
	glutSetCursor(GLUT_CURSOR_WAIT); // cursor especial de la ventana 
	InitGlew(); 
	Init1(); 
	glutDisplayFunc(Display1); // define la funcion de rendering 
	glutMouseFunc(MouseVentana1);
	win2 = glutCreateWindow("OpenGL Practica 2_2. Ventana2");
	Init2();
	glutDisplayFunc(Display2);
	glutMouseFunc(MouseVentana2);
	glutMainLoop(); // bucle principal 
	return 0;
}



