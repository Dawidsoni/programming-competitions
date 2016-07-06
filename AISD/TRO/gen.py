import random

for i in range(1, 11):
	f = open("test" + str(i) + ".in", "w")
	point_count = 500000
	f.write(str(point_count) + "\n")
	for i in range(0, point_count):
		p1 = random.randint(-10000000, 10000000)
		p2 = random.randint(-10000000, 10000000)
		f.write(str(p1) + " " + str(p2) + "\n")
	f.close()
