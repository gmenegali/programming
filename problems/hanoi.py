
def moveHanoi(hanoi, n, source, aux, target):
	# print(hanoi, n, source, aux, target)
	print(hanoi)
	if n == 1:
		hanoi[target].append(hanoi[source].pop())
		return

	moveHanoi(hanoi, n-1, source, target, aux)
	moveHanoi(hanoi, 1, source, aux, target)
	moveHanoi(hanoi, n-1, aux, source, target)



if __name__ == '__main__':
	n = 3
	hanoi = [
		[i+1 for i in reversed(range(n))],
		[],
		[]
	]
	moveHanoi(hanoi, n, 0, 1, 2)
