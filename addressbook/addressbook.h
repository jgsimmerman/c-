#ifndef ADDRESSBOOK_H	
#define ADDRESSBOOK_H

#include <QObject>
#include <QWidget>
#include <QMap>

class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;

class AddressBook : public QWidget
{
	Q_OBJECT //for signals and slots

	public:
		AddressBook(QWidget *parent = 0);
		enum Mode {NavigationMode, AddingMode, EditingMode};
	
	public slots:
		void addContact();
		void submitContact();
		void cancel();
		void next();
		void previous();
		void editContact();
		void removeContact();

	private:
		void updateInterface(Mode mode);
		QPushButton *addButton;
		QPushButton *editButton;
		QPushButton *removeButton;
		QPushButton *submitButton;
		QPushButton *cancelButton;

		QPushButton *nextButton;
		QPushButton *previousButton;

		QLineEdit *nameLine;
		QTextEdit *addressText;
		
		QMap<QString, QString> contacts;
		QString oldName;
		QString oldAddress;
		
		Mode currentMode;
};

#endif
