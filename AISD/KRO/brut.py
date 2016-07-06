
dim_x, dim_y = map(int, raw_input().split(' '))
n_point = (int)(input())

coord_map = []
result = []
for i in range(0, 1100):
	coord_map.append([])
	result.append([])
	for j in range(0, 1100):
		coord_map[i].append(0)
		result[i].append(0)
for i in range(0, n_point):
	coord_x, coord_y, weight = map(int, raw_input().split(' '))
	coord_map[coord_x][coord_y] = weight
for i in range(1, dim_x + 1):
	for j in range(1, dim_y + 1):
		result[i][j] = max(result[i - 1][j], result[i][j - 1])
		result[i][j] += coord_map[i][j]
print result[dim_x][dim_y]
	
