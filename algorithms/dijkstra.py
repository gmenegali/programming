def print_path(root, parents, destination):
	stack = []
	while destination != root:
		stack.append(destination)
		destination = parents[destination]

	print("Path: " + str(root), end=" ")
	for i in reversed(range(len(stack))):
		print(str(stack[i]), end=" ")
	print()

#destination is used only when print_path is True
def dijkstra(graph, root, destination, path=True):
	dist = [float('inf')]* len(graph)
	parents = [-1]* len(graph)
	dist[root] = 0
	solved = [root]

	while(len(solved) != len(graph)):
		#child = [child_index, weight]
		for child in graph[solved[-1]]:
			if dist[solved[-1]]+child[1] < dist[child[0]]: 
				dist[child[0]] = min(dist[child[0]], dist[solved[-1]]+child[1])
				parents[child[0]] = solved[-1]

		smallest = float('inf')
		next_target = -1
		for node,distance in enumerate(dist):
			if distance < smallest and node not in solved:
				smallest = distance
				next_target = node
		solved.append(next_target)
		
	print_path(root, parents, destination)
	return dist

#edge list item -> [source, destination, weight]
def build_graph(num_nodes, edge_list, undirected = True):
	graph = [[] for i in range(num_nodes)]
	for edge in edge_list:
		graph[edge[0]].append([edge[1],edge[2]])
		if(undirected):
			graph[edge[1]].append([edge[0],edge[2]])
	return graph



if __name__ == '__main__':
	num_nodes = 9
	edge_list = [
		[0,1,4],
		[0,7,8],
		[1,7,11],
		[1,2,8],
		[7,8,7],
		[7,6,1],
		[2,8,2],
		[2,3,7],
		[2,5,4],
		[8,6,6],
		[6,5,2],
		[5,3,14],
		[5,4,10],
		[3,4,9],
	]
	graph = build_graph(num_nodes, edge_list)
	# for line in graph:
		# print(line)
	print(dijkstra(graph, 0, 4, True))
