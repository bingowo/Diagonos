#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double flag[100];

int cmp(char a,char b){
    if(flag[a-'A']==flag[b-'A']){
        if(a!=b && abs(a-b)!=32) return a-b;
        else return b-a;
    }
    else return flag[b-'A']-flag[a-'A'];
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        for(int j=0;j<26;j++){
            double m;
            scanf("%f",&m);
            flag[j]=flag[j+32]=m;
        }
        char s[100]={0};
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
