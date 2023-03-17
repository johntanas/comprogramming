participants = input()
dice_throws = input().split()

pro = {i:dice_throws.count(i) for i in dice_throws}

nl = {}

for key, value in enumerate(dice_throws):
	if pro[value] == 1:
		nl[key + 1] = value

if not nl:
	print("none")
else:
	print(max(nl, key=lambda k: nl[k]))