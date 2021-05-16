def convertPattern(pattern):
    if pattern[0] == 'x':
        return list(pattern), False
    newPattern = ['x' if char == 'y' else 'y' for char in pattern]
    return newPattern, True

def formedString(x, y, pattern, string):
    newString = [x if char == 'x' else y for char in pattern]
    return "".join(newString)

# O(n+m) space
# O(n(n+m)) time
def xy(string, pattern):
    x=None
    y=None
    
    # invalid input case
    if len(string) < len(pattern):
        return x, y
    
    pattern, didSwitch = convertPattern(pattern)
    pos_y = pattern.index('y')
    
    if pos_y not in range(len(string)):
        if not len(string)%len(pattern):
            x = string[:len(string)%len(pattern)]
        return x, y
    
    num_x = 0
    num_y = 0

    for char in pattern:
        if char == 'x':
            num_x += 1
        if char == 'y':
            num_y += 1
    
    for lengthX in range(1, ((len(string)-1)//pos_y)+1):
        x = string[:lengthX]
        len_y = (len(string) - num_x*lengthX)//num_y
        if (len(string) - num_x*lengthX)%num_y and len_y < 0:
            continue
        y = string[lengthX*pos_y: lengthX*pos_y+len_y]
        newString = formedString(x, y, pattern, string)
        if newString == string:
            return (y, x) if didSwitch else (x, y)
    return None, None

print(xy("gogo23gogo23go", "xxyxxyx"))
print(xy("gogo23gogo23go", "yyxyyxy"))
