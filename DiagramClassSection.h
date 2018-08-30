#ifndef DIAGRAMCLASSSECTION_H
#define DIAGRAMCLASSSECTION_H

#define MARGIN         5
#define WIDTH        300
#define LINE_SPACING   0
#define WIDTH_WITH_MARGINS WIDTH + 2 * MARGIN

#include <QGraphicsObject>

class DiagramClassSection : public QGraphicsObject {
  Q_OBJECT
  friend class DiagramClass;
  public:
    enum Type {Title, Member, MemberFunction};

    DiagramClassSection(QGraphicsItem* = 0, Type = Title);
    ~DiagramClassSection();

    QRectF boundingRect() const;
    void   paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    qreal height();
    qreal width();
  protected:
    Type type;
    QVector<QGraphicsTextItem*> lines;
  protected slots:
    // slots to maintain parity with the DiagramClass
    void slotLineAdded(const QString&);
    void slotLineChanged(const QString&, int);
    void slotLineRemoved(int);
};

#endif
