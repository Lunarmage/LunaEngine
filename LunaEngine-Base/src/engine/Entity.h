

#include<memory>
#include <vector>
#include "Component.h"


class Core;


class Entity
{
	friend class Core;
public:
	std::shared_ptr<Core> getCore();

	template <typename T>
	std::shared_ptr<T> getComponent()
	{
		for (int i = 0; i<(components.size()); i++)
		{
			std::shared_ptr<T> TargetComponent = std::dynamic_pointer_cast<T>(components.at(i));
			if (TargetComponent)
			{
				return TargetComponent;
			}
		}

		//throw exception here, ie component not found
	}

	template <typename T>
	std::shared_ptr<T> addComponent() {
		std::shared_ptr<T> NewComp = std::make_shared<T>();
		NewComp->HostEntity = self;
		components.push_back(NewComp);
		NewComp->onInit(); 

		if (typeid(T) == typeid(Camera))
		{
			//assign new camera reference to core


		}
		return NewComp;
	}


	
	void setSelf(std::weak_ptr<Entity> ref);
	void setCore(std::weak_ptr<Core> ref);
	bool isKill() {return kill;}
private:
	std::weak_ptr<Entity> self;
	std::weak_ptr<Core> core;
	std::vector<std::shared_ptr<Component>> components;
	void tick();
	void display();
	bool kill =false;


};


