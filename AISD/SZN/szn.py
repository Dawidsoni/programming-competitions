from sets import Set

def isDistinct(twineList): 
	twineSet = Set()
	for it in twineList:
		if it in twineSet:
			return False
		twineSet.add(it)
	return True
			

twineCount = int(input())
twineList = []

for i in range(0, twineCount):
	twineLength, twineCount = map(int, raw_input().split(' '))
	for j in range(0, twineCount):
		twineList.append(twineLength)
	
while isDistinct(twineList) == False:
	twineList = sorted(twineList)
	removeInd = 0
	for i in range(len(twineList) - 1, 0, -1):
		if twineList[i] == twineList[i - 1]:
			removeInd = i
			break
	newEl = twineList[removeInd] * 2
	del twineList[removeInd]
	del twineList[removeInd - 1]
	twineList.append(newEl)
print len(twineList)

