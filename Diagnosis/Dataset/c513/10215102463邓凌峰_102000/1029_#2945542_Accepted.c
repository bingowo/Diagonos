#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>





int main()
{
    int n;scanf("%d",&n);
    char start=getchar();
    for(int i=0;i<n;i++){
        int zm[26]={0},index=0;
        char s[201];
        gets(s);
        char *p=s;
        while(*p){
            if(isalpha(*p)) zm[*p-'A']+=1;
            p++;
        }
        p=s;
        printf("case #%d:\n",i);
        for(;zm[index]==0;index++);
        while(*p){
            if(isalpha(*p)){
                *p=index+'A';
                zm[index]--;
                for(;zm[index]==0;index++);

            }
            p++;
        }
        printf("%s\n",s);
    }
    return 0;
}







