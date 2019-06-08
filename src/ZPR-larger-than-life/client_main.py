import tkinter as tk
import tkinter.filedialog as tkinterfiledialog
import platform
import os
from random import choice
from math import floor

WINDOW_WIDTH = 800
WINDOW_HEIGHT = 600
CELL_COUNT = 50

# Window (Frame)
class Window(tk.Frame):
	def __init__(self, parent=None, **kwargs):
		tk.Frame.__init__(self, parent, **kwargs)
		self.parent = parent
		self.height = self.winfo_reqheight() 
		self.width = self.winfo_reqwidth()

		self.bind("<Configure>", self.onWindowResize)

	def onWindowResize(self, event):
		self.parev_width = event.width
		self.parev_height = event.height

# ScalableCanvas (Canvas)
class ScalableCanvas(tk.Canvas):
	def __init__(self, parent=None, **kwargs):
		tk.Canvas.__init__(self, parent, **kwargs)
		self.bind("<Configure>", lambda event, arga=parent: self.onResize(event, arga))

		for i in range(CELL_COUNT+1):
			self.create_line(20 + i*(WINDOW_HEIGHT-300)/CELL_COUNT, 20, 20 + i*(WINDOW_HEIGHT-300)/CELL_COUNT, WINDOW_HEIGHT-80) #pionowe linie w tabeli
			self.create_line(20, 20 + i*(WINDOW_HEIGHT-100)/CELL_COUNT, WINDOW_HEIGHT-280, 20 + i*(WINDOW_HEIGHT-100)/CELL_COUNT) #poziome linie w tabeli
		self.addtag_all("all")

		self.height = self.winfo_reqheight() 
		self.width = self.winfo_reqwidth()

	def onResize(self, event, parent):
		wscale = float(parent.parev_width) / parent.width #obliczanie stosunku skalowania
		hscale = float(parent.parev_height) / parent.height
		
		parent.width = parent.parev_width
		parent.height = parent.parev_height
		self.config(width = parent.width, height = parent.height) #ustawianie nowych wymiarow Canvas
		self.scale("all", 0, 0, wscale, hscale) #ustawianie nowych wymiarow elementow wewnatrz

# RulesButton (Button)
class RulesButton(tk.Button):
	def __init__(self, parent=None, **kwargs):
		tk.Button.__init__(self, parent, **kwargs)
		self.parent = parent

def onPressSave():
	print('Called Save method!')
	if (platform.system() == "Windows"):
		directory = os.path.join("C:", "Users", os.getlogin(), "Desktop")
	else:
		directory = "/home/"+os.getlogin()
	save_dialog = tkinterfiledialog.asksaveasfilename(initialdir = directory,title = "Save rule as",filetypes = (("Textfiles","*.txt"),("All files","*.*")))
	print(save_dialog)
	try:
		with open(save_dialog, "w") as file:
			file.write(rule_field.get())
	except:
		print("Saving rule unsuccesful!")

def onPressLoad():
	print('Called Load method!')
	if (platform.system() == "Windows"):
		directory = os.path.join("C:", "Users", os.getlogin(), "Desktop")
	else:
		directory = "/home/"+os.getlogin()
	open_dialog = tkinterfiledialog.askopenfile(initialdir = directory,title = "Open rule",filetypes = (("Textfiles","*.txt"),("All files","*.*")))
	print(open_dialog)
	try:
		with open(open_dialog.name, "r") as file:
			read_rule = file.read()
			print(read_rule)
			rule_field.delete(0, tk.END)
			rule_field.insert(0, read_rule)
	except:
		print("Reading rule unsuccesful!")

	

def onPressRand():
	print('Called Randomize method!')
	r = range(1, floor((CELL_COUNT-0.5)/3.14))
	r_chosen = choice(r)
	c = range(0,256)
	c_chosen = choice(c)
	m = range(0,2)
	m_chosen = choice(m)
	n = ['M', 'N', 'C']
	n_chosen = choice(n)

	sb_max = 1
	if (n_chosen == 'M'):
		sb_max = (2*r_chosen + 1)**2
	elif (n_chosen == 'N'):
		sb_max = 2*r_chosen*(r_chosen+1)+1
	elif (n_chosen == 'C'):
		sb_max = floor(3.14*(r_chosen+0.5)**2)

	smin = range(0, sb_max)
	smin_chosen = choice(smin)
	smax = range(smin_chosen, sb_max)
	bmin = range(0, sb_max)
	bmin_chosen = choice(bmin)
	bmax = range(bmin_chosen, sb_max)
	
	rule_string = "{R:"+str(r_chosen)+",C:"+str(c_chosen)+",M:"+str(m_chosen)+",Smin:"+str(smin_chosen)+",Smax:"+str(choice(smax))+",Bmin:"+str(bmin_chosen)+",Bmax:"+str(choice(bmax))+",N:"+str(n_chosen)+"}"
	print(rule_string)
	rule_field.delete(0, tk.END)
	rule_field.insert(0, rule_string)


# IterButton (Button)
class IterButton(tk.Button):
	def __init__(self, parent=None, **kwargs):
		tk.Button.__init__(self, parent, **kwargs)
		self.parent = parent

def onPressPrev():
	print('Called Previous method!')

def onPressPlay():
	print('Called Play method!')

def onPressNext():
	print('Called Next method!')

root = tk.Tk()
root.title("Larger than Life")
geom_string = str(WINDOW_WIDTH)+"x"+str(WINDOW_HEIGHT)
root.geometry(geom_string)

main_frame = Window(root, width = WINDOW_HEIGHT, height = WINDOW_HEIGHT)
main_frame.pack(fill="both", expand=True)

canvas = ScalableCanvas(main_frame, width = WINDOW_WIDTH, height = WINDOW_HEIGHT, highlightthickness=0)
canvas.pack()

side_frame = tk.Frame(canvas, bg="gray")
sf = canvas.create_window(WINDOW_HEIGHT-250,0, anchor = "nw", window=(side_frame))

canvas.itemconfig(sf,width=230,height=WINDOW_HEIGHT)

save_rule = RulesButton(side_frame, text="Zapisz regule", command=onPressSave)
save_rule.pack(side="top")

load_rule = RulesButton(side_frame, text="Wczytaj regule", command=onPressLoad)
load_rule.pack(side="top")

rand_rule = RulesButton(side_frame, text="Losuj regule", command=onPressRand)
rand_rule.pack(side="top")

rule_field = tk.Entry(side_frame, width = 40, textvariable="Wpisz regule")
rule_field.pack(side="top")
rule_field.delete(0,tk.END)
rule_field.insert(0,"Wpisz regule")

iter_frame = tk.Frame(side_frame)
iter_frame.pack(side="top", anchor="center")

prev_iter = IterButton(iter_frame, text="<<", command=onPressPrev)
prev_iter.pack(side="left")

play_iter = IterButton(iter_frame, text=">", command=onPressPlay)
play_iter.pack(side="left")

next_iter = IterButton(iter_frame, text=">>", command=onPressNext)
next_iter.pack(side="left")



root.mainloop()