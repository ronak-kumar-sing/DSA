#include <iostream>
using namespace std;

//* Functions are set of code which performs somethings
//* Functions are used to modularise code -> breakdown the code into small , manageable and independent modules
//* Function are used to ⬆️es the readability
//* Function are used to use the same code multiple time's

//* Type of Functions
//* void -> which does'nt return anything
//* return -> it return something according to functions type
//* parameterised -> like 'returnType function(parameterDataType parameter)';
//* non-parameterised

//* pass by value -> when the copy send to function and no any change the origanal
// void change(int num)
// {
//   num += 5;
//   cout << num << endl;
//   num += 5;
//   cout << num << endl;
//   num += 5;
//   cout << num << endl;
// }
// int main()
// {
//   int num = 10;
//   change(num);
//   cout << num << endl;
//   return 0;
// }

//* pass by reference -> when the value it self the send to function and the change perform on original one
//* whenever '&' this mean the value's address will be take by the variable
// void change(int &num)
// {
//   num += 5;
//   cout << num << endl;
//   num += 5;
//   cout << num << endl;
//   num += 5;
//   cout << num << endl;
// }
// int main()
// {
//   int num = 10;
//   change(num);
//   cout << num << endl;
//   return 0;
// }

//! Note :- Array generally pass by reference without using '$' this
