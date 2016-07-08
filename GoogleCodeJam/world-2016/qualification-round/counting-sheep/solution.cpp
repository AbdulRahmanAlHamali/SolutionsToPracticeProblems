#include <iostream>
#include <vector>
using namespace std;

bool done(int n, bool* nums);

int main() 
{
	int T;
	cin>> T;

	vector<int> solutions;

	for (int i = 0; i < T; i++) 
	{
		int N;
		cin>> N;
		if (N == 0)
		{
			solutions.push_back(0);
		} 
		else 
		{
			bool numArray[10]= {false};
			int current = N;
			while(!done(current, numArray))
			{
				current+= N;
			}
			solutions.push_back(current);
		}	
	}

	for (int i = 0; i < T; i++)
	{
		cout<< "Case #"<< i + 1<< ": ";
		if (solutions[i] == 0)
		{
			cout<< "INSOMNIA";
		}
		else 
		{
			cout<< solutions[i];
		}
		cout<< endl;
	}
}

bool done(int n, bool* nums)
{
	while (n != 0)
	{
		int rem = n % 10;
		nums[rem] = true;
		n = n / 10;
	}

	bool result = true;
	for (int i = 0; i < 10; i++)
	{
		result = result and nums[i];
		if (result == false)
		{
			return false;
		}
	}
	return true;
}
