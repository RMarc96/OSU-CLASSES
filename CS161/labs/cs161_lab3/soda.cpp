#include<iostream>

using namespace std;

main(){
	int age, weekly_intake;
	float mouse_lethal, mouse_weight, mouse_death, human_weight, lifetime_intake;
	const double sweetner = 0.0001;
	
	cout << "What is the minimum amount of sweetener (in ounces) lethal to a mouse? ";
	cin >> mouse_lethal;
	
	cout << "What is the weight (in pounds) of the mouse? ";
	cin >> mouse_weight;

	mouse_death = mouse_lethal / mouse_weight;

	cout << "What is the dieter's weight (in pounds) at which they'll stop dieting? ";
	cin >> human_weight;


	cout << "How long do you think you will live (in years)? ";
	cin >> age;

	cout << "How many soda's do you drink a week? ";
	cin >> weekly_intake;

	lifetime_intake = age*52.1775*weekly_intake*sweetner;
	
	if((lifetime_intake / human_weight) <= mouse_death) {
		cout << "You would die." << endl;
		}
	else {
		cout << "You would live." << endl;
		}
	return 0;
}
