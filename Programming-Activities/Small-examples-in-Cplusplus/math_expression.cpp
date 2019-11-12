/* It verifies if a sequence of parentheses and square brackets in a mathematical expression is correct
    To compile it in Linux (terminal): g++ -o program math_expression.cpp
    To run it in Linux (terminal): ./program
*/

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int wellDone(char s[], int n);

main(){
    char sequence[50];
    strcpy(sequence,"((2+3)())()");
    int result = wellDone(sequence,11);
    cout << "Result: " << result << endl;
}

// Return 1 if the string s contains a well-done sequence of parentheses and square brackets and return 0 if it's not
int wellDone(char s[], int n){
   char stack[n];
   int t,i;
  
   t = 0;
   for (i = 0; i < n; ++i) {
      switch (s[i]) {
         case ')': if (t != 0 && stack[t-1] == '(') 
                      --t;
                   else return 0;
                   break;
         case ']': if (t != 0 && stack[t-1] == '[') 
                      --t;
                   else return 0;
                   break;
        case '(': stack[t++] = s[i];
                   break;
        case '[': stack[t++] = s[i];
                   break;
//         default:  stack[t++] = s[i];
      }
   }
   return t == 0;
}
