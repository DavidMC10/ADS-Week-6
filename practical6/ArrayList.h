/**
 * ArrayList.h
 *
 * Generic Dynamic ArrayList based on array
 * with advanced copy and equality operators

 * @author  Aiden McCaughey
 * @email   a.mccaughey@ulster.ac.uk
 * @version 1.20
 */

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "Array.h"
#include <exception>
#include <iostream>

template <class T>
class ArrayList {
public:
	explicit ArrayList(int size = 100);
	ArrayList(const ArrayList<T> &);
	void operator=(const ArrayList<T> &);

	bool operator==(const ArrayList<T> &) const;
	bool operator!=(const ArrayList<T> &) const;

	void clear();
	void add(const T &);
	void add(int, const T &);
	void remove(int);
	void set(int, const T &);
	T    get(int) const;
	int  find(T &) const;

	int  size() const;
	bool isEmpty() const;
	void print(std::ostream & os) const;

	// Immutable List processing functions
	ArrayList<T> reverse() const;
	ArrayList<T> take(int n) const;
	ArrayList<T> drop(int n) const;
	ArrayList<T> mid(int start, int count) const;
	T getNthLargest(int n) const;

private:
	Array<T> data;
	int count;
};

// --------------- ArrayList Implementation -----------------------

// Default Constructor
template <class T>
ArrayList<T>::ArrayList(int size) : data(size), count(0) {}

// PostCondition: construct ArrayList as a duplicate of c
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> & c) : data(c.data), count(c.count) {}

// PostCondition: assign c to ArrayList
template<class T>
void ArrayList<T>::operator=(const ArrayList<T> & c)
{
	data = c.data;
	count = c.count;
}


// PostCondition: returns true if ArrayLists are identical, false otherwise
template <class T>
bool ArrayList<T>::operator==(const ArrayList<T> & other) const
{
	bool same = true;
	if (size() != other.size()) {
		same = false;
	}
	for (int i = 0; same && i < size(); i++) {
		if (get(i) != other.get(i)) {
			same = false;
		}
	}
	return same;
}

// PostCondition: returns true if ArrayLists are not equal, false otherwise
template <class T>
bool ArrayList<T>::operator!=(const ArrayList<T> & other) const
{
	return !operator== (other);
}

// PostCondition: return length of ArrayList
template<class T>
int ArrayList<T>::size() const {
	return count;
}

// PreCondition: ArrayList is not full
// PostCondition: value added to end of ArrayList
template<class T>
void ArrayList<T>::add(const T & value) {
	add(size(), value);
}


// PreCondition: pos is a valid ArrayList position
// PostCondition: retrieves element at specified position in ArrayList
template<class T>
T ArrayList<T>::get(int pos) const {
	if (pos < 0 || pos >= count)
		throw std::out_of_range("ArrayList: invalid postion: " + std::to_string(pos));

	return data[pos];
}

// PreCondition: pos is a valid ArrayList position
// PostCondition: updates element at specified position in ArrayList
template<class T>
void ArrayList<T>::set(int pos, const T & value) {
	if (pos < 0 || pos >= count)
		throw std::out_of_range("ArrayList: invalid postion: " + std::to_string(pos));

	data[pos] = value;
}


// PostCondition: returns postion of e in ArrayList or -1 if not found
template<class T>
int ArrayList<T>::find(T & e) const {
	for (int i = 0; i < size(); i++) {
		if (get(i) == e)
			return i;
	}
	return -1;
}


// PostCondition: prints contents of ArrayList to standard output
template<class T>
void ArrayList<T>::print(std::ostream & os) const {
	os << "[ ";
	for (int i = 0; i < size(); i++) {
		os << get(i) << " ";
	}
	os << "]";
}

// PostCondition: ArrayList is emptied len == 0;
template<class T>
void ArrayList<T>::clear() {
	count = 0;				// reset length to zero
}

//PostCondition: returns length of ArrayList
template<class T>
bool ArrayList<T>::isEmpty() const {
	return (count == 0);
}

// PreCondition: None
// PostCondition: overload << operator to output ArrayList on ostream
template <class T>
std::ostream& operator <<(std::ostream& output, const ArrayList<T>& l) {
	l.print(output);
	return output;  // for multiple << operators.
}



// ----------------- COMPLETE THESE FUNCTIONS -----------------------------

// PreCondition: pos is a valid ArrayList position and ArrayList is not full
// PostCondition: inserts element value at specified position in ArrayList
template<class T>
void ArrayList<T>::add(int pos, const T & value) {


	// Checks to ensure that array is not out of bounds
	if (pos < 0 || pos > count)
		throw std::out_of_range("ArrayList: invalid postion: " + std::to_string(pos));

	// Checks to ensure list cannot overflow.
	// Checks to ensure the count is not greater or equal to the length.
	if (size() >= data.length())
		data.resize(size() * 2);

	// make room for new element
	for (int i = count; i > pos; i--)
	{
		data[i] = data[i-1];
	}

	// Assigns array with the value at position.
	data[pos] = value;
	
	// Increment count
	count++;

}

// PreCondition: pos is a valid ArrayList position
// PostCondition: remove element at specified position in  ArrayList
template<class T>
void ArrayList<T>::remove(int pos) {

	// Checks to ensure that array is not out of bounds
	if (pos < 0 || pos >= count)
		throw std::out_of_range("ArrayList: invalid postion: " + std::to_string(pos));

	// Shifts array elements to the left by 1.
	for (int i{ pos }; i < data.length() - 1; i++)
		data[i] = data[i + 1];

	// Last element gets assigned 0
	//data[data.length() - 1] = 0;

	// Decrement count
	count--;
}



// ----------------------- COMPLETE THESE IMMUTABLE LIST PROCESSING FUNCTIONS -----------------------

// PostCondition: return a new list as reverse of list
template<class T>
ArrayList<T> ArrayList<T>::reverse() const
{
	ArrayList<T> r(size());
	// complete function by filling r with elements in list in reverse order
	for (int i{ 0 }; i < size(); i++)
		r.add(data[size() - 1 - i]);
		
	return r;
}

// PreCondition: n >= 0 && n <= size()
// PostCondition: return a new list as first n elements of list
// throw std::out_of_range exception if n is invalid
template<class T>
ArrayList<T> ArrayList<T>::take(int n) const
{
	if (n < 0 || n > size())
		throw std::out_of_range("ArrayList: invalid number of elements to take: " + std::to_string(n));

	// create result array 
	ArrayList<T> t(n);

	// complete function by filling t with first n elements of list
	for (int i{ 0 }; i < n; i++)
		t.add(data[i]);

	return t;
}

// PreCondition: n >= 0 && n <= size()
// PostCondition: return new list with first n elements of list removed
// throw std::out_of_range exception if n is invalid
template<class T>
ArrayList<T> ArrayList<T>::drop(int n) const
{
	if (n < 0 || n > size())
		throw std::out_of_range("ArrayList: invalid number of elements to drop: " + std::to_string(n));

	// create result array 
	ArrayList<T> d(size() - n);
	
	//// complete function by filling d with list minus first n elements
	for (int i{ 0 }; i < size() - n; i++)
		d.add(data[n + i]);

	return d;
}


// PreCondition: start >= 0 && start < size() && count <= (size() - start)
template<class T>
ArrayList<T> ArrayList<T>::mid(int start, int count) const
{
	if (start < 0 || start >= size() || count > size() - start)
		throw std::out_of_range("ArrayList: mid(" + std::to_string(start) + "," + std::to_string(count) + ") invalid");

	// Returns a sublist
	return drop(start).take(count);
	
}


// PreCondition: n > 0 && n <= size() and array elements are unique
template<class T>
T ArrayList<T>::getNthLargest(int n) const
{
	//// replace return statement below with code to return the nth largest element in the list
	return T();
}


#endif /* ArrayList_H*/