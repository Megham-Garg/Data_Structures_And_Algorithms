import turtle
t=turtle.Turtle()
t.speed(1000000000000)
def square(length,angle):
    for a in range(4):
        t.forward(length)
        t.left(angle)
square(100,90)
for f in range(8):
        t.left(17)
        t.color('green')
        for r in range(36):
                square(100,90)
                t.left(10)
        t.left(17)
        t.color('blue')
        for r in range(36):
                square(100,90)
                t.left(10)