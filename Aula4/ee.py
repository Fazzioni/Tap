def getlist(a,l):
    print(a)
    if (l == 0):
        return

    s = ""
    for i in a:
        if (i == "0"):
            s += "10"
        else:
            s += "01"
        
    getlist(s, l-1)
##################

def getSequence(s):
    r = ""
    for i in s:
        if i == "0":
            r += "10"
        else:
            r += "01"
    print(r)

getlist("0", 3+3)
print("\n\n\n")

getSequence("11111111")
getSequence("11101111")