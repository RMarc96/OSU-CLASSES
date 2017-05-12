#include<iostream>
#include <stdlib.h>

using namespace std;

template <class T>


class vector {
   private:
	T *v;
	int s;
	int capacity;
   public:
	vector(){
		s=0;
		v=NULL;
     	 }
	~vector(){ delete [] v; }

	T operator[](int i){
		return *v[i];
	
	}

	//Only perform address arithmetic	

	void resize() {
		if( s >= capacity ) {
			v.clear();
			cout << "Enter a valid capacity: ";
			cin >> s;
		}
		v.push_back(s);
	
	};
		

	T at(int x){
		if(x >= s) {
			std::cout << "Out of bounds." << std::endl;
			try{ throw x, s, capacity; }
			catch(int &e) { cout << v[0] << "int thrown! " << endl;}	
		}
		return v[x];
	}



	//Copy constructor
	vector(vector<T> &other) { 
		s = other.s;
		
		v = new T[s];
		
		for(int i = 0; i < s; i++) {
			v[i] = other.v[i];
		}
	}

	//Assignment Operator Overload:
	void operator=(vector<T> &other) {
		this->s = other.s;
		v = new T[s];
		for(int i = 0; i < s; i++) {
			this->v[i] = other.v[i];
		}
	
	}



	int size() { return s; }

	void pushback(T ele) {
		T *temp;
		temp = new T[s];
	 
		for(int i=0; i<s-1; i++)
			temp[i]=v[i];

	 	delete [] v;
	 	s++;
		v = new T[s];

		for(int i=0; i<s-1; i++)
	    	v[i]=temp[i];

	 	v[s-1]=ele;
	 	delete [] temp;
      }
};
