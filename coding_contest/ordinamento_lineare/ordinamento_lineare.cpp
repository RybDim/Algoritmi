#include<iostream>
#include<fstream>

using namespace std;

template<typename T>
void stampaArray(T* array, int size, ofstream& out){
	for(int i=0; i<size; i++){
		out << array[i] << " ";
	}
}

template<typename T>
void countingSort(T* array, int size, ofstream& out){
	T max = array[0];
	T min = array[0];
	for (int i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
		else if (min > array[i])
			min = array[i];
	}
	int range = max - min + 1;
	T* temp = new T[size];
	int* frequencyArray = new int[range];
	for (int i = 0; i < range; i++)
		frequencyArray[i] = 0;
	for (int i = 0; i < size; i++)
		frequencyArray[((int)array[i]) - ((int)min)]++;
	for (int i = 1; i < range; i++)
		frequencyArray[i] += frequencyArray[i - 1];
	out << 0 << " ";
	for(int i=0; i<range-1; i++){
		out << frequencyArray[i] << " ";
	}
	for (int i = size - 1; i >= 0; i--) //stable version
	{
		temp[frequencyArray[((int)array[i]) - (int)min] - 1] = array[i];
		frequencyArray[((int)array[i]) - (int)min]--;
	}
	for (int i = 0; i < size; i++)
		array[i] = temp[i];

	delete[] frequencyArray;
	delete[] temp;
}
int main(){
	ifstream input("input.txt");
	ofstream output("output.txt");


	for(int i=0; i<100; i++){
		string tipo; input >> tipo;
		int size; input >> size;
		if(tipo == "int"){
			int* array = new int[size];
			for(int j=0; j<size; j++){
				input >> array[j];
			}
			countingSort(array, size, output);
			stampaArray(array, size, output);
			output << endl;
		}
		if(tipo == "bool"){
			bool* array = new bool[size];
			for(int j=0; j<size; j++){
				input >> array[j];
			}
			countingSort(array, size, output);
			stampaArray(array, size, output);
			output << endl;
		}
		if(tipo == "char"){
			char* array = new char[size];
			for(int j=0; j<size; j++){
				input >> array[j];
			}
			countingSort(array, size, output);
			stampaArray(array, size, output);
			output << endl;
		}
		if(tipo == "double"){
			double* array = new double[size];
			for(int j=0; j<size; j++){
				input >> array[j];
			}
			countingSort(array, size, output);
			stampaArray(array, size, output);
			output << endl;
		}

	}
}