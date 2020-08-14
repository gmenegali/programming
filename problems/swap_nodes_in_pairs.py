class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next

	def add(self, val):
		aux = self
		while aux.next != None:
			aux = aux.next	
		aux.next = ListNode(val)


class Solution:
	def swapPairsCalc(self, head):
		if head == None:
			return None

		firstNode = head
		if head != None:
			secondNode = head.next
		else:
			secondNode = None

		if secondNode != None:
			firstNode.next = self.swapPairsCalc(head.next.next)
			secondNode.next = firstNode
		else:
			firstNode.next = None
			return firstNode
		
		return secondNode

	def swapPairs(self, head):
		return self.swapPairsCalc(head)


if __name__ == '__main__':
	l = ListNode(1)
	l.add(2)
	l.add(3)
	l.add(4)
	l.add(5)
	# l.add(6)

	s = Solution()
	n = s.swapPairs(l)
	m = n

	while m != None:
		print(m.val, end=" ")
		m = m.next
	print('')