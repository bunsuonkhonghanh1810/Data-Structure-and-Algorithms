#ifndef __single_list_iterator__h__
#define __single_list_iterator__h__

#include "node.h"

template <class T>
class single_list_iterator {
	private:
		node<T> *current;

	public:
		single_list_iterator() {current = NULL;}
		single_list_iterator(node<T> *p) {current = p;}
		node<T> *getCurrent() {
			return current;
		}
		single_list_iterator<T> &operator=(single_list_iterator<T> p) {
			this->current = p.getCurrent();
			return *this;
		}	
		bool operator!=(single_list_iterator<T> p) {
			return current!=p.getCurrent();
		}
		single_list_iterator<T> operator++() {
			current = current->getNext();
			return current;
		}
		T &operator*() {
			return current->getElem();
		}
};
#endif
