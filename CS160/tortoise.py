#"Turtle Shapes" lab 6 edit by Ronald Salinas CS160
def main():
	import turtle
	window = turtle.Screen()
	my_turtle = turtle.Turtle()

	turtle.Screen().bgcolor("blue")
	turtle.color("red", "green")
	my_turtle.reset()
	window.reset()
	def square():
		for square in range(0,4):
			turtle.fd(200);
			turtle.rt(90);
	def triangle():
		for triangle in range(0,3):
			turtle.fd(200);
			turtle.lt(120);
	def hexagon():
		for hexagon in range(0,6):
			turtle.fd(120);
			turtle.rt(60);
	def octogon():
		for octogon in range(0,8):
			turtle.fd(100);
			turtle.lt(45);
	while True:
		shape = input("What shape do you want? (choices: square, triangle, hexagon, and octogon): ")
		if shape.lower() == 'square':
			square()
			pass
		elif shape.lower() == 'triangle':
			triangle()
			pass
		elif shape.lower() == 'hexagon':
			hexagon()
			pass
		elif shape.lower() == 'octogon':
			octogon()
			pass
		else:
			print("Invalid entry.")
			continue
		break
	while True:
		response = input("Would you like to draw another shape? 1 - 'Yes' or 0 - 'No': ")
		if response == '1':
			main()
		elif response == '0':
			print("Goodbye!")
			quit()
		else:
			print("Invalid entry.")
			continue
main()
