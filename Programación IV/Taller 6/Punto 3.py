'''
3. Investigar cómo implementar interfaces gráficas en Python y realizar dos
ejemplos.
'''
# Hecho por: Steven Grisales López - 1034289634

''' Librería Tkinter ''' 
import tkinter as tk
from tkinter import messagebox

def greet():
    messagebox.showinfo("Saludo", "¡Hola, mundo!")

# Crear la ventana
root = tk.Tk()
root.title("Ejemplo Tkinter")

# Crear un botón
btn = tk.Button(root, text="Saludar", command=greet)
btn.pack(padx=20, pady=20)

# Mostrar la ventana
root.mainloop()


''' Librería PyQT '''
import sys
# pip install PyQt5
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QMessageBox

def greet():
    QMessageBox.information(window, "Saludo", "¡Hola, mundo!")

# Crear la aplicación
app = QApplication(sys.argv)
window = QWidget()
window.setWindowTitle("Ejemplo PyQt")

# Crear un botón
btn = QPushButton("Saludar", window)
btn.setGeometry(100, 50, 100, 50)
btn.clicked.connect(greet)

# Mostrar la ventana
window.show()
sys.exit(app.exec_())
