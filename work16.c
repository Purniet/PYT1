/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
Input: "()[]{}"
Output: true
Input: "([)]"
Output: false
Input: "{[]}"
Output: true
*/
#include <stdio.h>
#include <stdlib.h>
#define N 200

int main()
{
    char a[N], c[N];
    int b[N] = {0}, i, j = 0, tag = 1;
    printf("Input your string:\n");
    gets(a);
    for(i = 0 ; i < N && a[i] != '\0' ; i++)
    {
        if(a[i] == '(')
        {
          b['(']++;
          c[j++] = a[i];
        }
        if(a[i] == '[')
        {
            b['[']++;
            c[j++] = a[i];
        }
        if(a[i] == '{')
            {
               b['{']++;
               c[j++] = a[i];
            }

        if(a[i] == ')')
        {
            if(c[--j] != '(') tag = 0;
            b[')']++;
        }

        if(a[i] == ']')
        {
            if(c[--j] != '[') tag = 0;
            b[']']++;
        }

        if(a[i] == '}')
        {
            if(c[--j] != '{') tag = 0;
            b['}']++;
        }


        if(b['('] < b[')'] || b['['] < b[']'] || b['{'] < b['}'] ) tag = 0;
    }
    if(b['('] != b[')'] || b['['] != b[']'] || b['{'] != b['}']) tag = 0;
    if(tag == 1) printf("\ntrue");
    else printf("\nfalse");

    return 0;
}
