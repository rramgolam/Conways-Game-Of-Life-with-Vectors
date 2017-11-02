#import <iostream>
#import <vector>
#include <unistd.h>

using namespace std;

const int GRID_SIZE = 38;

void initialiseGridScenarioOne(vector<vector<bool> >&);
void initialiseGridScenarioTwo(vector<vector<bool> >&);
void initialiseGridScenarioThree(vector<vector<bool> >&);
void initialiseGridScenarioFour(vector<vector<bool> >&);
void initialiseGridScenarioFive(vector<vector<bool> >&);

void printGrid(vector<vector<bool> >&);
int getNeighbours(int, int, vector<vector<bool> > &);
int getState(bool, int);


int showMenu()
{
    
#ifdef WINDOWS
    system("cls");
#else
    // Assume POSIX
    system ("clear");
#endif
    
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
    
    // 2d array using vectors
    vector<vector<bool> > theGrid(GRID_SIZE, vector<bool>(GRID_SIZE, 0));       // Grid initialised to 0's
    vector<vector<bool> > tmpGrid(GRID_SIZE, vector<bool>(GRID_SIZE, 0));       // Grid initialised to 0's

    switch (pattern)
    {
        case 1: initialiseGridScenarioOne(theGrid);
            break;
        
        case 2: initialiseGridScenarioTwo(theGrid);
            break;
        
        case 3: initialiseGridScenarioThree(theGrid);
            break;
            
        case 4: initialiseGridScenarioFour(theGrid);
            break;
            
        case 5: initialiseGridScenarioFive(theGrid);
            break;
         
        default:initialiseGridScenarioOne(theGrid);
            break;
    }
    
    printGrid(theGrid);
    cout << "Simulation starting in 2s..." << endl;
    usleep(2000000);

    for (int x = 0; x < numberOfGenerations; x++)                   // Begin Game
    {
        //For Each cell
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for(int j = 0; j < GRID_SIZE; j++)
            {
                
                int local_n = getNeighbours(i, j, theGrid);         // Get number of neighbours for the cell
                bool survival = getState(theGrid[i][j], local_n);   // Get its new state
                tmpGrid[i][j] = survival;                           // Set its state in the new grid
                
            }
        }
        printGrid(tmpGrid);                                         // Print out next gen
        theGrid = tmpGrid;                                          // Transfer to current gen for next iteration
        
        usleep(200000);                                             // Time between iteration
    }

	return 0;
}

void initialiseGridScenarioOne(vector<vector<bool> > &grid)
{
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][1] = 1;
    grid[2][2] = 1;
    
    cout << "\nPattern One Set (Still)." << endl;
}

void initialiseGridScenarioTwo(vector<vector<bool> > &grid)
{
    
    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;
    
    cout << "\nPattern Two Set (Oscillator)." << endl;
}

void initialiseGridScenarioThree(vector<vector<bool> > &grid)
{
    
    grid[1][2] = 1;
    grid[1][5] = 1;
    
    grid[2][1] = 1;
    grid[2][3] = 1;
    grid[2][4] = 1;
    grid[2][6] = 1;
    
    grid[3][2] = 1;
    grid[3][5] = 1;
    
    grid[4][2] = 1;
    grid[4][5] = 1;
    
    grid[5][1] = 1;
    grid[5][3] = 1;
    grid[5][4] = 1;
    grid[5][6] = 1;
    
    grid[6][2] = 1;
    grid[6][5] = 1;
    
    cout << "\nPattern Three Set (Octagon mid-set Oscillator)." << endl;
    
}

void initialiseGridScenarioFour(vector<vector<bool> > &grid)
{
    
    grid[0][3] = 1;
    grid[0][4] = 1;
    
    grid[1][2] = 1;
    grid[1][5] = 1;
    
    grid[2][1] = 1;
    grid[2][6] = 1;
    
    grid[3][0] = 1;
    grid[3][7] = 1;
    
    grid[4][0] = 1;
    grid[4][7] = 1;
    
    grid[5][1] = 1;
    grid[5][6] = 1;
    
    grid[6][2] = 1;
    grid[6][5] = 1;
    
    grid[7][3] = 1;
    grid[7][4] = 1;
    
    cout << "\nPattern Four Set (Octagon Oscillator)." << endl;
    
}

void initialiseGridScenarioFive(vector<vector<bool> > &grid)
{
    
    // NEEDS GRID SIZE OF 38
    grid[5][1] = 1;
    grid[5][2] = 1;
    grid[6][1] = 1;
    grid[6][2] = 1;
    
    grid[5][11] = 1;
    grid[6][11] = 1;
    grid[7][11] = 1;
    
    grid[4][12] = 1;
    grid[8][12] = 1;
    
    grid[3][13] = 1;
    grid[9][13] = 1;
    
    grid[3][14] = 1;
    grid[9][14] = 1;
    
    grid[6][15] = 1;
    
    grid[4][16] = 1;
    grid[8][16] = 1;
    
    grid[5][17] = 1;
    grid[6][17] = 1;
    grid[7][17] = 1;
    
    grid[6][18] = 1;
    
    grid[3][21] = 1;
    grid[4][21] = 1;
    grid[5][21] = 1;
    
    grid[3][22] = 1;
    grid[4][22] = 1;
    grid[5][22] = 1;
    
    grid[2][23] = 1;
    grid[6][23] = 1;
    
    grid[1][25] = 1;
    grid[2][25] = 1;
    grid[6][25] = 1;
    grid[7][25] = 1;
    
    grid[3][35] = 1;
    grid[4][35] = 1;
    grid[3][36] = 1;
    grid[4][36] = 1;
    
    cout << "\nPattern Five Set (Glider Gun)." << endl;
    
}


void printGrid(vector<vector<bool> >& grid)
{
    cout << endl;
    
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j])
            {
                cout << " o ";
            } else
            {
                cout << "   ";
            }
        }
        cout << endl;
    }
}

int getNeighbours(int i, int j, vector<vector<bool> >& grid)
{
    int count = 0;
    
    if ((i > 0) && (j > 0))                         // Top Left
    {
        if(grid[i - 1][j - 1]) {
            count++;
        }
    }
    
    if (i > 0)                                      // Top Mid
    {
        if (grid[i - 1][j]) {
            count++;
        }
    }
    
    if ((i > 0) && (j < GRID_SIZE-1))               // Top Right
    {
        if (grid[i - 1][j + 1]) {
            count++;
        }
    }
    
    if ((j > 0))                                    // Mid Left
    {
        if (grid[i][j - 1]) {
            count++;
        }
    }
    
    if (j < GRID_SIZE-1)                            // Mid Right
    {
        if (grid[i][j + 1]) {
            count++;
        }
    }
    
    if ((j > 0) && (i < GRID_SIZE-1))               // Bottom Left
    {
        if (grid[i + 1][j - 1]) {
            count++;
        }
    }
    
    if (i < GRID_SIZE-1)                            // Bottom Mid
    {
        if (grid[i + 1][j]) {
            count++;
        }
    }
    
    if ((i < GRID_SIZE-1) && (j < GRID_SIZE-1))     // Bottom Right
    {
        if (grid[i + 1][j + 1]) {
            count++;
        }
    }
    
    return count;
}

int getState(bool current_state, int n)
{
    if (current_state && (n < 2)) {
        return 0;
    }
    else if (current_state && (n == 2 || n == 3))
    {
        return 1;
    }
    else if (current_state && (n > 3))
    {
        return 0;
    }
    else if ((current_state == 0) && (n == 3))
    {
        return 1;
    }
    
    return current_state;
}


