#https://leetcode.com/problems/combination-sum/

class Solution:
	result = []

	def combinationSumCal(self, candidate, candidate_index, target, current):
		if target == 0:
			self.result.append(current)
		elif target < 0:
			return

		for cand in candidate[candidate_index:]:
			current.append(cand)
			self.combinationSumCal(candidate, candidate_index, target-cand, current.copy())
			current.pop()
			candidate_index += 1


	def combinationSum(self, candidate, target):
		self.result = []
		self.combinationSumCal(candidate, 0, target, [])
		return self.result


if __name__ == '__main__':
	candidate = [2,3,5]
	target = 8

	s = Solution()
	print(s.combinationSum(candidate, target))
