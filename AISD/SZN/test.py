import os

for i in range(2, 10001):
	print "test" + str(i)
	os.system("./szn < szn" + str(i) + ".in > wzo" + str(i) + ".out")
	os.system("python szn.py < szn" + str(i) + ".in > brut" + str(i) + ".out")
	diff = os.system("diff wzo" + str(i) + ".out brut" + str(i) + ".out")
	if diff != 0:
		print diff
		break
