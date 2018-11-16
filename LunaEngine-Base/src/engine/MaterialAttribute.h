

#include <memory>
#include <string>

class Texture;

struct MaterialAttribute
{
public:
std::string name;
int type;
float floatValue;
std::weak_ptr<Texture> textureValue;


};
