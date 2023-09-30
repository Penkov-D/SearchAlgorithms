
#include <iostream>
#include <cstdbool>
#include <vector>

/// <summary>
/// Return Ture if and only if 'x' is in 'vec'
/// </summary>
/// <param name="vec">array to be search in</param>
/// <param name="x">elemnt to find</param>
/// <returns>true if 'x' is in 'vec', false otherwise</returns>
bool search(std::vector<int> vec, int x)
{
	// Test if there elemnts in the array
	if (vec.size() == 0)
		return false;

	// If only one element in the array only one position 'x' can be
	if (vec.size() == 1)
		return vec[0] == x;

	// Hold the result
	bool answer = false;

	// Iterate recursivly thouw all the permutations
	for (unsigned int skip = 0; skip < vec.size(); skip++)
	{
		// Create new vector - similar to the original
		std::vector<int> newVec(vec);

		// Remove the elemnt in the 'skip' position
		newVec.erase(newVec.begin() + skip);

		// Search for 'x' in the sub array
		answer = answer || search(newVec, x);
	}

	return answer;
}


int main(int argc, char** argv)
{
	// Create some arbitrary vector
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	// Search for the number 5 in 'vec'
	std::cout << search(vec, -5) << std::endl;

	return 0;
}