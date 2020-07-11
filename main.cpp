#include <QtWidgets/QApplication>
#include <openglwindow.h>
#include <QtGui/qopenglshaderprogram.h>
#include <QtGui/qscreen.h>
#include <ParticleSystemWindow.h>
#include <QtWidgets/qpushbutton.h>
#include <qboxlayout.h>
#include <iostream>
#include <menu.h>
#include <ParticleSystem.h>
#include <qslider.h>
#include <QtWidgets>
#include <qabstractslider.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QSurfaceFormat format;
	format.setSamples(16);//4 samples of multisample AA and default geometry
	ParticleSystemWindow window;
	//a.setActiveWindow(*window);
	
	ParticleSystem* particles = new ParticleSystem();

	
	
	
	window.setFormat(format);
	window.particles = particles;
	window.resize(640, 480);
	window.setTitle("Particle Simulation");
	Menu* menu=new Menu;


	QVBoxLayout *layout = new QVBoxLayout();
	QPushButton *insertAttractor = new QPushButton("Insert Attractor");
	QPushButton *insertRepulsor = new QPushButton("Insert Repulsor");
	QPushButton *clear = new QPushButton("Clear Particles");
	QPushButton *particleAdder = new QPushButton("Add random Particle");
	QPushButton *generatorAdder = new QPushButton("Add Generator");

	QSlider *slider = new QSlider(Qt::Horizontal);
	slider->setRange(1, 10);
	slider->setValue(5);
	slider->setSingleStep(1);


	layout->addWidget(insertAttractor);
	layout->addWidget(insertRepulsor);
	layout->addWidget(clear);
	layout->addWidget(particleAdder);
	layout->addWidget(generatorAdder);




	layout->addWidget(slider);
	menu->connect(insertAttractor, SIGNAL(released()), particles, SLOT(AttractorButton()));
	menu->connect(insertRepulsor, SIGNAL(released()), particles, SLOT(RepulsorButton()));
	menu->connect(clear, SIGNAL(released()), particles, SLOT(ClearButton()));
	menu->connect(particleAdder, SIGNAL(released()), particles, SLOT(ParticleButton()));
	menu->connect(generatorAdder, SIGNAL(released()), particles, SLOT(GeneratorButton()));
	//slider->valueChanged->connect(particles, SLOT(ChangeFriction(int)));
	//menu->connect(slider, SIGNAL(sliderMoved()), particles, SLOT(ChangeFriction(int)));
	menu->connect(slider, SIGNAL(valueChanged(int)), particles, SLOT(ChangeMass(int)));
	//menu->connect(slider,SIGNAL valueChanged())

	menu->setLayout(layout);
	menu->setWindowTitle("Particle System Menu");
	

	

	
	//train_button->setText(tr("something"));
	//setCentralWidget(wdg);
	window.show();
	menu->show();
	//menu2->show();
	window.setAnimating(true);
	
	return a.exec();
}
