#pragma once
#include "openglwindow.h"
#include <qopenglshaderprogram.h>
#include <qscreen.h>
#include <ParticleSystem.h>

static const char *vertexShaderSource =
"precision highp float;\n"
"attribute vec4 posAttr;\n"
"attribute vec4 colAttr;\n"
"varying  vec4 col;\n"
"uniform  mat4 matrix;\n"
"attribute float radius;\n"
"void main() {\n"
"   col = colAttr;\n"
"	gl_PointSize=radius;\n"
"   gl_Position = matrix * posAttr;\n"
"}\n";

static const char *fragmentShaderSource =
"precision highp float;\n"
"varying  vec4 col;\n"
"void main() {\n"
"   gl_FragColor = col;\n"
"}\n";

class ParticleSystemWindow :public OpenGLWindow
{
public:
	ParticleSystem *particles;
	ParticleSystemWindow();
	void initialize() override;
	void render() override;
	void render(GLfloat* vertices, GLfloat* colors);
private:
	GLuint m_posAttr;
	GLuint m_colAttr;
	GLuint m_matrixUniform;
	GLuint radius;

	QOpenGLShaderProgram *m_program; //shading!
	int m_frame;
};

void ParticleSystemWindow::initialize()
{
	m_program = new QOpenGLShaderProgram(this); //new shader program
	m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);//add vertex
	m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);//add fragment
	m_program->link();//link to window, for qt
	m_posAttr = m_program->attributeLocation("posAttr"); //
	m_colAttr = m_program->attributeLocation("colAttr");
	m_matrixUniform = m_program->uniformLocation("matrix");
	radius = m_program->attributeLocation("radius");
	glEnable(GL_PROGRAM_POINT_SIZE);
}
void ParticleSystemWindow::render(GLfloat* vertices, GLfloat* colors)
{
	/*const qreal retinaScale = devicePixelRatio();
	glViewport(0, 0, width() * retinaScale, height() * retinaScale);

	glClear(GL_COLOR_BUFFER_BIT);

	m_program->bind(); //bind shader, for OpenGL

	QMatrix4x4 matrix;
	matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	matrix.translate(0, 0, -2);
	//perform physics rotation here
	//turn input into vertices/colors here
	//glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);
	glVertexAttribPointer(radius,1,GL_FLOAT,GL_FALSE,0,)

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawArrays(GL_POINTS, 0, 10);

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	m_program->release();

	++m_frame;*/

}
void ParticleSystemWindow::render()
{
	const qreal retinaScale = devicePixelRatio();
	glViewport(0, 0, width() * retinaScale, height() * retinaScale);

	glClear(GL_COLOR_BUFFER_BIT);

	m_program->bind(); //bind shader, for OpenGL

	QMatrix4x4 matrix;
	matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	matrix.translate(0, 0, -100);
	particles->PerformPhysics();
	
	//matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0, 0, 1);//gives us the moving triangle

	m_program->setUniformValue(m_matrixUniform, matrix);

	/*GLfloat vertices[] = {
		0.0f, 0.707f,
		-0.5f, -0.5f,
		0.5f, -0.5f
	};*/
	GLfloat *vertices=particles->getVertices();
	GLfloat *radii = particles->getRadii();
	GLfloat *colors = particles->getColors();
/*	GLfloat vertices[] = {
	0.0f, 0.707f,
	-0.5f, -0.5f,
	0.5f, -0.5f
	};*/


	glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);
	glVertexAttribPointer(radius, 1, GL_FLOAT, GL_FALSE, 0, radii);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glDrawArrays(GL_POINTS, 0, particles->particles.size());

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(2);

	m_program->release();

	++m_frame;
}
ParticleSystemWindow::ParticleSystemWindow()
	: m_program(0)
	, m_frame(0)
{
}