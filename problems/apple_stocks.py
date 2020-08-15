def get_max_profit(stock_prices):
	min_found = float('inf')
	max_profit = -float('inf')
	for val in stock_prices:
		if val-min_found > max_profit:
			max_profit = val-min_found
		if val < min_found:
			min_found = val
	return max_profit

stock_prices = [10, 7, 5, 8, 11, 9]
print(get_max_profit(stock_prices))
