/*********************************************************************
** Program Filename: Recursion
** Author: James S. Gill
** Date: 2016-01-31
** Description: Lab 4, write a string in reverse, sum of an array and
add a triangle
** Input: choice from menu, size of array and triangle, values for sum
** Output: a reverse string, sum of numbers, sum of triangle
*********************************************************************/
#include <iostream>
#include <string>

using namespace std;

void reverse(string);
int sum(int[], int);
int triangle(int);

int main()
{
    string a;
    int size;
    int choice; //user selection

    while(true){  //while loop, return 0 when user enters 4
        cout << "\n1. Reverse String \n" << "2. Sum of Array \n" << "3. Triangle function \n"
        << "4. Exit \n" << "(Enter 1, 2, 3, or 4)" << endl;
        cin >> choice;

       if (choice == 1){
                cout << "Enter a string, any string at all: " << endl;
                cin >> a;
                reverse(a);
       }

       if (choice == 2){
                cout << "Enter size of array: " << endl;
                cin >> size;
                int array[size];
                int val;
                cout << "Please enter " << size << " values: " << endl;
                for (int i = 0; i < size; i ++){
                    cout << "value " << i + 1 << " : " << endl;
                    cin >> val;
                    array[i] = val;
                }
                cout << "\n" << sum(array, size);
       }

        if (choice == 3){

                cout << "Enter size of triangle: " << endl;
                cin >> size;
                cout << "\n" << triangle(size);
        }

        if (choice == 4){

                cout << "Thanks for visiting" << endl;
                return 0;
        }
    }
}


/*********************************************************************
 ** Function: reverse
 ** Description: output reverse letters of a string
 ** Parameters: a string
 *********************************************************************/
void reverse(string a){
    if (a.length() == 1){
        cout << a;
    }

    else{
        cout << a.at(a.length() - 1) << "\n";
        reverse(a.substr(0, a.length() - 1));

    }
}


/*********************************************************************
 ** Function: sum
 ** Description: sum values of a given array using recursion
 ** Parameters: an array and size of the array
 *********************************************************************/
int sum(int arr[], int size){

    if (size == 1){
        return arr[0];
    }

    else{
        return arr[size - 1] + sum(arr, size - 1);
    }
}


/*********************************************************************
 ** Function: triangle
 ** Description: output sum of a mathematical triangle function
 ** Parameters: # of rows in the triangle
 *********************************************************************/
int triangle(int rows)
{
    if (rows == 1){
        return 1;
    }

    else{
        return rows + triangle(rows-1);
    }
}
