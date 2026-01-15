from _collections import deque


def solution(n, cores):

    if n <= len(cores):
        return n

    n -= len(cores)
    timer = deque([[] for _ in range(max(cores)+1)])
    for idx, c in enumerate(cores):
        timer[c].append(idx+1)

    while True:
#        print(timer)
        if not timer[0]:
            timer.rotate(-1)
        else:
            item = timer.popleft()
            timer.appendleft([])
            n -= len(item)
            if n <= 0:
                break
            for i in item:
                timer[cores[i - 1]].append(i)
            timer.rotate(-1)
    item.sort()
#    print(item,' ',n)
    return item[n-1]


print(solution(6, [1, 2, 3]))
