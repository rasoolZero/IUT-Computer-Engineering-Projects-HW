# search.py
# ---------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

from ipaddress import collapse_addresses
from sqlite3 import Row
import util

from game import Directions

S = Directions.SOUTH
W = Directions.WEST
N = Directions.NORTH
E = Directions.EAST


class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()


def sampleSearch(problem) -> list:
    """
       Based on the list of moves returned by this function, Pacman moves two cells to the south,
       one cell to the west, one cell to the south, two cells to the west, one cell to the south,
       and finally, one cell to the west. Pacman reached his goal.
    """

    """
        In the functions “depthFirstSearch” and “aStarSearch”, 
        your algorithm must find a sequence of legal moves and return it as a list.
    """

    """
         Any move that causes Pacman to hit the wall is illegal. 
         If the returned list contains any illegal moves, the program stops by 
         raising an exception in line 353 of the pacman.py file.
    """

    return [S, S, W, S, W, W, S, W]


def sampleSearch2(problem) -> list:
    return [W, W, W, W, S, S, E, S, S, W]


""" ******************************************************************************** """


def depthFirstSearch(problem) -> list:
    from queue import LifoQueue
    stack = LifoQueue()  
    startNode = problem.getStartState()
    stack.put([(startNode,None,None)])
    visited = [startNode]
    while not stack.empty():
        path = stack.get()
        triple = path[-1]
        node = triple[0]

        if problem.isGoalState(node):
            actions = []
            for triple in path[1:]:
                actions.append(triple[1])
            return actions

        for triple in problem.getSuccessors(node):
            if triple[0] not in visited:
                visited.append(triple[0])
                new_path = list(path)
                new_path.append(triple)
                stack.put(new_path)
    return []


class Node:
    row = 0
    col = 0
    g = 0
    h = 0
    f = 0
    pathToNode = []
    state = None
    action = None
    def __init__(self,row:int,col:int,state,action:Directions,path:list):
        self.row = row
        self.col = col
        self.state = state
        self.action = action
        self.pathToNode = path.copy()
        self.pathToNode.append(action)
    def __lt__(self,other):
        return self.f < other.f
    def __gt__(self,other):
        return self.f > other.f
    def __eq__(self,other):
        return self.state == other.state
    
def manhattanDistance(node1:Node,node2:Node):
    return abs(node1.row - node2.row) + abs(node1.col - node2.col)

def aStarSearch(problem) -> list:
    

    goalNode = Node(5,1,None,None,[])
    startNode = Node(1,5,problem.getStartState(),None,[])
    openlist = [startNode] #list of open nodes
    closedlist = [] #list of visited states
    while len(openlist) != 0: 
        openlist.sort()
        nodeToExpand = openlist.pop(0)
        #print(nodeToExpand.pathToNode)
        closedlist.append(nodeToExpand.state)

        if problem.isGoalState(nodeToExpand.state):
            actions = nodeToExpand.pathToNode
            return actions[1:]
        for triple in problem.getSuccessors(nodeToExpand.state):
            #print(triple)
            if triple[0] in closedlist:
                continue
            row = nodeToExpand.row
            col = nodeToExpand.col
            if triple[1] == S:
                row+=1
            if triple[1] == N:
                row-=1
            if triple[1] == W:
                col-=1
            if triple[1] == E:
                col+=1
                
            neighbor = Node(row,col,triple[0],triple[1],nodeToExpand.pathToNode)
            neighbor.g = nodeToExpand.g + triple[2]
            neighbor.h = manhattanDistance(neighbor,goalNode)
            neighbor.f = neighbor.g + neighbor.h
            if neighbor in openlist:
                existingIndex = openlist.index(neighbor)
                if neighbor.g > openlist[existingIndex].g:
                    continue
            openlist.append(neighbor)
    #print(actions)
    return []


""" ******************************************************************************** """


def breadthFirstSearch(problem):
    """Search the shallowest nodes in the search tree first."""
    util.raiseNotDefined()


def uniformCostSearch(problem):
    """Search the node of the least total cost first."""
    util.raiseNotDefined()


def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0


# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
