#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LEN 1100

void Count(int c[],char w[],int n)
{
    for (int i=0; i<n; i++) {
        if(i==0){
            if(w[i]!=w[i+1]){
                c[i]=2;
            }
            else{
                c[i]=1;
            }
        }
        else if(i==n-1){
            if(w[i-1]!=w[i]){
                c[i]=2;
            }
            else{
                c[i]=1;
            }
        }
        else{
            if(w[i-1]!=w[i]&&w[i]!=w[i+1]&&w[i-1]!=w[i+1]){
                c[i]=3;
            }
            else if(w[i-1]!=w[i]||w[i]!=w[i+1]){
                c[i]=2;
            }
            else{
                c[i]=1;
            }
        }
    }
}

void add(int a[],int b[])
{
    for (int i=LEN-1; i; i--) {
        a[i]+=b[i];
        for (int k=i; a[k]>=10; k--) {
            a[k]%=10;
            a[k-1]+=1;
        }
    }
}

void multi(int a[],int n)
{
    int temp[LEN];
    memmove(temp, a, sizeof(temp));
    for (int i=1; i<n; i++) {
        add(a, temp);
    }
}

int main(void)
{
    char w[LEN];
    scanf("%s",w);
    int lenth=strlen(w);
    int choice[len];
    if(lenth==1){
        choice[0]=1;
    }
    else{
        Count(choice, w, lenth);
    }
    int a[LEN] = {[LEN-1]=1},idx=0;
    for (int i=0; i<lenth; i++) {
        multi(a, choice[i]);
    }
    for (idx=0; a[idx]==0; idx++);
    for (; idx<len; idx++) {
        printf("%d",a[idx]);
    }
    return 0;
}
