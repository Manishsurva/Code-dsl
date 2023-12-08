
studentmarks = []
studentpresent = []
studentabsent = []

def mark():
    
    num = int(input("Enter number of students:\n"))
    print("consider absent student's score as 0")
    for i in range(1,num + 1):
        print("enter marks of student:")
        s = int(input())
        studentmarks.append(s)
        if(s > 0):
            studentpresent.append(s)
        else:
            studentabsent(s)
            print("marks of students:", studentmarks)
                
             
def average():
    p = 0
    for i in studentpresent:
        p = p + i
    average = p / (len(studentpresent))
    print("average marks of class is:",average)
def high_low():
    print("highest marks in class:", max(studentpresent))
    print("lowest marks in class:", min(studentpresent))
def absent_length():
    print("count of students who were absent:",len(studentabsent))
def frequency():
    print("marks with highest freq count:",max(set(studentpresent), key=studentpresent.count))
mark()
average()
high_low()
absent_length()
frequency()


        
        

