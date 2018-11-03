#include "Material.h"
#include "Mesh.h"

class MeshRenderer: public Component 
{
private:
std::weak_ptr<Mesh> mesh
std::shared_ptr<Material> material


public:
void onInit();
void onDisplay();

void setMesh(std::weak_ptr<Mesh> inputMesh);
std::weak_ptr<Mesh> getMesh();
void setMaterial(std::shared_ptr<Material> inputMaterial;
std::shared_ptr<Material> getMaterial();

};