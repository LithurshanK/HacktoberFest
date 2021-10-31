#[0,1,1,2,3,5,8,13,21,34]

def summ(a):
    n=len(a)
    if len(a)==1:
        return a[0]
    else:
        return a[n-1]+summ(a[:-1])

print(summ([0,1,1,2]))
    
