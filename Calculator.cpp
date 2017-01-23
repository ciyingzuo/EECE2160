#include"Calculator.h"

using namespace std;

// return value1
template<class T> T Calculator<T>::getValue1() {
		return value1;
	}

// return value2
template<class T> T Calculator<T>::getValue2() {
		return value2;
	}

// get the sum of two value
template<class T> T Calculator<T>::getSum() {
	return value1 + value2;
	}

// compare two value with and
template<class T> int Calculator<T>::getLogicalAND() {
		return value1 && value2;
	}

// determine if value1 bigger than value2
template<class T> bool Calculator<T>::isGreater() {
		return value1 > value2;
	}
