def thief():
    comb=input().split(" ")
    for i in range(4):
        for j in range(4):
            for l in range(4):
                for u in range(4):
                    print(comb[i],comb[j],comb[l],comb[u])
def thief2():
    comb=input().split(" ")
    for i in range(4):
        for j in range(4):
            for l in range(4):
                for u in range(4):
                    if(j!=i and j!=l and j!=u and j!=l and l!=u):

                        
                        print(comb[i],comb[j],comb[l],comb[u])


def palindrome():
    string2=""
    string3=""
    string1=input()
    string=[]
    string[:]=string1
    for i in range(len(string)):
        string2+=string[len(string)-i-1]
    if string2==string1:
        print("yes")
    else:
        print("no")


def sort():
    list=input().split()
    bool1=input("enter true for ascending order and false for descending order")
    if bool1=="true":
        list.sort()
    else:
        list.sort(reverse=True)
    print(list)
        

def sing():
    for i in range(10):  
        print(10-i," green bottles hanging on the wall ",10-i," green bottles hanging on the wall,And if one green bottle should accidentally fall,Therell be ",10-i-1," green bottles hanging on the wall.")
                    
def twoint():
    n=int(input())
    list1=[]
    for i in range(n):
        list1.append(input().split())
    for i in range(n):
        a=int(list1[i][0])
        b=int(list1[i][1])
        if a>b:
            if (a-b)%10==0:
                print((a-b)//10)
            else:
                print((a-b)//10+1)
        else:
            if (b-a)%10==0:
                print((b-a)//10)
            else:
                print((b-a)//10+1)
            
twoint()
