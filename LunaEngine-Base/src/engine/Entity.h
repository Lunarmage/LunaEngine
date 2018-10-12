class Entity
{
public:
	std::weak_ptr<Core> getCore():
	/* template for component additon and init
	std::shared_ptr<T> addComponent<T>();
	*/
private:
	std::weak_ptr<Core> core;
	std::vector<std::shared_ptr<Component>> components;
	void tick();
	void display();

};