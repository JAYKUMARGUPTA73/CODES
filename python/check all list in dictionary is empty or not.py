list2=[{},{},{},{}]
list1=[{1:"jay"},{2:"kumar",3:"gupta"},{}]
count=0
for i in range(0,len(list2)):
    if len(list2[i])==0:
        count+=1
print(count)
if(count==len(list2)):
    print("All dictionaries in list are empty")
else:
    print("All dict in list are not empty")
    