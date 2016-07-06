import random

for i in range(1, 11):
	t_file = open("big" + str(i) + ".in", "w+")
	t_file.write("5000 5000\n")
	for i in range(0, 5000):
		for j in range(0, 5000):
			t_file.write(str(random.randint(1, 9)))
		t_file.write("\n")
		
	t_file.close()
