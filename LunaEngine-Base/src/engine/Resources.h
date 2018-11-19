#pragma once
#include <list>
#include <vector>
#include <memory>
#include <string>
#include "Resource.h"


class Resources
{
public:

	template<class T>
	std::shared_ptr<T> load(std::string path)
	{ 
			//check if path exists

			for (std::list<std::shared_ptr<Resource> >::iterator it = Sresources.begin();
				it != Sresources.end(); it++)
			{
				if ((*it)->getPath() == path)
				{
					return std::dynamic_pointer_cast<T>(*it);
				}


			}
			
			//if not create
			std::shared_ptr<T> temp = std::make_shared<T>();
			temp->load(path);
			Sresources.push_back(temp);
			return temp;
		
		
	}

private:
	std::vector<std::shared_ptr<Resource>> resources;
	std::list<std::shared_ptr<Resource>> Sresources;
};

