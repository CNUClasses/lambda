//============================================================================
// Name        : lambda.cpp
// Author      : 
// Version     :
// Copyright   : Steal this code!
// Description : Hello World in C++, Ansi-style
//============================================================================
// C++ program to demonstrate lambda expression in C++
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Function to print vector
void printVector(vector<int> v) {
	// lambda expression to print vector
	for_each(v.begin(), v.end(), [](int i) {std::cout << i << " ";});
	cout << endl;
}

//functor (has operator ()
struct comp_f {
	comp_f() {
		;
	}
	bool operator()(int i, int j) {
		return (j > i);
	}
};

//for cort
bool compare(int i, int j) {
	return (j > i);
}

void compare_function_functor_lambda() {
	std::cout << "In compare_function_functor_lambda" << endl;
	vector<int> v { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	int n = v.size();

	printVector(v);

	//sort the vector by function (requires external function)
	sort(v.begin(), v.end(), compare);

	//sort by functor (requires external function)
	comp_f fcmp;
	bool bGreater = fcmp(1, 2);	//acts as a function call
	sort(v.begin(), v.end(), fcmp);

	//	sort(v.begin(), v.end(), comp_f());

	//sort by lambda (self contained)
//	sort(v.begin(), v.end(), [](int i,int j)->bool{return i<j;});

	printVector(v);
	std::cout << endl << endl;

}

void demoLambda() {
	std::cout << "In demoLambda" << endl;
	vector<int> v { 4, 1, 3, 5, 2, 3, 1, 7 };

	printVector(v);

	// below snippet find first number greater than 4
	// find_if searches for an element for which
	// function(third argument) returns true
	vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i)
	{
		return i > 4;
	});
	cout << "First number greater than 4 is : " << *p << endl;

	// function to sort vector, lambda expression is for sorting in
	// non-decreasing order Compiler can make out return type as
	// bool, but shown here just for explanation
	sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
	{
		return a > b;
	});

	printVector(v);

	// function to count numbers greater than or equal to 5
	int count_5 = count_if(v.begin(), v.end(), [](int a)
	{
		return (a >= 5);
	});
	cout << "The number of elements greater than or equal to 5 is : " << count_5
			<< endl;

	// function for removing duplicate element (after sorting all
	// duplicate comes together)
	p = unique(v.begin(), v.end(), [](int a, int b)
	{
		return a == b;
	});

	// resizing vector to make size equal to total different number
	v.resize(distance(v.begin(), p));
	printVector(v);

	// accumulate function accumulate the container on the basis of
	// function provided as third argument
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int f = accumulate(arr, arr + 10, 1, [](int i, int j)
	{
		return i * j;
	});

	cout << "Factorial of 10 is : " << f << endl;

	// We can also access function by storing this into variable
	auto square = [](int i)
	{
		return i * i;
	};

	cout << "Square of 5 is : " << square(5) << endl;
}

int main() {
	compare_function_functor_lambda();
	demoLambda();
}

