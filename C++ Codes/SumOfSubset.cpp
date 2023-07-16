// Dynamic Programming
// for subset sum problem
#include <iostream>
using namespace std;
bool isSubsetSum(int set[], int n, int sum)
{
	bool subset[n + 1][sum + 1];

	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j]
							|| subset[i - 1][j - set[i - 1]];
		}
	}
	for (int i = 0; i <= n; i++)
	{
	for (int j = 0; j <= sum; j++)
		printf("%4d", subset[i][j],"/n");
    	cout <<"\n";


	return subset[n][sum];
	}
}

// Driver code
int main(){
	int set[] = { 3,5,7,10,12 };
	int sum = 15;
	int n = sizeof(set) / sizeof(set[0]);
	if(isSubsetSum(set, n, sum) == true){
		cout <<"YES it has solution";
	}
	else{
		cout<<"NO it has no solution";
	}
	return 0;
}

