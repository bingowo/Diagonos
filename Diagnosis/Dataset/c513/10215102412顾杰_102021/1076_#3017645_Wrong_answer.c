#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char c;
        int st=0,a[201]={0},p=0;
        while((c=getchar())!='\n')
        {
            //printf("%d",st);
            a[p++]=st;
            switch(st)
            {
            case -1:
                break;
            case 0:
                if(c=='(')st=1;
                if(c=='[')st=2;
                if(c=='{')st=3;
                break;
            case 1:
                if(c==')')st=a[p-=2];
                else if(c=='{')st=3;
                else st=-1;
                break;
            case 2:
                if(c==']')st=-1;
                else if(c=='('){st=1;a[p-1]=4;}
                else st=-1;
                break;
            case 3:
                if(c=='}')st=-1;
                else if(c=='['){st=2;a[p-1]=5;}
                else st=-1;
                break;
            case 4:
                if(c==']')st=a[p-=2];
                else if(c=='(')st=1;
                else st=-1;
                break;
                break;
            case 5:
                if(c=='}')st=a[p-=2];
                else if(c=='[')st=2;
                else st=-1;
                break;
                break;
            }
        }
        //printf("\n");
        //for(int j=0;j<10;j++)printf("%d",a[j]);
        if(st==0)printf("Yes\n");
        else printf("No\n");
    }
    
}
