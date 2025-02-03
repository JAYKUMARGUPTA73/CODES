list1=["abcd","abc","defd","annba","a","aa"]
count=0
for i in range(0,len(list1)):
    if len(list1[i])>=2:
        if list1[i][0]==list1[i][len(list1[i])-1]:
            count+=1
print("count is:"+str(count)) 
 