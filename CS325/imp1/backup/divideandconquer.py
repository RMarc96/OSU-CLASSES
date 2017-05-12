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


#	print "STRIP: " + str(My)
#	print "LENGTH:" + str(len(My))
	
	for i in range(0, len(My) - 1):
		j = i + 1
#		print My
#		print len(My)
		while float(My[j][1]) - float(My[i][0]) <= d and j+1 != len(My):
			d = distance(My[i], My[j])
			dm = min(d, dm)
			j = j + 1
	return dm 

def div_and_conq(Px, closest_points): #for this naive appraoch, the array is sorted by x coordinates
	if len(Px) <= 3 and len(Px) != 1:
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
			med = float((float(Px[mid][0]) + float(Px[mid - 1][0])) / 2)
		else:
			med = float(Px[mid][0])
		Q = Px[:mid]
		R = Px[mid:]
		d1 = div_and_conq(Q, closest_points)
		d2 = div_and_conq(R, closest_points)
		d = min(d1, d2)
#		print d1
#		print d2
#		print di


		for i in range(0, len(Px)):
			if (float(Px[i][0]) <= float(med+d) and float(Px[i][0]) >= float(med-d)):
				closest_points.append(Px[i])
		closest_points.sort(key=lambda y: y[1])
		
#		print "FULL ARRAY: " + str(closest_points)

		dm = closest_cross_pair(closest_points, d)
		print dm
		return dm

def readfile(fn):
	coords = []
	pairs = []

	distances = []
	closest_points = []
	points = []
	with open(fn) as f:
		coords = f.read().splitlines()
	for i in range(len(coords)):
		pairs.append(coords[i].split())
	pairs.sort(key=lambda x: x[0]) #sorts based on x coordinate only
	div_and_conq(pairs, closest_points)
def main(filename):
	if len(filename) == 1:
		fn = filename[0]	
		readfile(fn)
	else:
		print "Error reading command line. Format: program <filename>"

	



if __name__ == "__main__":
    main(sys.argv[1:])
