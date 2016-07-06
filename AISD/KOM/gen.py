import random

for i in range(1, 1001):
	fileTest = open("test" + str(i) + ".in", "w")	
	nCount = random.randint(3, 100000)
	mCount = random.randint(nCount, 1000000)
	gCount = random.randint(1, nCount)
	fileTest.write(str(nCount) + " " + str(mCount) + " " + str(gCount) + "\n")
	for j in range(0, mCount):
		fromV = random.randint(1, nCount)
		toV = random.randint(1, nCount)
		dist = random.randint(1, 100)
		fileTest.write(str(fromV) + " " + str(toV) + " " + str(dist) + "\n")
	goalList = range(1, nCount + 1)
	random.shuffle(goalList)
	for j in range(0, gCount):
		fileTest.write(str(goalList[j]) + " ")	
	fileTest.close()
		
		
	
