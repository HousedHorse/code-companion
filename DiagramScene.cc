#include "DiagramScene.h"

#include <QtWidgets>
#include <QPrinter>

// default constructor
DiagramScene::DiagramScene(QWidget* parent) : QGraphicsScene(parent) {
  printer = new QPrinter(QPrinter::HighResolution);
}

DiagramScene::~DiagramScene() {
  delete printer;
}

void DiagramScene::exportToPDF(const QString& fileName) {
  printer->setPageSize(QPrinter::A4);
  printer->setOrientation(QPrinter::Portrait);
  printer->setOutputFormat(QPrinter::PdfFormat);
  printer->setOutputFileName(fileName);

  QPainter p;
  if(!p.begin(printer)) {
    qDebug() << "Error exporting diagram to PDF!";
    return;
  }
  render(&p);
  p.end();
}
