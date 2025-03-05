int: countOfEdges;
int: countOfNodes;
array[1..countOfEdges,1..2] of int: edges;
array[1..countOfNodes] of var int: nodes;

%constraint forall(i in 1..roadCount) ( abs(nodes[roads[i,1]] - nodes[roads[i,2]]) >= 2000 );
constraint forall(i in 1..countOfEdges) ( abs(nodes[edges[i,1]] - nodes[edges[i,2]]) >= 2000 );
constraint forall(i in 1..countOfNodes) (nodes[i]>=100000);
constraint max(nodes) <= (3*min(nodes));

solve satisfy;

