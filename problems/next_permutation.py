# https://leetcode.com/problems/next-permutation

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

class Solution:
	def nextPermutation(self, nums):
		nums_size = len(nums)
		previous = nums[nums_size-1]
		need_sort_everything = True
		for i in reversed(range(nums_size-1)):
			if nums[i] < previous:
				target = float('inf')
				target_index = i
				for j in range(i+1, nums_size):
					if nums[j] > nums[i] and target > nums[j]:
						target = nums[j]
						target_index = j
				nums[i], nums[target_index] = nums[target_index], nums[i]
				quick_sort(nums, i+1, nums_size-1)
				need_sort_everything = False
				break
			previous = nums[i]
		if need_sort_everything:
			quick_sort(nums, 0, nums_size-1)


if __name__ == '__main__':
	a = [3,2,1]
	s = Solution()
	s.nextPermutation(a)
	print(a)
