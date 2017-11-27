#!/usr/bin/env python3
import sys
import math

eps = float(sys.argv[1])
n = 1+1/math.sqrt(eps)
ans = 0.0

for k in range(1, int(n)):
	ans += 1/k**2

print(math.sqrt(6*ans))
