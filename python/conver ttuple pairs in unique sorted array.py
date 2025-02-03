from collections import Counter
list1=[(2,3),(3,4),(5,4),(2,1)]
print(type(list1[0]))
list2=list()
for i in range(0,len(list1)):
    for j in range(0,len(list1[i])):
        list2.append(list1[i][j])
list3=list()
count=Counter(list2)
for keys in count:
    if keys not in list3:
        list3.append(keys)
#bubble sort:
for i in range(0,len(list3)-1):
    for j in range(0,len(list3)-1):
        if list3[j]>list3[j+1]:
            temp=list3[j+1]
            list3[j+1]=list3[j]
            list3[j]=temp
print(list3)
            
        