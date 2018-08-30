#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGraphicsView;
class QGraphicsScene;
class DiagramScene;

class MainWindow : public QMainWindow {
  Q_OBJECT
  public:
    MainWindow();
    ~MainWindow();
  protected:
    void createGraphicsView();
    void createTopBar();
    void createStatusBar();

    bool promptToSave();

    void closeEvent(QCloseEvent*);

    QGraphicsView*  view;
    DiagramScene*   scene;
  private:
  protected slots:
    void slotNewFile();
    void slotAbout();
    void slotExport();
};

#endif
