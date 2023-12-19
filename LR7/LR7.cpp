// LR7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "lib.h"
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <forward_list>
#include <algorithm>

typedef map<Mark, int> myMapType;
bool IsOdd(int i) { return ((i % 2) == 1); }
//task 4
class MathFunctor {
private:
	string operation;

public:
	MathFunctor(string op) : operation(op) {}

	double operator()(double a, double b)const {
		if (operation == "plus")
			return a + b;
		else if (operation == "addition")
			return a - b;
		else if (operation == "times")
			return a * b;
		else if (operation == "divides")
			if (b != 0) {
				return a / b;
			}
			else {
				cerr << "Error: Division by zero\n";
				return 0.0;
			}
		else if (operation == "modulus")
			if (b != 0) {
				return static_cast<int>(a) % static_cast<int>(b);
			}
			else {
				cerr << "Error: Modulus by zero\n";
				return 0.0;
			}
		else if (operation == "negate")
			return -a;
		else
			cerr << "Error: Unknown operation\n";
		return 0.0;
	}
};
class EqualityFunctor {
private:
	string operation;

public:
	EqualityFunctor(string op) : operation(op) {}

	template <typename T> bool operator()(T a, T b)const {
		if (operation == "equal_to")
			return a == b;
		else if (operation == "not_equal_to")
			return !(a == b);
		else if (operation == "greater")
			return a > b;
		else if (operation == "less")
			return a < b;
		else if (operation == "greater_equal")
			return (a > b) || (a == b);
		else if (operation == "less_equal")
			return (a < b) || (a == b);
		else
			cerr << "Error: Unknown operation\n";
		return false;
	}
};
class LogicFunctor {
private:
	string operation;

public:
	LogicFunctor(string op) : operation(op) {}

	bool operator()(bool a, bool b)const {
		if (operation == "logical_and")
			return a && b;
		else if (operation == "logical_or")
			return a || b;
		else if (operation == "logical_not")
			return !a;
		else
			cerr << "Error: Unknown operation\n";
		return false;
	}
};

int main() {
	//task 1 vector
	vector<Mark> myVector;
	myVector.push_back(Mark(10, 23, 11, 2023));//Додає елемент в кінець вектора
	myVector.push_back(Mark(10, 23, 11, 2023));
	myVector.pop_back();//Видаляє елемент з кінця вектора
	int size = myVector.size();//Повертає поточний розмір вектора.

	//task 1 list
	list<Mark> myList;
	myList.push_back(Mark(10, 23, 11, 2023));//Додає елемент в кінець списку
	myList.push_front(Mark(10, 21, 03, 1980));//Додає елемент в початок списку
	myList.erase(myList.begin());// Видаляє елемент за ітератором

	//task 1 deque
	deque<Mark> myDeque;
	myDeque.push_back(Mark(10, 23, 11, 2023));//Додає елемент в кінець дека
	myDeque.push_front(Mark(10, 21, 03, 1980));//Додає елемент в початок дека
	myDeque.pop_back();//Видаляє елемент з кінця дека

	//task 1 set
	set<Mark> mySet;
	mySet.insert(Mark(10, 23, 11, 2023));//Додає елемент в множину
	mySet.insert(Mark(10, 21, 03, 1980));
	mySet.erase(Mark(10, 23, 11, 2023));//Видаляє елемент за значенням або ітератором
	auto it = mySet.find(Mark(10, 21, 03, 1980));//Знаходить елемент за значенням

	//task 1 multiset
	multiset<Mark> myMultiSet;
	myMultiSet.insert(Mark(10, 23, 11, 2023));//Додає елемент в мультимножину
	myMultiSet.insert(Mark(10, 21, 03, 1980));
	myMultiSet.insert(Mark(10, 23, 11, 2023));
	myMultiSet.erase(Mark(10, 21, 03, 1980));//Видаляє елемент за значенням або ітератором
	auto itMulti = myMultiSet.find(Mark(10, 23, 11, 2023));//Знаходить елемент за значенням

	//task 1 map
	map<Mark, int> myMap;
	myMap[Mark(10, 23, 11, 2023)] = 1;
	myMap.insert(myMapType::value_type(Mark(10, 21, 03, 1980), 2));//Додає пару ключ-значення в мапу
	myMap.erase(Mark(10, 23, 11, 2023));//Видаляє елемент за ключем або ітератором
	auto itMap = myMap.find(Mark(10, 21, 03, 1980));//Знаходить значення за ключем

	//task 1 multimap
	multimap<Mark, int> myMultiMap;
	myMultiMap.insert(myMapType::value_type(Mark(10, 21, 03, 1980), 1));//Додає пару ключ-значення в мапу
	myMultiMap.insert(myMapType::value_type(Mark(10, 21, 03, 1980), 2));
	myMultiMap.insert(myMapType::value_type(Mark(10, 23, 11, 2023), 3));
	myMultiMap.erase(Mark(10, 23, 11, 2023));//Видаляє елемент за ключем або ітератором
	auto itMultiMap = myMultiMap.find(Mark(10, 21, 03, 1980));//Знаходить значення за ключем

	//task 1 stack
	stack<Mark> myStack;
	myStack.push(Mark(10, 21, 03, 1980));//Додає елемент в стек
	myStack.push(Mark(10, 23, 11, 2023));
	myStack.pop();//Видаляє верхній елемент стеку
	Mark topElement = myStack.top();//Повертає значення верхнього елементу без видалення

	//task 1 queue
	queue<Mark> myQueue;
	myQueue.push(Mark(10, 21, 03, 1980));//Додає елемент в чергу
	myQueue.push(Mark(10, 23, 11, 2023));
	myQueue.pop();//Видаляє перший елемент черги
	Mark frontElement = myQueue.front();//Повертає значення першого елементу без видалення

	//task 1 priority_queue
	priority_queue<Mark> myPriorityQueue;
	myPriorityQueue.push(Mark(10, 21, 03, 1980));//Додає елемент в пріоритетну чергу
	myPriorityQueue.push(Mark(10, 23, 11, 2023));
	myPriorityQueue.pop();//Видаляє елемент з найвищим пріоритетом
	Mark topElementPriorityQueue = myPriorityQueue.top();//Повертає значення елементу з найвищим пріоритетом без видалення



	//task 2 input and output and random access
	vector<Mark>::iterator inputIter = myVector.begin();
	vector<Mark>::iterator outputIter = myVector.end();

	cout << "Vector of Marks: " << endl;
	cout << endl;
	for (auto it = inputIter; it != outputIter; ++it) {
		cout << "        Marks day: " << it->getday() << endl;
		*it = Mark(10, 21, 03, 1980);
		cout << "        Marks day changed: " << it->getday() << endl;
	}

	//task 2 forward
	forward_list<int> myForwardList = { 1, 2, 3, 4, 5 };
	forward_list<int>::iterator forwardIter = myForwardList.begin();

	cout << "Elements in the forward_list using forward iterator: ";
	for (; forwardIter != myForwardList.end(); ++forwardIter) {
		cout << *forwardIter << endl;
	}
	cout << endl;

	//task 2 bidirectional
	list<Mark>::iterator bidirectionalIter = myList.begin();

	// Використання двонаправленого ітератора для переміщення вперед та назад
	while (bidirectionalIter != myList.end()) {
		cout << bidirectionalIter->getyear() << " ";
		++bidirectionalIter;
	}
	cout << endl;
	// Переміщення назад
	while (bidirectionalIter != myList.begin()) {
		--bidirectionalIter;
		cout << bidirectionalIter->getyear() << " ";
	}
	cout << endl;
	//task 3.1
	vector<int> numbers = { 1, 2, 3, 3, 4, 5, 6 };

	vector<int>::iterator it31 = adjacent_find(numbers.begin(), numbers.end());

	if (it31 != numbers.end()) {
		cout << "the first pair of repeated elements are: " << *it31 << endl;
	}
	cout << endl;
	//task 3.2
	vector<int> myvector32(7);
	copy(numbers.begin(), numbers.end(), myvector32.begin());
	for (vector<int>::iterator it = myvector32.begin(); it != myvector32.end(); ++it)
		cout << ' ' << *it;
	cout << endl;

	//task 3.3
	vector<int> myvector33(7);
	copy_backward(numbers.begin(), numbers.end(), myvector33.end());
	for (vector<int>::iterator it = myvector33.begin(); it != myvector33.end(); ++it)
		cout << ' ' << *it;
	cout << endl;

	//task 3.4
	cout << "number 3 appears - " << count(numbers.begin(), numbers.end(), 3) << " times " << endl;
	cout << endl;

	//task 3.5
	cout << "ood number appears - " << count_if(numbers.begin(), numbers.end(), IsOdd) << " times " << endl;
	cout << endl;
}
