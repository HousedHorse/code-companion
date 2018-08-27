TEMPLATE = app
TARGET   = code-companion

QT = core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES  += main.cc MainWindow.cc DiagramScene.cc DiagramClass.cc DiagramClassSection.cc
HEADERS  += MainWindow.h DiagramScene.h DiagramClass.h DiagramClassSection.h
RESOURCES = code-companion.qrc
