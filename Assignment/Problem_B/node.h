#ifndef __node__h__
#define __node__h__

#include <bits/stdc++.h>
using namespace std;

template<class T>
class node {
	private:
		T elem;
		node *next;

	public:
		node() {}
		node(T x, node<T> *N = NULL): elem(x), next(N) {}
		T &getElem() {
			return elem;
		}
		void setElem(T x) {
			elem = x;
		}
		node<T> *&getNext() { 
			return next;
		}
		void setNext(node<T> *N = NULL) {
			next = N;
		}
};
#endif
