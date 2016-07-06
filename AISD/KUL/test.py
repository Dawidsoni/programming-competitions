import os

for i in range(7, 101):
	print "test" + str(i)
	os.system("./wzo < " + str(i) + ".in > wzo" + str(i) + ".out")
	diff = os.system("diff " + str(i) + ".out wzo" + str(i) + ".out")
	if diff != 0:
		print diff
		break
