import numpy as np

f = open("big_input.txt", "wb")
elemCount, queryCount = 100000, 100000
f.write(str(elemCount) + " " + str(queryCount) + "\n")
for i in range(elemCount):
	f.write(str(np.random.randint(10000000)) + " ")
f.write("\n")
for i in range(queryCount):
	ind1, ind2 = np.random.randint(elemCount) + 1, np.random.randint(elemCount) + 1
	fromInd, toInd = (ind1, ind2) if ind1 < ind2 else (ind2, ind1)
	num = np.random.randint(toInd - fromInd + 1) + 1
	f.write(str(fromInd) + " " + str(toInd) + " " + str(num) + "\n")	
f.close()
