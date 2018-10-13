//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//****** Alumno (s): Garcia Villavicencio Danahe ****************//
//*************		Visual Studio 2017						******//
//*************		Fecha de entrega: 12 Octubre 			******//
//****** En esta preactica se realizo el cambio de texturas de ****//
//******          una mesa de ajedrez mediante imagenes          ***//
//***Teclas para manipular  camara   *************************//
//**** Para mover el teclado:    *****************************//
//****  Derecha: teclas 'A' 'a'      *************************//
//****  Izquierda: teclas 'D' 'd'    *************************//
//****  Acercar: teclas 'W' 'w'      *************************//
//****  Alejar: teclas 'S' 's'       *************************//
//************************************************************//
//mesa
//flechas del teclado para girar la mesa
//************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position

CTexture t_mosaico; //
CTexture t_marmol; //
CTexture t_marmol2; //
CTexture t_marmol3; //
CTexture t_cami; //
CTexture t_madera5; //imagenes que se agregaron


//Declaramos la nueva textura con nuestra imagen

int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;


void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor (0.5, 1.0, 0.5, 0.0f);				// verde de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//Modificado
	//imagenes que se agregaron
	t_madera5.LoadTGA("madera5.tga");
	t_madera5.BuildGLTexture();
	t_madera5.ReleaseImage();

	t_mosaico.LoadTGA("mosaico.tga");
	t_mosaico.BuildGLTexture();
	t_mosaico.ReleaseImage();

	t_marmol.LoadTGA("marmol.tga");
	t_marmol.BuildGLTexture();
	t_marmol.ReleaseImage();

	t_marmol2.LoadTGA("marmol2.tga");
	t_marmol2.BuildGLTexture();
	t_marmol2.ReleaseImage();

	t_marmol3.LoadTGA("marmol3.tga");
	t_marmol3.BuildGLTexture();
	t_marmol3.ReleaseImage();

	t_cami.LoadTGA("cami.tga");
	t_cami.BuildGLTexture();
	t_cami.ReleaseImage();

	//esta parte es para subir una imagen propia y hacerla una textura

}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void prisma (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
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

		
		glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 1.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(4.0, 4.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, 4.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}

void prisma2(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(1.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);
	
	//modificado:
		
		glPushMatrix(); //mesa
			glColor3f(1.0, 1.0, 1.0);
			glScalef(3.0,1.0,3.0);  
			prisma(t_cami.GLindex, t_marmol3.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata delantera izquierda
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(-1.75, -1.0, 1.75);
		glScalef(0.5,3.0,0.5);  
		prisma2(t_marmol2.GLindex, t_madera5.GLindex);
		glPopMatrix();
		
		glPushMatrix();//pata trasera izquierda
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(-1.75, -1.0, -1.75);
		glScalef(0.5, 3.0, 0.5);
		prisma2(t_marmol2.GLindex, t_madera5.GLindex);
		glPopMatrix();

		glPushMatrix();//pata delantera derecha
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(1.75, -1.0, 1.75);
		glScalef(0.5, 3.0, 0.5);
		prisma2(t_marmol2.GLindex, t_madera5.GLindex);
		glPopMatrix();

		glPushMatrix();//pata trasera derecha
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(1.75, -1.0, -1.75);
		glScalef(0.5, 3.0, 0.5);
		prisma2(t_marmol2.GLindex, t_madera5.GLindex);
		glPopMatrix();

		glPushMatrix();//borde derecho
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(1.75, 0.0, 0.0);
			glScalef(0.5, 1.0, 3.0);
			prisma2(t_marmol3.GLindex, t_marmol3.GLindex);
		glPopMatrix();

		glPushMatrix();//borde izquierdo
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-1.75, 0.0, 0.0);
			glScalef(0.5, 1.0, 3.0);
			prisma2(t_marmol3.GLindex, t_marmol3.GLindex);
		glPopMatrix();

		glPushMatrix();//borde trasero
			glTranslatef(0.0, 0.0, -1.75);
			glScalef(3.0, 1.0, 0.5);
			prisma2(t_marmol3.GLindex, t_marmol3.GLindex);
		glPopMatrix();

		glPushMatrix();//borde delantero
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, 0.0, 1.75);
			glScalef(3.0, 1.0, 0.5);
			prisma2(t_marmol3.GLindex,t_marmol3.GLindex);
		glPopMatrix();
		

		glPushMatrix();//silla
		glTranslatef(5.0, -1.0, 0.0);

		glPushMatrix(); //base
		glScalef(1.5, 0.75, 1.5);
		prisma(t_marmol3.GLindex, t_marmol3.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata delantera derecha
		glTranslatef(-0.6, -1.08, 0.6);
		glScalef(0.3, 1.4, 0.3);
		prisma2(t_madera5.GLindex, t_madera5.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata delantera izquierda
		glTranslatef(-0.6, -1.08, -0.6);
		glScalef(0.3, 1.4, 0.3);
		prisma2(t_madera5.GLindex, t_madera5.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata trasera derecha
		glTranslatef(0.6, -1.08, 0.6);
		glScalef(0.3, 1.4, 0.3);
		prisma2(t_madera5.GLindex, t_madera5.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata trasera izquierda
		glTranslatef(0.6, -1.08, -0.6);
		glScalef(0.3, 1.4, 0.3);
		prisma2(t_madera5.GLindex, t_madera5.GLindex);
		glPopMatrix();


		glPushMatrix(); //respaldo 1
		glTranslatef(0.6, 1.4, -0.6);
		glScalef(0.3, 2.0, 0.3);
		prisma2(t_madera5.GLindex, t_madera5.GLindex);
		glPopMatrix();

		glPushMatrix(); //respaldo 2
		glTranslatef(0.6, 1.4, 0.6);
		glScalef(0.3, 2.0, 0.3);
		prisma2(t_madera5.GLindex, t_madera5.GLindex);
		glPopMatrix();

		glPushMatrix(); //respaldo 3
		glTranslatef(0.6, 2.5, 0.0);
		glScalef(0.3, 0.5, 1.5);
		prisma2(t_madera5.GLindex, t_madera5.GLindex);
		glPopMatrix();

		glPushMatrix();
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1f);
		glTranslatef(0.6, 1.3, 0.0);
		glScalef(0.3, 1.8, 0.9);
		prisma2(t_cami.GLindex, t_cami.GLindex);
		glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glPopMatrix();

		glPopMatrix();

		//hasta aquí
		glPopMatrix();
		
	//hasta aquí
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 9");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

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
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
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
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
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
  glutInitWindowSize  (5000, 5000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 9"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}