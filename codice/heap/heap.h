#ifndef HEAP_H
#define HEAP_H
#include<iostream>

template<typename T> class PriorityQueue{
	public:
		virtual T* extract() = 0;
		virtual PriorityQueue<T>* enqueue(T x) = 0;
		virtual double compare(T* a, T* b) = 0;
		virtual void printKey(int i) const = 0;
};

template <typename T> class BinaryHeap : public PriorityQueue<T>{
	private:
		T** queue;
		size_t heapsize;
		size_t queueLength;

		int getLeft(int i){
			return i << 1
		}

		int getRight(int i){
			return (i << 1)|1;
		}

		int getParent(int i){
			return i >> 1;
		}

		void swap(int i, int j){
			T* temp = queue[i];
			queue[i] = queue[j];
			queue[j] = temp;
		}

		void heapify(int index){
			int max = index;
			while(index <= heapsize/2){
				int right = getRight(index);
				int left = getLeft(index);
				if(left <= heapsize && compare(queue[left], queue[max]))
					max = left;
				if(right <= heapsize && compare(queue[right], queue[max]))
					max = right;
				if(max == index)
					break;
				swap(max, index);
				index = max;
			}
		}
};

#endif
