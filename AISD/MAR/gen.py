import random
from sets import Set

for i in range(11, 13):
	writer = open("test" + str(i) + ".in", "w")
	keyCount = 200000
	writer.write(str(keyCount) + "\n")
	arr = Set()
	i = 0
	while i < keyCount:
		key = random.randint(1, 500000)
		if key in arr:
			continue		
		writer.write(str(key) + " ")
		arr.add(key)
		i += 1
		print i		
	writer.close()
	
