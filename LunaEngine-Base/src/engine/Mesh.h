#include <GL\glew.h>

#include <memory>
#include <string>
#include"VertexBuffer.h"

#include "Resource.h"


#ifndef MESH_H
#define MESH_H



class Mesh:public Resource
{
public:

~Mesh();

void load(std::string path);
int getVertexCount();
void setBuffer(std::string attribute, VertexBuffer *buffer);

GLuint returnID();

private:
void setID();

std::vector<VertexBuffer *> buffers;
void splitString(std::string& input, char splitter, std::vector<std::string>& output);

void splitStringWhitespace(std::string& input, std::vector<std::string>& output);
GLuint id;

};

#endif // !MESH_H
