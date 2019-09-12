#include "pch.h"
#include <gl\glew.h>
#include <MeGlWindow.h>
#include <iostream>
#include <fstream>
#include <glm.hpp>
using namespace std;
using glm::vec3;
GLuint ColorMe;

void sendDataToOpenGL()
{
	GLfloat verts[] =
	{
		+0.0f, +1.0f,
		+1.0f, +0.0f,
		-1.0f, +0.0f,

		+0.0f, +0.0f,
		-1.0f, -1.0f,
		+1.0f, -1.0f,

		+0.0f, +1.0f,
		+1.0f, +0.0f,
		-1.0f, +0.0f,

		+0.0f, +0.0f,
		-1.0f, -1.0f,
		+1.0f, -1.0f,
	};
	GLuint VertBufferID;
	glGenBuffers(1, &VertBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, VertBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);//position
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
	glEnableVertexAttribArray(1);//color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char)(sizeof(float) * 2));

}

void MeGlWindow::paintGL()
{
	glViewport(0, 0, width(), height());
	glDrawArrays(GL_TRIANGLES, 0, 6);
}//lkjdfkljklfjadsklgfj;dsklgj;klgjfkljgfkl

void InstallShaders()
{
	GLuint vert = glCreateShader(GL_VERTEX_SHADER);
	GLuint frag = gloCreateShader(GL_FRAGMENT_SHADER);

	const char* adapt[1];
	string Vertex = readShaderCode("VertexShader.glsl");
	adapt[0] = Vertex.c_str();
	glShaderSource(vert, 1, adapt 0);

	string Fragment = readShaderCode("FragmentShader.glsl");
	adapt[0] = Fragment.c_str();
	glShaderSource(frag, 1, adapt, 0);

	glCompileShader(vert);
	glCompileShader(frag);

	ColorMe = glCreateProgram();
	glAttachShader(ColorMe, vert);
	glAttachShader(ColorMe, frag);
	glLinkProgram(ColorMe);

	glUseProgram(ColorMe);
}

void MeGLWindow::initializeGL()
{
	glewInit();
	sendDataToOpenGL();
	InstallShaders();
}

void MeGLWindow::paintGL();
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, width(), height());

	GLint Color = glGetUniformLocation(ColorMe, "Color");
	glUniform3f(Color, 0.0f, 1.0f, 1.0f);

	glm::vec2 TriangleOffset;
	GLint offsetUniformLoc = glGetUniformLocation(ColorMe, "Offset");
	glUniform2f(offsetUniformLoc, TriangleOffset[0], TriangleOffset[1]);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0); //draw indices info
}