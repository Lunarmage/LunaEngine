
#include "Resource.h"
#include "GL/glew.h"
#include <memory>

class Texture: public Resource
{
public:
GLuint getID();
void load(std::string path);


private:
GLuint id;




int type;
};