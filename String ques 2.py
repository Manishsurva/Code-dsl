string = input("enter the string:")
wordis = string.split()
longest_word = max(wordis,key=len)
print("longest word is:",longest_word)



char = input("enter the char for fre:")
count=0
i=0
while(i<len(string)):
    if(string[i]==char):
        count=i+1
    i=i+1
print("fre is :",count)


def palindrome(string):
    string = string.lower().replace('','')
    return string ==string[::-1]
print("is palindrome:",palindrome(string))

substring=input("enter ur substring:")
print("index of substring is:",string.index(substring))


def word_count(str):
    counts = dict()
    words = str.split()
    for word in words:
        if word in counts:
            counts[word] +=1
        else:
            counts[word]=1
    return counts
print("ur word count:\n",word_count(string))
    


    
               
               
