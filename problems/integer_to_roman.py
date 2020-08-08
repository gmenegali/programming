#https://leetcode.com/problems/integer-to-roman/

class Solution:
	def handle_digit(self, digit, begin_unit, middle_unit, end_unit):
		result = ""
		
		if digit >= 1 and digit <= 3:
			for i in range(digit):
				result += begin_unit
		elif digit == 4:
			result += begin_unit
			result += middle_unit
		elif digit >= 5 and digit <= 8:
			result += middle_unit
			for digit in range(digit-5):
				result += begin_unit
		elif digit == 9:
			result += begin_unit
			result += end_unit
		
		return result


	def intToRoman(self, num):
		result = ""

		m = int(num/1000)
		c = int((num/100) % 10)
		d = int((num/10) % 10)
		u = int(num % 10)

		if m:
			for i in range(m):
				result += 'M'
		if c:
			result += self.handle_digit(c, 'C', 'D', 'M')
		if d:
			result += self.handle_digit(d, 'X', 'L', 'C')
		if u:
			result += self.handle_digit(u, 'I', 'V', 'X')

		return result


if __name__ == '__main__':
	s = Solution()
	print(s.intToRoman(10))
	print(s.intToRoman(100))
	print(s.intToRoman(901))
	print(s.intToRoman(3999))
