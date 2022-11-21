#include<iostream>
#include<fstream>

using namespace std;


void stampaArray(int* array, int size, ofstream& out){
	for(int i=0; i<size; i++){
		out << array[i] << " ";
	}
}


void countingSort(int* array, int size, ofstream& out){
	int max = array[0];
	int min = array[0];
	for (int i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
		else if (min > array[i])
			min = array[i];
	}
	int range = max - min + 1;
	int* temp = new int[size];
	int* frequencyArray = new int[range];
	for (int i = 0; i < range; i++)
		frequencyArray[i] = 0;
	for (int i = 0; i < size; i++)
		frequencyArray[array[i] - min]++;
	for (int i = 1; i < range; i++)
		frequencyArray[i] += frequencyArray[i - 1];
	out << 0 << " ";
	for(int i=0; i<range-1; i++){
		out << frequencyArray[i] << " ";
	}
	for (int i = size - 1; i >= 0; i--) //stable version
	{
		temp[frequencyArray[array[i] - min] - 1] = array[i];
		frequencyArray[array[i] - min]--;
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
		int size; input >> size;
		int* array = new int[size];
		for(int j=0; j<size; j++){
			input >> array[j];
		countingSort(array, size, output);
		stampaArray(array, size, output);
		output << endl;

	}
}