#include <iostream>
#include <fstream>
#include <array>
#include <cmath>
#include <vector>
#include <random>

using namespace std;


class Face : public vector<int>{
public:
	Face(){
		magicNumber = 0;
		setupVector();
	}
	Face(int magic){
		magicNumber = magic;
		setupVector();
	}
	Face(int magic,const vector<int> & v){
		magicNumber = magic;
		for(size_type i=0;i<v.size();i++)
			this->push_back(v[i]);
	}
	Face(const Face & f){
		magicNumber = f.getMagic();
		for(size_type i=0;i<f.size();i++)
			this->push_back(f[i]);
	}

	int eval() const{
		int matches=0;
		for(size_type i=0;i<this->size();i++)
			if(this->at(i)==magicNumber)
				matches++;
		return matches;
	}
	void print(ostream & out) const{
		for(size_type i=0;i<this->size();i++){
			out << this->at(i) << ' ';
			if((i+1)%3==0)
				out << endl;
		}
	}
	friend ostream& operator<<(ostream & out, Face & face){
		face.print(out);
		return out;
	}



	void setMagic(int magic){
		magicNumber = magic;
	}
	int getMagic() const {
		return magicNumber;
	}
private:
	void setupVector(){
		for(int i=0;i<9;i++)
			this->push_back(0);
	}
	int magicNumber=0;
};




class Cube : public vector<Face>{
public:
	enum moves{U,D,L,R,F,B,u,d,l,r,f,b};
	Cube(){
		this->push_back(Face(1,{1,1,1,1,1,1,1,1,1}));
		this->push_back(Face(2,{2,2,2,2,2,2,2,2,2}));
		this->push_back(Face(3,{3,3,3,3,3,3,3,3,3}));
		this->push_back(Face(4,{4,4,4,4,4,4,4,4,4}));
		this->push_back(Face(5,{5,5,5,5,5,5,5,5,5}));
		this->push_back(Face(6,{6,6,6,6,6,6,6,6,6}));
	}

	Cube(const Cube & cube){
		this->clear();
		for(int i=0;i<6;i++)
			this->push_back(cube[i]);
		this->path = cube.getPath();
	}

	int eval(){
		int total=0;
		for(size_type i=0;i<this->size();i++)
			total+=this->at(i).eval();
		return total;
	}
	static int getMaxEval(){
		return 6*9;
	}
	static string moveToString(Cube::moves m,bool counterClockwise){
	static const char * movesStr [] = {"U","D","L","R","F","B","u","d","l","r","f","b"};
	string result = movesStr[static_cast<int>(m)];
	if(counterClockwise)
		result+="'";
	return result;
}

	bool operator < (Cube & another){
		return this->eval() < another.eval();
	}
	bool operator > (Cube & another){
		return this->eval() > another.eval();
	}
	bool operator <= (Cube & another){
		return this->eval() <= another.eval();
	}
	bool operator >= (Cube & another){
		return this->eval() >= another.eval();
	}

	friend istream & operator>>(istream & in , Cube & cube){
		vector<int> numbers(9);
		for(int i=0;i<6;i++){
			for(int j=0;j<9;j++)
				in >> numbers[j];
			cube[i] = Face(i+1,numbers);
		}
		return in;
	}

	friend ostream& operator<<(ostream & out, Cube & cube){
		for(size_type i=0;i<cube.size();i++)
			out << cube[i] << endl;
		out << endl << cube.getPath() << endl;
		return out;
	}

	void move(moves m,bool counterClockwise=false){
		if(m==U)
			moveUP(counterClockwise);
		if(m==D)
			moveDOWN(counterClockwise);
		if(m==L)
			moveLEFT(counterClockwise);
		if(m==R)
			moveRIGHT(counterClockwise);
		if(m==F)
			moveFRONT(counterClockwise);
		if(m==B)
			moveBACK(counterClockwise);

		if(m==u)
			moveUP(counterClockwise,true);
		if(m==d)
			moveDOWN(counterClockwise,true);
		if(m==l)
			moveLEFT(counterClockwise,true);
		if(m==r)
			moveRIGHT(counterClockwise,true);
		if(m==f)
			moveFRONT(counterClockwise,true);
		if(m==b)
			moveBACK(counterClockwise,true);

		path+=(moveToString(m,counterClockwise) + " ");
	}


	string getPath() const{
		return path;
	}
	void clearPath(){
		path = "";
	}

private:

	void moveRIGHT(bool counterClock = false , bool wide = false){
		vector<int> temp(9);
		for(int i=0;i<9;i++)
			temp[i]=this->at(4)[i];


		if(counterClock){
			if(wide){
				this->at(4)[7] = this->at(0)[1];
				this->at(4)[4] = this->at(0)[4];
				this->at(4)[1] = this->at(0)[7];

				this->at(0)[1] = this->at(2)[1];
				this->at(0)[4] = this->at(2)[4];
				this->at(0)[7] = this->at(2)[7];

				this->at(2)[1] = this->at(5)[1];
				this->at(2)[4] = this->at(5)[4];
				this->at(2)[7] = this->at(5)[7];

				this->at(5)[1] = temp[7];
				this->at(5)[4] = temp[4];
				this->at(5)[7] = temp[1];
			}
			this->at(4)[6] = this->at(0)[2];
			this->at(4)[3] = this->at(0)[5];
			this->at(4)[0] = this->at(0)[8];

			this->at(0)[2] = this->at(2)[2];
			this->at(0)[5] = this->at(2)[5];
			this->at(0)[8] = this->at(2)[8];

			this->at(2)[2] = this->at(5)[2];
			this->at(2)[5] = this->at(5)[5];
			this->at(2)[8] = this->at(5)[8];

			this->at(5)[2] = temp[6];
			this->at(5)[5] = temp[3];
			this->at(5)[8] = temp[0];
		}
		else{
			if(wide){
				this->at(4)[7] = this->at(5)[1];
				this->at(4)[4] = this->at(5)[4];
				this->at(4)[1] = this->at(5)[7];

				this->at(5)[1] = this->at(2)[1];
				this->at(5)[4] = this->at(2)[4];
				this->at(5)[7] = this->at(2)[7];

				this->at(2)[1] = this->at(0)[1];
				this->at(2)[4] = this->at(0)[4];
				this->at(2)[7] = this->at(0)[7];

				this->at(0)[1] = temp[7];
				this->at(0)[4] = temp[4];
				this->at(0)[7] = temp[1];
			}
			this->at(4)[6] = this->at(5)[2];
			this->at(4)[3] = this->at(5)[5];
			this->at(4)[0] = this->at(5)[8];

			this->at(5)[2] = this->at(2)[2];
			this->at(5)[5] = this->at(2)[5];
			this->at(5)[8] = this->at(2)[8];

			this->at(2)[2] = this->at(0)[2];
			this->at(2)[5] = this->at(0)[5];
			this->at(2)[8] = this->at(0)[8];

			this->at(0)[2] = temp[6];
			this->at(0)[5] = temp[3];
			this->at(0)[8] = temp[0];
		}

	}

	void moveLEFT(bool counterClock = false , bool wide = false){
		vector<int> temp(9);
		for(int i=0;i<9;i++)
			temp[i]=this->at(4)[i];

		if(!counterClock){
			if(wide){
				this->at(4)[7] = this->at(0)[1];
				this->at(4)[4] = this->at(0)[4];
				this->at(4)[1] = this->at(0)[7];

				this->at(0)[1] = this->at(2)[1];
				this->at(0)[4] = this->at(2)[4];
				this->at(0)[7] = this->at(2)[7];

				this->at(2)[1] = this->at(5)[1];
				this->at(2)[4] = this->at(5)[4];
				this->at(2)[7] = this->at(5)[7];

				this->at(5)[1] = temp[7];
				this->at(5)[4] = temp[4];
				this->at(5)[7] = temp[1];
			}
			this->at(4)[8] = this->at(0)[0];
			this->at(4)[5] = this->at(0)[3];
			this->at(4)[2] = this->at(0)[6];

			this->at(0)[0] = this->at(2)[0];
			this->at(0)[3] = this->at(2)[3];
			this->at(0)[6] = this->at(2)[6];

			this->at(2)[0] = this->at(5)[0];
			this->at(2)[3] = this->at(5)[3];
			this->at(2)[6] = this->at(5)[6];

			this->at(5)[0] = temp[8];
			this->at(5)[3] = temp[5];
			this->at(5)[6] = temp[2];
		}
		else{
			if(wide){
				this->at(4)[7] = this->at(5)[1];
				this->at(4)[4] = this->at(5)[4];
				this->at(4)[1] = this->at(5)[7];

				this->at(5)[1] = this->at(2)[1];
				this->at(5)[4] = this->at(2)[4];
				this->at(5)[7] = this->at(2)[7];

				this->at(2)[1] = this->at(0)[1];
				this->at(2)[4] = this->at(0)[4];
				this->at(2)[7] = this->at(0)[7];

				this->at(0)[1] = temp[7];
				this->at(0)[4] = temp[4];
				this->at(0)[7] = temp[1];
			}
			this->at(4)[8] = this->at(5)[0];
			this->at(4)[5] = this->at(5)[3];
			this->at(4)[2] = this->at(5)[6];

			this->at(5)[0] = this->at(2)[0];
			this->at(5)[3] = this->at(2)[3];
			this->at(5)[6] = this->at(2)[6];

			this->at(2)[0] = this->at(0)[0];
			this->at(2)[3] = this->at(0)[3];
			this->at(2)[6] = this->at(0)[6];

			this->at(0)[0] = temp[8];
			this->at(0)[3] = temp[5];
			this->at(0)[6] = temp[2];
		}

	}
	void moveUP(bool counterClock=false, bool wide=false){
		int numberOfCells = wide?6:3;
		vector<int> cells(numberOfCells);
		for(int i=0;i<numberOfCells;i++)
			cells[i]=i;

		if(counterClock)
			rotate({4,3,2,1},cells);
		else
			rotate({1,2,3,4},cells);
	}

	void moveDOWN(bool counterClock=false, bool wide=false){
		int numberOfCells = wide?6:3;
		int startingIndex=9-numberOfCells;
		vector<int> cells(numberOfCells);
		int index=0;
		for(int i=startingIndex;i<9;i++)
			cells[index++]=i;

		if(counterClock)
			rotate({4,3,2,1},cells);
		else
			rotate({1,2,3,4},cells);
	}
	void moveBACK(bool counterClock=false, bool wide = false){
		vector<int> temp(9);
		for(int i=0;i<9;i++)
			temp[i]=this->at(0)[i];

		if(counterClock){
			if(wide){
				this->at(0)[3] = this->at(3)[1];
				this->at(0)[4] = this->at(3)[4];
				this->at(0)[5] = this->at(3)[7];

				this->at(3)[1] = this->at(5)[5];
			    this->at(3)[4] = this->at(5)[4];
			    this->at(3)[7] = this->at(5)[3];

			    this->at(5)[5] = this->at(1)[7];
			    this->at(5)[4] = this->at(1)[4];
			    this->at(5)[3] = this->at(1)[1];

				this->at(1)[7] = temp[3];
				this->at(1)[4] = temp[4];
				this->at(1)[1] = temp[5];
			}
			this->at(0)[6] = this->at(3)[0];
			this->at(0)[7] = this->at(3)[3];
			this->at(0)[8] = this->at(3)[6];

			this->at(3)[0] = this->at(5)[2];
			this->at(3)[3] = this->at(5)[1];
			this->at(3)[6] = this->at(5)[0];

			this->at(5)[2] = this->at(1)[8];
			this->at(5)[1] = this->at(1)[5];
			this->at(5)[0] = this->at(1)[2];

			this->at(1)[8] = temp[6];
			this->at(1)[5] = temp[7];
			this->at(1)[2] = temp[8];
		}
		else{
			if(wide){
				this->at(0)[5] = this->at(1)[1];
				this->at(0)[4] = this->at(1)[4];
				this->at(0)[3] = this->at(1)[7];

				this->at(1)[1] = this->at(5)[3];
				this->at(1)[4] = this->at(5)[4];
				this->at(1)[7] = this->at(5)[5];

				this->at(5)[3] = this->at(3)[7];
				this->at(5)[4] = this->at(3)[4];
				this->at(5)[5] = this->at(3)[1];

				this->at(3)[1] = temp[3];
				this->at(3)[4] = temp[4];
				this->at(3)[7] = temp[5];
			}
			this->at(0)[8] = this->at(1)[2];
			this->at(0)[7] = this->at(1)[5];
			this->at(0)[6] = this->at(1)[8];

			this->at(1)[2] = this->at(5)[0];
			this->at(1)[5] = this->at(5)[1];
			this->at(1)[8] = this->at(5)[2];

			this->at(5)[0] = this->at(3)[6];
			this->at(5)[1] = this->at(3)[3];
			this->at(5)[2] = this->at(3)[0];

			this->at(3)[0] = temp[6];
			this->at(3)[3] = temp[7];
			this->at(3)[6] = temp[8];
		}
	}

	void moveFRONT(bool counterClock=false, bool wide=false){
		int numberOfCells = wide?6:3;
		vector<int> temp(numberOfCells);
		for(int i=0;i<numberOfCells;i++)
			temp[i]=this->at(0)[i];

		if(counterClock){
			if(wide){
				this->at(0)[3] = this->at(3)[1];
				this->at(0)[4] = this->at(3)[4];
				this->at(0)[5] = this->at(3)[7];

				this->at(3)[1] = this->at(5)[5];
			    this->at(3)[4] = this->at(5)[4];
			    this->at(3)[7] = this->at(5)[3];

			    this->at(5)[5] = this->at(1)[7];
			    this->at(5)[4] = this->at(1)[4];
			    this->at(5)[3] = this->at(1)[1];

				this->at(1)[7] = temp[3];
				this->at(1)[4] = temp[4];
				this->at(1)[1] = temp[5];
			}
			this->at(0)[0] = this->at(3)[2];
			this->at(0)[1] = this->at(3)[5];
			this->at(0)[2] = this->at(3)[8];

			this->at(3)[2] = this->at(5)[8];
			this->at(3)[5] = this->at(5)[7];
			this->at(3)[8] = this->at(5)[6];

			this->at(5)[8] = this->at(1)[6];
			this->at(5)[7] = this->at(1)[3];
			this->at(5)[6] = this->at(1)[0];

			this->at(1)[6] = temp[0];
			this->at(1)[3] = temp[1];
			this->at(1)[0] = temp[2];
		}
		else{
			if(wide){
				this->at(0)[5] = this->at(1)[1];
				this->at(0)[4] = this->at(1)[4];
				this->at(0)[3] = this->at(1)[7];

				this->at(1)[1] = this->at(5)[3];
				this->at(1)[4] = this->at(5)[4];
				this->at(1)[7] = this->at(5)[5];

				this->at(5)[3] = this->at(3)[7];
				this->at(5)[4] = this->at(3)[4];
				this->at(5)[5] = this->at(3)[1];

				this->at(3)[1] = temp[3];
				this->at(3)[4] = temp[4];
				this->at(3)[7] = temp[5];
			}
			this->at(0)[2] = this->at(1)[0];
			this->at(0)[1] = this->at(1)[3];
			this->at(0)[0] = this->at(1)[6];

			this->at(1)[0] = this->at(5)[6];
			this->at(1)[3] = this->at(5)[7];
			this->at(1)[6] = this->at(5)[8];

			this->at(5)[6] = this->at(3)[8];
			this->at(5)[7] = this->at(3)[5];
			this->at(5)[8] = this->at(3)[2];

			this->at(3)[2] = temp[0];
			this->at(3)[5] = temp[1];
			this->at(3)[8] = temp[2];
		}
	}


	void rotate(const array<int,4> faces ,const vector<int> cells){
		vector<int> temp(9);
		for(size_type i=0;i<cells.size();i++)
			temp[cells[i]] = this->at(faces[3])[cells[i]];
		for(int i=2;i>=0;i--)
			for(size_type j=0;j<cells.size();j++)
				this->at(faces[i+1])[cells[j]] = this->at(faces[i])[cells[j]];
		for(size_type i=0;i<cells.size();i++)
			this->at(faces[0])[cells[i]] = temp[cells[i]];

	}

	string path="";
};

typedef Cube::moves moves;
typedef pair<moves,bool> Gene;
typedef vector<Gene> Chrome;
typedef vector<Chrome> Population;
#define TOUR_N 10
#define MUTATE_P 4 // in percent
#define POPULATION_SIZE 150
#define ELITE_PERCENT 5  // in percent
#define CHROME_SIZE 60

Gene createRandomGene(){
	Gene result = Gene(static_cast<moves>(rand()%12),rand()%2);
	return result;
}
Chrome createRandomChrome(int size){
	Chrome result;
	for(int i=0;i<size;i++)
		result.push_back(createRandomGene());
	return result;
}
Population createRandomPopulation(int populationSize,int chromeSize){
	Population result;
	for(int i=0;i<populationSize;i++)
		result.push_back(createRandomChrome(chromeSize));
	return result;
}

void sortPopulation(vector<Cube> & results,Population & population){
	int size = results.size();
	for(int i=0;i<size-1;i++)
		for(int j=0;j<size-i-1;j++)
			if(results[j]<results[j+1]){
				swap(results[j],results[j+1]);
				swap(population[j],population[j+1]);
			}
}

Chrome parentTournamentSelection(Population & currentPopulation){
	static const int n = TOUR_N;
	int minIndexSoFar=INT_MAX;
	int size = currentPopulation.size();
	for(int i=0;i<n;i++)
		minIndexSoFar = min(minIndexSoFar,rand()%size);
	return currentPopulation[minIndexSoFar];
}


Population breed(Population & currentPopulation){
	int size = currentPopulation.size();
	int chromeSize = currentPopulation[0].size();
	Population babies = Population(size);
	for(int i=0;i<size;i++){
		babies[i] = Chrome(chromeSize);

		int lowerBound = 0.25*chromeSize;
		int pivot = rand()%(static_cast<int>(0.5*chromeSize))+lowerBound;
//		cout << "pivot : " << pivot << endl;
		Chrome parent1 = parentTournamentSelection(currentPopulation);
		Chrome parent2 = parentTournamentSelection(currentPopulation);

		for(int j=0;j<chromeSize;j++){
			if(j<pivot)
				babies[i][j] = parent1[j];

			else
				babies[i][j] = parent2[j];

		}
	}
	return babies;
}

void mutate(Population & children){
	static const int probabilty = MUTATE_P; //2%
	int size = children.size();
	int chromeSize = children[0].size();
	for(int i=0;i<size;i++){
//		cout << "new chrome" << endl;
		for(int j=0;j<chromeSize;j++)
			if(rand()%100 < probabilty){
//				cout << "changing Gene" << endl;
				children[i][j] = createRandomGene();
			}
	}
}

int main(int argc, char * argv[])
{
	if (argc<2){
		cout << "use like this: Rubik.exe input_filename" << endl;
		system("PAUSE");
		return 1;
	}
	ifstream ifile(argv[1]);

	if(!ifile.good()){
		cout << "could not open file" << endl;
		system("PAUSE");
		return 1;
	}

	Cube mainCube,bestCube;
	ifile >> mainCube;
	ifile.close();
	bestCube = mainCube;

	int const populationSize = POPULATION_SIZE;
	int const matePivot = populationSize*ELITE_PERCENT/100;
	int const chromeSize = CHROME_SIZE;

	int counter=0;
	srand(time(0));

	Population currentPopulation = createRandomPopulation(populationSize,chromeSize);
	vector<Cube> results(populationSize);
	while(bestCube.eval()!=Cube::getMaxEval()){
		counter++;
		//calculating fitness of the current population
		for(int i=0;i<populationSize;i++){
			results[i]=mainCube;
			for(int j=0;j<chromeSize;j++){
				results[i].move(currentPopulation[i][j].first,currentPopulation[i][j].second);
				if(results[i].eval() > bestCube.eval())
					bestCube = results[i];

			}
		}

		sortPopulation(results,currentPopulation);
//		if(counter%100==0)
//			cout << results[0];
//		for(int i=0;i<1;i++){
//			cout << results[i] << endl;
//			cout << i << " : " << results[i].eval() << endl;
//			cout << endl << endl;
//		}
		Population children = breed(currentPopulation);
		mutate(children);
		//calculating fitness of the children
		for(int i=0;i<populationSize;i++){
			results[i]=mainCube;
			for(int j=0;j<chromeSize;j++)
				results[i].move(children[i][j].first,children[i][j].second);

		}
		sortPopulation(results,children);
		int index=0;
		for(int i=matePivot;i<populationSize;i++)
			currentPopulation[i] = children[index++];

	}

	cout << bestCube;
	ofstream ofile("rubik output.txt");
	if(ofile.good()){
		ofile << bestCube;
		cout << "solution has been saved in 'rubik output.txt'"<< endl;
		ofile.close();
	}
	else{
		cout << "could not open the output file" << endl;
	}
	system("PAUSE");

    return 0;
}
