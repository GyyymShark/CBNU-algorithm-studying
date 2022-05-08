from itertools import permutations
number= int(input())
N_list = [i for i in range(1, number+1)]

for numbers in list(permutations(N_list)):
  for i in numbers: 
    print(i,end=" ")
  print()
