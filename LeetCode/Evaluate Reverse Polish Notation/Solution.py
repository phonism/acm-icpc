class Solution:
	# @param tokens, a list of string
	# @return an interger
	def evalRPN(self, tokens):
		stack = []
		for i in tokens:
			if i not in ('+', '-', '*', '/'):
				stack.append(int(i))
			else:
				op2 = stack.pop()
				op1 = stack.pop()
				if i == '+':
					stack.append(op1 + op2)
				elif i == '-':
					stack.append(op1 - op2)
				elif i == '*':
					stack.append(op1 * op2)
				else:
					stack.append(int(op1 * 1.0 / op2))
		return stack[0]

s1 = ["2", "1", "+", "3", "*"]
s2 = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
s3 = ["6", "4", "/", "4", "*"]
print s1
print s2
print Solution().evalRPN(s1)
print Solution().evalRPN(s2)
print Solution().evalRPN(s3)
print Solution().evalRPN(["1", "3", "-"])

