#ifndef MAINWINDOW_H
 #define MAINWINDOW_H

 #include <QMainWindow>
 #include "previewer.h"

 class QAction;
 class QMenu;

 class MainWindow : public QMainWindow
 {
     Q_OBJECT

 public:
     MainWindow();

 private slots:
     void open();
     void openUrl();
     void save();
     void about();
     void updateTextEdit();

 private:
     Previewer *centralWidget;
     QMenu *fileMenu;
     QMenu *helpMenu;
     QAction *openAct;
     QAction *openUrlAct;
     QAction *saveAct;
     QAction *exitAct;
     QAction *aboutAct;
     QAction *aboutQtAct;

     void createActions();
     void createMenus();
     void setStartupText();
 };

 #endif
