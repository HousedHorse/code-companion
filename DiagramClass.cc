#include "DiagramClass.h"

#include <QtWidgets>

// default constructor
DiagramClass::DiagramClass() : QGraphicsItem() {
  titleSection = QRectF(0, 0, 200, 20);
  memberSection = QRectF(0, 20, 200, 20);
  memberFunctionSection = QRectF(0, 40, 200, 20);
}

QRectF DiagramClass::boundingRect() const {
  qreal height = titleSection.height() +
                 memberSection.height() +
                 memberFunctionSection.height();

  qreal width = 200;

  return QRectF(0, 0, width, height);
}

void DiagramClass::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
    QWidget* widget = 0) {
  Q_UNUSED(option);
  Q_UNUSED(widget);

  painter->drawRect(titleSection);
  painter->drawRect(memberSection);
  painter->drawRect(memberFunctionSection);
  painter->drawRect(boundingRect());
}
