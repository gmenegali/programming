def get_different_number(arr):
	for i in range(len(arr)):
		temp = arr[i]
		while temp < len(arr)-1 and arr[temp] != temp:
			arr[temp], temp = temp, arr[temp]

	for i in range(len(arr)):
		if i != arr[i]:
			return i

	return len(arr)


if __name__ == '__main__':
	v = [1,2,3,4,6,0]
	print(get_different_number(v))