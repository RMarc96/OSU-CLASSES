def num_tests():
	return int(input("Enter number of assignments you've had: "))
	return int(input("Enter number of tests: "))
def get_score():
	score = []
	test = num_tests()
	for i in range(0, test):
		score.append(float(input("Enter assignment grade: ")))
	return score
def main():	
	score = get_score()
	total = sum(score)
	#test = num_tests()	
	print(score)
	print(total)
main()
