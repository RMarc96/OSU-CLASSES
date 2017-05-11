#########################################################
#Filename: Weighted grade calculator
#Author: Ronald Salinas
#Date: 26 November 2014
#Description: Calculates weighted class grade
#Input: User assignment, test, final, quiz, and lab scores
#Output: Weighted grade (in percent)
#########################################################


################################################################################################
#Function: Get values for scores
#Description: Assigns values to a specific category's list
#Parameters: Assignment / test / final / quiz / lab list
#Pre-conditions: Finite list must be initialized to 0's with lenfth equal to amount of scores
#Post-conditions: List is assigned values given by user
#################################################################################################
def get_scores(category):
	for i in range(len(category)):
		try:
			category[i] = float(input("Enter score: "))
		except ValueError:
			print("Invalid input in one of the values. Enter scores in again from the beginning for this category.")
			get_scores(category)

################################################################################################
#Function: Calculate weighted average for category
#Description: Uses a category's values list, weight, and list size to calculate weighted average
#Parameters: Category's list of score values, category's weight, and category's length value
#Pre-conditions: 'category' is a finite list of numbers, 'weight' is a value from 0 to 100, and 'size' is a number = length of that the category's list
#Post-conditions:  Values returned are floating point numbers
###############################################################################################
def calculate_weighted_avg(category, weight, size):
	if category == 'l_scores':
		return sum(category)
	else:
		return((float(sum(category) / len(size))*weight))

###############################################################################################
#Function: Overall class grade
#Description: Uses each category's grade (obtained frmo calculate_weighted_avg()) and finds overall class grade
#Parameters: Values of each category's weighted average, int and float numbers
#Pre-conditions: Arguments are number values, not lists
#Post-conditions: Value returned should just be a floating point number
################################################################################################
def calculate_class_grade(a_grade, t_grade, l_grade, q_grade, f_grade):
	if f_grade == 'Weighted with tests.':
		return ((a_grade+t_grade+q_grade+l_grade) / 100)
	else:
		return ((a_grade+t_grade+q_grade+l_grade+f_grade) / 100)

############################################################################################################################
#Function: Get initial inputs
#Description: Gets initial inputs: the amount of scores in each category and their weights
#Parameters: Assignments, tests, final(s), quizzes, and labs
#Pre-conditions: String which signifies which statement to run
#Post-conditions: Either an integer for category quantity or a floating point number (between 0 and 100) for category weight
############################################################################################################################
def get_initial_input(category):
	if category == 'assignments':
		return(int(input("Enter quantity of assignments: ")))
	elif category == 'tests':
		return(int(input("Enter the quantity of tests (not including final(s)): ")))
	elif category == 'final':
		return(int(input("Enter the quantity of finals: ")))
	elif category == 'quizzes':
		return(int(input("Enter the quantity of quizzes: ")))
	elif category == 'labs':
		return(int(input("Enter the quantity of labs: ")))
	elif category == 'a_weight':
		return(float(input("Enter weight of assignments (e.g. if weight is 20%, enter 20): ")))
	elif category == 't_weight':
		return(float(input("Enter the weight of tests (e.g. if weight is 20%, enter 20): ")))
	elif category == 'q_weight':
		return(float(input("Enter the weight of quizzes (e.g. if weight is 20%, enter 20): ")))
	elif category == 'l_weight':
		return(float(input("Enter the weight of labs (e.g. if weight is 20%, enter 20): ")))
	elif category == 'f_weight':
		while True:
			different = input("Are finals not graded under tests, i.e. are they weighted differently? Enter 'yes' or 'no': ")
			if different.lower() == 'yes':
				return(float(input("Enter the weight of final(s): ")))
				break
			elif different.lower() == 'no':
				return('Weighted with tests.')
				break
			else:
				print("Invalid input. Enter again.")
				continue

#######################################################################################################################################
#Function: Main function
#Description: Supplies variables for each category's otal, scores list, weight, and average, and the overall grade. Prints these values
#Parameters: -
#Pre-conditions: -
#Post-conditions: -
#######################################################################################################################################
def main():
	#Assignment, lab, final, test, and quiz totals, scores, and weights
	a_total = int(get_initial_input('assignments'))
	a_scores = [0]*a_total
	get_scores(a_scores)
	a_weight = get_initial_input('a_weight')
	
	t_total = int(get_initial_input('tests'))
	t_scores = [0]*t_total
	get_scores(t_scores)
	t_weight = get_initial_input('t_weight')
	
	f_total = int(get_initial_input('final'))
	f_scores = [0]*f_total
	get_scores(f_scores)
	f_weight = get_initial_input('f_weight')

	q_total = int(get_initial_input('quizzes'))
	q_scores = [0]*q_total
	get_scores(q_scores)
	q_weight = get_initial_input('q_weight')
	
	l_total = int(get_initial_input('labs'))
	l_scores = [0]*l_total
	get_scores(l_scores)
	l_weight = get_initial_input('l_weight')
	
	#Checks to see if weight equal to 100. If more or less, program terminates
	if f_weight == 'Weighted with tests.':
		weight_total = a_weight + t_weight + q_weight + l_weight
		if weight_total > 100:
			print("Weight exceeds 100%. Make sense, fool.")
			quit()
	elif f_weight != 'Weighted with tests.':
		weight_total = a_weight + t_weight + q_weight + l_weight + f_weight
		if weight_total > 100:
			print("Total weight exceeds 100%. Try again.")
			quit()
		elif weight_total < 100:
			print("Total weight is less than 100%. Try again.")
			quit()
	else:
		pass

	print("							")
	print("Your assignment scores: " + str(sorted(a_scores)))
	print("Assignments weight: " + str(a_weight) + "% ")
	print("							")
	print("Your test scores: " + str(sorted(t_scores)))
	print("Tests weight: " + str(t_weight) + "% ")
	print("							")
	print("Your quiz scores: " + str(sorted(q_scores)))
	print("Quizzes weight: " + str(q_weight) + "% ")
	print("							")
	print("Your lab scores: " + str(sorted(l_scores)))
	print("Labs weight: " + str(l_weight) + "% ")
	print("							")
	print("Your final score(s): " + str(sorted(f_scores)))
	print("Final(s) weight: " + str(f_weight) + "% ")
	print("							")

	#Assignment grade
	a_grade = calculate_weighted_avg(a_scores, a_weight, a_scores)
	#Calculates differently if final is weighed with tests or not
	if f_weight == 'Weighted with tests.':
		t_grade = calculate_weighted_avg((t_scores + f_scores), t_weight, (t_scores + f_scores))
		f_grade = 'Weighted with tests.'
	elif f_weight != 'Weighted with tests.':
		t_grade = calculate_weighted_avg(t_scores, t_weight, t_scores)
		f_grade  = calculate_weighted_avg(f_scores, f_weight, f_scores)
	#Quiz grade
	q_grade = calculate_weighted_avg(q_scores, q_weight, q_scores)
	#Lab grade
	l_grade = calculate_weighted_avg(l_scores, l_weight, l_scores)
	
	#Overall class grade
	class_grade = calculate_class_grade(a_grade, t_grade, q_grade, l_grade, f_grade)

	print("								")
	print("Your class weighted grade is: " + str(class_grade) + "% ")
	print("								")
	#Loops when the user wishes to or terminates when they don't
	while True:
		end = input("Do you want to calculate for another class? Type 'yes' or 'no': ")
		if end == 'yes':
			main()
			break
		elif end == 'no':
			print("Goodbye!")
			exit()
		else:
			print("Invalid input.")
			continue

main()
