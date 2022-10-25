#change root to a for every student(vertice) that has b as root 
def change_root(roots,a,b):
    while(b in roots):
        roots[roots.index(b)] = a
        
# n - no of students and p - no of pairs 
n, p = map(int, input().strip().split())

pairs=[]

for i in range(p):
    u,v = map(int, input().strip().split())
    pairs.append([u,v])

roots=[]

# initialize root of a student as themself (root student will represent each district)
for i in range(n):
    roots.append(i)

for pair in pairs:
    u = pair[0]
    v = pair[1]
    a = roots[u]
    b = roots[v]
    # if there is a pair with different roots
    if (a!=b):
        
        #set the root to same 
        #select the root which have maximum students under it.
        if (roots.count(a)>= roots.count(b)):
            change_root(roots,a,b)
            
        else:
            change_root(roots,b,a)
            
# total number of ways possible
possiblePairs = n*(n-1)/2

# to findout the different districts based on root student
root_set = set(roots)

for root in root_set:
    x = roots.count(root)
    # when there is 2 or more students from same districts
    if x>=2:
        # substract the ways possible for selecting from same district
        possiblePairs -= x*(x-1)/2

print(int(possiblePairs))
    
