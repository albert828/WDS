#ifndef VIEWER_HH
#define VIEWER_HH

#include <QGLViewer/qglviewer.h>



class Viewer : public QGLViewer
{
 public:
  Viewer(QWidget *pParent = nullptr): QGLViewer(pParent) {}
 protected :
  /**
   * @brief Draws all wiev
   */
  virtual void draw();
  /**
   * @brief Initialize OpenGL widget
   */
  virtual void init();
};
#endif
