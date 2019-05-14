#include "Viewer.hh"
#include <iostream>
#include "Manipulator.hh"
#include <SOIL/SOIL.h>

#define COMPILE_TEXTURES 0

using namespace std;
#if COMPILE_TEXTURES == 1
#define HEIGHT__CHECK_BOARD 64
#define WIDTH__CHECK_BOARD  64
static GLubyte Image_CheckBoard[HEIGHT__CHECK_BOARD][WIDTH__CHECK_BOARD][4];
static GLuint Texture4Bg;
static GLuint Texture4Manip;


void MakeImage_CheckBoard(void)
{
    int Idx_Height, Idx_Width, Intensity;
    
    for (Idx_Height = 0; Idx_Height < HEIGHT__CHECK_BOARD; Idx_Height++) {
        for (Idx_Width = 0; Idx_Width < WIDTH__CHECK_BOARD; Idx_Width++) {
            Intensity = (((Idx_Height & 0x8)==0)^((Idx_Width & 0x8)==0))*255;
            Image_CheckBoard[Idx_Height][Idx_Width][0] = static_cast<GLubyte>(Intensity);
            Image_CheckBoard[Idx_Height][Idx_Width][1] = static_cast<GLubyte>(Intensity);
            Image_CheckBoard[Idx_Height][Idx_Width][2] = static_cast<GLubyte>(Intensity);
            Image_CheckBoard[Idx_Height][Idx_Width][3] = static_cast<GLubyte>(255);
        }
    }
}
#endif
void GLCreateBox( double Size_X,  double Size_Y,  double Size_Z )
{
    glPushMatrix();
    glScalef( static_cast<GLfloat>(Size_X), static_cast<GLfloat>(Size_Y), static_cast<GLfloat>(Size_Z) );

    glBegin(GL_POLYGON);
    //glColor3f(   1.0,  1.0, 1.0 );
    glTexCoord2f(0.0, 0.0); glVertex3f(  0.5, -0.5, 0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f(  0.5,  0.5, 0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, 0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_POLYGON);
    // glColor3f(  1.0,  0.0,  1.0 );
    glTexCoord2f(0.0, 0.0); glVertex3f( 0.5, -0.5, -0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f( 0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( 0.5,  0.5,  0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();

    // Green side - LEFT
    glBegin(GL_POLYGON);
    // glColor3f(   0.0,  1.0,  0.0 );
    glTexCoord2f(0.0, 0.0); glVertex3f( -0.5, -0.5,  0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f( -0.5,  0.5,  0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

    // Blue side - TOP
    glBegin(GL_POLYGON);
    // glColor3f(   0.0,  0.0,  1.0 );
    glTexCoord2f(0.0, 0.0); glVertex3f(  0.5,  0.5,  0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f(  0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    //   glColor3f(   1.0,  0.0,  0.0 );
    glTexCoord2f(0.0, 0.0); glVertex3f(  0.5, -0.5, -0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f(  0.5, -0.5,  0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5, -0.5,  0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    glPopMatrix();
}

// Draws a spiral
void Viewer::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*-----------------------------------------------------
    *  Tworzenie tła wypełnionego wygenerowaną teksturą
    */
#if COMPILE_TEXTURES == 1
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, Texture4Bg);
#endif

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glLoadIdentity();
    glDepthMask(GL_FALSE);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();

    glLoadIdentity();
    glOrtho(0,1,1,0,-1,1);

    glColor3f(   0.0,  0.0,  1.0 );
    glBegin(GL_QUADS);  // Tworzenie kwadratu, na którym będzie
    glTexCoord2f(0,0); // rozpięta tekstura tła.
    glVertex2f(0,0);

    glTexCoord2f(1,0);
    glVertex2f(1,0);

    glTexCoord2f(1,1);
    glVertex2f(1,1);

    glTexCoord2f(0,1);
    glVertex2f(0,1);
    glEnd();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glDepthMask(GL_TRUE);
    /*- Koniec ---
   *  Tworzenie tła wypełnionego
   *------------------------------------------------------------*/
#if COMPILE_TEXTURES == 1
    glBindTexture(GL_TEXTURE_2D, Texture4Manip);

    glDisable(GL_TEXTURE_2D);
#endif
    glScalef( 1.0, 1.0, 1.0 );

    glRotatef( -90, 1.0, 0.0, 0.0);
    glRotatef( -90, 0.0, 0.0, 1.0);
    glRotatef( static_cast<GLfloat>(Manip.GetQ0_deg()), 0.0, 0.0, 1.0 );
    glTranslatef( 0.0, 0.0, -0.5 );
    glColor3f(1.0,1.0,1.0);
    GLCreateBox(0.1,0.1,1.0);
#if COMPILE_TEXTURES == 1
    glBindTexture(GL_TEXTURE_2D, Texture4Manip);
    glEnable(GL_TEXTURE_2D);
#endif
    glTranslatef( 0.0, 0.0, 0.55 );
    glRotatef( static_cast<GLfloat>(Manip.GetQ2_deg()), 0.0, 1.0, 0 );
    GLCreateBox(1.0,1.5,0.01);

    glFlush();
#if COMPILE_TEXTURES == 1
    glDisable(GL_TEXTURE_2D);
#endif
}

void Viewer::init()
{
    glClearColor (1, 1, 1, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
#if COMPILE_TEXTURES == 1
    MakeImage_CheckBoard();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    //even better quality, but this will do for now.
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    //to the edge of our shape.
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIDTH__CHECK_BOARD,
                 HEIGHT__CHECK_BOARD, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 Image_CheckBoard);

    Texture4Bg = SOIL_load_OGL_texture(
                "laka.jpg",
                //"solar.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );
    //Moje
    Texture4Manip = SOIL_load_OGL_texture(
                "solar.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );
#endif
}

