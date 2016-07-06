import random

for i in range(2, 10001):
	f = open("szn" + str(i) + ".in", "w")
	twineCount = random.randint(1, 10)
	f.write(str(twineCount) + "\n")
	occupied = []
	for j in range(0, twineCount):
		twineLength = 0
		while twineLength == 0 or (twineLength in occupied):
			twineLength = random.randint(1, 20)
		occupied.append(twineLength)
		twineCount = random.randint(1, 10)
		f.write(str(twineLength) + " " + str(twineCount) + "\n")
	f.close()
		
