class Solution:
	# @program s, a string
	# @return a string
	def reverseWords(self, s):
		return " ".join(s.split()[::-1])

s = "the sky is blue"
print (s[::-1])
print (s.split())
print (Solution().reverseWords(s))