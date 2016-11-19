#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

class QWebView;
class QLineEdit;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow();

	protected slots:
		
		void adjustLocation();
		void changeLocation();
		void adjustTitle();
		void setProgress(int p);
		void finishLoading(bool);

		void highlightAllLinks();
		void rotateImages(bool invert);
		void removeGifImages();
		void removeInlineFrames();
		void removeObjectElements();
		void removeEmbeddedElements();

	private:
		QString jQuery;
		QWebView *view;
		QLineEdit *locationEdit;
		QAction *rotateAction;
		int progress;

};

#endif
