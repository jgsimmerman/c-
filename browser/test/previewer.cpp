#include <QtGui>
 #include "previewer.h"

 Previewer::Previewer(QWidget *parent)
     : QWidget(parent)
 {
     setupUi(this);
 }

 void Previewer::setBaseUrl(const QUrl &url)
 {
     baseUrl = url;
 }

 void Previewer::on_previewButton_clicked()
 {
     // Update the contents in web viewer
     QString text = plainTextEdit->toPlainText();
     webView->setHtml(text, baseUrl);
 }
