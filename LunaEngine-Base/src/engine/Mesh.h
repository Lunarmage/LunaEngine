

#include <memory>



#include "Resource.h"


#ifndef MESH_H
#define MESH_H



class Mesh:public Resource
{
public:
~Mesh();


std::shared_ptr<Mesh> loadAndCreate(std::string path);
int getVertexCount();
void setBuffer(std::string attribute, VertexBuffer *buffer);

GLuint returnID();

private:
void setID();

std::vector<VertexBuffer *> buffers;

GLuint id;
};

#endif // !MESH_H
