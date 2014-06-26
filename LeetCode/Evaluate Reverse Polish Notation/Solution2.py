import operator

ARITHMETIC_OPERATORS = {
	'+': operator.add,
	'-': operator.sub,
	'*': operator.mul,
	'/': operator.div,
}

class Solution:
	# @param tokens, a list of string
	# @return an interger
	def evalRPN(self, tokens, operators = ARITHMETIC_OPERATORS):
		stack = []
		for val in tokens:
			if val in operators:
				f = operators[val]
				if f == operator.div:
					stack.append(stack.pop() * 1.0)
				stack[-2:] = [int(f(*stack[-2:]))]
			else:
				stack.append(int(val))
		return stack.pop()
		

s1 = ["2", "1", "+", "3", "*"]
s2 = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
s3 = ["6", "4", "/", "4", "*"]
print s1
print s2
print Solution().evalRPN(s1)
print Solution().evalRPN(s2)
print Solution().evalRPN(s3)