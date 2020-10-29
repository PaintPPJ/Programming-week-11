#include<iostream>
#include<vector>

using namespace std;
const unsigned int numCoins = 8; // 8 --> 1p, 2p, 5p, 10p, 20p, 50p, 100p, 200p
const unsigned int Coins[numCoins] = { 1,2,5,10,20,50,100,200 }; //Coin p England (1p 2p 5p 10p 20p 50p 100p 200p)

typedef vector<unsigned long long> combin;

int main()
{

	vector<combin> before;

	unsigned int test;
	test = 1; //Input 1 time
	while (test--)
	{
		unsigned int total;
		cin >> total;
		for (unsigned int cents = before.size(); cents <= total; cents++)
		{
			combin ways(numCoins);

			ways[0] = 1;

			for (size_t i = 1; i < ways.size(); i++)
			{
				ways[i] = ways[i - 1];
				auto currentCoin = Coins[i];
				if (cents >= currentCoin)
				{
					auto remaining = cents - currentCoin;
					ways[i] += before[remaining][i];
				}
				ways[i] %= 1000000007;
			}
			before.push_back(ways);

		}
		auto result = before[total];
		auto combination = result.back();
		combination %= 1000000007;
		cout << combination << endl;
	}
	return 0;
}