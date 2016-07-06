def updateSizeTab(dayCount):
	for i in range(0, dayCount):
		for j in range(0, nPow):
			sizeTab[j] += powTab[j]
			
def updateSum(curLength):
	currentSum = 0
	for i in range(0, nPow):
		if sizeTab[i] > curLength:
			currentSum += (sizeTab[i] - curLength)
			sizeTab[i] = curLength
	print currentSum
			

nPow, nSkos = map(int, raw_input().split())
powTab = map(int, raw_input().split())
sizeTab = []
lastDay = 0
for i in range(0, nPow):
	sizeTab.append(0)
for i in range(0, nSkos):
	curDay, curLength = map(int, raw_input().split())
	updateSizeTab(curDay - lastDay)
	updateSum(curLength)
	lastDay = curDay
	
	

