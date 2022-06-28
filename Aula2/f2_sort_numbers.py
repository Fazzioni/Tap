import random

size = 20

l = []
for i in range(size):
    l.append(i+1)

for i in range(size*2):
    el = random.randrange(0,size),random.randrange(0,size)
    l[el[0]],l[el[1]] = l[el[1]],l[el[0]]



indice = 0
l.insert(0,0)
l.append(0)
print(int(len(l)-1))

for i in range(len(l)-1):
    print(l[i]," ",l[i+1])

print("\n\n")
print(l)