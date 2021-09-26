#include "Comp0.hh"
#include "Comp1.hh"
#include <cstdlib>
#include <vector>
#include <cassert>

template <typename E, typename Comp> class heap {
private:
	std::vector <E> Heap;

	void swap(std::vector<E> &A, int i, int j) {
		E temp = A[i];
		A[i] = A[j];	
		A[j] = temp;
	}

	void siftdown(int pos) {
		while (!isLeaf(pos)) { // Stop if pos is a leaf
			int j = leftchild(pos); int rc = rightchild(pos);
			if ((rc < Heap.size()) && Comp::prior(Heap[rc], Heap[j])) 
			j = rc; // Set j to greater childs value
			if (Comp::prior(Heap[pos], Heap[j])) return; // Done
			swap(Heap, pos, j);
			pos = j; // Move down
		}
	}

public:
	heap() // Constructor
	{ buildHeap(); }
	int size() const // Return current heap size
	{
		return Heap.size();
	}
	bool isLeaf(int pos) const // True if pos is a leaf
	{ return (pos >= Heap.size()/2) && (pos < Heap.size()); }
	int leftchild(int pos) const
	{ return 2*pos + 1; } // Return leftchild position
	int rightchild(int pos) const
	{ return 2*pos + 2; } // Return rightchild position
	int parent(int pos) const // Return parent position
	{ return (pos-1)/2; }
	void buildHeap() // Heapify contents of Heap
	{ for (int i = Heap.size()/2-1; i >= 0; i--) siftdown(i); }

	void printHeap(){
		for(int i = 0; i < Heap.size(); i++){
			std::cout << Heap[i] << std::endl;
		}
	}

	void insert(const E& it) {
		int curr = Heap.size();
		Heap.push_back(it);
		while ((curr != 0) && (Comp::prior(Heap[curr], Heap[parent(curr)]))) {
			swap(Heap, curr, parent(curr));
			curr = parent(curr);
		}
	}

	E removefirst() {
		swap(Heap, 0, Heap.size() - 1); // Swap first with last value
		E temp = Heap[Heap.size() - 1];
		Heap.pop_back();
		if (Heap.size() != 0) siftdown(0); // Siftdown new root val
		return temp;
	}
};
