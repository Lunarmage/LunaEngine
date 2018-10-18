struct EngineVec3
{
int x,y,z;
}

class Transform:: public Component
{
Private:
EngineVec3 localPosition;
EngineVec3 localRotation;
EngineVec3 localScale;

Public:
//apply amount to existing local variables
void translate(EngineVec3 amount);
void rotate(EngineVec3 amount);
void scale(EngineVec3 amount);

//set local variable to input
void setLocalPostion(EngineVec3 input);
void setLocalRotation(EngineVec3 input);
void setLocalScale(EngineVec3 input);
}