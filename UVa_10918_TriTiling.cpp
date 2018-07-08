#include <bits/stdc++.h>

int memo[16];

int dp(int i) {
	if(i == 0) return 1;
	if(memo[i] != -1) return memo[i];
	int ans = 0;
	for(int j = i; j > 0; j--)
		ans += (j == i ? 3 : 2) * dp(j - 1);
	return memo[i] = ans;
}

int main() {
	memset(memo, -1, sizeof memo);
	dp(30 >> 1);
	int n;
	while(true) {
		scanf("%d", &n);
		if(n == -1) break;
		printf("%d\n", n % 2 == 0 ? dp(n >> 1) : 0);
	}
	return 0;
}
