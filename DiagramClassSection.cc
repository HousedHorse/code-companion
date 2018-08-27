#include "DiagramClassSection.h"

#include <QtWidgets>

// default constructor
DiagramClassSection::DiagramClassSection(QGraphicsItem* parent) :
  QGraphicsObject(parent) {
  
  }

QRectF DiagramClassSection::boundingRect() const {

}

void DiagramClassSection::paint(QPainter* painter,
    const QStyleOptionGraphicsItem* option, QWidget* widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);
  painter->drawRect(boundingRect());
}
