import turtle
pep=turtle.Turtle()
for i in range(5):
    pep.forward(100)
    for i in range(5):
        pep.forward(100)
        pep.right(90)
        pep.color('blue')
        pep.forward(100)
        pep.right(90)
        pep.color('red')
        pep.forward(100)
        pep.right(90)
        pep.color('green')
        pep.forward(100)

# list(range(5))
# will print [0, 1, 2, 3, 4]
