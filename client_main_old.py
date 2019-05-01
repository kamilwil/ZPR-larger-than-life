import tkinter as tk

WINDOW_WIDTH = 800
WINDOW_HEIGHT = 600
CELL_COUNT = 30
ITER_COUNT = 100

# CANVAS - tabela z komorkami
class ScalableCanvas(tk.Canvas):
	def __init__(self, parent, **kwargs):
		tk.Canvas.__init__(self, parent, **kwargs) #inicjacja Canvas
		self.bind("<Configure>", self.onResize) #powiazanie eventu odpowiedzialnego za zmiane rozmiaru okna z metoda callback
		for i in range(CELL_COUNT+2):
			self.create_line((i-1)*(WINDOW_HEIGHT-100)/CELL_COUNT, 0, (i-1)*(WINDOW_HEIGHT-100)/CELL_COUNT, WINDOW_HEIGHT-100) #pionowe linie w tabeli
			self.create_line(0, (i-1)*(WINDOW_HEIGHT-100)/CELL_COUNT, WINDOW_HEIGHT-100, (i-1)*(WINDOW_HEIGHT-100)/CELL_COUNT) #poziome linie w tabeli
		self.addtag_all("all")

		self.height = self.winfo_reqheight() 
		self.width = self.winfo_reqwidth()
	
	def onResize(self, event):
		wscale = float(event.width) / self.width #obliczanie stosunku skalowania
		hscale = float(event.height) / self.height
		self.width = event.width
		self.height = event.height
		self.config(width = self.width, height = self.height) #ustawianie nowych wymiarow Canvas
		self.scale("all", 0, 0, wscale, hscale) #ustawianie nowych wymiarow elementow wewnatrz

def onPressRules(self):
	#tu bedzie obsluga przycisku
	print('Hey! Ew prest the batyn! Heer haev sam logynfow.')

root = tk.Tk()
root.title("Larger than Life")
geom_string = str(WINDOW_WIDTH)+"x"+str(WINDOW_HEIGHT)
root.geometry(geom_string)

main_frame = tk.Frame(root, width = WINDOW_WIDTH, height = WINDOW_HEIGHT)
#main_frame = tk.Frame(root)
main_frame.pack(fill="both", expand=True)
#main_frame.grid(row=0, column=0)

canvas = ScalableCanvas(main_frame, width = WINDOW_WIDTH, height = WINDOW_HEIGHT, highlightthickness=0)
#canvas = ScalableCanvas(main_frame, highlightthickness = 0)
#canvas.place(x=50,y=50)
#canvas.pack(side="left")
canvas.pack(fill="both", expand=True)

#for i in range(CELL_COUNT+2):
#	canvas.create_line((i-1)*(WINDOW_HEIGHT-100)/CELL_COUNT, 0, (i-1)*(WINDOW_HEIGHT-100)/CELL_COUNT, WINDOW_HEIGHT-100) #pionowe linie w tabeli
#	canvas.create_line(0, (i-1)*(WINDOW_HEIGHT-100)/CELL_COUNT, WINDOW_HEIGHT-100, (i-1)*(WINDOW_HEIGHT-100)/CELL_COUNT) #poziome linie w tabeli

#canvas.addtag_all("all")

# BUTTON - przycisk otwierajacy panel z regulami
rules = tk.Button(main_frame, text="Zarzadzaj regulami")
rules.bind("<Button-1>", onPressRules)
rules.pack(side="left")
#rules.grid(row=0,column=1)




root.mainloop()