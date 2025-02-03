import tkinter as tk
windows=tk.Tk()
y=0
def greet():
    global y
    y+=1
    print(y)
# windows.geometry("200*100")
b=tk.Button(windows,text="click me",command=greet)
b.pack()
windows.mainloop()
