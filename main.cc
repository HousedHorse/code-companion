#include <QApplication>
#include "MainWindow.h"

int main(int argc, char** argv) {

  QApplication app(argc, argv);

  MainWindow view;
  view.show();

  return app.exec();

}
