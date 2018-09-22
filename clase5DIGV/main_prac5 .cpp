//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//***** Alumno (s): Garcia Villavicencio Danahe ***********//
//*************	Visual estudio 2017						******//
//*************	manupulacion del teclado			******////     
//        hombro:    arriba   H          abajo   h
//        antebrazo: arriba  C                abajo  c
//		  muñeca:    enfrente M                  atras m
//		  dedos:     cerrar                       abrir
//      dedo 1 "y" arriba "Y" abajo completo; "u" arriba "U" abajo medio
//      dedo 2 "n" arriba "N" abajo completo; "k" arriba "K" abajo medio
//      dedo 3 "j" arriba "J" abajo completo; "b" arriba "B" abajo medio
//      dedo 4 "l" arriba "L" abajo completo;
//      dedo 5 "oi" arriba "O" abajo completo; "´p" arriba "P" abajo medio
//************************************************************//

#include "Main.h"
float	transX = 0.0,
		transZ = -5.0f,
		angleX = 0.0,
		angleY = 0.0,
		movCodo = 0.0,
		movMuñeca = 0.0,
		movDedo1 = 0.0,
		movDedo1a =  0.0,	
		movDedo2 = 0.0,
		movDedo2a = 0.0,
		movDedo3 = 0.0,
		movDedo3a = 0.0,
		movDedo4 = 0.0,
		movDedo4a = 0.0,		movDedo5 = 0.0,
		movDedo5a = 0.0;
int screenW = 0.0,
	screenH = 0.0;

float	red[3] = { 1.0, 0.0, 0.0 },
		green[3] = { 0.0,1.0,0.0 },
		blue[3] = { 0.0,0.0,1.0 },
		white[3] = { 1.0,1.0,1.0 },
		yellow[3] = { 1.0,1.0,0.0 };

void InitGL ( void )     // Inicializamos parametros
{
	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(float color[3])
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};
	glColor3fv(color);
		glBegin(GL_POLYGON);	//Front		
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();
		glBegin(GL_POLYGON);  //Bottom
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
		glTranslatef(transX, 0.0f, transZ);
		glRotatef(angleY, 0.0, 1.0, 0.0);
		glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí.
		glRotatef(movCodo, 0.0, 0.0, 1.0); 
		glTranslatef(1.25, 0.0, 0.0); //translado a la derecha
		glPushMatrix();
			glScalef(2.5, 1.0, 1.0);
			prisma(red);	//A  mandando el color
		glPopMatrix();
	    glTranslatef(1.25, 0.0, 0.0);//TRASLADAR
		glRotatef(movMuñeca, 0.0, 1.0, 0.0); //ROTAR codo
		glTranslatef(1.0, 0.0, 0.0); //PIVOTE
		glPushMatrix();
			glScalef(2.0, 1.0, 1.0);
			prisma(green);	//B
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.0, 0.35, 0.375);
			glRotatef(movDedo1, 0.0, 0.0, 1.0); //movimiento dedos
			glTranslatef(0.375, 0.0, 0.0);//pivote
			glPushMatrix();
				glScalef(0.75, 0.3, 0.25);
				prisma(white);
			glPopMatrix();
			glTranslatef(0.375, 0.0, 0.0);
				glRotatef(movDedo1a, 0.0, 0.0, 1.0);//moviento dedos 
				glTranslatef(0.5, 0.0, 0.0);//pivote
				glScalef(1.0, 0.3, 0.25);
				prisma(yellow);
		glPopMatrix();
		//segundo dedo
		glPushMatrix();
		glTranslatef(1.0, 0.35,-.05);
			glRotated(movDedo2, 0.0, 0.0, 1.0);//movimiento dedo
			glTranslatef(0.5, 0.0, 0.0);//pivote
			glPushMatrix();
				glScalef(1.0, 0.3 , 0.25);
				prisma(blue);
			glPopMatrix();
			glTranslated(0.5, 0.0, 0.0);
			glRotatef(movDedo2a, 0.0, 0.0, 1.0);//moviento dedo
			glTranslated(0.5, 0.0, 0.0);//pivote
			glScalef(1.0, 0.3, 0.25);
			prisma(yellow);
		glPopMatrix();
	//tercer dedo
		glPushMatrix();
			glTranslatef(1.0, 0.35, -0.4);
			glRotatef(movDedo3, 0.0, 0.0, 1.0);//moviento dedo
			glTranslatef(0.375, 0.0, 0.0);//pivote
			glPushMatrix();
			glScalef(0.75, 0.3, 0.25);
			prisma(white);
		glPopMatrix();
			glTranslatef(0.375, 0.0, 0.0);
		glRotatef(movDedo3a, 0.0, 0.0, 1.0);//moviento dedo
		glTranslatef(0.5, 0.0, 0.0);//pivote
		glScalef(1.0, 0.3, 0.25);
		prisma(blue);
		glPopMatrix();
		//cuarto dedo
		glPushMatrix();
		glTranslatef(1.0, -0.35, 0.2);
		glRotatef(movDedo4, 0.0, -1.0, 0.0);//moviento dedo
		glTranslatef(0.375, 0.0, 0.0);//pivote
		glPushMatrix();
		glScalef(0.75, 0.3, 0.25);
		prisma(white);
		glPopMatrix();
		glTranslatef(0.375, 0.0, 0.0);
		glRotatef(movDedo4a, 0.0, -1.0, 0.0);//moviento dedo
		glTranslatef(0.5, 0.0, 0.0);//pivote
		glScalef(1.0, 0.3, 0.25);
		prisma(yellow);
		glPopMatrix();
		//quinto dedo
		glPushMatrix();
		glTranslatef(1.0, 0.35, -0.4);
		glRotatef(movDedo5, 0.0, 0.0, 1.0);//moviento dedo
		glTranslatef(0.375, 0.0, 0.0);//pivote
		glPushMatrix();
		glScalef(0.5, 0.2, 0.15);
		prisma(white);
		glPopMatrix();
		glTranslatef(0.375, 0.0, 0.0);
		glRotatef(movDedo5a, 0.0, 0.0, 1.0);//moviento dedo
		glTranslatef(0.5, 0.0, 0.0);//pivote
		glScalef(1.0, 0.3, 0.25);
		prisma(blue);
		glPopMatrix();
		glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}
	glViewport(0,0,width,height);	
	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();
	// Tipo de Vista
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);
	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'a':
		case 'A':
			transX -= 1.0f;
			break;
		case 'd':
		case 'D':
			transX += 1.0f;
			break;
		case 'c':
			if(90.0 > movCodo)
			movCodo += 1.0f;
			break;
		case 'C':
			if (-120.0 < movCodo)
			movCodo -= 1.0f;
			break;
		case 'm':
			if (5.0 >movMuñeca)
				movMuñeca += 2.5;
			break;
		case 'M':
			if (-95.0 < movMuñeca )
				movMuñeca -= 2.5;
			break;
		case 'y':
			if(45>movDedo1)
				movDedo1 += 2.0;
			break;
		case 'Y':
			if(-90<movDedo1)
				movDedo1 -= 2.0;
			break;
			break;
		case 'u':
			if(0>movDedo1a)
				movDedo1a += 2.0;
			break;
		case 'U':
			if(-90<movDedo1a)
				movDedo1a -= 2.0;
			break;
		case 'n':
			if (45>movDedo2)
				movDedo2 += 2.0;
			break;

		case 'N':
			if (-110<movDedo2)
				movDedo2 -= 2.0;
			break;

		case 'k':
			if (0>movDedo2a)
				movDedo2a += 2.0;
			break;
		case 'K':
			if (-110<movDedo2a)
				movDedo2a -= 2.0;
			break;
		case 'j':
			if (45>movDedo3)
				movDedo3 += 2.0;
			break;
		case 'J':
			if (-90<movDedo3)
				movDedo3 -= 2.0;
			break;
		case 'b':
			if (0>movDedo3a)
				movDedo3a += 2.0;
			break;
		case 'B':
			if (-100<movDedo3a)
				movDedo3a -= 2.0;
			break;
		case 'l':
			if (45>movDedo4)
				movDedo4 += 2.0;
			break;
		case 'L':
			if (-90<movDedo4)
				movDedo4 -= 2.0;
			break;
		case 'p':
			if (0>movDedo5)
				movDedo4a += 2.0;
			break;
		case 'P':
			if (-100<movDedo5)
				movDedo4a -= 2.0;
			break;		case 'o':
			if (0 > movDedo5a)
				movDedo5a += 2.0;
			break;
		case 'O':
			if (-100 < movDedo5a)
				movDedo5a -= 2.0;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX -= 2.0;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX += 2.0;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0;
		break;
    default:
		break;
  }
  glutPostRedisplay();
}
int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (screenW-16, screenH-80);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Mano"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 
  return 0;
}