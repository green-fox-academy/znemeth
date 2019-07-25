import turtle
import pylint

win = turtle.Screen()
t = turtle.Pen()

colors = ['#c0c2ce', '#ffdead', '#c9c9ff', '#ddc1da', '#f7baa1', '#e1e9b7', '#73736f', '#bac8bd', '#c9c9ff', '#ffdead', '#e1e9b7', '#177e89']

t.fillcolor(colors[0])
t.begin_fill()

for i in range(12):
    t.forward(50)
    t.left(30)

t.end_fill()

for i in range(11):
    t.fillcolor(colors[i + 1])
    t.begin_fill()
    t.left(30)

    for i in range(12):
        t.forward(50)
        t.left(30)
    t.end_fill()

win.exitonclick()
