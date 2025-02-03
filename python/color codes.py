list1=["black","red","white"]
list2=["#000000","FF00000","#800000"]
list3=list()
for i in range(0,len(list1)):
    dict1={
        "color_name":list1[i],
        "code":list2[i]
    }
    list3.append(dict1)
print(list3)
    