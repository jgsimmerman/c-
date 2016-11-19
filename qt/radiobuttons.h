#ifndef RADIOBUTTONS_H
#define RADIOBUTTONS_H

#include <QWidget>

class QGroupBox;

class RadioButtons : public QWidget
{
	Q_OBJECT

	public:
		RadioButtons(QWidget *parent = 0);

	private:
		QGroupBox *radio();

};

#endif
