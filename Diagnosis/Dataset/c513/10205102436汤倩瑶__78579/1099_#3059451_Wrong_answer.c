#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    char s[1001];
    char *a[36]= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    for(int i=0; i<T; i++)
    {
        printf("case #%d:\n",i);
        scanf("%s",s);
        printf("%s",s);
        

    }



}
