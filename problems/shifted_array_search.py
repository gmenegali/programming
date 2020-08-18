def shifted_arr_search(shiftArr, num):
	pass

def binary_search(v, l, h, target):
	if l > h:
		return -1

	middle = int((l+h)/2)
	if v[middle] == target:
		return middle
	elif v[middle] > target:
		return binary_search(v, l, middle-1, target)
	else:
		return binary_search(v, middle+1, h, target)

def find_pivot(v, l, h):
	print(str(l) + "  " + str(h))
	if l > h:
		return 0

	middle = int((l+h)/2)
	if v[middle] < v[middle-1]:
		return middle

	if v[middle] >= v[l]:
		return find_pivot(v, middle+1, h)
	else:
		return find_pivot(v, l, middle-1)

def findPivotPoint(arr):
	begin = 0
	end = len(arr) - 1

	while (begin <= end):
		mid = int((end + begin)/2)
		if (mid == 0 or arr[mid] < arr[mid-1]):
			return mid
		if (arr[mid] > arr[0]):
			begin = mid + 1
		else:
			end = mid - 1

	return 0


if __name__ == '__main__':
	v = [3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,1,2]
	print(findPivotPoint(v))

