arraySize = input()
array = map(int, raw_input().split())

for i in range(0, arraySize):	
	index = array.index(min(array))
	print index
	array[index] = 100000
	
	
