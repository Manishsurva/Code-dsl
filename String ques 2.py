string = input("enter your string:")
wordis = string.split()
longest_word = max(wordis, key = len)
print("longest word is :",longest_word)

char = input("please enter frequency of character:")
count = 0
i=0
while(i<len(string)):
    if(string[i]==char):
        count=count+1
    i=i+1
print("freq of the",char,"in stri string is:",count)

def palindrome(string):
    string = string.lower().replace('','')
    return string == string[::-1]
print("is palindrome:",palindrome(string))

substring = input("enter the sub string:")
print("index of your sub string is:",string.index(substring))

def word_count(str):
    count = dict()
    words = str.split()
    for word in words:
        if word in count:
            count[word] += 1
        else:
            count[word] = 1
    return
print("count the occurance of each word is:\n", word_count(string))


