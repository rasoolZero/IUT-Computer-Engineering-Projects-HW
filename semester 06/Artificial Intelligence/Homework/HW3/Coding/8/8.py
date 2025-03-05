import queue


class Node:
    row=0
    col=0
    pathToNode = []
    def __init__(self,c=0,r=0):
        self.col=c
        self.row=r
        pathToNode = []
    
    def getNeighbors(self):
        neighborsList = []
        for i in range(-2,3,4):
            for j in range(-1,2,2):

                n = Node(self.col+i,self.row+j)
                n.pathToNode = self.pathToNode.copy()
                if n.isValid():
                    n.pathToNode.append(n)
                    neighborsList.append(n)

                n = Node(self.col+j,self.row+i)
                n.pathToNode = self.pathToNode.copy()
                if n.isValid():
                    n.pathToNode.append(n)
                    neighborsList.append(n)

        return neighborsList
    
    def isValid(self):
        return self.col>0 and self.col<=4 and self.row>0 and self.row<=4 and self not in self.pathToNode #can't visit the same square twice
    def __repr__(self):
        return f"({self.col},{self.row})"
    def __str__(self):
        return f"{self.col} {self.row}"
        
    def __eq__(self, other):
        if (isinstance(other, Node)):
            return self.row == other.row and self.col == other.col
        return False



def bfs(startNode,listOfPawns):
    q = queue.SimpleQueue()
    startNode.pathToNode.append(startNode)
    q.put(startNode)
    bestPath=[]
    bestRecord=0
    while not q.empty():
        nodeToExpand = q.get()
        for neighbor in nodeToExpand.getNeighbors():
            q.put(neighbor)
            
            capturedPawns = [x for x in listOfPawns if x in neighbor.pathToNode]
            if len(capturedPawns) > bestRecord:
                bestRecord = len(capturedPawns)
                bestPath = neighbor.pathToNode.copy()
            
            if bestRecord ==  len(listOfPawns):
                return True,bestPath,bestRecord
    return False,bestPath,bestRecord

col,row = list(map(int,input().split(" ")))
startNode = Node(col,row)

listOfPawns = []
while(True):
    col,row = list(map(int,input().split(" ")))
    if col==0 and row==0:
        break
    listOfPawns.append(Node(col,row))

success , bestPath , numberOfPawnsCaptured = bfs(startNode,listOfPawns)

if not success:
    print("Fail")
    print(numberOfPawnsCaptured)
for node in bestPath:
    print(str(node))