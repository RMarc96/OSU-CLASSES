t = input("Enter the amount of tickets you have: ")
t = int(t)
if t >= 10:
	print("You get " + str(int(t/10)) + " candybar(s) and " + str(int((t%10)/3)) + " gumball(s). ")
elif 3 <= t < 10:
	print("You get " + str(int((t%10/3))) + " gumball(s).")
else:
	print("You don't even have enough tickets for a gumball!")
