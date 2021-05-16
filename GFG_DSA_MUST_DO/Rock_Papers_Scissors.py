import simpleguitk as simplegui
import random

COMPUTER_SCORE = 0
HUMAN_SCORE = 0
human_choice = ""
computer_choice = ""

def choice_to_number(choice):
    return {'rock':0,'paper':1,'scissors':2}[choice]


def number_to_choice(number):
    return {0:'rock',1:'paper',2:'scissors'}[number]

def random_computer_choice():
    return random.choice(['rock','paper','scissors'])

def choice_result(computer_choice,human_choice):
    global COMPUTER_SCORE
    global HUMAN_SCORE
    if computer_choice=='rock':
        if human_choice=='paper':
            HUMAN_SCORE+=1
        elif human_choice=='scissors':
            COMPUTER_SCORE+=1
    elif computer_choice=='paper':
        if human_choice=='rock':
            COMPUTER_SCORE+=1
        elif human_choice=='scissors':
            HUMAN_SCORE+=1
    elif computer_choice=='scissors':
        if human_choice=='paper':
            COMPUTER_SCORE+=1
        elif human_choice=='rock':
            HUMAN_SCORE+=1

def test_choice_to_number():
    assert choice_to_number('rock') == 0
    assert choice_to_number('paper') == 1
    assert choice_to_number('scissors') == 2
    
def test_number_to_choice():
    assert number_to_choice(0) == 'rock'
    assert number_to_choice(1) == 'paper'
    assert number_to_choice(2) == 'scissors'
    
def test_all():
    test_choice_to_number()
    test_number_to_choice()

test_all()


# Handler for mouse click on rock button.
# This code is for the GUI part of the game.
def rock():
    global human_choice, computer_choice
    global HUMAN_SCORE, COMPUTER_SCORE
    
    human_choice = 'rock'
    computer_choice = random_computer_choice()
    choice_result(computer_choice, human_choice)

# Handler for mouse click on paper button.
def paper():
    global human_choice, computer_choice
    global HUMAN_SCORE, COMPUTER_SCORE
    
    human_choice = 'paper'
    computer_choice = random_computer_choice()
    choice_result(computer_choice, human_choice)
    
# Handler for mouse click on scissors button.
def scissors():
    global human_choice, computer_choice
    global HUMAN_SCORE, COMPUTER_SCORE
    
    human_choice = 'scissors'
    computer_choice = random_computer_choice()
    choice_result(computer_choice, human_choice)

# Handler to draw on canvas
def draw(canvas):
    
    try:
        # Draw choices
        canvas.draw_text("You: " + human_choice, [10,40], 48, "Green")
        canvas.draw_text("Comp: " + computer_choice, [10,80], 48, "Red")
        
        # Draw scores
        canvas.draw_text("Human Score: " + str(HUMAN_SCORE), [10,150], 30, "Green")
        canvas.draw_text("Comp Score: " + str(COMPUTER_SCORE), [10,190], 30, "Red")
        
    except TypeError:
        pass
    

# Create a frame and assign callbacks to event handlers
def play_rps():
    frame = simplegui.create_frame("Home", 300, 200)
    frame.add_button("Rock", rock)
    frame.add_button("Paper", paper)
    frame.add_button("Scissors", scissors)
    frame.set_draw_handler(draw)
    frame.start()
 
play_rps()
