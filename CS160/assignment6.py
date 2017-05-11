#Assignment 6
def main():
	deno = input("Enter number of tests/assignments/quizzes/labs you've done: ")

	while True:
		final = input("Do you have a final that is graded differently? ")
		if final.lower() == 'yes':
			fingrade = input("Enter how much the final is worth (in points): ")
			while fingrade[i] < 0:
				print("Invalid input. Try again.")
			else:
			continue
		elif final.lower() == 'no':
			break
		else:
			print("Invalid input")
