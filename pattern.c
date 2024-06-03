#include<stdio.h>
int main()
{
    int n ;
    int x =1;
    printf("enter value of n ");
    scanf("%d",&n);
for (int i = 1; i <=n; i++)
{
    for (int k = 1; k < i; k++)
    {
        printf(" ");
        /* code */
    }
    for (int j =n; j >= i ; j--)
    {
        printf("*");
        /* code */
    }
    
    printf("\n");
    /* code */
}
for (int i = 1; i <=n-1; i++)
{
    for (int k = n-1; k > i; k--)
{
    printf(" ");
    /* code */
}
for (int j = 2; j >= x; j--)
{
    printf("*");
    /* code */
}
x--;
printf("\n");
}

}
