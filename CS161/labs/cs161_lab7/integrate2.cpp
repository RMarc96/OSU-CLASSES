#include<iostream>
#include<cmath>

using namespace std;
void get_input(int &a, int &b, int &n);
void compute(int a, int b, int n, int i);

int main(){
	int i = 1, a = 0, b = 0, n = 0;

	get_input(a, b, n);
	cout << "a: " << a << "\tb: " << b << "\tn: " << n << "\ti: " << i << endl;
	compute(a,b,n,i);

	return 0;
}

void get_input(int &a, int &b, int &n) {
	cout << "Enter lower bound: ";
	cin >> a;

	cout << "Enter higher bound: ";
	cin >> b;
	
	cout << "Enter number of squares: ";
	cin >> n;

	return;
}
void compute(int a, int b, int n, int i) {
	float sum = 0;
	for(int i; i<n; i++){
		cout << sum << endl;
		float w = 0, h = 0;
		w = i*(float((b-a) / n));
		h = float(pow(w, 5) + 10);	
		sum += w*h;
	}
	cout << "f(x) = x**5 + 10 integrated from " << a << " to " << b << " is " << sum << endl;
}
