def get_initial_input():
	return int(input("Enter total number of work you've had graded: "))
def get_tests():
	return int(input("Enter number of tests: "))

def get_scores():
	score = []
	for i in range(0,get_initial_input()):
		score.append(float(input("Enter grade: ")))
	return score	
def calculate_weighted_avg():
	return 
def main():
	amount = get_initial_input()
	score = get_scores()
	total = sum(score)
	
	print(score)
	print(total)

main()
