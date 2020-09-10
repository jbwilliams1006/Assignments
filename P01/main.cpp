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
//       An adjustment to the stack class to add functionality. The program adjusts the pop method being called when the stack is empty, as well as resizes the array when the stack is full
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
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
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
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
        int mul;
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
       S2 = new int[2*size]; //creates new array equal to new capcity size
        for (int i=0; i<size; i++) //for loop to copy array data
          S2[i] = S[i];
      delete [] S;                  // deleting old array
      S = S2;                     // setting old array size to new array 
      int mul = 1;                  //Used to reduce stacks size
      capacity = size;
      }
        top++;              // move top of stack up
        size++;             // increment size
        S[top] = data;      // add item to array
       int mul = 0;         //Used to reduce stacks size

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
      if (size==0)
        {
          cout<<"Error: Stack empty!";
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
      if (size < capacity/2 && mul == 1 ) //if the stack gets below half full and
      {                                   //has been doubled then it gets resized
        capacity = capacity/2;
      }
    }

    /**
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty() {
        //return size == 0;
        return top == -1;
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() {
        return top == capacity - 1;
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     * 
     * Returns:
     *     void
     */    
    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }

};

int main() {
  
    Stack S1;           // calls default constructor
    Stack S2(3);       // calls overloaded constructor

    S2.Push(7); //Pushing in 4 elements in a stack size of 3
    S2.Push(4);
    S2.Push(8);
    S2.Push(5);
    
    S2.Print();
    cout << "Popped a: " << S2.Pop() << endl;
    cout << "Popped a: " << S2.Pop() << endl;
    cout << "Popped a: " << S2.Pop() << endl;
    cout << "Popped a: " << S2.Pop() << endl;
    cout << "Popped a: " << S2.Pop() << endl;
  
    
    // S1.Push(9);

    // //S1.Print();           // old way to print!
    // cout << S1 << endl;     // cool way to print


}
