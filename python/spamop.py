import pyautogui as spam
import time

limit=input("enter your limit: ")
msg=input("enter your msg: ")

i=0
time.sleep(0)
while(i<int(limit)):
    spam.typewrite(msg)
    spam.press('Enter')
    i+=1

    