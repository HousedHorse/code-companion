#ifndef DIAGRAMCLASS_H
#define DIAGRAMCLASS_H

#include <QGraphicsObject>

class DiagramClassSection;

class DiagramClass : public QGraphicsObject {
  Q_OBJECT
  public:
    DiagramClass();
    ~DiagramClass();

    QRectF boundingRect() const;
    void   paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

    void changeTitle(const QString&);
    void addMember(const QString&);
    void changeMember(const QString&, int);
    void removeMember(int);
    void addMemberFunction(const QString&);
    void changeMemberFunction(const QString&, int);
    void removeMemberFunction(int);
  protected:
    DiagramClassSection* titleSection;
    DiagramClassSection* memberSection;
    DiagramClassSection* memberFunctionSection;

    QString           title;
    QVector<QString*> members;
    QVector<QString*> memberFunctions;
  private:
  signals:
    // signals to maintain parity with the DiagramSections
    void titleChanged(const QString&);
    void memberAdded(const QString&);
    void memberChanged(const QString&, int);
    void memberRemoved(int);
    void memberFunctionAdded(const QString&);
    void memberFunctionChanged(const QString&, int);
    void memberFunctionRemoved(int);
};

#endif
