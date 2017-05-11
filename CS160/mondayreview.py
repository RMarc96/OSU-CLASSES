
def get_num_students():
	return int(input("Enter the number of students: "))
def get_scores(scores):
	for i in range(len(scores)):
		scores[i] = float(input("Enter test score: "))
def main():
	students = get_num_students()
	print(students)
	test_scores = [0]*students
	get_scores(test_scores)
	print(test_scores)
main()
