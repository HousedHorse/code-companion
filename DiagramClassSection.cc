#include "DiagramClassSection.h"

#include <QtWidgets>

// default constructor
DiagramClassSection::DiagramClassSection(QGraphicsItem* parent, Type t) :
  QGraphicsObject(parent) { type = t; }

// destructor
DiagramClassSection::~DiagramClassSection() { }

// calclulate and return bounding rectangle of the graphics object
QRectF DiagramClassSection::boundingRect() const {
  qreal width  = 0;
  qreal height = 0;

  // calculate width
  // base width + 2 margin widths
  width = WIDTH + 2 * MARGIN;

  // calculate height
  height = 2 * MARGIN; // add 2 margin heights
  for(int i = 0; i < lines.size(); i++) {
    // add the height of each line of text
    height += lines.at(i)->boundingRect().height();
    // add line spacing for each line that is not the last
    // line spacing is currently 0 anyway, but in the future this might change
    if(i < lines.size() - 1) height += LINE_SPACING;
  }

  // set a minimum height of 50 for a section
  // may want to do this in a more clever way in the future
  if(height < 50)
    height = 50;

  // return the bounding rectangle
  return QRectF(0, 0, width, height);
}

void DiagramClassSection::paint(QPainter* painter,
    const QStyleOptionGraphicsItem* option, QWidget* widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);

  // draw the bounding rect
  painter->drawRect(boundingRect());

  // determine position for lines of text
  // start with a point one margin height and width away from the top left corner
  QPointF position;
  position.setX(MARGIN);
  position.setY(MARGIN);
  QPointF dPosition; // delta position which will be used to move it down for each line


  for(int i = 0; i < lines.size(); i++) {
    if(lines.at(i)){
      // set the position of each line
      lines.at(i)->setPos(position);
      
      // set the delta position (0, height of line + any spacing)
      dPosition.setX(0);
      dPosition.setY(lines.at(i)->boundingRect().height() + LINE_SPACING);
      // shift position by delta position for the next line
      position += dPosition;
    }
  }
}

// some convenience methods to return the height and width of the section
qreal DiagramClassSection::height() { return boundingRect().height(); }
qreal DiagramClassSection::width() { return boundingRect().width(); }

// whenever a line is added to the class,
// add its graphical representation to the section
void DiagramClassSection::slotLineAdded(const QString& line) {
  // we need to check to see if it is the title section
  // since there can only be one title
  if(type == Title) {
    if(lines.size() == 0) {
      lines.append(new QGraphicsTextItem(line, this));
    }
    else
      // if the class already has a title, change the current one
      // instead of addign a new one
      if(lines.at(0)) {
        lines.at(0)->setPlainText(line);
      }
  } else {
    lines.append(new QGraphicsTextItem(line, this));
  }

  // set tooptip for each line of text
  QGraphicsItem* currLine = lines.at(lines.size() - 1);
  if(currLine) {
    switch(type) {
      case Title:
        currLine->setToolTip("Name of the class");
        break;
      case Member:
        currLine->setToolTip("Data member of the class");
        break;
      case MemberFunction:
        currLine->setToolTip("Member function of the class");
        break;
    }
  }
}

// whenever a line is modified in the class,
// change its graphical representation as well
void DiagramClassSection::slotLineChanged(const QString& newLine, int i) {
  if(i > 0 && i < lines.size()){
    if(lines.at(i))
      lines.at(i)->setPlainText(newLine);
  }
}

// whenever a line is removed from the class,
// remove its graphical representation as well
void DiagramClassSection::slotLineRemoved(int i) {
  if(i > 0 && i < lines.size()){
    QGraphicsTextItem* old = lines.at(i);
    old->setParentItem(0);
    delete old;
    lines.remove(i);
  }
}
