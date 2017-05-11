#include<iostream>
#include<cmath>
#define EXP 5

using namespace std;

int integrate_rec(int &i, int &b, int &a, int &n, float &sum);
int get_input(int &b, int &a, int &n);

int main(){
	int a = 0,b = 0,n = 0,i = 1;
	float sum = 0;
	cout << "a: " << a << "\tb: " << b << "\tn: " << n << "\ti: " << i << endl;	
	get_input(b, a, n);
	cout << "Lower bound: " << a << endl;
	cout << "Higher bound: " << b << endl;
	integrate_rec(i, b, a, n, sum);


	return 0;
}

int get_input(int &b, int &a, int &n){
	cout << "Enter lower bound: ";
	cin >> a;

	cout << "Enter higher bound: ";
	cin >> b;

	cout << "Enter number of Riemann squares: ";
	cin >> n;
	
	return b, a, n;
}
int integrate_rec(int &i, int &b, int &a, int &n, float &sum){
	float w = 0, h = 0;
	w = i * ( float(float(b)-float(a)) / float(n));

	h = float(pow(w, EXP)) + 10;
	
	sum += float(w*h);
	cout << "#" << i << ": " << sum << endl;
	i = i + 1;

	if(i<n){

		integrate_rec(i, b, a, n, sum);
	}
	cout << "Integral of X**5+10 from " << a << " to " << b << " is " << sum << endl;
}
