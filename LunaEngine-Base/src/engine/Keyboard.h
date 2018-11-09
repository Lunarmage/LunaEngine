
#include <vector>
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	bool getKey(int keyCode);
	bool getKeyDown(int keyCode);
	bool getKeyUp(int keyCode);
private:
	std::vector<int> keyCodes;
};

