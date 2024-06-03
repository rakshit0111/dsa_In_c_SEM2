#include<stdio.h>
#include<string.h>
char stack [1000];
int isinibrac(char c)
{
    return (c == '[' || c == '{' || c == '(' );
    
}
int islastbrac(char c)
{
    return (c == ')' || c == '}' || c ==']');
}
int ismatches(char ch , char chr)
{
    return ((ch == '(' && chr ==')') || (ch == '{' && chr =='}') || (ch == '[' && chr ==']'));
}
int isBalanced(char* exp)
{
    
    int top = -1;
    for (int i = 0; exp[i]!='\0'; i++)
    {
        
        if (isinibrac(exp[i]))
        {
            stack[++top] = exp[i];
        }
        else if (islastbrac(exp[i]))
        {
            if (top == -1 || !ismatches(stack[top],exp[i]))
            {
                return 0;
                /* code */
            }
            else
            {
                top --;
            }
            /* code */
        }
        
        
        /* code */
    }
    return 1;
}

int main()
{
    char exp[100];
    printf("Enter the expression\n");
    fgets(exp,sizeof(exp),stdin);
    if (exp[strlen(exp)-1]=='\n')
    {
        exp[strlen(exp)-1] = '\0';
        /* code */
    }
    
    if(isBalanced(exp))
    {
        printf("BALANCED\n");
    }
    else
    {
        printf("NOT BALANCED\n");
    }
    return 0;
}
