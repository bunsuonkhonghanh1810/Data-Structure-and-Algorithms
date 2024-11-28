#ifndef __single_list__h__
#define __single_list__h__

#include "single_list_iterator.h"

template<class T>
class single_list {
	private:
		node<T> *head, *tail;

	public:
		typedef single_list_iterator<T> iterator;
		single_list(): head(NULL), tail(NULL) {}
		single_list(int n, T x): head(NULL), tail(NULL) {
			for (int i = 0; i < n; i++) push_back(x);
		}
		single_list(const single_list<T> &other) : head(NULL), tail(NULL) {
			for (single_list<T>::iterator i = other.begin(); i != other.end(); ++i) push_back(*i);
		}

		iterator begin() {
			return head;
		}
		iterator end() {
			return NULL;
		}
		int size() {
			int count = 0;
			for (single_list<T>::iterator i = this->begin(); i != this->end(); i++) {
				count++;
			}
			return count;
		}
		bool empty() {
			return this->size() == 0;
		}
		T &front() {
			return head->getElem();
		}
		T &back() {
			return tail->getElem();
		}
		void push_front(T x) {
			head = new node<T>(x,head);
			if (this->size() == 1) tail = head;
		}
		void push_back(T x) {
			if (this->size() == 0) push_front(x);
			else {
				tail->setNext(new node<T>(x,NULL));
				tail = tail->getNext();
			}
		}
		void pop_front() {
			if (this->size() == 0) return;
			if (this->size() == 1) {
				head = tail = NULL;
			}else {
				head = head->getNext();
			}
		}
		void pop_back() {
			if (this->size() == 0) return;
			if (this->size() == 1) {
				head = tail = NULL;
			}else {
				node<T> *p = head;
				while (p->getNext() != tail) p = p->getNext();
				p->setNext(NULL);
				tail = p;
			}
		}
		void insert(node<T> *p, node<T> *X) {
			node<T> *temp = p->getNext();
			p->setNext(X);
			X->setNext(temp);
		}
		void erase(node<T> *p) {
			if (p == head) {
				head = head->getNext();
				return;
			}
			node<T> *temp = head;
			while (temp != NULL && temp->getNext() != p) temp = temp->getNext();
			if (temp != NULL) temp->setNext(p->getNext());	
		}
};
#endif 