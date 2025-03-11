#include <iostream>
#include <string>
#include <functional>

int main()
{
	std::string name = "Jong";
	std::hash<std::string> hasher;
	size_t hashValue = hasher(name);

	std::cout << "Hash value of '" << name << " ': " << hashValue << '\n';

	return 0;
}
