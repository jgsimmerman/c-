#include <QtGui>
 #include <QtWebKit>
 #include "mainwindow.h"

 MainWindow::MainWindow()
 {
     createActions();
     createMenus();
     centralWidget = new Previewer(this);
     setCentralWidget(centralWidget);

     connect(centralWidget->webView, SIGNAL(loadFinished(bool)),
         this, SLOT(updateTextEdit()));
     setStartupText();
 }

 void MainWindow::createActions()
 {
     openAct = new QAction(tr("&Open..."), this);
     openAct->setShortcuts(QKeySequence::Open);
     openAct->setStatusTip(tr("Open an existing HTML file"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     openUrlAct = new QAction(tr("&Open URL..."), this);
     openUrlAct->setShortcut(tr("Ctrl+U"));
     openUrlAct->setStatusTip(tr("Open a URL"));
     connect(openUrlAct, SIGNAL(triggered()), this, SLOT(openUrl()));

     saveAct = new QAction(tr("&Save"), this);
     saveAct->setShortcuts(QKeySequence::Save);
     saveAct->setStatusTip(tr("Save the HTML file to disk"));
     connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

     exitAct = new QAction(tr("E&xit"), this);
     exitAct->setStatusTip(tr("Exit the application"));
     exitAct->setShortcuts(QKeySequence::Quit);
     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

     aboutAct = new QAction(tr("&About"), this);
     aboutAct->setStatusTip(tr("Show the application's About box"));
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

     aboutQtAct = new QAction(tr("About &Qt"), this);
     aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
     connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
 }

 void MainWindow::createMenus()
 {
     fileMenu = menuBar()->addMenu(tr("&File"));
     fileMenu->addAction(openAct);
     fileMenu->addAction(openUrlAct);
     fileMenu->addAction(saveAct);
     fileMenu->addSeparator();
     fileMenu->addAction(exitAct);

     menuBar()->addSeparator();

     helpMenu = menuBar()->addMenu(tr("&Help"));
     helpMenu->addAction(aboutAct);
     helpMenu->addAction(aboutQtAct);
 }

 void MainWindow::about()
 {
     QMessageBox::about(this, tr("About Previewer"),
         tr("The <b>Previewer</b> example demonstrates how to "
            "view HTML documents using a QWebView."));
 }

 void MainWindow::open()
 {
     QString fileName = QFileDialog::getOpenFileName(this);
     if (!fileName.isEmpty()) {
         // read from file
         QFile file(fileName);

         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::information(this, tr("Unable to open file"),
                 file.errorString());
             return;
         }

         QTextStream out(&file);
         QString output = out.readAll();

         // display contents
         centralWidget->plainTextEdit->setPlainText(output);
         centralWidget->setBaseUrl(QUrl::fromLocalFile(fileName));
     }
 }

 void MainWindow::openUrl()
 {
     bool ok;
     QString url = QInputDialog::getText(this, tr("Enter a URL"),
                   tr("URL:"), QLineEdit::Normal, "http://", &ok);

     if (ok && !url.isEmpty()) {
         centralWidget->webView->setUrl(url);
     }
 }

 void MainWindow::save()
 {
     QString content = centralWidget->plainTextEdit->toPlainText();
     QString fileName = QFileDialog::getSaveFileName(this);

     if (!fileName.isEmpty()) {
         // save to file
         QFile file(fileName);

         if (!file.open(QIODevice::WriteOnly)) {
             QMessageBox::information(this, tr("Unable to open file"),
                 file.errorString());
             return;
         }

         QTextStream in(&file);
         in << content;
     }
 }

 void MainWindow::updateTextEdit()
 {
     QWebFrame *mainFrame = centralWidget->webView->page()->mainFrame();
     QString frameText = mainFrame->toHtml();
     centralWidget->plainTextEdit->setPlainText(frameText);
 }

 void MainWindow::setStartupText()
 {
     QString string = "<html><body><h1>HTML Previewer</h1>"
                      " <p>This example shows you how to use QWebView to"
                      " preview HTML data written in a QPlainTextEdit.</p>"
                      " </body></html>";
     centralWidget->webView->setHtml(string);
 }
