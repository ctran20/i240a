#include <iostream>

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "command.hh"
#include "job.hh"

class QueueZeroHeap {
public:
	QueueZeroHeap() : nElements(0)
	{
		buildHeap();
	}

	void enqueue(Job job) {
		nElements++;
		heap.insert(heap.end(), job); //add value at end
		for (int pos = nElements - 1; //pos of added value
			(pos != 0 && heap[pos].priority0 > heap[parent(pos)].priority0)
			|| ((heap[pos].priority0 == heap[parent(pos)].priority0)
			&& heap[pos].id.at(2) > heap[parent(pos)].id.at(2));
			pos = parent(pos)) {
			swap(pos, parent(pos));
		}
	}

	Job dequeue() {
		assert(nElements > 0 && "heap is empty");
		Job value = heap[0];
		heap[0] = heap[nElements - 1]; //put last element at root
		heap.erase(heap.end());
		--nElements; //delete it
		if (nElements > 0) siftDown(0);  //move it to correct position

		return value;
	}

	int size() { return nElements; }

private:
	std::vector<Job> heap;
	int nElements; //# of currently allocated element in heap

	/** Heapify heap [0, nElements). */
	void buildHeap() {
		//move internal nodes down if necessary
		for (int i = nElements / 2 - 1; i >= 0; --i) {
			siftDown(i);
		}
	}

	/** Move element at pos down in the tree until it is greater
	 *  than either of its two children.
	 *  When it is necessary to move down, prefer to move down
	 *  into subtree with the greater root.
	 */
	void siftDown(int pos) {
		assert(0 <= pos && pos < nElements);
		while (!isLeaf(pos)) {
			int leftKidPos = leftChild(pos);
			//there must be a left kid since pos is not a leaf
			assert(0 <= leftKidPos && leftKidPos < nElements);
			int rightKidPos = rightChild(pos);
			int maxKidPos =
				((rightKidPos >= 0 && heap[rightKidPos].priority0 > heap[leftKidPos].priority0)
				|| ((heap[pos].priority0 == heap[parent(pos)].priority0)
				&& heap[pos].id.at(2) > heap[parent(pos)].id.at(2))
				)
				? rightKidPos
				: leftKidPos;
			if (heap[pos].priority0 > heap[maxKidPos].priority0
				|| ((heap[pos].priority0 == heap[parent(pos)].priority0)
				&& heap[pos].id.at(2) > heap[parent(pos)].id.at(2))
				) return;
			swap(pos, maxKidPos);
			pos = maxKidPos;
		}
	}

	void swap(int pos1, int pos2) {
		assert(0 <= pos1 && pos1 < nElements);
		assert(0 <= pos2 && pos2 < nElements);
		Job tmp = heap[pos1];
		heap[pos1] = heap[pos2];
		heap[pos2] = tmp;
	}

	//tree accessors
	bool isLeaf(int pos) const {
		return (pos >= nElements / 2) && (pos < nElements);
	}

	int leftChild(int pos) {
		return (2 * pos + 1 < nElements) ? 2 * pos + 1 : -1;
	}

	int rightChild(int pos) {
		return (2 * pos + 2 < nElements) ? 2 * pos + 2 : -1;
	}

	int parent(int pos) {
		return (pos > 0) ? (pos - 1) / 2 : -1;
	}

	friend std::ostream& operator<<(std::ostream& out, const QueueZeroHeap& heap);
};

class QueueOneHeap {
public:
	QueueOneHeap() : nElements(0)
	{
		buildHeap();
	}

	void enqueue(Job job) {
		nElements++;
		heap.insert(heap.end(), job); //add value at end
		for (int pos = nElements - 1; //pos of added value
			(pos != 0 && heap[pos].priority1 < heap[parent(pos)].priority1)
			|| ((heap[pos].priority1 == heap[parent(pos)].priority1)
				&& heap[pos].id.at(2) < heap[parent(pos)].id.at(2));
			pos = parent(pos)) {
			swap(pos, parent(pos));
		}
	}

	Job dequeue() {
		assert(nElements > 0 && "heap is empty");
		Job value = heap[0];
		heap[0] = heap[nElements - 1]; //put last element at root
		heap.erase(heap.end());
		--nElements; //delete it
		if (nElements > 0) siftDown(0);  //move it to correct position

		return value;
	}

	int size() { return nElements; }

private:
	std::vector<Job> heap;
	int nElements; //# of currently allocated element in heap

	/** Heapify heap [0, nElements). */
	void buildHeap() {
		//move internal nodes down if necessary
		for (int i = nElements / 2 - 1; i >= 0; --i) {
			siftDown(i);
		}
	}

	/** Move element at pos down in the tree until it is greater
	 *  than either of its two children.
	 *  When it is necessary to move down, prefer to move down
	 *  into subtree with the greater root.
	 */
	void siftDown(int pos) {
		assert(0 <= pos && pos < nElements);
		while (!isLeaf(pos)) {
			int leftKidPos = leftChild(pos);
			//there must be a left kid since pos is not a leaf
			assert(0 <= leftKidPos && leftKidPos < nElements);
			int rightKidPos = rightChild(pos);
			int maxKidPos =
				((rightKidPos >= 0 && heap[rightKidPos].priority1 < heap[leftKidPos].priority1)
					|| ((heap[pos].priority1 == heap[parent(pos)].priority1)
						&& heap[pos].id.at(2) < heap[parent(pos)].id.at(2))
					)
				? rightKidPos
				: leftKidPos;
			if (heap[pos].priority0 < heap[maxKidPos].priority0
				|| ((heap[pos].priority1 == heap[parent(pos)].priority1)
					&& heap[pos].id.at(2) < heap[parent(pos)].id.at(2))
				) return;
			swap(pos, maxKidPos);
			pos = maxKidPos;
		}
	}

	void swap(int pos1, int pos2) {
		assert(0 <= pos1 && pos1 < nElements);
		assert(0 <= pos2 && pos2 < nElements);
		Job tmp = heap[pos1];
		heap[pos1] = heap[pos2];
		heap[pos2] = tmp;
	}

	//tree accessors
	bool isLeaf(int pos) const {
		return (pos >= nElements / 2) && (pos < nElements);
	}

	int leftChild(int pos) {
		return (2 * pos + 1 < nElements) ? 2 * pos + 1 : -1;
	}

	int rightChild(int pos) {
		return (2 * pos + 2 < nElements) ? 2 * pos + 2 : -1;
	}

	int parent(int pos) {
		return (pos > 0) ? (pos - 1) / 2 : -1;
	}

	friend std::ostream& operator<<(std::ostream& out, const QueueOneHeap& heap);
};