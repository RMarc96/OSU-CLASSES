#Lab 8 Problem 4 by Ronald Salinas
integers = []
size = int(input("How many numbers will you be inputting? "))
integers = [0]*size

for i in range(size):
	integers[i] = int(input("Enter an integer: "))
set = set(integers)
integers = list(set)
print("Integers you entered: " + str(sorted(integers)))
replace = input("Do you want to replace any of these values? 1-Yes or 0-No: ")
if replace == '1':
	remove = int(input("Which integer do you want to replace? "))
	substitute = int(input("Replace this integer with what other integer? "))
	for i in range(len(integers)):
		if integers[i] == int(remove):
			integers[i] = int(substitute)
	print("Your new list is " + str(integers))
else:
	print("Alrighty.")
	quit()
