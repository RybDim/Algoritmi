#include<iostream>
#include<fstream>

using namespace std;

template<typename T> class Heap{
	private:
		T* vettore;
		int heapsize;
		int chiamate_heapify;

	public:
		Heap(){
			heapsize = 0;
		}

		int Parent(int index){
			return index >> 1;
		}

		int Left(int index){
			return index << 1;
		}

		int Right(int index){
			return (index << 1)|1;
		}

		void Heapify(int index){
			chiamate_heapify++;
			int max = index;
			int right = Right(index);
			int left = Left(index);
			if(left <= heapsize && vettore[left] < vettore[max])
				max = left;
			if(right <= heapsize && vettore[right] < vettore[max])
				max = right;
			if(max != index){
				swap(vettore[index], vettore[max]);
				Heapify(max);
			}
		}

		void build_heap(T* vett, int n){
			this->heapsize = n;
			this->vettore = vett;
			for(int i=heapsize/2; i > 0; i--)
				Heapify(i);
		}

		T estrai(){
			swap(vettore[1], vettore[heapsize]);
			heapsize--;
			Heapify(1);
			//cout << vettore[heapsize+1] << endl;
			return vettore[heapsize+1];
		}



		void print(ofstream& out){
			out << chiamate_heapify-1 << " ";
		}
};

template<typename T>
void stampa_array(T* array, int dimensione, ofstream& out){
	for(int i=1; i<=dimensione; i++){
		out << array[i] << " ";
	}
	out << endl;
}

int main(){
	ifstream input("input.txt");
	ofstream output("output.txt");

	for(int i=0; i<100; i++){
		string tipo; input >> tipo;
		int dimensione; input >> dimensione;
		if(tipo == "bool"){
			Heap<bool>* heap = new Heap<bool>();
			bool* vettore = new bool[200];
			for(int j=1; j<=dimensione; j++)
				input >> vettore[j];
			heap->build_heap(vettore, dimensione);
			bool* out = new bool[dimensione+1];
			for(int k=dimensione; k>0; k--){
				out[k] = heap->estrai();
			}
			heap->print(output);
			stampa_array(out, dimensione, output);
			delete[] out;
			delete heap;
			delete [] vettore;
		}
		if(tipo == "char"){
			Heap<char>* heap = new Heap<char>();
			char* vettore = new char[200];
			for(int j=1; j<=dimensione; j++)
				input >> vettore[j];
			heap->build_heap(vettore, dimensione);
			char* out = new char[dimensione+1];
			for(int k=dimensione; k>0; k--){
				out[k] = heap->estrai();
			}
			heap->print(output);
			stampa_array(out, dimensione, output);
			delete[] out;
			delete heap;
			delete [] vettore;
		}
		if(tipo == "int"){
			Heap<int>* heap = new Heap<int>();
			int* vettore = new int[200];
			for(int j=1; j<=dimensione; j++){
				input >> vettore[j];
			}
			heap->build_heap(vettore, dimensione);
			int* out = new int[dimensione+1];
			for(int k=dimensione; k>0; k--){
				out[k] = heap->estrai();
			}
			heap->print(output);
			stampa_array(out, dimensione, output);
			delete[] out;
			delete heap;
			delete [] vettore;
		}
		if(tipo == "double"){
			Heap<double>* heap = new Heap<double>();
			double* vettore = new double[200];
			for(int j=1; j<=dimensione; j++)
				input >> vettore[j];
			heap->build_heap(vettore, dimensione);
			double* out = new double[dimensione+1];
			for(int k=dimensione; k>0; k--){
				out[k] = heap->estrai();
			}
			heap->print(output);
			stampa_array(out, dimensione, output);
			delete[] out;
			delete heap;
			delete [] vettore;
		}
	}
}