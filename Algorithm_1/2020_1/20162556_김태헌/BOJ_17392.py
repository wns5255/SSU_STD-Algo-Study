import sys

n, m = map(int, sys.stdin.readline().split())

result = sum(map(lambda x: int(x) + 1, sys.stdin.readline().split()))
tmp = int(max(0, (m - result) / (n+1)))
if not bool(tmp):
    output = max(0, m - result)
else:
    output = sum(map(lambda x: x*x, range(1, tmp+1))) * (n+1)
    tmp2 = m - result - tmp * (n+1)
    output += tmp2 * pow((tmp+1), 2)
print(output)
