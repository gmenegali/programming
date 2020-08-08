def merge_sort_calc(f, s):
	merged = []
	while(len(f) != 0 or len(s) != 0):
		if len(s) > 0 and len(f) > 0:
			if s[0] > f[0]:
				merged.append(f.pop(0))
			else:
				merged.append(s.pop(0))
		elif len(s) == 0:
			while len(f) > 0:
				merged.append(f.pop(0))
		elif len(f) == 0:
				while len(s) > 0:
					merged.append(s.pop(0))
	return merged

def merge_sort(v):
	if(len(v) == 1):
		return v
	else:
		mid = int(len(v)/2)
		first_half = merge_sort(v[:mid])
		second_half = merge_sort(v[mid:])
		v = merge_sort_calc(first_half, second_half)

		return(v)


if __name__ == '__main__':
	v = [100,21,3110,40,300]
	print(merge_sort(v))