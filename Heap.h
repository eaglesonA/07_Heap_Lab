#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  int numItems;
  std::pair<Pri, T>* backingArray;

  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //method to swap items in backingArray
  void swap(unsigned long a, unsigned long b);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};

#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
  arrSize=START_SIZE;
  numItems=0;
  backingArray = new std::pair<Pri, T>[arrSize]; 
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
  delete[] backingArray; 
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
  std::pair<Pri, T>* tempArray = new std::pair<Pri, T>[arrSize*2];
  for(int i=0; i<arrSize; i++)
  { tempArray[i] = backingArray[i]; }
  delete[] backingArray;
  backingArray = tempArray;
  arrSize = arrSize*2;
}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
  if(numItems>=arrSize)
  { grow(); }
  backingArray[numItems] = toAdd;
  numItems++;
  if(numItems>=1)
  {bubbleUp(numItems-1);}
}

template<class Pri, class T>
void Heap<Pri,T>::swap(unsigned long a, unsigned long b){
  std::pair<Pri, T> temp = backingArray[b];
  backingArray[b] = backingArray[a];
  backingArray[a] = temp;
}


template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
	if(index==1)
	{	if(backingArray[0] > backingArray[1])
			{ swap(0,1); }
	}
	else
	{	while(index>0 && (backingArray[index] < backingArray[(index-1)/2]))
		 {
			 swap(index, (index-1)/2); 
			 bubbleUp(index-1);
		}
	}
}


template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
	
	if(numItems>=(2*index)+2)
	{
		unsigned long rightChild = (2*index)+2;
		if(backingArray[rightChild] < backingArray[index])
		{ 
			swap(rightChild, index);
			trickleDown(index+rightChild);
			trickleDown(0);
		}
	}
	if(numItems>=(2*index)+1)
	{ 
		unsigned long leftChild = (2*index)+1;
		if(backingArray[leftChild] < backingArray[index])
		{ 
			swap(leftChild, index);
			trickleDown(index+leftChild);
			trickleDown(0);
		}
	}

}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
	if(arrSize<=0)
	{ throw std::string("array is empty in remove");}
  std::pair<Pri,T> tmp= backingArray[0];
  numItems--;
  backingArray[0] = backingArray[numItems];
  trickleDown(0);
  return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
  return numItems;
}

