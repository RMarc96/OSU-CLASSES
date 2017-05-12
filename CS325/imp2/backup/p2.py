#!/usr/bin/python

import sys
import math
import time
import csv

size = 6
table = [[0 for x in range(size)] for y in range(size)]

def openCost(costFile):
	with open(costFile) as csvfile:
		readCSV = csv.reader(csvfile, delimiter=',')

		i = 0	
		for row in readCSV:
			#print(row)
			table[i] = row
			i = i + 1	


# THIS FUNCTION WILL ONLY WORK FOR 1 PAIR OF STRINGS. CHANGE LATER
def openStrings(stringsFile):
	with open(stringsFile) as csvfile:
		readCSV = csv.reader(csvfile, delimiter=',')

		for line in readCSV:
			string1 = line[0]
			string2 = line[1]
		#	string2 = line[1][1:]
			
			editDistance(string1, string2)

def getCost(char1, char2):
	if(char1 == "-"): a = 1
	elif(char1 == "A"): a = 2
	elif(char1 == "T"): a = 3
	elif(char1 == "G"): a = 4
	else: a = 5


	if(char2 == "-"): b = 1
	elif(char2 == "A"): b = 2
	elif(char2 == "T"): b = 3
	elif(char2 == "G"): b = 4
	else: b = 5

#	print "Value at that point is: " + table[a][b]

	return int(table[a][b])


def editDistance(str1, str2):

	print str(str1) + " with length " + str(len(str1))
	print str(str2) + " with length " + str(len(str2))

	matrix = {}

	#This table won't be correct since operations have varied costs
	for i in range(0, len(str1)+1):
		if i == 0:
			matrix[i,0] = getCost("-", "-")
		else:	
			matrix[i, 0] = getCost("-", str1[i-1]) + int(matrix[i-1,0])
	for j in range(0, len(str2)+1): 
		if j == 0:
			matrix[0, j] = getCost("-", "-")	
		else:	
			matrix[0, j] = getCost("-", str2[j-1]) + int(matrix[0, j-1])

#	print "X base cases:"
#	for i in range(0, (len(str1)+1)):
#		print matrix[i, 0]


#	print "Y base cases:"
#	for j in range(0, len(str2)+1):
#		print matrix[0, j]


#	for i in range(1, (len(str1)+1)):
#		for j in range(1, (len(str2)+1)):
#			if(str1[i-1] == str2[j-1]): diff = 0
#			else: diff = 1
#			matrix[i,j] = min(matrix[i-1,j] + 1, matrix[i, j-1] + 1, matrix[i-1,j-1] + diff)
		

	for i in range(1, (len(str1)+1)):
		for j in range(1, (len(str2)+1)):
			cost = getCost(str1[i-1], str2[j-1])
			matrix[i,j] = min(matrix[i-1,j]+cost, matrix[i, j-1]+cost, matrix[i-1, j-1]+cost)


	print "The cost for " + str1 + " and " + str2 + " is:    " + str(matrix[i,j])


def main(args):
	if len(args) == 2:
		arg1 = args[0]
		arg2 = args[1]		
		openCost(arg1)
		openStrings(arg2)
	else:
		print "Invalid arguments!"


if __name__ == "__main__":
	main(sys.argv[1:])
	
