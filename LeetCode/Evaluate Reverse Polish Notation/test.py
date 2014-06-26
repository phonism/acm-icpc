import operator

ARITHMETIC_OPERATORS = {
    '+':  operator.add, '-':  operator.sub,
    '*':  operator.mul, '/':  operator.div, '%':  operator.mod,
    '**': operator.pow, '//': operator.floordiv,
}

def postfix(expression, operators = ARITHMETIC_OPERATORS):
    stack = []
    for val in expression.split():
        if val in operators:
            f = operators[val]
            if f == operator.div:
                stack.append(stack.pop() * 1.0)
            stack[-2:] = [int(f(*stack[-2:]))]
        else:
            stack.append(int(val))
    return stack.pop()

expression = "2 1 + 3 *"
expression2 = "10 6 9 3 + -11 * / * 17 + 5 +"
print postfix(expression2)