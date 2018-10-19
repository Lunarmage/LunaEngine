#include "Resource.h"

class Texture: public Resource
{
public:
GLuint getID();



private:
GLuint id;
std::shared_ptr<Texture> load(std::string path);
std::shared_ptr<Texture> create(int width,int height);

int type;
};