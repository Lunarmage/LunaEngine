
#include <vector>
#include <memory>
#include <string>
#include "Resource.h"


class Resources
{
public:

	template<class T>
	std::shared_ptr<T> load(std::string path);


	

private:
	std::vector<Resource> resources;

};

