#include <stdio.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

float red = 1.0, green = 1.0, blue = 1.0;
int win1, win2, win3;

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
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
}

void Display1(){
	glClear(GL_COLOR_BUFFER_BIT); //fondo negro
	glutWireTeapot(0.5);
	glFlush();
}

void Display2(){
	glClear(GL_COLOR_BUFFER_BIT); //fondo negro
	glutWireTeapot(0.5);
	glFlush();
}

void Dimensiones(int ancho, int alto){
	float dx = 2.0;
	float dy = 2.0;

	if (ancho > alto){
		dx = 2.0 * (float)ancho / (float)alto;
	}
	if (alto > ancho){
		dy = 2.0 * (float)alto / (float)ancho;
	}

	glViewport(0, 0, ancho, alto);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, 1.0f, 0.0f);
	glutPostRedisplay();
}
void Dimensiones2(int ancho, int alto){
	float dx = ancho*(2/300);
	float dy = dx*(alto/ancho);
	glViewport(0, 0, ancho, alto);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, 1.0f, 0.0f);
	glutPostRedisplay();
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

	win1 = glutCreateWindow("OpenGL Practica 2_2 Ventana1");
	InitGlew();
	Init();
	glutDisplayFunc(Display1); // define la funcion de rendering

	win2 = glutCreateWindow("OpenGL Practica 2_2 Ventana2");
	Init();
	glutDisplayFunc(Display2); // define la funcion de rendering
	glutReshapeFunc(Dimensiones);

	win3 = glutCreateWindow("OpenGL Practica 2_2 Ventana3");
	Init();
	glutDisplayFunc(Display2); // define la funcion de rendering
	glutReshapeFunc(Dimensiones);


	glutMainLoop();

	return 0;
}