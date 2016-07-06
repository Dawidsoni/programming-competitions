import random

f = open("test.in", "w+")
f.write(str(100000) + "\n")
for i in range(0, 100000):
	xCoord = random.randint(1, 1000000000)
	yCoord = random.randint(1, 1000000000)
	f.write(str(xCoord) + " " + str(yCoord) + "\n")

f.close()
