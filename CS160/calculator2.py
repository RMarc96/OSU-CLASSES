while 1:
	operand = input("Please put in an operation (+, -, /, *, **, %): ")
	if len(operand) == 0:
		print("You didn't type anything in. Terminating program.")
		break
	num1 = input("Please put in a number: ")
	if len(str(num1)) == 0:
		print ("You didn't type anything in. Terminating program.")
		break
	num2 = input("Please put in a second number: ")
	if len(str(num2)) == 0:
		print("You didn't type anything in. Terminating program.")
		break
	if operand == "+":
		print(float(num1)+float(num2))
	elif operand == "-":
		print(float(num1)-float(num2))
	elif operand == "/":
		print(float(num1)/float(num2))
	elif operand == "*":
		print(float(num1)*float(num2))
	elif operand == "**":
		print(float(num1)**float(num2))
	elif operand == "%":
		print(float(num1)%float(num2))
	else:
		print("Invalid input. Terminating program.")
	response = input("Would you like to make another calculation? Type 1 for 'Yes' or 0 for 'No': ")

	if response == "0":
		print("Goodbye!")
		break
	elif response != "1":
		print("Invalid input. Terminating program.")
		break
