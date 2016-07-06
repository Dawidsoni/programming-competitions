import random

for i in range(1, 1001):
	print "gen test" + str(i)
	f = open("test" + str(i) + ".in", "w")
	dim_x = random.randint(1, 300)
	dim_y = random.randint(1, 300)	
	point_count = random.randint(1, dim_x * dim_y)
	f.write(str(dim_x) + " " + str(dim_y) + "\n")
	p_list = []
	for i in range(0, dim_x + 1):
		p_list.append([])
		for j in range(0, dim_y + 1):
			p_list[i].append(0)
	for i in range(0, dim_x * dim_y):
		coord_x = random.randint(1, dim_x)
		coord_y = random.randint(1, dim_y)
		weight = random.randint(1, 1000000000)
		p_list[coord_x][coord_y] = weight
	c_list = []
	for j in range(1, dim_x + 1):
		for k in range(1, dim_y + 1):
			if p_list[j][k] == 0:
				continue
			c_list.append((j, k, p_list[j][k]))
	f.write(str(len(c_list)) + "\n")
	for it in c_list:
		f.write(str(it[0]) + " " + str(it[1]) + " " + str(it[2]) + "\n")
	f.close()
