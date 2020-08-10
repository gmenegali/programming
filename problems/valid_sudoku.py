class Solution:
	def isValidSudoku(self, board):
		# Row
		for row in board:
			counter = [0 for x in range(9)]
			for e in row:
				if e != '.':
					counter[int(e) - 1] += 1
			for e in counter:
				if e > 1:
					return False

		# Column
		for j in range(9):
			counter = [0 for x in range(10)]
			for i in range(9):
				if board[i][j] != '.':
					counter[int(board[i][j]) - 1] += 1
			for e in counter:
				if e > 1:
					return False

		# Square
		counter = [[0 for x in range(9)] for x in range(9)]
		for i in range(9):
			for j in range(9):
				value = board[i][j]
				if value != '.':
					if i < 3:
						if j < 3:
							counter[0][int(value) - 1] += 1
						elif j > 2 and j < 6:
							counter[1][int(value) -1] += 1
						elif j > 5:
							counter[2][int(value) - 1] += 1
						
					elif i > 2 and i < 6:
						if j < 3:
							counter[3][int(value) - 1] += 1
						elif j > 2 and j < 6:
							counter[4][int(value) - 1] += 1
						elif j > 5:
							counter[5][int(value) - 1] += 1

					else:
						if j < 3:
							counter[6][int(value) - 1] += 1
						elif j > 2 and j < 6:
							counter[7][int(value) - 1] += 1
						elif j > 5:
							counter[8][int(value) -1] += 1

		for row in counter:
			for e in row:
				if e > 1:
					return False

		return True

if __name__ == '__main__':
	inp = [
	  ["5","3",".",".","7",".",".",".","."],
	  ["6",".",".","1","9","5",".",".","."],
	  [".","9","8",".",".",".",".","6","."],
	  ["8",".",".",".","6",".",".",".","3"],
	  ["4",".",".","8",".","3",".",".","1"],
	  ["7",".",".",".","2",".",".",".","6"],
	  [".","6",".",".",".",".","2","8","."],
	  [".",".",".","4","1","9",".",".","5"],
	  [".",".",".",".","8",".",".","7","9"]
	]
	# board = [[j for j in range(9)] for i in range(9)]
	s = Solution()
	print(s.isValidSudoku(inp))

	# print(board[3:])        