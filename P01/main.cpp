///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Joshua Williams
// Email:            jbrockwilliams@gmail.com
// Label:            P01
// Title:            Program 1 Stack Upgrade 
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       An adjustment to the stack class to add functionality. The program adjusts the pop method being called when the stack is half empty, as well as resizes the array when the stack is full
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       input.txt
//       P01 Output
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

/**
 * Stack
 * 
 * Description:
 *      Integer array based stack implementation
 * 
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - void Print()
 *      - int capa ()
 *      - int maximum ()
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *  Stack S;
 *  S.Push(value);
 *  S.Pop;
 *  S.capa();
 *  S.maximum();
 *      
 */
class Stack {
private:
    int *S;       //array pointer
    int *S2;      //second array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
    int mul;      //Used to reduce stacks size
    int max;      //keeps track of max capacity
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     * 
     * Returns:
     *     Void
     */
    Stack() {
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        mul = 0;
        max = 0;                //sets max to 0
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     * 
     * Returns:
     *     Void
     */
    Stack(int cap) {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
        mul = 0;
        max = 0;                //sets max to 0
    }

    /**
     * Push:
     *    Push item onto stack. Also checks to see if the stack is full and if so it re-sizes the stack 
     * Params:
     *    int : data
     * 
     * Returns:
     *     Void
     */
    void Push(int data) {
      if(size == capacity)
      {
       int *S2 = new int[2*size]; //creates new array equal to new capcity size
        for (int i=0; i<size; i++) //for loop to copy array data
          S2[i] = S[i];
      delete [] S;                  // deleting old array
      S = S2;                     // setting old array size to new array 
      mul++;                  //Used to reduce stacks size
      capacity = size*2; //doubles the size of the capacity
      cout<<"\n+ : "<<left<< setw(2)<<(size/2)<<" -> "<<size; //displays addition in stack size 
        if (capacity>max)
          {
            max = capacity; //sets max to largest capacity  
          }
      } 
        top++;              // move top of stack up
        size++;             // increment size
        S[top] = data;      // add item to array

    }

    /**
     * Pop:
     *    remove item from stack. Also check to see if stack is empty and if so to report empty stack to user.
     * Params:
     *    void
     * 
     * Returns:
     *     int
     */
    int Pop() {
      if (size < (capacity/2) && mul > 0 ) //if the stack gets below half full and
      {                                   //has been doubled then it gets resized
        capacity = capacity/2;
        cout<<"\n- : "<<left<< setw(2)<<capacity*2<<" -> "<<capacity; //displays when a downsizing in the array occurs
      }
      if (size==0)
        {
          cout<<"Error: Stack empty!\n";
          int data = -1;
          return data;
        }
      else 
      { 
        int data = S[top];  // pull item from stack
        top--;              // shrink the stack
        size--;             // update our size
        return data;        // send item back
      }
      
    }

    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }

    int capa() //function to get the size of the stack 
    {
      return capacity;
    }

    int maximum() //function to return max capacity
    {
      return max;
    }

};

int main() {
Stack S1;
ofstream outfile;
outfile.open ("P01 Output");

outfile << "Name: Joshua Williams \n"
        << "Program: P01 \n"
        << "Date: 15 Sep 2020\n\n"
        << "Start Size: "
        << S1.capa() <<endl; //Prints out the starting capacity size

ifstream fin;
    string command;
    int value;

    fin.open("input.txt");
    while(!fin.eof())
    {
        fin>>command;           // read push or pop  
        cout<<command<<" "; 


        if(command == "push"){  // if command is a push we need
            fin>>value;         // to read a value in as well
            cout<<value;
            S1.Push(value); //pushes value from input file into stack   
        }
        if(command == "pop")
        {
          S1.Pop();//pops value from stack
        }
        
        cout<<endl;
    }

outfile <<"Max Size: "<< S1.maximum()<<endl; //Calls maximum capacity value
outfile <<"Ending size: "<< S1.capa(); // Calls ending capacity value
return 0;
}
