import os

for i in range(1, 1001):
	print "test" + str(i)
	os.system("./fib < fib" + str(i) + ".in > wzo" + str(i) + ".out")
	#os.system("python brut.py < fib" + str(i) + ".in > brut" + str(i) + ".out")
	#diff = os.system("diff -b wzo" + str(i) + ".out brut" + str(i) + ".out")
	#if diff != 0:
	#	print diff
	#	break
