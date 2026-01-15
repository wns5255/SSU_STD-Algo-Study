import sys
from math import inf
import heapq

def problem11779_floyd2():
    n = int(sys.stdin.readline().rstrip())
    m = int(sys.stdin.readline().rstrip())
    arr = [[0 if i == j else inf for i in range(n)] for j in range(n)]
    idx_arr = [[0 for i in range(n)] for j in range(n)]

    for i in range(m):
        x, y, z = map(int, sys.stdin.readline().rstrip().split())
        arr[x-1][y-1] = z

    start, end = map(int, sys.stdin.readline().rstrip().split())

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if arr[i][k] + arr[k][j] < arr[i][j]:
                    idx_arr[i][j] = k+1
                    arr[i][j] = arr[i][k] + arr[k][j]
    p = []
    def path(q, r):
        if idx_arr[q][r] != 0:
            path(q, idx_arr[q][r])
            p.append(idx_arr[q][r])
            path(idx_arr[q][r], r)

    path(start-1, end-1)
    p = [start] + p + [end]
    p = list(map(str, p))
    print(arr[start-1][end-1])
    print(len(p))
    print(' '.join(p))


def problem11779_dijkstra():
    n = int(sys.stdin.readline())
    m = int(sys.stdin.readline())
    arr = [[] for i in range(n+1)]
    dist = [inf for i in range(n+1)]
    parent = [-1 for i in range(n+1)]

    for i in range(m):
        x, y, z = map(int, sys.stdin.readline().split())
        arr[x].append((y, z))

    start, end = map(int, sys.stdin.readline().split())

    queue = []
    heapq.heappush(queue, (0, start))
    parent[start] = start
    dist[start] = 0
    while queue:
        tmp = heapq.heappop(queue)
        cost = -tmp[0]
        pos = tmp[1]

        if dist[pos] < cost:
            continue

        for bus in arr[pos]:
            next_pos = bus[0]
            next_cost = cost + bus[1]
            if dist[next_pos] > next_cost:
                dist[next_pos] = next_cost
                heapq.heappush(queue, (-next_cost, next_pos))
                parent[next_pos] = pos

    path = [end]
    idx = end
    while parent[idx] != start:
        idx = parent[idx]
        path.append(idx)
    path.append(start)
    print(dist[end])
    print(len(path))
    path = list(map(str, reversed(path)))
    print(' '.join(path))


problem11779_dijkstra()