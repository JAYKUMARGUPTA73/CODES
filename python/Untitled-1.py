import turtle
s=turtle.Screen()
s.bgcolor("black")
t=turtle.Turtle()
t.pencolor("white")
t.pensize(0.3)
t.speed(0)
a=0
while a<3000:
  a+=0.5
  t.circle(a)
  t.left(6)
  if a>50 and a<100:
    t.pencolor("green")
  if a>100 and a<150:
    t.pencolor("orange")
  if a>150 and a<200:
    t.pencolor("navy")
  if a>200 and a<250:
    t.pencolor("red")
  if a>250 and a<300:
    t.pencolor("pink")
