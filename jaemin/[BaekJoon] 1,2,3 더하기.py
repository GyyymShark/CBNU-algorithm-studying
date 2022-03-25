N=int(input())

def sol(n):
  if n==1:
    return 1
  elif n==2:
    return 2
  elif n==3:
    return 4
  else:
    return sol(n-1)+sol(n-2)+sol(n-3) #3이상일 경우 하위 3개일 합과 같음

for i in range(N):
  n=int(input())
  print(sol(n))
