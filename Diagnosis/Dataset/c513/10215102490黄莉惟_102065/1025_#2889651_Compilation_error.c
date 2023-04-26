#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct {
    char letter[20];
} WORD;
int count(char *s){
    int i=0;
    int num;
    int sum=0;
    int ret=0;
    for(i=0;i<strlen(s);i++){
        sum=0;
        num=s[i];
        for(j=0;j<strlen(s);j++){
            if(s[j]==num){
                sum++;
            }
        }
        if(sum==1){
            ret++;
        }
    }
    return ret;
}
long long comp(int *s1,int *s2){
    WORD v1=*(WORD*)s1;
    WORD v2=*(WORD*)s2;
    int number1=count(s1);
    int number2=count(s2);
    if(number1==number2)
        return strcmp(s1,s2);
    else
		return number1-number2;
    
}
/********** Specification of Input **********/
void Input(WORD a[],int n)
{ 
   int i=0;
   while(n>0){
      int num;
      scanf("%s",a[i].letter); 
      i++;
      n--;
       
    }
    
    
}

/********** Specification of Sort **********/
void Sort(WORD *ps, int n)
{ 
    qsort(ps,n,sizeof(ps[0]),comp);
}

#include <stdio.h>
#define N 100000

int main() {
    int i,n,t,j;
    scanf("%d\n", &t);
    for(i=0;i<t;i++){
        scanf("%d\n", &n);
        WORD a[n];
        Input(a,n);
        Sort(a, n);
        for (j = 0; j < n; j++)
        printf("%s\n", a[j].letter);
        
    }
    return 0;

    
}  
