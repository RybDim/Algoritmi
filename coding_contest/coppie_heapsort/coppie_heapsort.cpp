#include<iostream>
#include<fstream>

using namespace std;

template<typename T>
class Coppia{
private:
	T a;
	T b;
public:
	Coppia(){}
	Coppia(T val1, T val2){
		a = val1;
		b = val2;
	}
	bool operator>(Coppia& coppia){
		if(this->a > coppia.a)
			return 1;
		else if(this->a == coppia.a && this->b > coppia.b)
			return 1;
		else return 0;
	}

	friend ofstream& operator<<(ofstream& out, Coppia<T>& coppia){
		out << "(" << coppia.a << " " << coppia.b << ")";
		return out;
	}
};

template<typename T> class Heap{
	private:
		Coppia<T>* vettore;
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
			if(left <= heapsize && vettore[left] > vettore[max])
				max = left;
			if(right <= heapsize && vettore[right] > vettore[max])
				max = right;
			if(max != index){
				swap(vettore[index], vettore[max]);
				Heapify(max);
			}
		}

		void build_heap(Coppia<T>* vett, int n){
			this->heapsize = n;
			this->vettore = vett;
			for(int i=heapsize/2; i > 0; i--)
				Heapify(i);
		}

		Coppia<T> estrai(){
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
void stampa_array(Coppia<T>* array, int dimensione, ofstream& out){
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
			Coppia<bool>* vettore = new Coppia<bool>[200];
			for(int j=1; j<=dimensione; j++){
				char par; input >> par;
				bool val1; input >> val1;
				bool val2; input >> val2;
				input >> par;
				vettore[j] = Coppia(val1, val2);
			}
			heap->build_heap(vettore, dimensione);
			Coppia<bool>* out = new Coppia<bool>[dimensione+1];
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
			Coppia<char>* vettore = new Coppia<char>[200];
			for(int j=1; j<=dimensione; j++){
				char par; input >> par;
				char val1; input >> val1;
				char val2; input >> val2;
				input >> par;
				vettore[j] = Coppia(val1, val2);
			}
			heap->build_heap(vettore, dimensione);
			Coppia<char>* out = new Coppia<char>[dimensione+1];
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
			Coppia<int>* vettore = new Coppia<int>[200];
			for(int j=1; j<=dimensione; j++){
				char par; input >> par;
				int val1; input >> val1;
				int val2; input >> val2;
				input >> par;
				vettore[j] = Coppia(val1, val2);
			}
			heap->build_heap(vettore, dimensione);
			Coppia<int>* out = new Coppia<int>[dimensione+1];
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
			Coppia<double>* vettore = new Coppia<double>[200];
			for(int j=1; j<=dimensione; j++){
				char par; input >> par;
				double val1; input >> val1;
				double val2; input >> val2;
				input >> par;
				vettore[j] = Coppia(val1, val2);				
			}
			heap->build_heap(vettore, dimensione);
			Coppia<double>* out = new Coppia<double>[dimensione+1];
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