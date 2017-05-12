#!/usr/bin/python

import sys
import math
import time
import csv

size = 6
table = [[0 for x in range(size)] for y in range(size)]
def write_file(str1, str2, cost):
	f = open("imp2output.txt", 'a')
	f.write(str1 + ',' + str2 + ':' + str(cost) + '\n')
	
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
	matrix = {}

	#This table won't be correct since operations have varied costs
	for i in range(0, len(str1)+1):
		if i == 0:
			matrix[i,0] = getCost("-", "-")
		else:	
			matrix[i, 0] = getCost("-", str1[i-1]) + matrix[i-1,0]
	for j in range(0, len(str2)+1): 
		if j == 0:
			matrix[0, j] = getCost("-", "-")	
		else:	
			matrix[0, j] = getCost("-", str2[j-1]) + matrix[0, j-1]
	
#	for i in range(1, (len(str1)+1)):
#		for j in range(1, (len(str2)+1)):
#			if str1[i-1] == str2[j-1]: cost = 0
#			else: cost = getCost(str1[i-1], str2[j-1])
#			
#			#min -> insert, delete, sub/copy
			
#			matrix[i,j] = min(matrix[i-1,j]+getCost(str1[i-1], "-"), matrix[i, j-1]+getCost("-", str2[j-1]), matrix[i-1, j-1]+cost)
`	
	backtrace = []
	for i in range(1, (len(str1)+1)):
		for j in range(1, (len(str2)+1)):
			flag = ""
			if str1[i-1] == str2[j-1]: cost = 0
			else: cost = getCost(str1[i-1], str2[j-1])
			
			#min -> insert(left), delete(up), sub/copy(diag)
			left = matrix[i-1,j]+getCost(str1[i-1], "-")
			up = matrix[i, j-1]+getCost("-", str2[j-1])
			diag = matrix[i-1, j-1]+cost
			
			matrix[i,j] = left
			flag = "left"
			
			if matrix[i,j] > up:
				matrix[i,j] = up
				flag = "up"
			if matrix[i,j] >= diag:
				matrix[i,j] = diag
				flag = "diag"
			
			backtrace.append(flag)
			

	print "Minimum is: " + str(matrix[i,j])	
	print backtrace
#	cost = matrix[i,j]
	
#	trace = []
#	tracei = []
#	tracej = []
#	minimum = matrix[i, j]
#	trace.append(minimum)
	
#	while i > 0 and j > 0:
#		ins = matrix[i-1,j]
#		dele = matrix[i,j-1]
#		sub = matrix[i-1,j-1]
#		minimum = min(ins, dele, sub)
#		trace.append(minimum)		
#		if minimum == sub:
#			tracei.append(str1[i-1])
 #                       tracej.append(str2[j-1])
#			i = i - 1
#			j = j - 1
#		elif minimum == dele:
#			tracej.append(str2[j-1])
 #                       tracei.append('-')
#			j = j-1

#		elif minimum == ins:
 #                       tracei.append(str1[i-1])
#			tracej.append('-')
#			i = i - 1

#	tracei.reverse()
#	tracej.reverse()
#	strj = ""
#	stri = ""
#	for i in tracei:
#		stri = stri + i
#	for j in tracej:
#		strj = strj + j
#	write_file(stri, strj, cost)

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
	
