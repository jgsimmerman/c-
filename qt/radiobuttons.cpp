#include <QtGui>

#include "radiobuttons.h"

RadioButtons::RadioButtons(QWidget *parent)
	: QWidget(parent)
{
	QGridLayout *grid = new QGridLayout;
	grid->addWidget(radio(), 0, 0);
	setLayout(grid);

	setWindowTitle(tr("Radio Buttons"));
	resize(480, 320);
}

QGroupBox *RadioButtons::radio()
{
	QGroupBox *groupBox = new QGroupBox(tr("Radio Buttons"));

	QRadioButton *radio1 = new QRadioButton(tr("&Qt"));
	QRadioButton *radio2 = new QRadioButton(tr("&wxWidgets"));
	QRadioButton *radio3 = new QRadioButton(tr("&MFC"));
	QRadioButton *radio4 = new QRadioButton(tr("&GTK"));
	radio1->setChecked(true);

	QPushButton *go = new QPushButton(tr("&Go"));	

	QListView *text = new QListView();

	QVBoxLayout *vbox = new QVBoxLayout;

	vbox->addWidget(text);	

	vbox->addWidget(radio1);
	vbox->addWidget(radio2);
	vbox->addWidget(radio3);
	vbox->addWidget(radio4);

	vbox->addWidget(go);

	vbox->addStretch(1);

	//QVBoxLayout *vbox2 = new QVBoxLayout;
	//vbox2->addWidget(go);

	groupBox->setLayout(vbox);
	//groupBox->setLayout(vbox2);

	return groupBox;
}
