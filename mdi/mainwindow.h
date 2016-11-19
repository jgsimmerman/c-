#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MdiChild;
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow();

	protected:
		void closeEvent(QCloseEvent *event);

	private slots:
		void newFile();
		void open();
		void save();
		void saveAs();
		void cut();
		void copy();
		void paste();
		void about();
		void updateMenus():
		void updateWindowMenu();
		MdiChild *createMdiChild();
		void switchLayoutDirection();
		void setActiveSubWindow(QWidget *window);

	private:
		void createActions();
		void createMenus();
		void createToolBars();
		void createStatusBar();
		void readSettings();
		void writeSettings();
		MdiChild *activeMdiChild();
		QMdiSubWindow *findMdiChild(const QString &fileName);

		QMdiArea *mdiArea;
		QSignalMapper *windowMapper;

		QMenu *fileMenu;
		QMenu *editMenu;
		QMenu *windowMenu;
		QMenu *helpMenu;
		QToolBar *fileToolBar;
		QToolBar *editTooldBar;
		QAction *newAct;
		QAction *openAct;
		QAction *saveAct;
		QAction *saveAsAct;
		QAction *exitAct;
		QAction *cutAct;
		QAction *copyAct;
		QAction *pasteAct;
		QAction *closeAct;
		QAction *closeAllAct;
		QAction *tileAct;
		QAction *cascadeAct;
		QAction *nextAct;
		QAction *previousAct;
		QAction *separatorAct;
		QAction *aboutAct;
		QAction *aboutQtAct;
};

#endif

