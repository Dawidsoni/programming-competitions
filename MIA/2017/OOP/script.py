from random import choice
from string import ascii_lowercase

f = open("test.in", "w")
f.write(str(100000) + " " + str(100000) + "\n")
for i in range(0, 100000):
	text = ''.join(choice(ascii_lowercase) for i in range(30))
	f.write(text + "\n")
for i in range(0, 100000):
	text1 = ''.join(choice(ascii_lowercase) for i in range(10))
	text2 = ''.join(choice(ascii_lowercase) for i in range(10))	
	f.write(text1 + "*" + text2 + "\n")	
f.close()	
