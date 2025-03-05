int : countOfNodes;
int : countOfEdges;


array[1..countOfEdges, 1..2] of int: edges;
array[1..countOfNodes] of var 1..4: nodes;

constraint forall(i in 1..countOfEdges) (nodes[edges[i,1]] != nodes[edges[i,2]]);

constraint count(nodes,1) >= count(nodes,2);
constraint count(nodes,2) >= count(nodes,3);
constraint count(nodes,3) >= count(nodes,4);
constraint count(nodes,1) <= 2*count(nodes,4);
