#This is the program for a brute force approach to solving the closest points problem, and will run in O(n^2) time.
import sys
import math


pairList = []


def distance(pt1, pt2):
	dist = math.sqrt(pow((float(pt2[0])-float(pt1[0])), 2) + pow((float(pt2[1])-float(pt1[1])), 2))
	return dist
def writefile(points, distance):
	f1 = "output_naive.txt"	
	with open(f1, "a+") as f:
		f.write(str(distance) + '\n')
		for i in points:
			f.write(i[0] + " " + i[1] + '\n')

def writefile2(points):
	f1 = "output_naivepoints.txt"	
	with open(f1, "a+") as f:
		for i in points:
			f.write(i[0] + " " + i[1] + '\n')

def writefile3(distance):
	f1 = "output_naivedistance.txt"	
	with open(f1, "a+") as f:
		f.write(str(distance) + '\n')


	

def closest_cross_pair(My, d):
	dm = d
	for i in range(len(My) - 1):
		j = i + 1
		while float(My[j][1]) - float(My[i][1]) <= d and j + 1 != len(My):
			# Output all to a file and only present the last one
			d = distance(My[i], My[j])
				
			if(d <= dm):
				pairList.append(My[i])
				pairList.append(My[j])
					
			dm = min(d, dm)
#			print dm
			j = j + 1
	return dm 

def div_and_conq(Px): #for this naive appraoch, the array is sorted by x coordinates
	closest_points = []
	if len(Px) <= 3:
		current = math.sqrt(pow((float(Px[1][0])-float(Px[0][0])), 2) + pow((float(Px[1][1])-float(Px[0][1])), 2))
		for i in range(len(Px)):
                	for j in range(i):
                        	distance = math.sqrt(pow((float(Px[j][0])-float(Px[i][0])), 2) + pow((float(Px[j][1])-float(Px[i][1])), 2))
				if distance < current:
					current = distance
		return current
	
	else:
		mid = len(Px) / 2	
		if len(Px) % 2 == 0:
			med = (float(Px[mid][0]) + float(Px[mid - 1][0])) / 2	
		else:
			med = float(Px[mid][0])
		Q = Px[:mid]
		R = Px[mid:]
		
		d1 = div_and_conq(Q)
		d2 = div_and_conq(R)
		d = min(d1, d2)
		for i in range(len(Px)):
			if float(Px[i][0]) <= med + d and float(Px[i][0]) >=  med - d:
				closest_points.append(Px[i])
		closest_points.sort(key=lambda y: y[1])
		dm = closest_cross_pair(closest_points, d)
	#	print dm
		return dm

def readfile(fn):
	coords = []
	pairs = []
	with open(fn) as f:
		coords = f.read().splitlines()
	for i in range(len(coords)):
		pairs.append(coords[i].split())
	pairs.sort(key=lambda x: x[0]) #sorts based on x coordinate only

	result = div_and_conq(pairs)
	print "CLOSEST DISTANCE: " + str(result)
	print pairList
	
	writefile3(result)
def main(filename):
	if len(filename) == 1:
		fn = filename[0]	
		readfile(fn)
	else:
		print "Error reading command line. Format: program <filename>"

	



if __name__ == "__main__":
    main(sys.argv[1:])
