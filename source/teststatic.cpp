/*
TestStatic
(c) 2016
original authors: David I. Schwartz
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*	This tutorial illustrates the utilization of keyword static of
	class members and member functions.
*	It covers the concepts such as const, constructor, destructor, 
	and member access operators.
*/

#include <iostream>  // for cout and endl
#include <string>    // for string
using namespace std; // for cout and endl
// for static: see https://msdn.microsoft.com/en-us/library/s1sb61xd(v=vs.110).aspx

#pragma region Person declarations
class Person {       // declare class Person
// declare private members:
private:
	string name;
	int label;
	static int count; // declare static int type member count (one copy of this member is shared by all instance)
// declare public members:
public:
	Person(string n);        // constructor
	~Person();               // destructor
	string getName() const;  // declare member function (not modifiable)
	int getLabel() const;    // declare member function (not modifiable)
	void print() const;      // declare member function (not modifiable)
	static int getCount();   // declare static member function
	static void reset();     // declare static member function
};
#pragma endregion

#pragma region Person definitions
// data:
int Person::count=0;         // initialize Person member count to 0

// construction:
Person::Person(string n) {   // define constructor whose parameter is string type
	name = n;                // put the value of parameter to private member name
	label = ++count;         // label get's the value of count and count+1 everytime it gets called
}

// destruction:
Person::~Person() {}         // define destructor

// accessors:
string Person::getName()  const { return name; }   // member function getName returns to name
int    Person::getLabel() const { return label; }  // member function getLabel returns to label
int    Person::getCount() { return count; }        // static member function getCount returns to count
void   Person::print()    const { cout << "Person: " << getName() << ", Label: " << getLabel() << endl; }  // member function print print out the name and label of the Person

// mutator:
void Person::reset() { count = 0; }  // define static member function reset: reset the private member count to 0

#pragma endregion

#pragma region Test Person
int main () {
	Person* p1 = new Person("Sam");  // create a pointer p1 points to a Person object, allocate memory in the heap
	Person* p2 = new Person("Pat");  // create a pointer p2 points to a Person object, allocate memory in the heap
	p1->print();                     // output: Person: Sam, Label: 1
	p2->print();                     // output: Person: Pat, Label: 2
	cout << "Count: " << Person::getCount() << endl;        // output: Count: 2
	Person::reset();                 // call the member function, reset the count
	cout << "Count reset: " << Person::getCount() << endl;  // output: Count reset: 0
	p1->reset(); // also works
	delete p1;   // deallocate memory
	delete p2;   // deallocate memory
	system("pause");
}
#pragma endregion