#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(string input);
int solve_recursive(string input, int current);

int main()
{
	int T;
	cin>> T;

	vector<int> solutions;

	for (int i = 0; i < T; i++)
	{
		string input;
		cin>> input;

		solutions.push_back(solve(input));	
	}

	for (int i = 0; i < T; i++)
	{
		cout<< "Case #"<< i + 1<< ": "<< solutions[i]<< endl;
	}
}

int solve(string input)
{
	return solve_recursive(input, input.length() - 1);
}

int solve_recursive(string input, int current)
{
	
	if (current == -1)
	{
		return 0;
	}

	if (input[current] == '+')
	{
		int after = solve_recursive(input, current - 1);
		if (current != input.length() - 1 && input[current + 1] == '-')
		{
			return after + 1;
		} 
		else
		{
			return after;
		}
	}
	else 
	{
		int after = solve_recursive(input, current - 1);
		if (current != input.length() - 1 && input[current + 1] == '-')
		{
			return after;
		} 
		else
		{
			return after + 1;
		}
	}	
}
