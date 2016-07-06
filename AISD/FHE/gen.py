import random

for i in range(1, 1001):
	fileTest = open("fib" + str(i) + ".in", "w")	
	arraySize = random.randint(1, 100000)
	fileTest.write(str(arraySize) + "\n")
	array = range(0, arraySize)
	random.shuffle(array)	
	for it in array:
		fileTest.write(str(it) + " ")
		
		
	fileTest.close()
		
		
	
