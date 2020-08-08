def quick_sort(v, begin, end):
	if begin < end:
		pivot = v[begin]
		pivot_index = begin
		for i in range(begin+1, end+1):
			if pivot > v[i]:
				if pivot_index == i-1:
					v[pivot_index], v[i] = v[i], v[pivot_index]
					pivot_index = i
				else:
					v[pivot_index+1], v[i] = v[i], v[pivot_index+1]
					v[pivot_index], v[pivot_index+1] = v[pivot_index+1], v[pivot_index]
					pivot_index += 1
		quick_sort(v, begin, pivot_index-1)
		quick_sort(v, pivot_index+1, end)


if __name__ == '__main__':
	v = [100,21,3110,40,300]
	quick_sort(v, 0, len(v)-1)
	print(v)