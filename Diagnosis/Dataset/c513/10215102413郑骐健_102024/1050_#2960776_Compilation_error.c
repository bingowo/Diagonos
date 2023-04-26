#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  num 501


    int find (char *p1,char *p2)
    {
        for(int i=0;i<=strlen(p2)-strlen(p1);i++)
        {
            int k;
            for( k=0;k<strlen(p1);k++)
            {
                if(p1[k]!=p2[i+k])break;
            }
            if(k==strlen(p1))return i;
        }
        return -1;

    }
    int find2(char *p1,char*p2)
    {
        for(int i=strlen(p2)-1;i>=strlen(p1)-1;i--)
        {
            int k;
            for(k=0;k<strlen(p1);k++)
            {
                if(p1[strlen(p1)-k-1]!=p2[i-k])break;
            }
        if(k==strlen(p1))return i;
        }
        return -1;
    }
    int main()
    {
    int t ;
    scanf("%d",&t);
    for(int i =0;i<t;i++)

    {
        printf("case #%d:\n",i);
        char s1[80];
        char s2[80];
        char s[80];
        scanf("%s%s%s",s1,s2,s);
        char*p1,*p2;
        int point1 = find(s1,s);
        point1+=strlen(s1)-1;
        int point2=find(s2,s);
        if(point1==-1||point2==-1)
        {
            printf("0\n");
        }
        else{
        int tail2 = find2(s2,s);
        tail2=tail2-strlen(s2)+1
        int max =tail2 - point1;
        printf("%d\n",max);
    }}
    return 0;
    }
