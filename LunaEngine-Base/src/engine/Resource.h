

#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
class Resource
{
public:
	std::string getPath();
	virtual ~Resource();
protected:
	std::string path;
};


#endif // !RESOURCE_H