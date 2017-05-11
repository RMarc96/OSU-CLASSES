#include<iostream>

using namespace std;

int main() {
	float cereal_weight, lifespan, weeklyintake;

	cout << "Enter the weight (in ounces) of a box of cereal: ";
	cin >> cereal_weight;

	cout << "Your cereal weighs "<<  cereal_weight/35273.92 << " in metric tons." << endl;
	cout << "You need " << 35273.92/cereal_weight << " cereal boxes to have 1 metric ton of cereal." << endl;

	cout << "How many boxes of cereal do you eat per week? ";
	cin >> weeklyintake;

	cout << "How long (in years) do you expect to live? ";
	cin >> lifespan;


	cout << "In your lifetime, you'll eat " << lifespan*52.1775*weeklyintake << " boxes of cereal in your whole life, fatty." << endl; //Note: There are 52.1775 weeks in an average year

	return 0;
}
