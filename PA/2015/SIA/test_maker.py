import os

for i in range(0, 10000):
	print "test" + str(i)
	os.system("./wzo < test" + str(i) + ".txt > wzo" + str(i) + ".out")
	os.system("python brut.py < test" + str(i) + ".txt > brut" + str(i) + ".out")
	diff = os.system("diff wzo" + str(i) + ".out brut" + str(i) + ".out")
	if diff != 0:
		print "ERROR TEST " + str(i)
		break
