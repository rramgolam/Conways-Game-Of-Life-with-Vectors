#import <iostream>

using namespace std;

const int GRID_SIZE = 38;

int showMenu()
{
    cout << "\nPlease chooes which seed pattern to start from:" << endl;
    cout << "    1. Square (Still Life)" << endl;
    cout << "    2. Blinker (Oscillator)" << endl;
    cout << "    3. Octagon (Finite Oscillator)" << endl;
    cout << "    4. Octagon - different period (Finite Oscillator)" << endl;
    cout << "    5. Single Glider Gun" << endl;
    
    cout << endl;
    
    int choice = 1;
    cin >> choice;
    
    
    return choice;
}

int main()
{
	cout << "Starting Game Of Life Simulation" << endl;
    
    int pattern = showMenu();
    
    int numberOfGenerations = 10;
    cout << "Please Enter the number of generations to populate:" << endl;
    cin >> numberOfGenerations;

	return 0;
}
