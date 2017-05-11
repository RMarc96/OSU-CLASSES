import math

num = float(input("Enter a number to find its square root: "))
guess = float(input("What do you think the square root is? "))
new_estimate = (guess + num /guess)/2.0
error = .0000001
while abs(num**0.5 - new_estimate) > error:
	new_estimate = (new_estimate + num / new_estimate) / 2;
print("The square root of " + str(num) + " is about " + str(new_estimate))

print("The actual square root of " + str(num) + " is " + str(math.sqrt(num)))

