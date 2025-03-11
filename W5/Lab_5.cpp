#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<int, int> createHashTable(const std::vector<int>& arr)
{
	std::unordered_map<int, int> hashTable;

	for (int i = 0; i < arr.size(); i++)
	{
		hashTable[arr[i]] = i;
	}

	return hashTable;
}

int search(const std::unordered_map<int, int>& hashTable, int target)
{
	auto it = hashTable.find(target);
	if (it != hashTable.end())
	{
		return it->second;
	}
	else
	{
		return -1;
	}
}

int main()
{
	std::vector<int> array = { 200, 400, 100, 50, 350 };
	std::unordered_map<int, int> lookupTable = createHashTable(array);

	std::cout << search(lookupTable, 200) << '\n';
	std::cout << search(lookupTable, 400) << '\n';
	std::cout << search(lookupTable, 500) << '\n';

	return 0;
}
