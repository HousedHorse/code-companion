#include "MainWindow.h"
#include <QtWidgets>
#include "DiagramScene.h"
#include "DiagramClass.h"

// default constructor
MainWindow::MainWindow() : QMainWindow() {
  createGraphicsView();
  createTopBar();

  // test stuff
  DiagramClass* dClass1 = new DiagramClass();
  scene->addItem(dClass1);
}

MainWindow::~MainWindow() {
  delete view;
  for(int i = 0; i < scene->items().size(); i++) {
    delete scene->items().at(i);
  }
  delete scene;
  for(int i = 0; i < menuBar()->actions().size(); i++) {
    delete menuBar()->actions().at(i);
  }
}

void MainWindow::createGraphicsView() {
  view    = new QGraphicsView;
  scene   = new DiagramScene;
  view->setDragMode(QGraphicsView::ScrollHandDrag);
  view->setScene(scene);
  setCentralWidget(view);
}

void MainWindow::createTopBar() {
  QMenu* fileMenu = menuBar()->addMenu(tr("&File"));
  QMenu* editMenu = menuBar()->addMenu(tr("&Edit"));
  QMenu* helpMenu = menuBar()->addMenu(tr("&Help"));

  // file new
  QAction* newAction = new QAction(tr("&New"));
  newAction->setShortcut(QKeySequence::New);
  fileMenu->addAction(newAction);
  connect(newAction, SIGNAL(triggered()), this, SLOT(slotNewFile()));

  // file export
  QAction* exportAction = new QAction(tr("E&xport"));
  exportAction->setShortcut(QKeySequence(tr("ctrl+e")));
  fileMenu->addAction(exportAction);
  connect(exportAction, SIGNAL(triggered()), this, SLOT(slotExport()));

  fileMenu->addSeparator(); // separate the quit option

  // file quit
  QIcon quitIcon(":/images/exit.png");
  QAction* closeAction = new QAction(quitIcon, tr("&Quit"), this);
  closeAction->setShortcut(QKeySequence::Quit);
  fileMenu->addAction(closeAction);
  connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));

  // about help
  QIcon aboutIcon(":/images/about.png");
  QAction* aboutAction = new QAction(aboutIcon, tr("&About"), this);
  helpMenu->addAction(aboutAction);
  connect(aboutAction, SIGNAL(triggered()), this, SLOT(slotAbout()));
}

void MainWindow::slotNewFile() {
  if(promptToSave()) {
    // new file here
  }
}

void MainWindow::slotAbout() {
  QMessageBox::about(this, tr("Code Companion &trade;"),
      tr("<b>Code Companion</b> makes your life as a programmer "
        "much easier by streamlining the preliminary stages of beginning a new "
        "programming project.<br><br>Simply use the dynamic <i>UML diagram "
        "creation interface</i> to plan the UML class diagram for your project, "
        "then export your project and watch the magic.<br><br> The software will "
        "export your UML diagram to an automatically formatted PDF, and then "
        "generate the necessary skeleton code for your headers and class files.<br><br>"
        "&copy; 2018 William Findlay"));
}

void MainWindow::slotExport() {
  scene->exportToPDF(tr("test.pdf"));
}

bool MainWindow::promptToSave() {
  // return true for now
  return true;
}

void MainWindow::closeEvent(QCloseEvent* event) {
  if(promptToSave()){
    event->accept();
  } else {
    event->ignore();
  }
}
