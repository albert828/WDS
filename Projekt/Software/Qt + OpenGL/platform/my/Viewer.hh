#ifndef VIEWER_HH
#define VIEWER_HH

#include <QGLViewer/qglviewer.h>


/**
 * @brief Viever class : used to drawing OpenGL widget
 * 
 */
class Viewer : public QGLViewer
{
 public:
 /**
  * @brief Constructor of the Viever class
  * 
  */
  Viewer(QWidget *pParent = nullptr): QGLViewer(pParent) {}
 protected :
  /**
   * @brief It's overrided from QGLViever class. Draws OpenGL view. 
   Draws background texture. Draws
    solar platform objects with textures. Changes position of objects.
   */
  virtual void draw();
  /**
   * @brief Initialize OpenGL widget and loads textures.
   */
  virtual void init();
};
#endif
