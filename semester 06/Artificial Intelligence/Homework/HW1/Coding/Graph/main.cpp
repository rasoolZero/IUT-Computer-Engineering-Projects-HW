#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

class Graph : public vector<vector<bool>>{
public:
	Graph(){
		this->resize(0);
	}


	friend istream & operator>>(istream & in,Graph & graph){
		in >> graph.verteces;
		in >> graph.edges;
		graph.resize(graph.verteces);
		for(int i=0;i<graph.verteces;i++)
			graph[i].resize(graph.verteces);

		for(int i=0;i<graph.edges;i++){
			char c;
			int vert1,vert2;
			in >> c >> vert1 >> vert2;
			graph[vert1-1][vert2-1] = true;
			graph[vert2-1][vert1-1] = true;
		}
		graph.colors.resize(graph.verteces,0);
		graph.calculateUpperbound();
		return in;
	}

	friend ostream & operator<<(ostream & out,Graph & graph){
//		for(size_type i=0;i<graph.size();i++){
//			for(size_type j=0;j<graph[i].size();j++){
//				out << graph[i][j] << ' ';
//			}
//			out << endl;
//		}
//		out << endl;
		out << graph.upperbound << endl;
		for(size_type i=0;i<graph.colors.size();i++)
			out << i+1 << " " << graph.colors[i] << endl;
		return out;
	}

	void calculateUpperbound(){
		int maxDegree = 0;
		for(size_type i=0;i<this->size();i++){
			int neighbours=0;
			for(size_type j=0;j<this->at(i).size();j++)
				if(this->at(i)[j])
					neighbours++;
			if(maxDegree<neighbours)
				maxDegree = neighbours;
		}
		upperbound = maxDegree+1;
	}
	int getUpperbound() const{
		return upperbound;
	}
	void setUpperbound(int upper){
		upperbound = upper;
	}
	void randomColor(){
		for(size_type i=0;i<colors.size();i++)
			colors[i] = rand()%upperbound+1;
	}

	int eval() const{
		int sum=0;
		for(size_type i=0;i<this->size();i++)
			for(size_type j=i+1;j<this->at(i).size();j++)
				if( this->at(i)[j] && colors[i] == colors[j])
					sum++;
		return sum;
	}

	void mutate(){
		if(eval()==0)
			return;

		vector<int> validColorsBase;
		for(int i=0;i<upperbound;i++)
			validColorsBase.push_back(i+1);

		for(size_type i=0;i<this->size();i++){
			vector<int> validColors = validColorsBase;
			bool shouldMutate=false;
			for(size_type j=0;j<this->at(i).size();j++){
				if(this->at(i)[j]){
					remove(validColors.begin(),validColors.end(),colors[j]);
					if(colors[i] == colors[j])
						shouldMutate=true;
				}
			}
			if(shouldMutate && validColors.size()!=0)
				colors[i] = validColors[rand()%validColors.size()];
			else if(shouldMutate && validColors.size()==0)
				colors[i] = rand()%upperbound+1;
		}
	}

	bool operator<(const Graph & other){
		return (this->eval() < other.eval());
	}
	bool operator>(const Graph & other){
		return (this->eval() > other.eval());
	}

	vector<int> colors;

private:
	int verteces;
	int edges;
	int upperbound=0;
};



typedef vector<Graph> Population;
#define POPULATION_SIZE 100
#define MATE_P 5
#define TOUR_N 2

Graph parentTournamentSelection(Population & currentPopulation){
	static const int n = TOUR_N;
	int minIndexSoFar=INT_MAX;
	int size = currentPopulation.size();
	for(int i=0;i<n;i++)
		minIndexSoFar = min(minIndexSoFar,rand()%size);
	return currentPopulation[minIndexSoFar];
}


Population breed(Population & currentPopulation){
	int size = currentPopulation.size();
	int chromeSize = currentPopulation[0].colors.size();
	Population babies = Population(size);
	for(int i=0;i<size;i++){

		int lowerBound = 0.10*chromeSize;
		int upperBound = 0.90*chromeSize;
		int pivot = rand()%(upperBound-lowerBound+1)+lowerBound;

		Graph parent1 = parentTournamentSelection(currentPopulation);
		Graph parent2 = parentTournamentSelection(currentPopulation);

		babies[i] = parent1;

		for(int j=pivot;j<chromeSize;j++)
			babies[i].colors[j] = (parent2.colors[j]);

	}
	return babies;
}

void mutate(Population & babies){
	for(size_t i=0;i<babies.size();i++){
		babies[i].mutate();
	}
}

int main(int argc, char * argv[])
{

	if (argc<2){
		cout << "use like this: Graph.exe input_filename" << endl;
		system("PAUSE");
		return 1;
	}
	ifstream ifile(argv[1]);

	if(!ifile.good()){
		cout << "could not open file" << endl;
		system("PAUSE");
		return 1;
	}


	Graph mainGraph,bestSoFar;
	ifile >> mainGraph;
	ifile.close();
	mainGraph.calculateUpperbound();
	int k = mainGraph.getUpperbound();

	int const populationSize = POPULATION_SIZE;
	int const matePivot = populationSize*MATE_P/100;

	Population currentPopulation(populationSize);
	for(int i=0;i<populationSize;i++)
		currentPopulation[i] = mainGraph;


	time_t startTime = time(0);
	srand(startTime);
	cout << "starting" << endl;
	while(true){
		bool getout = false;
		if(time(0) - startTime >= 60){
			getout=true;
			break;
		}
		for(int i=0;i<populationSize;i++){
			currentPopulation[i].setUpperbound(k);
			currentPopulation[i].randomColor();   //random chrome
		}
		if(time(0) - startTime >= 60){
			getout=true;
			break;
		}

		while(true){
			sort(currentPopulation.begin(),currentPopulation.end());
			if(currentPopulation[0].eval()==0){
				bestSoFar = currentPopulation[0];
				cout << "minimum color so far: " << k << endl;
				k--;
				break;
			}
			if(time(0) - startTime >= 60){
				getout=true;
				break;
			}
			Population babies = breed(currentPopulation);
			if(time(0) - startTime >= 60){
				getout=true;
				break;
			}
			mutate(babies);
			if(time(0) - startTime >= 60){
				getout=true;
				break;
			}
			sort(babies.begin(),babies.end());
			if(time(0) - startTime >= 60){
				getout=true;
				break;
			}
			int index=0;
			for(int i=matePivot;i<populationSize;i++)
				currentPopulation[i] = babies[index++];

		}

		if(getout)
			break;
	}
	cout << "timer out" << endl;
	cout << bestSoFar;
	ofstream ofile("graph output.txt");
	if(ofile.good()){
		ofile << bestSoFar;
		cout << "best coloring has been saved in 'graph output.txt'"<< endl;
		ofile.close();
	}
	else{
		cout << "could not open the output file" << endl;
	}
	system("PAUSE");
    return 0;
}
