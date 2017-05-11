
def get_num_students():
	return int(input("Number of students: "))

def avg(scores):
	return sum(scores) / len(scores)

def main():
	scores = []
	for x in range(get_num_students()):
		raw = input("Score: ")
		scores.append(int(raw))

	scores.sort()

	print("Lowest: " + str(scores[0]))
	print("Highest: " + str(scores[-1]))
	print("Average: " + str(avg(scores)))

main()
