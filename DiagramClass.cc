#include "DiagramClass.h"
#include "DiagramClassSection.h"

#include <QtWidgets>

// default constructor
DiagramClass::DiagramClass() : QGraphicsObject() {
  // create the three sections and set their section type
  titleSection          = new DiagramClassSection(this, DiagramClassSection::Title);
  memberSection         = new DiagramClassSection(this, DiagramClassSection::Member);
  memberFunctionSection = new DiagramClassSection(this,
      DiagramClassSection::MemberFunction);

  // set tooltip for each section
  titleSection->setToolTip("Title");
  memberSection->setToolTip("Data members");
  memberFunctionSection->setToolTip("Member functions");

  // title section signal/slot
  connect(this, SIGNAL(titleChanged(const QString&)),
      titleSection, SLOT(slotLineAdded(const QString&)));

  // members section signals/slots
  connect(this, SIGNAL(memberAdded(const QString&)),
      memberSection, SLOT(slotLineAdded(const QString&)));
  connect(this, SIGNAL(memberChanged(const QString&, int)),
      memberSection, SLOT(slotLineChanged(const QString&, int)));
  connect(this, SIGNAL(memberRemoved(int)),
      memberSection, SLOT(slotLineRemoved(int)));

  // member functions section signals/slots
  connect(this, SIGNAL(memberFunctionAdded(const QString&)),
      memberFunctionSection, SLOT(slotLineAdded(const QString&)));
  connect(this, SIGNAL(memberFunctionChanged(const QString&, int)),
      memberFunctionSection, SLOT(slotLineChanged(const QString&, int)));
  connect(this, SIGNAL(memberFunctionRemoved(int)),
      memberFunctionSection, SLOT(slotLineRemoved(int)));

  // some test code
  changeTitle("Unnamed Class");
  addMember("Member 1");
  addMember("Member 2");
  addMember("Member 3");
  addMember("Member 4");
  addMember("Member 5");
  addMember("Member 6");
  changeMember("Changed Member", 3);
  changeMember("Changed Member", 99);
  changeMember("Changed Member", -1);
}

// destructor 
DiagramClass::~DiagramClass() {
  // delete members
  for(int i = 0; i < members.size(); i ++) {
    delete members.at(i);
  }

  // delete member functions
  for(int i = 0; i < memberFunctions.size(); i ++) {
    delete memberFunctions.at(i);
  }
}

// calculate bounding rect of the class
QRectF DiagramClass::boundingRect() const {
  // height is the sum of all section heights
  qreal height = titleSection->boundingRect().height() +
                 memberSection->boundingRect().height() +
                 memberFunctionSection->boundingRect().height();

  // width is the set width + the margins
  qreal width = WIDTH + 2 * MARGIN;

  return QRectF(0, 0, width, height);
}

void DiagramClass::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
    QWidget* widget = 0) {
  Q_UNUSED(option);
  Q_UNUSED(widget);

  // move member section down by the height of the title section
  memberSection->setPos(0, titleSection->height());
  // move member function section down by the height of the title section
  // and the member section
  memberFunctionSection->setPos(0, memberSection->height() + titleSection->height());

  // draw the bounding rect
  // this shouldnt strictly be necessary anymore,
  // I may change this
  painter->drawRect(boundingRect());
}

// change the title (name) of the class
void DiagramClass::changeTitle(const QString& t) {
  title = t;
  emit titleChanged(t);
}

// add a member to the class
void DiagramClass::addMember(const QString& m) {
  members.append(new QString(m));
  emit memberAdded(m);
}

// change a member in the class
void DiagramClass::changeMember(const QString& m, int i) {
  if(i > 0 && i < members.size()){
    QString* old = members.at(i);
    members[i] = new QString(m);
    delete old;
    emit memberChanged(m, i);
  }
}

// remove a member from the class
void DiagramClass::removeMember(int i) {
  if(i > 0 && i < members.size()){
    QString* old = members.at(i);
    delete old;
    members.remove(i);
    emit memberRemoved(i);
  }
}

// add a member function the class
void DiagramClass::addMemberFunction(const QString& m) {
  memberFunctions.append(new QString(m));
  emit memberAdded(m);
}

// change a member function in the class
void DiagramClass::changeMemberFunction(const QString& m, int i) {
  if(i > 0 && i < memberFunctions.size()){
    QString* old = memberFunctions.at(i);
    memberFunctions[i] = new QString(m);
    delete old;
    emit memberChanged(m, i);
  }
}

// remove a member function from the class
void DiagramClass::removeMemberFunction(int i) {
  if(i > 0 && i < memberFunctions.size()){
    QString* old = memberFunctions.at(i);
    delete old;
    memberFunctions.remove(i);
    emit memberRemoved(i);
  }
}
