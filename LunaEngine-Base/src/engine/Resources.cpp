#include "Resources.h"
#include "Resource.h"

/*
template<class T>
std::shared_ptr<T> Resources::load(std::string path)
{
	//check if path exists

	for (std::vector<std::shared_ptr<Resource> >::iterator it = resources.Begin();
		it != resources.end(); it++)
	{
		if ((*it)->getPath == path)
		{
			return it;
		}


	}

	//if not create
	std::shared_ptr<T> temp = std::make_shared<T>();
	temp.load(std::string path);
	resources.push_back(temp);
	return temp;

}
*/