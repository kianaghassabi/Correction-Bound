#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <conio.h>
#include <algorithm>    // std::max

using namespace std;

void printVector(vector<int> vect) {
	for (int i = 0;i < vect.size();i++)
	{
		cout<<vect[i]<<" ";
	}
}

void printVector2D(vector<vector<int>> vect) {
	for (int i = 0;i < vect.size();i++)
	{
		for (int j = 0;j < vect[i].size();j++)
		{
	    	cout << vect[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;

}

//function for producing all permutations of a given pattern
vector<vector<int>> functionA(vector<int> pattern) {
	vector<int> Permutation;
	vector<vector<int>> allPermutations;
	do {

		vector<int> temp;
		// std::copy (pattern.begin(),pattern.end(),back_inserter(temp.begin()));
		allPermutations.push_back(pattern);

	} while (std::prev_permutation(pattern.begin(), pattern.end()));

	return allPermutations;
}

//function for producing all permutations of a given pattern
vector<vector<int>> prev_permutation(vector<int> pattern) {
	vector<int> Permutation;
	vector<vector<int>> allPermutations;
	do {

		vector<int> temp; 
		// std::copy (pattern.begin(),pattern.end(),back_inserter(temp.begin()));
		allPermutations.push_back(pattern);

	} while (std::prev_permutation(pattern.begin(), pattern.end()));

	return allPermutations;
}

//function for checking whether the  pattern mathces the indices
bool MatchErrorIndices(vector<int> pattern, vector<int> ErrorIndices,int &counter)
{
	for (int i = 0;i < ErrorIndices.size();i++)
	{
		if (pattern[ErrorIndices[i]] != 1)
		{

			return false;
		}
		counter++;
	}
	return true;
}

//
int PermuationIterations(vector<int> pattern,int k,int r)
{
	int numofIteration = 0;
	vector<vector<int>> allPermutations;

	vector<int> indicies(k+r, 0);

	for (int i = 0;i < r;i++)
	{
		indicies[i] = 1;
	}

	int counter = 0; 
	do {
		counter++; 
		bool flag = false;

		for (int i = 0;i < pattern.size();i++)
		{
			if (pattern[i] == 1 && indicies[i] != pattern[i])
			{
				flag = true;
			}
		}

		if (flag == false) {
			return counter; 
		}


	} while (std::prev_permutation(indicies.begin(), indicies.end()));

	



}

//generating the initial pattern 
vector<int> generateErrorPattern(int K, int R) {
	vector<int> pattern;
	for (int i = 0;i < K;i++)
	{
		pattern.push_back(1);
	}

	for (int i = 0;i <R;i++)
	{
		pattern.push_back(0);
	}
	return pattern;
}

vector<int> GenerateErrorIndicies(int n)
{
	vector<int> indicies(n,0);
	printVector(indicies);
	
	int number;
	cout << "\nTotal number of errors: ";
	cin >> number;
	if (number >= n)
	{
		cout << "FALSE INPUT";
	}
	for (int i = 0;i < number;i++)
	{
		int index;
		cout << "\nEnter the index of error number " << i<<":";
		cin >> index;
		indicies[index] = 1;
		
	}
	return indicies;

}

float average(vector<int> vect)
{
	float avg;
	float sum = 0;
	for (int i = 0;i < vect.size();i++)
	{
		sum += vect[i];
	}
	avg = sum / vect.size();
	return avg;
}

int max(vector<int> vect)
{
	int maximum= *max(vect.begin(), vect.end());
	return maximum;
}

int main()
{

	while (true) {
		//oldPermutation();

		int k;
		cout << "\n\nEnter K(symbol): ";
		cin >> k;

		int r;
		cout << "\n\nEnter r(redunduncy): ";
		cin >> r;

		int e;
		cout << "\n\nEnter e(error): ";
		cin >> e;

		int total = r + k;

		std::vector<int>  pattern;
		std::vector<int>  ErrorIndices;

		pattern = generateErrorPattern(e, total - e);

		cout << "\n\your initial pattern is:";
		printVector(pattern);
		cout << endl;

		vector<vector<int>> allpatterns;
		allpatterns = functionA(pattern);
		printVector2D(allpatterns);

		//ErrorIndices = GenerateErrorIndicies(total);
		//cout << "\n\ErrorIndices:";
		//printVector(ErrorIndices);
		//cout << endl;

		//answer will be the maximum of all elements in allindicies vector
		vector<int> eachpatternIteration;

		for (int i = 0;i < allpatterns.size();i++)
		{
			int numofIteration;
			numofIteration = PermuationIterations(allpatterns[i], k, r);
			cout << "\nindex iteration----->" << numofIteration;
			eachpatternIteration.push_back(numofIteration);
		}

		cout << "\n\n--------------\nallindicies\n";
		printVector(eachpatternIteration);

		std::vector<int>::iterator result;

		float averg = average(eachpatternIteration);
		cout << "\naverage" << averg << endl;

		//result = std::max_element(eachpatternIteration.begin(), eachpatternIteration.end());
		//std::cout << "max element at: " << std::distance(eachpatternIteration.begin(), result) << '\n';
		std::cout << "The largest element is " << *std::max_element(eachpatternIteration.begin(), eachpatternIteration.end()) << '\n';

		//cout << "\n\nmax-->"<< max(eachpatternIteration);

	}
		_getch();

		return 0;

	
}