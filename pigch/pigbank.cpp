// Author: Swarnaprakash
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct coin {
	int value;
	int weight;

	coin(int value, int weight) {
		this->value = value;
		this->weight = weight;
	}
};

int dp(int net_weight, vector<coin> &coins) {
	int ans[net_weight + 1];
	memset(ans, 0x3f, sizeof(ans));
	ans[0] = 0;
	for (int i = 1;i <= net_weight; ++i) {
		for (int j = 0; j < coins.size(); ++j) {
			if (coins[j].weight <= i) ans[i] = min(ans[i], ans[i-coins[j].weight] + coins[j].value);
		}
	}
	return ans[net_weight];
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int e,f;
		scanf("%d %d",&e,&f);
		int n;
		vector<coin> coins;
		scanf("%d",&n);
		while(n--) {
			int p,w;
			scanf("%d %d",&p,&w);
			coins.push_back(coin(p,w));
		}
		int ans = dp(f-e,coins);
		if(ans == 0x3f3f3f3f)
			puts("This is impossible.");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",ans);
	}
}

