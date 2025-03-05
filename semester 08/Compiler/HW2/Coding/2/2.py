from graphviz import Graph
from queue import LifoQueue as Stack

class LL1Parser:
    def __init__(self,filename : str):
        self.grammar__ = dict()
        with open(filename,'r') as file:
            self.grammar__ = eval(file.read())
        self.first__ = {}
        self.follow__ = {}
        self.table__ = {}
        self.calculate_first_set__()
        self.calculate_follow_set__()
        self.create_parsing_table__()

    def calculate_first_symbol__(self,symbol):
        if len(self.first__[symbol]) > 0:
            return
        productions = self.grammar__[symbol]
        for production in productions:
            if not production:
                self.first__[symbol].add('')
            elif production[0].isupper():
                self.calculate_first_symbol__(production[0])
                self.first__[symbol].update(self.first__[production[0]])
            else:
                self.first__[symbol].add(production[0])

            i = 1
            while i < len(production) and production[i-1].isupper() and '' in self.first__[production[i-1]]:
                if production[i].isupper():
                    self.calculate_first_symbol__(production[i])
                    self.first__[symbol].update(self.first__[production[i]] - {''})
                else:
                    self.first__[symbol].add(production[i])
                i += 1

    def calculate_first_set__(self):
        for variable in self.grammar__:
            self.first__[variable] = set()
        for variable in self.grammar__:
            self.calculate_first_symbol__(variable)


    def calculate_first_sentence__(self,sentence):
        first = set()
        for symbol in sentence:
            if symbol in self.grammar__.keys():
                first_symbol = self.first__[symbol]
                first.update(first_symbol - {''})
                if not '' in first_symbol:
                    return first
            else:
                first.add(symbol)
                return first
        first.add('')
        return first
    

    def calculate_follow_for_symbol__(self,symbol):
        for variable, productions in self.grammar__.items():
            for production in productions:
                for i in range(len(production)):
                    if production[i] == symbol:
                        if i == len(production) - 1:
                            self.follow__[symbol].update(self.follow__[variable])
                        else:
                            first_sentence = self.calculate_first_sentence__(production[i+1:])
                            if '' in first_sentence:
                                self.follow__[symbol].update(self.follow__[variable])
                            self.follow__[symbol].update(first_sentence - {''})


    def calculate_follow_set__(self):
        for variable in self.grammar__:
            self.follow__[variable] = set()
        self.follow__[list(self.grammar__.keys())[0]].add('$')
        while True:
            follow_old = self.follow__.copy()
            for variable in self.grammar__:
                self.calculate_follow_for_symbol__(variable)
            if follow_old == self.follow__:
                return
    
    def create_parsing_table__(self):
        for variable in self.grammar__:
            self.table__[variable] = {}
        
        for variable, productions in self.grammar__.items():
            for production in productions:
                first_production = self.calculate_first_sentence__(production)
                for terminal in first_production:
                    if terminal != '':
                        self.table__[variable][terminal] = production
                if '' in first_production:
                    for terminal in self.follow__[variable]:
                        self.table__[variable][terminal] = production
                        
    def parse_string(self,string : str) -> Graph:
        start_symbol = list(self.grammar__.keys())[0]
        stack = Stack()
        stack.put('$')
        stack.put(start_symbol)

        input_string = string+'$'
        tree = Graph()
        tree.node(start_symbol)
        counter = 0
        while stack.qsize() != 0:
            current_stack_name = stack.get()
            current_stack_symbol = current_stack_name[0]
            current_input = input_string[0]
            if current_input == current_stack_symbol:
                if current_input == '$':
                    return tree
                input_string = input_string[1:]
            elif current_stack_symbol in self.table__ and current_input in self.table__[current_stack_symbol]:
                production = self.table__[current_stack_symbol][current_input]
                if production == '':
                    tree.node('ε'+str(counter),label = 'ε',color = 'red')
                    tree.edge(current_stack_name,'ε'+str(counter))
                    counter += 1
                else:
                    temp = []
                    for symbol in production:
                        if symbol.isupper():
                            color = 'black'
                        else:
                            color = 'red'
                        tree.node(symbol+str(counter),color = color,label=symbol)
                        tree.edge(current_stack_name,symbol+str(counter))
                        temp.append(symbol+str(counter))
                        counter += 1
                    for symbol in reversed(temp):
                        stack.put(symbol)
            else:
                return None
        return tree


            


p1 = LL1Parser("input1.txt")
tree1 = p1.parse_string('abbacabba')
tree1.render('1',format="png")

p2 = LL1Parser("input2.txt")
tree2 = p2.parse_string('00110000')
tree2.render('2',format="png")

p3 = LL1Parser("input3.txt")
tree3 = p3.parse_string('n*n+n')
tree3.render('3',format="png")