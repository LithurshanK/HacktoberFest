def pal(word):
    word=list(word)
    if len(word)==0 or len(word)==1:
        return "palindrome"
    else:
        if word[0]==word[-1]:
            return pal(word[1:-1])
        else:
            return 'no'
print(pal('noon'))
