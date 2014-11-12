07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Add puts its info in the first available space (numItems), That, on its own, is constant. But then it calls bubbleUp, which moves the data into the correct place. It takes an index, checks if it needs to be moved, if so it divides the index by two and goes from there (making it lg n). 
Remove is the same, except it calls trickleDown (which moves the node with least priority down to the bottom of the tree).

2. I delete backing Array in the destructor, and delete local variables in methods (anything with "new").

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1:

Add 7)
7 would be added to the left side of 16.
16 and 7 would swap.

Add 3)
3 would be added to the right side of 7
7 and 3 would swap
3 and 6 would swap.
3 and 4 would swap.
3 is now the root.

10.2:

Remove 6)
Swap 6 with 55 (6 is the root, and 55 is the last node)
Six is removed from the array.
55 is the root.
55 and 8 swap
55 and 16 swap

Remove 8)
8 and 93 swap (8 is the root and 93 is the last node)
8 is removed from the array
93 and 16 swap
50 and 93 swap

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
parent = (i-1)/2
left child = 2i+1
right child = 2i+2

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
Is it possible to call bubbleUp and trickleDown recursively? 