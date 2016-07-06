import math

point_count = (int)(input())

point_list = []
result = 10e16

def getDist(p1, p2):
	dist_x = abs(p1[0] - p2[0])
	dist_y = abs(p1[1] - p2[1])	
	return math.sqrt(pow(dist_x, 2) + pow(dist_y, 2))

def getTriangle(p1, p2, p3):
	return getDist(p1, p2) + getDist(p2, p3) + getDist(p1, p3)


for i in range(0, point_count):
	point_x, point_y = map(int, raw_input().split(' '))
	point_list.append((point_x, point_y))
for i in range(0, point_count):
	for j in range(i + 1, point_count):
		for k in range(j + 1, point_count):
			dist = getTriangle(point_list[i], point_list[j], point_list[k])
			result = min(result, dist)
print (int)(result)
