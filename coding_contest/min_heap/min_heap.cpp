#include<iostream>
#include<fstream>

using namespace std;

template<typename T>
class Min_Heap{
private:
	T* vettore;
	int chiamate_heapify;
	int heapsize;
	int dimensione;

public:
	Min_Heap(int dim) : dimensione(dim){
		vettore = new T[dimensione];
		heapsize = 0;
		chiamate_heapify = 0;
	}

	~Min_Heap(){
		delete[] vettore;
	}

	int getChiamate(){
		return this->chiamate_heapify;
	}

	int Left(int index){
		return index << 1;
	}

	int Right(int index){
		return (index << 1)|1;
	}

	int Parent(int index){
		return index >> 1;
	}

	void Swap(T &a, T &b){
		T temp = a;
		a = b;
		b = temp;
	}

	void Heapify(int i){
		if(heapsize >= 1)
			chiamate_heapify++;
		int max = i;
		int left = Left(i);
		int right = Right(i);
		if(left <= heapsize && vettore[left] < vettore[max])
			max = left;
		if(right <= heapsize && vettore[right] < vettore[max])
			max = right;
		if(max != i){
			Swap(vettore[max], vettore[i]);
			Heapify(max);
		}
	}

	void Insert(T key){
		heapsize++;
		vettore[heapsize] = key;
		int i = heapsize;
		while(i > 1 && vettore[Parent(i)] > vettore[i]){
			Swap(vettore[Parent(i)], vettore[i]);
			i = Parent(i);
		}
	}

	void Extract(){
		Swap(vettore[1], vettore[heapsize]);
		heapsize--;
		Heapify(1);
		//return vettore[heapsize+1];
	}

	void Stampa(ofstream &out){
		for(int i=1; i<=heapsize; i++)
			out << vettore[i] << " ";
		out << endl;
	}
};

int main(){
	ifstream input("input.txt");
	ofstream output("output.txt");

	for(int i=0; i<100; i++){
		string tipo; input >> tipo;
		int N; input >> N;
		if(tipo=="char"){
			Min_Heap<char> heap(N);
			for(int i=0; i<N; i++){
				string operazione; input >> operazione;
				if(operazione == "extract")
					heap.Extract();
				else{
					char key = operazione[operazione.length()-1];
					heap.Insert(key);
				}
			}
			output << heap.getChiamate() << " ";
			heap.Stampa(output);
		}
		if(tipo == "bool"){
			Min_Heap<bool> heap(N);
			for(int i=0; i<N; i++){
				string operazione; input >> operazione;
				if(operazione == "extract")
					heap.Extract();
				else{
					bool key = stoi(operazione.substr(2, operazione.length()-1));
					heap.Insert(key);
				}
			}
			output << heap.getChiamate() << " ";
			heap.Stampa(output);
		}
		if(tipo == "int"){
			Min_Heap<int> heap(N);
			for(int i=0; i<N; i++){
				string operazione; input >> operazione;
				if(operazione == "extract")
					heap.Extract();
				else{
					int key = stoi(operazione.substr(2, operazione.length()-1));
					heap.Insert(key);
				}
			}
			output << heap.getChiamate() << " ";
			heap.Stampa(output);	
		}
		if(tipo == "double"){
			Min_Heap<double> heap(N);
			for(int i=0; i<N; i++){
				string operazione; input >> operazione;
				if(operazione == "extract")
					heap.Extract();
				else{
					double key = stod(operazione.substr(2, operazione.length()-1));
					heap.Insert(key);
				}
			}
			output << heap.getChiamate() << " ";
			heap.Stampa(output);
		
		}
	}
}