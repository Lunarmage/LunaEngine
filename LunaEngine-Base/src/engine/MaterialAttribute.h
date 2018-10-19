#include <memory>
#include <string>


struct MaterialAttribute
{
public:
std::string name;
int type;
float floatValue;
std::weak_ptr<Texture> textureValue;


};