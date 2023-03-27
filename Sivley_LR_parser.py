#BNF Parser
#Codey Sivley
#Programming Languages Fall 2021
grammar = {
    "E": "E + T",
    "E'": "T",
    "T": "T * F",
    "T'": "F",
    "F": "( E )",
    "F'": "id"
    }

###parse table###
#list of dictionaries, indexes are states, action/goto dictionary key values
matrix = [{"(":["s", 4], "id": ["s", 5], "E":1, "T":2, "F":3},#0
          {"+":["s", 6], "$": "acc"},
          {"+":["r", 2], "*":["s", 7], "$":["r", 2]},
          {"+":["r", 4], "*":["r", 4], "$":["r", 4]},
          {"(":["s", 11], "id":["s", 12], "E":8, "T":9, "F":10},
          {"+":["r", 6], "*":["r", 6], "$":["r", 6]}, #5
          {"(":["s", 4], "id":["s", 5], "T":13, "F":3},
          {"(":["s", 4], "id":["s", 5], "F":14},
          {"+":["s", 15], ")":["s", 16]},
          {"+":["r", 2], "*":["s", 17], ")":["r", 4]},
          {"+":["r", 4], "*":["r",4], ")":["r",4]}, #10
          {"(":["s", 11], "id":["s", 12], "E":18, "T":9, "F":10},
          {"+":["r", 6], "*":["r",6], ")":["r",6]},
          {"+":["r", 1], "*":["s", 7], "$":["r",1]},
          {"+":["r", 3], "*":["r", 3], "$":["r",3]},
          {"(":["s", 11], "id":["s", 12], "T":19, "F":10}, #15
          {"+":["r", 5], "*":["r", 5], "$":["r",5]},
          {"(":["s", 11], "id":["s", 12], "F":20},
          {"+":["s", 15], ")":["s", 21]},
          {"+":["r", 1], "*":["s", 17], ")":["r", 1]},
          {"+":["r", 3], "*":["r", 3], ")":["r", 3]}, #20
          {"+":["r", 5], "*":["s", 5], ")":["r", 5]}
          ]

###expected results###
#A + B * C                               = Accept
#A * B + C * A                          = Accept
#( A + B ) * ( C * D )                  = Accept
#A + B + C * A + B * C                  = Accept
#(A + B + C) * A * (B * C)              = Accept
#A * ( B  +  C )  * (B * ( A + D ) )    = Accept
#( ( ( A * B ) ) )                          = Accept

tokenStack = []
stateStack = []

stateStack.append(0)

sentence = "id + id"
sentence += " $"
tokenList = sentence.split()

def shift(token):
    state = stateStack[-1]
    if state == 0:
        tokenStack.append(token)
        stateStack.append
        if token == "id":
            stateStack.append(5)
        elif token == "(":
            stateStack.append(4)
        elif token == "E":
            stateStack.append(3)
        elif token == "T":
            stateStack.append(2)
        elif token == "E":
            stateStack.append(1)
        else:
            None
    if state == 5:
        tokenStack.pop()
        stateStack.pop()

        
        
