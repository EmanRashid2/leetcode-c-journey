#include <stdbool.h>
#include <string.h>

bool isValid(char * s){
    int len = strlen(s);
    char stack[len];  // use array as stack
    int top = -1;     // stack pointer

    for(int i = 0; i < len; i++){
        char c = s[i];

        if(c == '(' || c == '{' || c == '['){
            stack[++top] = c;  // push opening bracket
        } else {
            if(top == -1) return false; // stack empty, no matching opening
            char open = stack[top--];   // pop top
            if((c == ')' && open != '(') ||
               (c == '}' && open != '{') ||
               (c == ']' && open != '[')){
                return false;
            }
        }
    }

    return top == -1; // stack should be empty if valid
}

