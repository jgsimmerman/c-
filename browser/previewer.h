#ifndef PREVIEWER_H
 #define PREVIEWER_H

 #include "ui_previewer.h"

 class Previewer : public QWidget, public Ui::Form
 {
     Q_OBJECT

 public:
     Previewer(QWidget *parent = 0);

     void setBaseUrl(const QUrl &url);

 public slots:
     void on_previewButton_clicked();

 private:
     QUrl baseUrl;
 };

 #endif
