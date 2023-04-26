#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//A:0 B:1 AB:2 O:3
const int ABO[4][4][4]={
1,0,0,1, 1,1,1,1, 1,1,1,0, 1,0,0,1,
1,1,1,1, 0,1,0,1, 1,1,1,0, 0,1,0,1,
1,1,1,0, 1,1,1,0, 1,1,1,0, 1,1,0,0,
1,0,0,1, 0,1,0,1, 1,1,0,0, 0,0,0,1};
char ans_ABO[4][3]={"A","B","AB","O"};
int read( char s[])
{
    int temp1=0;
    if(strcmp(s,"?")==0)
        temp1=-1;
    else if(strcmp(s,"A")==0)
        temp1=0;
    else if(strcmp(s,"B")==0)
        temp1=1;
    else if(strcmp(s,"AB")==0)
        temp1=2;
    else if(strcmp(s,"O")==0)
        temp1=3;
    return temp1;
}
int main()
{
    char s1[5],s2[5],s3[2];
    scanf("%s%s%s",s1,s2,s3);
    int mother,father,child;
    mother=read(s1);
    father=read(s2);
    child=read(s3);
    if(child==-1)
    {
        printf("%s %s {",s1,s2);
       // printf("%s,",ans_ABO[3]);
        int i=0;
        for(i=0;i<3;i++)
        {
            if(ABO[mother][father][i])
              printf("%s,",ans_ABO[i]);
        }
        if(ABO[mother][father][3])
                printf("%s",ans_ABO[i]);
        printf("}");
    }

}
