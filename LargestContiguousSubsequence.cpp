/*
	Author: Mohamed Kazma
	Description: An O(n) algorithm for finding the sum of the largest contiguous subsequence in a set of unordered integers (And also prints the result out)
*/

#include <iostream>
#include <stdlib.h>
#include <vector>

// Function that finds the largest contiguous subsequence
int FindLargestSubsequence(std::vector<int> subsequence , std::vector<int>& optimal)
{
	std::vector<int> currSequence;
	int maxSumSubArray = 0;	// Result for the current subarray we are looking at 
	int maxCurrent = 0;		// Total result we are looking at for the moment

	for (int i = 0; i < subsequence.size(); i++)
	{
		maxSumSubArray += subsequence[i];			// Add new value to the sum
		if (maxSumSubArray < 0) 
		{
			maxSumSubArray = 0; 	// If the result is negative then the subarray with this new value is not optimal
			currSequence.clear();	// We are done with the current sequence
		}
		else currSequence.push_back(subsequence[i]);
		if (maxCurrent < maxSumSubArray) 
		{
			maxCurrent = maxSumSubArray;
			optimal = currSequence;	// Lets hope its just a pointer switch
		}
	}

	return maxCurrent;
}

int main()
{
	// Build some random valued arrays and then try to find the values for those maybe do that a million times
	// Build random array of numbers	
	// Generate a random array
	int size = 1000000;

	for(int j = 0; j< 10; j++)
	{
		std::vector<int> list;
		for(int i = 0; i < size; ++i)
		{
			int value = (rand() % 200) - 100;
			//std::cout << value;
			list.push_back(value);

			//if (i == size - 1)	std::cout << " ]" << std::endl;		
			//else  std::cout << ", ";		
		}

		// Get largest subsequence sum
		std::vector<int> optimalResult;
		int result = FindLargestSubsequence(list , optimalResult);
		std::cout << "The Largest Contiguous Subsequence's sum is: " << result << std::endl;

		for(int i = 0; i < optimalResult.size(); i++)
		{
			std::cout << optimalResult[i] << " ";
		}

		std::cout << std::endl;
	}
	return 0;
}