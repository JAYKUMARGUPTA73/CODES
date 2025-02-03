def common(list1,list2):
    for i in range(0,len(list1)):
        if list1[i] in list2:
            print(list1[i])
            return True
list3=["jay","hey"]
list4=["kumar","hey"]
result=common(list3,list4)
print(result)