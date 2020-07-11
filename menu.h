#pragma once



#include <QMainWindow>
#include <qpushbutton.h>




class Menu : public QWidget
{
	Q_OBJECT
public:
	explicit Menu(QWidget *parent = 0) {}
private:
	QPushButton *m_button;

};
