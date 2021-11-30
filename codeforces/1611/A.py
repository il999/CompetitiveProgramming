testcases = int(input())

for x in range(testcases):
    num = str(input())

    
    even_number_counter = 0
    for i in range(len(num)):
        if int(num[i])%2 == 0:
            even_number_counter += 1

   
    if int(num[-1])%2 == 0:
        print(0)

    
    elif even_number_counter == 0:
        print(-1)
    
    
    elif int(num[0])%2==0:
        print(1)

    
    else:
        
            
                print(2)
