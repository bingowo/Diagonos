#include<stdio.h>
#include<string.h>
int max(int s[],int n)
{
    int i = 0;
    while(i<n-1)
    {
       if(s[i] > s[i+1]) s[i+1] = s[i] , i++;
        else i++;
    }
    return s[i];
}

int main()
{
    int i,j = 0;
    char s[57];
    int k = 1,num[51];
    scanf("%s",s);
    if(strlen(s) == 1){printf("1");return 0;}
   else
   {
       for(i = 1; i < strlen(s); i++)
    {
        if(s[i] != s[i-1])k++;
        else {num[j] = k; j++; k = 1;}
    }
    num[j] = k;
    printf("%d",max(num,j+1));
   }
    return 0;
}
