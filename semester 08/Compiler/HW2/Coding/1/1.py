import json


def LCP(strs : list):
    
    shortest_str = min(strs, key=len)

    for i, char in enumerate(shortest_str):
        for other_str in strs:
            if other_str[i] != char:
                return shortest_str[:i]
    
    return shortest_str





class Grammar:
    def __init__(self,filename:str):
        self.grammar__ = dict()
        with open(filename,'r') as file:
            self.grammar__ = eval(file.read())
        

    def transform(self):
        self.eliminate_left_recursion__()
        self.left_factor__()
    
    def eliminate_left_recursion__(self):
        variables = list(self.grammar__.keys())
        for i in range(len(variables)):
            self.eliminate_indirect_left_recursion__(i,variables)
            self.eliminate_direct_left_recursion__(variables[i])
            
    def eliminate_indirect_left_recursion__(self, i:int ,variables: list ):
        variable_i = variables[i]
        for j in range(i):
            variable_j = variables[j]
            new_production_set = set()
            for production in self.grammar__[variable_i]:
                if production and variable_j[0] == production[0]:
                    for production_to_replace in self.grammar__[variable_j]:
                        new_production = production.replace(variable_j,production_to_replace,1)
                        new_production_set.add(new_production)
                else:
                    new_production_set.add(production)
            self.grammar__[variable_i] = list(new_production_set)

    def eliminate_direct_left_recursion__(self,variable_i:str):
        alternative_rule_set = set()
        main_rule_set = set()
        for rule in self.grammar__[variable_i]:
            if rule and variable_i[0] == rule[0]:
                alternative_rule_set.add(rule.replace(variable_i,'',1)+variable_i+'`')
            else:
                main_rule_set.add(rule+variable_i+'`')
        # a direct recursion was found
        if len(alternative_rule_set) > 0:
            alternative_rule_set.add('')
            self.grammar__[variable_i] = list(main_rule_set)
            self.grammar__[variable_i+'`'] = list(alternative_rule_set)

    def left_factor__(self):
        variables = list(self.grammar__.keys())
        i = 0
        while(i < len(variables)):
            variable = variables[i]
            i+=1
            rules = self.grammar__[variable]
            rules.sort()
            new_rule_set = set()
            j = 0
            while (j < len(rules)):
                jump_to = -1
                for k in range(len(rules),j+1,-1):
                    partition_of_rules = rules[j:k]
                    prefix = LCP(partition_of_rules)
                    if prefix:
                        jump_to = k
                        alternative = variable
                        while alternative in variables:
                            alternative+='`'
                        new_rule_set.add(prefix+alternative)
                        alternative_productions = [rule.replace(prefix,'',1) for rule in partition_of_rules]
                        self.grammar__[alternative] = list(set(alternative_productions))
                        variables = list(self.grammar__.keys())
                        break
                if jump_to != -1:
                    j = jump_to
                else:
                    new_rule_set.add(rules[j])
                    j+=1
            self.grammar__[variable] = list(new_rule_set)



    def __str__(self) -> str:
        return json.dumps(self.grammar__,indent = 4)

g = Grammar('input3.txt')
g.transform()
print(g)