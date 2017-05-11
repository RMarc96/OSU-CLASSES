#"Buoyancy Program" lab 6 edit by Ronald Salinas CS160
def main():
	end = False
	while not end:
		while True:
			try:
				r = float(input("What is the radius of your sphere? "))
			except ValueError:
				print("Invalid input. Try again.")
				continue
			if r < 0:
				print("Cannot be negative. Try again.")
				continue
			else:
				break
		v = float((4/3)*3.14*(r**3))
		if v == 0:
			print("Your sphere doesn't exist.")
			early_end = input("Would you like to measure another sphere? 1 - 'Yes' or 0 - 'No': ")
			while early_end != '0' or early_end != '1':
				if early_end == '0':
					print("Goodbye!")
					quit()
				elif early_end == '1':
					main()
				else:
					print("Invalid input")
					continue
		F = v*r
		print('The buoyant force of your sphere is ' + str(F))
		while True:
			try:
				w = float(input("What is the weight of your sphere? "))
			except ValueError:
				print("Invalid input. Try again.")
				continue
			if w < 0:
				print("Cannot be negative. Try again.")
				continue
			else:
				break
		if w == 0:
			print("How can your sphere not have weight? If it's way too light to measure, it will probably float.")
			done = True
		elif F >= w:
			print("This sphere will float. ")
			done = True
		else:
			print("This sphere will sink. ")
			done = True
		if done:
			response = input("Would you like to measure another sphere? 1 - 'Yes' or 0 - 'No': ")
			while response != '0' or response != '1':
				if response == '0':
					end = True
					print("Goodbye!")
					quit()
				elif response == '1':
					end = False
					break
				else:
					print("Invalid input.")
					response =input("Would you like to measure another sphere? 1 - 'Yes' or 0 - 'No': ")
		if end == True:
			print("Goodbye!")
			break
			end()
main()
