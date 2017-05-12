#This is the program for a brute force approach to solving the closest points problem, and will run in O(n^2) time.
import sys
import math
import os
import time

def distance(pt1, pt2):
	dist = math.sqrt(pow((float(pt2[0])-float(pt1[0])), 2) + pow((float(pt2[1])-float(pt1[1])), 2))
	return dist

def writefile(points):
	f1 = "temp.txt"	
	with open(f1, "w+") as f:
		for i in points:
			f.write(i[0] + " " + i[1] + '\n')

def closest_cross_pair(My, d):
	dm = d
	for i in range(len(My) - 1):
		j = i + 1
		while float(My[j][1]) - float(My[i][1]) <= d and j + 1 != len(My):
			d = distance(My[i], My[j])
			dm = min(d, dm)
			j = j + 1
	return dm 
def write_distance(dist):
	#with open(fn) as f:
        #        coords = f.read().splitlines()
        #for i in range(len(coords)):
        #        pairs.append(coords[i].split())

	f1 = "temp.txt"
	f2 = "output_divideandconquer.txt"
	with open(f1) as f:
                coords = f.read().splitlines()
	
	with open(f2, "a+") as f:
		f.write(str(dist) + '\n')
		for i in coords:
			f.write(i + " ")
	os.remove(f1)	

def div_and_conq(Px): #for this naive appraoch, the array is sorted by x coordinates
	closest_points = []
	if len(Px) <= 3:
		current = math.sqrt(pow((float(Px[1][0])-float(Px[0][0])), 2) + pow((float(Px[1][1])-float(Px[0][1])), 2))
		for i in range(len(Px)):
                	for j in range(i):
				p = []
				p.append(Px[i])
				p.append(Px[j])
				writefile(p)			
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
		
		return dm
		
def readfile(fn):
	coords = []
	pairs = []

	with open(fn) as f:
		coords = f.read().splitlines()
	for i in range(len(coords)):
		pairs.append(coords[i].split())
	start = time.time()
	pairs.sort(key=lambda x: x[0]) #sorts based on x coordinate only
	d = div_and_conq(pairs)
	print "ELAPSED:",time.time()-start
	write_distance(d)
def main(filename):
	if len(filename) == 1:
		fn = filename[0]	
		readfile(fn)
	else:
		print "Error reading command line. Format: program <filename>"

	



if __name__ == "__main__":
    main(sys.argv[1:])
