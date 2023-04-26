#include<stdio.h>
#include<string.h>
int main(){
    char str[110][31];
    int count=0;
    int i=0; 
    while(scanf("%s",str[count])!=EOF)
    {  count++;
       printf("%s",str[count]) ;
    }
    
}
