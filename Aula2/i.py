a = "dcaa"
#a = "cbbaaab"
#a = "cbaaabb"
a = "dccccecccaaaa"
 
# a = "dcaaa"
# gerar todas as possibilidades
 
a = "dcaab"
#a = "dccccecccaaaa"
a = "cbbab"
a = "daaaaaaa"

a = "dccccecccaaaa"
def compare(a):
    ma = max([len(v) for v in a])
    mi = min([len(v) for v in a])
    last = 0 
    for j in range(mi):
        if (ord(a[0][j]) > (ord(a[1][j]))):
            return a[1]
        elif (ord(a[0][j]) < (ord(a[1][j]))):
            return a[0]
    for i in a:
        if (len(i) == mi):
            return i

low = None
for i in range(len(a)):    
    s = ""
    for b in range(i+1):
        s+=a[b]
    for c in range(i,-1,-1):
        s+=a[c]
    if (low == None):
        low = s
    else:
        low = compare([low,s])
    print(s)

print("\n\n\n"+low)

print("\n1\n"+str(len(a))+"\n"+a)
