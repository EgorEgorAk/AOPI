import math
from tkinter import *
from tkinter import messagebox
window = Tk() #Создаём окно приложения.
window.title("квадратные уравнения")
window.mainloop()
window.geometry('400x400')
def standard(a,b,c):
    
    d = b**2 - 4 * a * c
    print("Дискриминант равен :", d)
    if d == 0:
        x = -b/(2*a)
        print(f'В вашем уравнении один корень: {x}')
    elif d > 0:
        x1 = (-b+math.sqrt(d))/(2*a)
        x2 = (-b-math.sqrt(d))/(2*a) 
        print(f'Ваше уравнение имеет 2 корня : {x1, x2}')
    else:
        print("Ошибка ввода.")
def vieta(a,b,c):
    a == 1
    sum = -b
    proizv = c
    print(f'Сумма корней и их произведение по теореме виета:{sum,proizv}')
    

def main():
    try:
        a = int(input("Введите заначение a : "))
        b = int(input("Введите значение b : "))
        c = int(input("Введите значение с : "))
        if a == 0:
            print("Это не квадратное уравнение")

            return 
        print("Стандертное решение :")
        standard(a, b, c)
        print("\nПо теореме Виета:")
        vieta(a, b, c)
    except ValueError:
        print("Ошибка ввода")

if __name__ == "__main__":
    main()