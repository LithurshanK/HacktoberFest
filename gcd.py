def gcd(x,y):
    if x==y:
        return x
    elif x>y:
        return gcd(x-y,y)
    elif x<y:
        return gcd(x,y-x)

data=list(map(int,input("Enter 2 numbers with space: ").split()))
print(gcd(data[0],data[1]))
