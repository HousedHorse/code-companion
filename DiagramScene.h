#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>

class QPrinter;

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
