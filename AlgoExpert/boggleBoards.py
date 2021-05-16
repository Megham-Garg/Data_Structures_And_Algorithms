# O(wc + mn) space
# O(wc + mn(8^c)) time
def explore(i, j, board, trieNode, visited, finalWords):
    if visited[i][j] or:
        return
    currentLetter = board[i][j]
    if currentLetter not in trieNode:
        return
    visited[i][j] = True
    trieNode = trieNode[currentLetter]
    if "*" in trieNode:
        finalWords[trieNode["*"]] = True
    neighbours = getNeighbour(i, j, board)
    for neighbour in neighbours:
        explore(neighbour[0], neighbour[1], trieNode, visited, finalWords)
    visited[i][j] = False

def boggleBoard(board, words):
    trie = Trie()
    for word in words:
        trie.addWord(word)

    finalWords = {}
    visited = [[False for letter in row] for row in board]

    for i in range(len(board)):
        for j in range(len(board[0])):
            explore(i, j, board, trie.root, visited, finalWords)
    return (finalWords.keys())

class Trie:
    def __init__():
        self.root = {}
        self.endPoint = "*"
    
    def addWord(word):
        current = self.root
        for letter in word:
            if letter not in current:
                current[letter] = {}
            current = current[letter]
        current[self.endPoint] = word

def getNeighbour(i, j, board):
    neighbour = []
    if i > 0 and j > 0:
        neighbour.append([i-1,j-1])
    if i > 0 and j < len(board[0])-1:
        neighbour.append([i-1,j+1])
    if i < len(board)-1 and j < len(board[0])-1:
        neighbour.append([i+1,j+1])
    if i < len(board)-1 and j > 0:
        neighbour.append([i+1,j-1])
    if i > 0:
        neighbour.append([i-1,j])
    if i < len(board) - 1:
        neighbour.append([i+1,j])
    if j > 0:
        neighbour.append([i,j-1])
    if j < len(board[0]) - 1:
        neighbour.append([i,j+1])
    return neighbour

def __init__():
    # todo