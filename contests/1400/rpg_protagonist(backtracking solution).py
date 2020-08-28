result = 0

def solution(p, f, cnts, cntw, s, w, np, nf):
	global result
	if ((p < s and f < s) or cnts == 0) and ((p < w and f < w) or cntw == 0):
		result = max(result, np + nf)
	print((p, f, cnts, cntw, s, w, np, nf, result))

	if cnts > 0 and p >= s:
		solution(p-s, f, cnts-1, cntw, s, w, np+1, nf)
	
	if cnts > 0 and f >= s:
		solution(p, f-s, cnts-1, cntw, s, w, np, nf+1)
	
	if cntw > 0 and p >= w:
		solution(p-w, f, cnts, cntw-1, s, w, np+1, nf)

	if cntw > 0 and f >= w:
		solution(p, f-w, cnts, cntw-1, s, w, np, nf+1)


if __name__ == '__main__':
	t = int(input())
	while(t):
		cap = input().split()
		count = input().split()
		weights = input().split()
		
		p = int(cap[0])
		f = int(cap[1])
		cnts = int(count[0])
		cntw = int(count[1])
		s = int(weights[0])
		w = int(weights[1])

		solution(p, f, cnts, cntw, s, w, 0, 0)
		t-=1

