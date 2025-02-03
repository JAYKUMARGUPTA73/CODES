import tkinter as tk
windows=tk.Tk()
windows.title("Email-Box")
root=tk.Frame(windows)
to_label=tk.Label(windows,text="To:")
to_label.grid(row=0,column=0)
to_input=tk.Entry(windows)
to_input.grid(row=0,column=1)
windows.mainloop()