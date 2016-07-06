import random

for i in range(0, 10000):
	currentFile = open("test" + str(i) + ".txt", "w+")
	nPow = random.randint(1, 1000)
	nKos = random.randint(1, 1000)
	currentFile.write(str(nPow) + " " + str(nKos) + "\n")
	for j in range(0, nPow):
		currentFile.write(str(random.randint(1, 1000000)) + " ")
	currentFile.write("\n")
	lastDay = 0
	for j in range(0, nKos):
		lastDay = lastDay + random.randint(1, 10)
		currentFile.write(str(lastDay) + " " + str(random.randint(1, 1000000)) + "\n")	
	currentFile.close()
	
	
	currentFile.close()
