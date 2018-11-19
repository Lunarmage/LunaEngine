#include "Component.h"
#include "Entity.h"
#include "Core.h"

std::shared_ptr<Environment> Component::getEnvironment()
{
	return getCore()->getEnvironment();

}

std::shared_ptr<Entity> Component::getEntity()
{
	return HostEntity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
	return getEntity()->getCore();
}

void Component::onDisplay()
{
	
}

void Component::onTick()
{
	
}

void Component::onInit()
{

}

void Component::onBegin()
{


}