#include "Resource.h"

class Mesh:public Resource
{
public:
~Mesh();
void addFace(


private:
std::shared_ptr<Mesh> create();
std::shared_prt<Mesh> load(std::string path);

};