#include <iostream>
#include <vector>
using namespace std;
 

int main()
{
    int c, n;
    vector<int>customer(21);
    vector<int>cost(21);
    vector<int>dp(100001); // 최대 고객

    cin >> c >> n;
   
	for (int i = 1; i <= n; i++)
		cin >> cost[i] >> customer[i];

	for (int i = 1; i <= n; i++)
		for (int j = cost[i]; j <= 100000; j++)
			dp[j] = max(dp[j], dp[j - cost[i]] + customer[i]);

	// 출력
	for (int i = 1; i <= 100000; i++)
		if (dp[i] >= c) {
			cout << i;
            break;
		}
        
	return 0;
}