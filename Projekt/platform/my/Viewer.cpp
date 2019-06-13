#include "Viewer.hh"
#include <iostream>
#include "Manipulator.hh"
#include <stb_image.h>
#include <qdebug.h>

using namespace std;

/**
 * @brief Contains a background texture
 * 
 */
static GLuint TextureBackground;
/**
 * @brief Contains a solar panel texture
 * 
 */
static GLuint TextureSolar;

/**
 * @brief Creates a cuboid in one color

 * @param [in] Size_X - size in x axis
 * @param [in] Size_Y - size in y axis
 * @param [in] Size_Z - size in z axis
 */
void GLCreateBox( double Size_X,  double Size_Y,  double Size_Z )
{
    glPushMatrix();
    glScalef( static_cast<GLfloat>(Size_X), static_cast<GLfloat>(Size_Y), static_cast<GLfloat>(Size_Z) );
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(  0.5, -0.5, 0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f(  0.5,  0.5, 0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, 0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();

    //RIGHT
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f( 0.5, -0.5, -0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f( 0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( 0.5,  0.5,  0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();

    //LEFT
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f( -0.5, -0.5,  0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f( -0.5,  0.5,  0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

    //TOP
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(  0.5,  0.5,  0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f(  0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();

    //BOTTOM
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(  0.5, -0.5, -0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f(  0.5, -0.5,  0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5, -0.5,  0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    glPopMatrix();
}

/**
 * @brief Creates a cuboid with solar panel texture on the front side

 * @param [in] Size_X - size in x axis
 * @param [in] Size_Y - size in y axis
 * @param [in] Size_Z - size in z axis
 */
void GLCreateTextureBox( double Size_X,  double Size_Y,  double Size_Z )
{
    glPushMatrix();
    glScalef( static_cast<GLfloat>(Size_X), static_cast<GLfloat>(Size_Y), static_cast<GLfloat>(Size_Z) );

    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, TextureSolar);

    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(  0.5, -0.5, 0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f(  0.5,  0.5, 0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, 0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();

    glDisable(GL_TEXTURE_2D);

    //RIGHT
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f( 0.5, -0.5, -0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f( 0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( 0.5,  0.5,  0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();

    //LEFT
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f( -0.5, -0.5,  0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f( -0.5,  0.5,  0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

    //TOP
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(  0.5,  0.5,  0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f(  0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5,  0.5, -0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();

    //BOTTOM
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(  0.5, -0.5, -0.5 );
    glTexCoord2f(0.0, 1.0); glVertex3f(  0.5, -0.5,  0.5 );
    glTexCoord2f(1.0, 1.0); glVertex3f( -0.5, -0.5,  0.5 );
    glTexCoord2f(1.0, 0.0); glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    glPopMatrix();
}

// Draws view
void Viewer::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, TextureBackground);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glLoadIdentity();
    glDepthMask(GL_FALSE);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();

    glLoadIdentity();
    glOrtho(0,1,1,0,-1,1);

    glColor3f(   0.0,  0.0,  1.0 );
    glBegin(GL_QUADS);  // Tworzenie kwadratu, na teksture tla
    glTexCoord2f(0,0);
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

    glDisable(GL_TEXTURE_2D);


    glScalef( 1.0, 1.0, 1.0 );

    glRotatef( -90, 1.0, 0.0, 0.0);
    glRotatef( -90, 0.0, 0.0, 1.0);
    glRotatef( static_cast<GLfloat>(Manip.GetQ0_deg()), 0.0, 0.0, 1.0 );
    glTranslatef( 0.0, 0.0, -0.5 );
    glColor3f(1.0,1.0,1.0);
    GLCreateBox(0.1,0.1,1.0);

    glTranslatef( 0.0, 0.0, 0.55 );
    glRotatef( static_cast<GLfloat>(Manip.GetQ2_deg()), 0.0, 1.0, 0 );
    GLCreateTextureBox(1.0,1.5,0.01);

    glTranslatef( 0.0, 0.0, -0.019);
    GLCreateBox(1.05,1.55,0.02);

    glFlush();
}

void Viewer::init()
{
    glClearColor (1, 1, 1, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    glGenTextures(1, &TextureBackground);
    glBindTexture(GL_TEXTURE_2D, TextureBackground);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load("laka.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        qDebug() << "Failed to load texture" << endl;
    }
    stbi_image_free(data);

    glGenTextures(1, &TextureSolar);
    glBindTexture(GL_TEXTURE_2D, TextureSolar);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width1, height1, nrChannels1;
    unsigned char *data1 = stbi_load("solar.jpg", &width1, &height1, &nrChannels1, 0);
    if (data1)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width1, height1, 0, GL_RGB, GL_UNSIGNED_BYTE, data1);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        qDebug() << "Failed to load texture" << endl;
    }
    stbi_image_free(data1);
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

