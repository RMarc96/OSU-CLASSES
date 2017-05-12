#include<iostream>

using namespace std;

class DumbBell{
	private:
		int weight;
	public:
		void setWeight(int);
		int getWeight();
};

void DumbBell::setWeight(int w){
	weight =  w;
}

int DumbBell::getWeight(){
	return weight;
}


int main() {
	DumbBell bar;
	bar.setWeight(200);

	cout << "The weight is " << bar.weight << endl;
	return 0;
}
