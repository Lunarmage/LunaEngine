

class Environment
{
public:
	Environment();
	~Environment();
	float getDeltaTime();
	void setDeltaTime(float diff);
private:
	float deltaTime;
	
};

