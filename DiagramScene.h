#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>

class QPrinter;

// this class is a wrapper for QGraphicsScene that adds the
// ability to export the scene to PDF

class DiagramScene : public QGraphicsScene{
  Q_OBJECT
  public:
    DiagramScene(QWidget* = 0);
    ~DiagramScene();
    void exportToPDF(const QString&);
  protected:
    QPrinter *printer;
  private:

};

#endif
