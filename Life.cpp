/********************************************************************
** Program Filename: Life
** Author: James S. Gill
** Date: 2016-01-17
** Description: Runs choice of 3 shapes on 20 x 40 grid for Conways Game of Life
** Input: shape, x coordinate, y coordinate, # of generations
** Output: Pre defined # of static arrays with moving shapes
*********************************************************************/
#include <iostream>
#include <string>

using namespace std;



/*********************************************************************
 ** Function: CheckNeighbour
 ** Description: Counts the # of live neighbours (8 neighbours)
 ** Parameters: array, x and y values, height and width of invisible array
 ** Pre-Conditions: value contains 8 neighbours
 ** Post-Conditions: value is successfully passed to cellstate
 *********************************************************************/
int checkNeighbour(int **arr, int x, int y, int maxHeight, int maxWidth)
{
    int tally = 0;
    if ((x > 1 && x < maxWidth - 1) && (y > 1 && y < maxHeight - 1))//handles edge case
    {
        if (arr[y-1][x-1] == 1)
        {
            tally += 1;
        }
        if (arr[y-1][x] == 1)
        {
            tally += 1;
        }
        if (arr[y-1][x+1] == 1)
        {
            tally += 1;
        }
        if (arr[y][x-1] == 1)
        {
            tally += 1;
        }
        if (arr[y][x+1] == 1)
        {
            tally += 1;
        }
        if (arr[y + 1][x-1] == 1)
        {
            tally += 1;
        }
        if (arr[y + 1][x] == 1)
        {
            tally += 1;
        }
        if (arr[y+1][x+1] == 1)
        {
            tally +=1;
        }
    }

    return tally;
}



/*********************************************************************
 ** Function: checkValue
 ** Description: Returns the value of the cell
 ** Parameters: array, x and y values
 ** Pre-Conditions: a value exists in the array
 ** Post-Conditions: a holds the correct value of the static array
 *********************************************************************/
int checkValue(int **arr, int x, int y)
{
    int a;
    a = arr[y][x];
    return a;
}



/*********************************************************************
 ** Function: writeArray
 ** Description: Writes the Array
 ** Parameters: array, x and y values
 ** Pre-Conditions: a value exists in the array
 ** Post-Conditions: a holds the correct value of the static array
 ** Citation: Cierra Shawe   DynMem.cpp       7/7/15
 *********************************************************************/
int** writeArray (int x, int y)
{
    int **temp;

    temp = new int*[y]; //creating first chunk of memory,points to start of larger array

    for(int i = 0; i < y; i++) //if y is 10, 10 times your going to create 10 arrays
        temp[i] = new int[x]; // x number of columns, creating the rest

    return temp; //returning the new array
}



/*********************************************************************
 ** Function: print
 ** Description: Prints out the contents of the array
 ** Parameters: array, x and y values
 ** Pre-Conditions: a value exists in the array
 ** Post-Conditions:
 *********************************************************************/
void print(int **array, int x, int y)
{

    for(int i = 10; i < y; i++)
    {
        for (int j = 10; j < x; j++)
        {
            cout << array[i][j] ;
        }
        cout << endl;
    }

    cout << endl;

}


/*********************************************************************
 ** Function: createOscillator
 ** Description: creates basic Oscillator Shape
 ** Parameters: array, width and height of array
 ** Pre-Conditions: 1 is selected from menu
 ** Post-Conditions: Program is run x number of times
 *********************************************************************/
void createOscillator(int **&arr, int width, int height)
{

    int dead = 0;
    int live = 1;
    int x;
    int y;
    do
    {
        cout << "Enter starting x-coordinate (1 - " << width-12 << ")" <<endl;
        cin >> x;
        x += 9;
        cout << "Enter starting y-coordinate (2- " << height-11 << ")" <<endl;
        cin >> y;
        y +=9;
    }
    while(x < 10 || x > 47 || y < 11 || y > 28);

    for (int i = 0; i < height; i++)
    {
       for (int j = 0; j < width; j++)
           {
                if(i == y && (j == x || j == x+1 || j == x+2))  //Creates Shape
                {
                    arr[i][j] = live;
                }

                else
                {
                    arr[i][j] = dead; // initializing array to be all 0's
                }
            }
    }
}


/*********************************************************************
 ** Function: createGlider
 ** Description: creates basic Glider
 ** Parameters: array, width and height of array
 ** Pre-Conditions: 2 is selected from menu
 ** Post-Conditions: Program is run x number of times
 *********************************************************************/
void createGlider(int **&arr, int width, int height)
{

    int dead = 0;
    int live = 1;
    int x;
    int y;
    do
    {
        cout << "Enter starting x-coordinate (1 - " << width-12 << ")" <<endl;
        cin >> x;
        x +=9;
        cout << "Enter starting y-coordinate (3- " << height-10 << ")" <<endl;
        cin >> y;
        y +=9;
    }
    while(x < 10 || x > 47 || y < 12 || y > 29);

    for (int i = 0; i < height; i++)
    {
       for (int j = 0; j < width; j++)
           {
           // cout << "second loop" << endl;
                if(i == y && (j == x || j == x+1 || j == x+2))//Bottom row
                {
                    arr[i][j] = live;
                }
                else if (i == y-1 && (j == x+2)) //Middle row
                {
                    arr[i][j] = live;
                }
                else if (i == y - 2 && (j == x+1)) //top row
                {
                    arr[i][j] = live;
                }
                else
                {
                    arr[i][j] = dead; // initializing array to be all 0's
                }

            }
    }
}


/*********************************************************************
 ** Function: createGun
 ** Description: creates basic Gun
 ** Parameters: array, width and height of array
 ** Pre-Conditions: 3 is selected from menu
 ** Post-Conditions: Program is run x number of times
 *********************************************************************/
void createGun(int **&arr, int width, int height)
{
    int dead = 0;
    int live = 1;
    int x;
    int y;
    do{
    cout << "Enter starting x-coordinate (1 - " << width-45 << ")" <<endl;
    cin >> x;
    x +=9;
    cout << "Enter starting y-coordinate (6- " << height-13 << ")" <<endl;
    cin >> y;
    y +=9;
    }
    while(x < 10 || x > 14 || y < 15 || y > 26);
    for (int i = 0; i < height; i++){ //Rows
      for (int j = 0; j < width; j++) //Columns
           {
               //Bottom row of leftmost square
               if(i == y && (j == x || j == x + 1 || j == x + 10 || j == x + 14 ||
                             j == x + 16|| j == x + 17 || j == x + 22 || j == x + 24))
                {
                    arr[i][j] = live;
                }
               //Top row of Leftmost Square
                else if (i == y - 1 && (j == x || j == x+1 || j == x + 10 || j == x + 16
                            || j == x + 20 || j == x + 21))
                {
                    arr[i][j] = live;
                }
                //Bottom row Rightmost Square
                else if (i == y - 2 && (j == x + 11 || j == x + 15|| j == x + 20
                            || j == x + 21 || j == x + 34 || j == x + 35))
                {
                    arr[i][j] = live;
                }
                else if (i == y - 3 && (j == x + 12 || j == x + 13 || j == x + 20
                                        || j == x +21 || j == x + 34 || j == x + 35))
                //Top row Rightmost Square
                {
                    arr[i][j] = live;
                }
                //row above Rightmost square
                else if (i == y - 4 && (j == x + 22 || j == x + 24))
                {
                    arr[i][j] = live;
                }
                //row 2 above Rightmost square
                else if (i == y - 5 && (j == x + 24))
                {
                    arr[i][j] = live;
                }
                //row 1 below leftmost square
                else if (i == y + 1 && (j == x + 10 || j == x + 16 || j == x + 24))
                {
                    arr[i][j] = live;
                }
                //row 1 below leftmost square

                else if (i == y + 2 && (j == x + 11 || j == x + 15))
                {
                    arr[i][j] = live;
                }
                //row 1 below leftmost square
                else if (i == y + 3 && (j == x + 12 || j == x + 13))
                {
                    arr[i][j] = live;
                }
                //initializing array to be all 0's
                else
                {
                    arr[i][j] = dead;
                }

           }
    }
}



/*********************************************************************
 ** Function: copy
 ** Description: Copies contents of array
 ** Parameters: array, temp array, rows and columns of array
 ** Pre-Conditions: temp array is correctly created
 ** Post-Conditions: values correctly printed
 *********************************************************************/
void copy(int **a, int **temp, int rows, int columns)
{
  for(int j = 0; j < rows; j++)
  {
		for(int i = 0; i < columns; i++)
			a[j][i] = temp[j][i];
	}
}

/*********************************************************************
 ** Function: cellState
 ** Description: Converts cell to alive or dead depending on neighbour tally
 ** Parameters: tally and curVal being red
 ** Pre-Conditions: tally is correct number and curVal is correct
 ** Post-Conditions: copied to temp array
 *********************************************************************/
int cellState(int tally, int curVal)
{
    int val;
    if (curVal == 1) //if cell is alive
    {
        if (tally == 0 || tally == 1 || tally > 3)
        {
            val = 0;
        }

        else
        {
            val = 1;
        }
    }

    else if (curVal == 0)
    {
        if (tally == 3)
        {
            val = 1;
        }
        else
        {
            val = 0;
        }
    }
    return val;
}


/*********************************************************************
 ** Function: remove
 ** Description: Removes the allocated memory
 ** Pre-Conditions: array exists
 ** Post-Conditions: array is deleted in memory
 ** Citation: Cierra Shawe   DynMem.cpp       7/7/15
 *********************************************************************/
void remove(int **&arr, int y)
{

    for(int i = 0; i < y; i++)
        delete(arr[i]); // deleting the values of the array
        //UNRESERVES THE SPOT IN MEMORY
    delete(arr); // deleting the array

}



int main()
{
    int shape;
    int width = 50;
    int height = 30;
    int maxWidth = 60;
    int maxHeight = 60;
    int z; //placeholder
    int f; //placeholder
    int **a; //array
    int **temp; //temporary array
    int generations; //stores generations of cycles

    a = writeArray(60,60);
    temp = writeArray(60,60);

    while (shape < 1 || shape > 3)
    {
        cout << "What Shape would you like to use? 1. Oscillator 2. Glider" <<
        " 3.Glider Gun (Enter 1 2 or 3): " << endl;
        cin >> shape;
    }

    switch(shape)
    {
    case 1:
        createOscillator(a, width, height);
        break;
    case 2:
        createGlider(a, width, height);
        break;
    case 3:
        createGun(a, width, height);
        break;
    }

    do
    {
    cout << "For how many generations would you like to run this game(1-100)?" << endl;
    cin >> generations;
    }
    while (generations < 1 || generations > 100);

    print(a, width, height);

    for (int numTurn = 0; numTurn < generations; numTurn++){
    for (int i = 0; i < maxHeight; i++)  //ROWS, Print out second array
        {
        for (int j = 0; j < maxWidth; j++)  //COLUMNS
            {
                z = checkNeighbour(a, j, i, maxHeight, maxWidth);
                f = checkValue(a, j, i);
                temp[i][j] = cellState(z, f); //copying the updated value to temp array
            }
        }
        copy(a, temp, maxHeight, maxWidth); //Copy the entire temp array, store in a
        cout << endl;
        print(a, width, height); //print array temp
    }

    remove(a, maxHeight);
    remove(temp, maxHeight);
}


