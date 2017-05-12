#This is the program for a brute force approach to solving the closest points problem, and will run in O(n^2) time.
import sys
import math

def distance(pt1, pt2):
	dist = math.sqrt(pow((float(pt2[0])-float(pt1[0])), 2) + pow((float(pt2[1])-float(pt1[1])), 2))
	return dist

def writefile(points, distance):
	f1 = "output_bruteforce.txt"	
	with open(f1, "a+") as f:
		f.write(str(distance) + '\n')
		for i in points:
			f.write(i[0] + " " + i[1] + '\n')
	

def brute_sort(coords):
        #we will append all closest points to some array
        distances = []
        points = []
        closest_points = []
        current = math.sqrt(pow((float(coords[1][0])-float(coords[0][0])), 2) + pow((float(coords[1][1])-float(coords[0][1])), 2))
        for i in range(len(coords)):
                for j in range(i):
                        points.append((coords[i][0] + " " + coords[i][1], coords[j][0] + " " + coords[j][1]))
                        distance = math.sqrt(pow((float(coords[j][0])-float(coords[i][0])), 2) + pow((float(coords[j][1])-float(coords[i][1])), 2))
                        distances.append(distance)
                        if current > distance:
                                current = distance
                                point = coords[j][0] + " "  + coords[i][0] + " " +  coords[j][1] + " " + coords[i][1]
        for i in range(len(distances)):
                if distances[i] == current:
                        closest_points.append(sorted(points[i])) #handles other points of same distance


        closest_points = sorted(closest_points)


def closest_cross_pair(My, d):
	dm = d
	for i in range(len(My) - 1):
		j = i + 1
		while float(My[j][1]) - float(My[i][1]) <= d and j + 1 != len(My):
			d = distance(My[i], My[j])
			dm = min(d, dm)
			print dm
			j = j + 1
	return dm 
def div_and_conq(Px, Py): #for this naive appraoch, the array is sorted by x coordinates
	closest_points = []
	print Px
	if len(Px) <= 3:
		current = math.sqrt(pow((float(Px[1][0])-float(Px[0][0])), 2) + pow((float(Px[1][1])-float(Px[0][1])), 2))
		for i in range(len(Px)):
                	for j in range(i):
                        	distance = math.sqrt(pow((float(Px[j][0])-float(Px[i][0])), 2) + pow((float(Px[j][1])-float(Px[i][1])), 2))
				if distance < current:
					current = distance
		print current
		return current
	
	else:
		mid = len(Px) / 2	
		if len(Px) % 2 == 0:
			med = (float(Px[mid][0]) + float(Px[mid - 1][0])) / 2	
		else:
			med = float(Px[mid][0])
		Q = Px[:mid]
		R = Px[mid:]
		Qy = Py[:mid]
		Ry = Py[mid:]
		
		d1 = div_and_conq(Q, Qy)
		d2 = div_and_conq(R, Ry)
		d = min(d1, d2)
		for i in range(len(Px)):
			if float(Py[i][0]) <= med + d and float(Py[i][0]) >=  med - d:
				closest_points.append(Py[i])
		
		dm = closest_cross_pair(closest_points, d)
		print dm
		return dm

def readfile(fn):
	coords = []
	pairs = []
	pairsx = []
	pairsy = []
	with open(fn) as f:
		coords = f.read().splitlines()
	for i in range(len(coords)):
		pairs.append(coords[i].split())
	
	pairsx = pairs
	pairsy = pairs

	pairsx.sort(key=lambda x: x[0]) #sorts based on x coordinate only
	pairsy.sort(key=lambda y: y[1])

	div_and_conq(pairsx, pairsy)
def main(filename):
	if len(filename) == 1:
		fn = filename[0]	
		readfile(fn)
	else:
		print "Error reading command line. Format: program <filename>"

	



if __name__ == "__main__":
    main(sys.argv[1:])
