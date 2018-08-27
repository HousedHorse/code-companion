#ifndef DIAGRAMCLASSSECTION_H
#define DIAGRAMCLASSSECTION_H

#include <QGraphicsObject>

class DiagramClassSection : public QGraphicsObject {

  public:
    DiagramClassSection(QGraphicsItem* = 0);

    QRectF boundingRect() const;
    void   paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
  protected:
    QVector<QGraphicsTextItem*> line;
  private:

};

#endif
