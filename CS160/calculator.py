while 1:
	operand = input("Enter a number operation (+, -, /, *, **, %): ")
	if len(operand) == 0:
		print("Please try again and put something in next time!")
		break
	num1 = float(input("Enter your first number: "))
	num2 = float(input("Enter your second number: "))
	if operand == "+":
		print(num1 + num2)
	elif operand == "-":
		print(num1 - num2)
	elif operand == "/":
		print(num1 / num2)
	elif operand == "*":
		print(num1*num2)
	elif operand == "**":
		print(num1**num2)
	elif operand == "%":
		print(num1%num2)
	else:
		print("Please try inputting again correctly.")
	answer = input("Would you like to try again? Type 1 for 'Yes' or 0 for 'No'")
	if answer == "0":
		print("Thank you for using the calculator!")
		break
	elif answer != "1":
		print("Invalid input. Closing anyway.")
		break
