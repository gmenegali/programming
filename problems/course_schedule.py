class Solution:
	def isCyclic(self, graph, root, path, visitedNodes):
		if root in path:
			return True
		
		visitedNodes.add(root)
		path.add(root)

		for child in graph[root]:
			result = self.isCyclic(graph, child, path.copy(), visitedNodes)
			if result == True:
				return True

		return False


	def canFinish(self, numCourses, prerequisites):
		roots = set([i for i in range(numCourses)])
		graph = [[] for i in range(numCourses)]
		
		for prerequisite in prerequisites:
			graph[prerequisite[1]].append(prerequisite[0])
			if(prerequisite[0] in roots):
				roots.remove(prerequisite[0])

		visitedNodes = set()
		for root in roots:
			if(self.isCyclic(graph, root, set(), visitedNodes)):
				return False

		for i in range(numCourses):
			if i not in visitedNodes:
				return False

		return True


if __name__ == '__main__':
	s = Solution()

	# numCourses = 11
	# prerequisites = [
	# 	[1,0],
	# 	# [0,1]
	# 	[2,0],
	# 	[3,2],
	# 	[4,1],
	# 	[4,3],
	# 	[5,3],
	# 	[7,6],
	# 	[10,6],
	# 	[2,5],
	# ]

	numCourses = 8
	prerequisites = [
		[1,0],
		[2,6],
		[1,7],
		[5,1],
		[6,4],
		[7,0],
		[0,5],
	]

	# prerequisites = [[1,0],[2,6],[1,7],[5,1],[6,4],[7,0],[0,5]]
	
	result = s.canFinish(numCourses, prerequisites)
	print(result)
	