#include "OpenGLWindow.h"
#include <QtCore/qcoreapplication.h>
#include <QtGui/qopenglcontext.h>
#include <QtGui/qopenglpaintdevice.h>
#include <QtGui/qpainter.h>
#include <iostream>

OpenGLWindow::OpenGLWindow(QWindow *parent)
	: QWindow(parent)
	, m_animating(false)
	, m_context(0) //to my understanding is effectively the model, represents the OpenGL state of an underlying openGL context, enables rendering on a surface
	, m_device(0)//enables painting to an OpenGL context using QPainter, enables painting to a context (context->painting->surface render)
{
	setSurfaceType(QWindow::OpenGLSurface); //say window is for OpenGLRendering
}
OpenGLWindow::~OpenGLWindow()
{
	delete m_device;
}
void OpenGLWindow::render(QPainter *painter)
{
	//Q_UNUSED(painter);
}
void OpenGLWindow::render() //initializes a QOpenGLpaintDevice and calls into Render QPainter
{
	if (!m_device)
		m_device = new QOpenGLPaintDevice();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); //clear colors
	m_device->setSize(size() * devicePixelRatio()); //tell openGL size
	m_device->setDevicePixelRatio(devicePixelRatio());  //say pixel ratio

	QPainter painter(m_device); //make a painter using painter device m_device
	render(&painter); //render using said painter

}
void OpenGLWindow::initialize() //opengl initialization
{
}
void OpenGLWindow::renderLater()//schedule update when system is ready to repaint
{
	requestUpdate();
}
void OpenGLWindow::renderNow() //openGL commands!
{
	if (!isExposed())//make sure screen is visible
		return;
	bool needsInitialize = false;
	if (!m_context){// if we haven't made a context yet, make a QOpenGLContext with same QSurfaceFormat as was set on OpenGLWindow, initialize the subclass, and initialize OpenGLFunctions() to associate super class with context
		m_context = new QOpenGLContext(this);
		m_context->setFormat(requestedFormat());
		m_context->create();
		needsInitialize = true;
	}
	m_context->makeCurrent(this); //enables OpenGL commands to be used, initiates rendering of a frame and gives the surface to render as a parameter (aka the window)

	if (needsInitialize)// aka if there was no context
	{
		initializeOpenGLFunctions();
		initialize();
	}
	render();

	m_context->swapBuffers(this);//still not sure what swapbuffers does...
	if (m_animating) //schedule an update request (aka event will fire->renderNow)
		renderLater();
}

bool OpenGLWindow::event(QEvent *event) //not quite sure what this is
{
	switch (event->type())
	{
	case QEvent::UpdateRequest:
		renderNow();
		return true;
	default:
		//std::cout << "we did it";
		return QWindow::event(event);//ask how this is ddifferent from just return event
	}
}
void OpenGLWindow::exposeEvent(QExposeEvent *event) //visibility on screen has changed
{
	//Q_UNUSED(event);
	if (isExposed()) //make sure the window is exposed
		renderNow();
}
void OpenGLWindow::setAnimating(bool animating)
{
	m_animating = animating;
	if (animating)
		renderLater();
}
