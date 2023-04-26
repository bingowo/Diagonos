#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

int table[130]={0};

int main()
{
    char s[N]={0};
    scanf("%s",s);
    int len=strlen(s),max=0,start=0;
    for(int i=0;i<len;i++){
        memset(table,0,sizeof(table));
        int k=0,l=0;
        for(int j=i;j<len && k<70;j++){
            if(table[s[j]]==0){
                table[s[j]]++;
                l++;
                k++;
            }
            else
                break;
        }
        if(l>max){
            max=l;
            start=i;
        }
    }
    //printf("%d%d",start,max);
    for(int i=start,j=0;j<max;j++){
        printf("%c",s[i+j]);
    }
    return 0;
}

