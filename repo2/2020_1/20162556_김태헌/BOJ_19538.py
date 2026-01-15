import sys

n = int(sys.stdin.readline())
people_dict = [None] * (n+1)
for _ in range(n):
    people_dict[_+1] = [False, set(map(int, sys.stdin.readline().split()[:-1]))]

m = int(sys.stdin.readline())
ing = set()
trust = set()
start = set(map(int, sys.stdin.readline().split()))
for i in start:
    people_dict[i][0] = 1
    ing.update(people_dict[i][1])

ing -= start
trust.update(start)

n_iter = 2
while len(ing) != 0:
    change = set()
    tmp = set()
    finish = True
    for i in ing:
        count = people_dict[i][1] - trust
        if len(count) <= (len(people_dict[i][1])/2.):
            change.add(i)
            tmp.update(count)
            finish = False

    if finish:
        break
    for i in change:
        trust.add(i)
        people_dict[i][0] = n_iter
    tmp.update(ing)
    tmp -= change
    ing = tmp
    n_iter += 1

print(*map(lambda x: x[0]-1 if bool(x[0]) else -1, people_dict[1:]))