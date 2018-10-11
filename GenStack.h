/* Generic Stack Implementation */

#include <iostream>
#include <fstream>
//#include "fileScanner.h"

template <class T>
class GenStack
{
  private:

  public:

    GenStack(); //default constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack();

    void push(T d);
    char pop();
    char peek();

    bool isFull();
    bool isEmpty();

    int getSize(); //return size
    void resize(); //double size of stack if full
    //void print(); //prints out the stack

    int size;
    int top;

    T *myArray;
};

using namespace std;

//constructor
template <class T>
GenStack<T>::GenStack()
{

}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize) //overload constructor
{
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

//destructor
template <class T>
GenStack<T>::~GenStack()
{
  delete myArray;
  cout << "Stack Deleted." << endl;
}

//
template <class T>
void GenStack<T>::push(T d)
{
  //if stack is full
  if (top == size -1)
  {
    resize();
  }

  myArray[++top] = d; //puts d to the top of the stack
}

template <class T>
char GenStack<T>::pop()
{
  //error check
  //check if stack is empty
  if (top == -1)
  {
    cout << "Sorry, the stack is empty." << endl;
    return 0;
  }
  else
  {
    //remove rop element
    return myArray[top--];
  }
}

template <class T>
char GenStack<T>::peek()
{
  return myArray[top];
}

template <class T>
bool GenStack<T>::isFull()
{
  return (top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}

template <class T>
int GenStack<T>::getSize()
{
  return size;
}

template <class T>
void GenStack<T>::resize()
{
  T* temp = new T[size];
  temp = myArray;

  delete myArray;

  myArray = new T[size * 2];
  myArray = temp;

  delete temp;
}

// template <class T>
// void GenStack<T>::print()
// {
//   while( !myArray.isEmpty() )
//   {
//      cout << myArray.top() << " " << endl;
//      myArray.pop();
//   }
// }
