#Evaluation of postfix expression using python
def evaluate_postfix(expression):
    stack = []
    tokens = expression.split()

    for token in tokens:
        print(f"Processing token: {token}")
        if token.isdigit():
            stack.append(int(token))
        else:
            b = stack.pop()
            a = stack.pop()

            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            elif token == '/':
                stack.append(int(a / b))  
            else:
                raise ValueError(f"Unknown operator: {token}")

    return stack.pop()

expr = input("Enter a postfix expression: \n")
result = evaluate_postfix(expr)
print("Result:", result)
