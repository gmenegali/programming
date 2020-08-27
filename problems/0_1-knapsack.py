
def knapsack(values, weights, w, n, dp):
	if n == 0 or w == 0:
		return 0

	if dp[n][w] != -1:
		return dp[n][w]

	if weights[n-1] > w:
		dp[n][w] = knapsack(values, weights, w, n-1, dp)

	else:
		dp[n][w] = max(
				values[n-1] + knapsack(values, weights, w-weights[n-1], n-1, dp),
				knapsack(values, weights, w, n-1, dp)
		)

	return dp[n][w]

if __name__ == '__main__':
	n = 100
	w = 5000
	# values = [60,100,120]
	# weights = [10,20,30]
	values = [40 * i for i in range(n)]
	weights = [10 * i for i in range(n)]
	dp = [[-1 for j in range(w+1)] for i in range(n+1)]


	print(knapsack(values, weights, w, len(values), dp))