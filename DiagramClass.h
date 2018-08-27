#ifndef DIAGRAMCLASS_H
#define DIAGRAMCLASS_H

#include <QGraphicsItem>

class DiagramClass : public QGraphicsItem {

  public:
    DiagramClass();

    QRectF boundingRect() const;
    void   paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
  protected:
    QRectF titleSection;
    QRectF memberSection;
    QRectF memberFunctionSection;
  private:

};

#endif
