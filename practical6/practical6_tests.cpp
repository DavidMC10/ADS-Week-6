/*
* Library Test Cases Using the Catch 2 Test Library
* https://github.com/catchorg/Catch2/
*
* practical6_tests.cpp
*
* Updated on: 7th March 2018
* Author: David McElhinney
* Version 1.00
*/

// important to add this definition and then include the library
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Library Header files 
#include "Array.h"
#include "ArrayList.h"
#include "OrderedList.h"


// Question 2
// PreCondition: n > 0 && n <= size() and array elements are unique
template<class T>
T getNthLargest(int n, const ArrayList<T> & list)
{
	// Can't fully complete 2 due to bug
	if (n < 0 || n >= list.size())
		throw std::out_of_range("ArrayList: invalid element in list: " + std::to_string(n));

	// Create temporary list with list that was passed in.
	OrderedList<T> temp(list);

	return	temp.get(temp.size()-n);
}


// You can add some additional tests to the partially completed test sections below.

/**
 *  ArrayList Processing Test Axioms
 */
TEST_CASE("ArrayList Processing Axioms", "[ArrayListFunc]")
{
	ArrayList<int> l;

	SECTION("Test getNthLargest")
	{
		// Create simple ArrayList and add elements
		ArrayList<int> a;
		a.add(18); a.add(8); a.add(2); a.add(5); a.add(6); a.add(3); a.add(4);

		// second largest is 8
		REQUIRE(getNthLargest(2, a) == 8);
	}

	SECTION("Test Reverse")
	{
		// create a suitable test - replace true with the test expression

		// Create simple ArrayList and add elements
		ArrayList<int> a, b;
		a.add(1);
		a.add(3);
		a.add(2);

		// Reverse array and assign to b
		b = a.reverse();


		// Third element should be 1
		REQUIRE(b.get(2) == 1);
	}

	SECTION("Test Take")
	{
		// Create simple ArrayList and add elements
		ArrayList<int> a;
		a.add(1);
		a.add(3);
		a.add(2);
		a.add(5);
		a.add(6);
		a.add(7);
		a.add(4);


		// Take 6 elements and assign to b
		ArrayList<int> b = a.take(6);

		// Size should be 6
		REQUIRE(b.size() == 6);
	}

	SECTION("Test Drop")
	{

		// Create simple ArrayList and add elements
		ArrayList<int> a;
		a.add(1);
		a.add(3);
		a.add(2);
		a.add(5);
		a.add(6);
		a.add(7);
		a.add(4);
		a.add(23);
		a.add(18);


		// Drop 6 elements and assign to b
		ArrayList<int> b = a.drop(6);

		// Size should be 3
		REQUIRE(b.size() == 3);
	}

	SECTION("Test mid")
	{
		// Create simple ArrayList and add elements
		ArrayList<int> a;
		a.add(1);
		a.add(3);
		a.add(2);
		a.add(5);
		a.add(6);
		a.add(7);
		a.add(4);

		// Drop first 2 elements and then take the next 3 to place in b
		ArrayList<int> b = a.mid(2, 3);

		// Size should be 3
		REQUIRE(b.size() == 3);
	}
}

//  ------------------- DO NOT MODIFY BELOW THIS LINE ---------------------

/**
 *  ArrayList Class Test Axioms
 */
TEST_CASE("ArrayList Axioms", "[ArrayList]")
{
	ArrayList<int> l;

	SECTION("SizeTest")
	{
		REQUIRE(l.size() == 0);
	}

	SECTION("Test Copy Constructor")
	{
		ArrayList<int> a;
		a.add(1);
		a.add(3);
		a.add(2);

		ArrayList<int> c(a);

		REQUIRE(a == c);
	}

	SECTION("Test Assignment Operator")
	{
		ArrayList<int> a;
		a.add(1);
		a.add(3);
		a.add(2);

		ArrayList<int> c;
		c = a;

		REQUIRE(a == c);
	}

	SECTION("Empty Test")
	{
		REQUIRE(l.isEmpty() == true);
	}

	SECTION("AddThenSizeIsOne")
	{
		l.add(0, 1);
		REQUIRE(l.size() == 1);
	}

	SECTION("AddThenNotEmpty")
	{
		l.add(0, 1);
		REQUIRE(l.isEmpty() == false);
	}

	SECTION("Add Then Get")
	{
		l.add(1);
		l.add(2);
		REQUIRE(l.get(1) == 2);
	}

	SECTION("Add Remove Then Size")
	{
		l.add(0, 1);
		l.remove(0);

		REQUIRE(l.size() == 0);
	}

	SECTION("Test Equal")
	{
		ArrayList<int> r;
		r.add(0, 1);
		l.add(0, 1);

		REQUIRE(l == r);
	}

	SECTION("Test Not Equal")
	{
		ArrayList<int> r;
		r.add(0, 1);
		l.add(0, 2);

		REQUIRE(l != r);
	}

	SECTION("Test Clear then equal")
	{
		l.add(1);
		l.clear();
		REQUIRE(l == ArrayList<int>());
	}

	SECTION("Test Invalid Remove")
	{
		REQUIRE_THROWS(l.remove(0));
	}

	SECTION("Test Set Out of Range")
	{
		REQUIRE_THROWS(l.set(0, 1));
	}

}


