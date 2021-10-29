#include <iostream>
#include <cstring>

using namespace std;

//create a Node class for HashTable

template<typename T>
class Node {
public:
	string key;
	T value;
	Node<T> * next;

	Node(string key, T val) {
		this->key = key;
		value = val;
		next = NULL;
	}

	//Recursive destructor call to avoid Memory Leak
	~Node() {
		if (next != NULL) {
			delete next;
		}
	}

};

//Implementing HashTable class

template<typename T>
class HashTable {

	Node<T> ** table; //pointer to array of pointers
	int current_size;
	int table_size;

	int hashFn(string key) {

		int idx = 0;
		int p = 1;
		for (int j = 0; j < key.length(); j++) {

			idx += (key[j] * p) % table_size;
			idx %= table_size;
			p = (p * 27) % table_size;
		}
		return idx;
	}

	void rehash() {
		cout << "Rehash called" << endl;
		Node<T> ** oldTable = table;
		int oldTableSize = table_size;

		//approximation find the next prime no
		table_size = 2 * table_size;
		table = new Node<T>* [table_size];

		for (int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}
		current_size = 0;
		//shift the elements from the oldTable to new Table

		for (int i = 0; i < oldTableSize; i++) {

			Node<T>* temp = oldTable[i];

			while (temp != NULL) {

				insert(temp->key, temp->value);
				temp = temp->next;
			}

			if (oldTable[i] != NULL) {
				delete oldTable[i];
			}
		}

		delete [] oldTable;
	}

public:

	HashTable(int ts = 7) {

		table_size = ts;
		table = new Node<T>*[table_size];
		current_size = 0;
		for (int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}
	}

	void insert(string key, T value) {

		int idx = hashFn(key);

		Node<T>* n = new Node<T>(key, value);
		n->next = table[idx];
		table[idx] = n;
		current_size++;

		//rehash
		float load_factor = current_size / (table_size * 1.0);
		if (load_factor > 0.7) {
			rehash();
		}
	}

	void print() {

		for (int i = 0; i < table_size; i++) {
			cout << "Bucket " << i << "->";
			Node<T> * temp = table[i];

			while (temp != NULL) {
				cout << " [ " << temp->key << "," << temp->value << " ] ->";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	T* search(string key) {

		int idx = hashFn(key);

		Node<T>* temp = table[idx];

		while (temp != NULL) {
			if (key == temp->key) {
				return &temp->value;
			}
			temp = temp->next;
		}
		return NULL;
	}

	void erase(string key) {

		int idx = hashFn(key);

		Node<T>* temp = table[idx];
		Node<T>* prev = table[idx];

		while (temp != NULL) {
			if (temp->key == key) {
				prev->next = temp->next;
				delete temp;
			}
			prev = temp;
			temp = temp->next;
		}
		return;
	}

	T& operator[] (string key) {

		T* f = search(key);

		if (f == NULL) {
			T garbage;
			insert(key, garbage);
			f = search(key);
		}

		return *f;
	}

};