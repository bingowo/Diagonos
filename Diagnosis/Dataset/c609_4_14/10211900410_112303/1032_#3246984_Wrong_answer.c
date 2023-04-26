#include<stdio.h>
#include<string.h>
int main()
{
    char s[50];
    scanf("%s",&s);
    int l=1,k=0;
    int L[50]={1};
    for(int i=1;i<strlen(s);i++){
        if(s[i]!=s[i-1]) l++;
        else{
            L[k++]=l;
            l=1;
        }
    }
    int max=L[0];
    for(int i=0;i<k;i++){
        if(L[i]>max) max=L[i];
    }
    printf("%d",max);
    return 0;
}
