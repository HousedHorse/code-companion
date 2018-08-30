#ifndef MEMBERFUNCTION_H
#define MEMBERFUNCTION_H

#include "DataMember.h"

class MemberFunction : DataMember {

  public:
    MemberFunction();
    ~MemberFunction();
  protected:
    QVector<QString*> arguments;
  private:

};

#endif
