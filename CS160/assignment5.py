#CS160 - Assignment 5 "Turtle Star" by Ronald Salinas
import turtle

wn = turtle.Screen()
wn.title("Click on the turtle to make a star.")  #Random title
wn.bgcolor('light blue')
turtle = turtle.Turtle()
turtle.shape('turtle')
def star(x,y):			#Define function for the drawing
	turtle.reset()		#Clears any previously drawn items
	turtle.penup()
	turtle.speed(10)
	turtle.goto(-97,35)	#Sets starting position
	turtle.pendown()
	for star in range(0,5):
		turtle.fd(200)
		turtle.rt(144)
	turtle.penup()
	turtle.goto(0,0)
turtle.onclick(star)		#Repeats when turtle is clicked
wn.mainloop()
