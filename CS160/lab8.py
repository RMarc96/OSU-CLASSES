#Lab 8 Problem 3 by Ronald Salinas

initial_input = int(input("How many scores are you entering? "))
scores = [0]*initial_input
for i in range(initial_input):
	scores[i] = float(input("Enter score: "))
print("Entered scores: " + str(sorted(scores)))
average = sum(scores) / initial_input
print("The average of your scores is " + str(average))
