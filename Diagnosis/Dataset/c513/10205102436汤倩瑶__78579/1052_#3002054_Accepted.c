#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{int T;
scanf("%d",&T);
char s[25];

for(int i=0;i<T;i++)
{
    scanf("%s",s);
   // printf("%s",s);
    int a[128]={0};
    int ans[10]={0};
int l=strlen(s);
//printf("%d",l);
    for(int j=0;j<l;j++)
    {
        a[s[j]]+=1;
        //a[j]=j;
    }
   /* for(int j=0;j<128;j++)
    {
       printf("%d",a[j]);
    }*/
   /* two:w
    four:u  five:F
    six:x  seven:S
    eight:g three:H
zero:z
    one:O
    nine:I*/
if(a['Z']>0)
    {
        a['E']-=a['Z'];
        a['O']-=a['Z'];
        a['R']-=a['Z'];
        ans[0]+=a['Z'];
        a['Z']-=a['Z'];
    }
    if(a['W']>0)
    {
        a['T']-=a['W'];
        a['O']-=a['W'];
        ans[2]+=a['W'];
        a['W']-=a['W'];
    }
    if(a['U']>0)
    {
        a['F']-=a['U'];
        a['O']-=a['U'];
        a['R']-=a['U'];
        ans[4]+=a['U'];
        a['U']-=a['U'];
    }
     if(a['X']>0)
    {
        a['S']-=a['X'];
        a['I']-=a['X'];

        ans[6]+=a['X'];
        a['X']-=a['X'];
    }
     if(a['G']>0)
    {

        a['E']-=a['G'];
        a['I']-=a['G'];

        a['H']-=a['G'];
        a['T']-=a['G'];
        ans[8]+=a['G'];
        a['G']-=a['G'];
    }
    if(a['F']>0)
    {


        a['I']-=a['F'];
        a['V']-=a['F'];
        a['E']-=a['F'];
        ans[5]+=a['F'];
        a['F']-=a['F'];
    }
    if(a['S']>0)
    {


        a['E']-=a['S'];
        a['V']-=a['S'];
        a['E']-=a['S'];
        a['N']-=a['S'];
        ans[7]+=a['S'];
        a['S']-=a['S'];
    }
    if(a['T']>0)
    {


        a['H']-=a['T'];
        a['R']-=a['T'];
        a['E']-=a['T'];
        a['E']-=a['T'];
        ans[3]+=a['T'];
        a['T']-=a['T'];
    }
    if(a['O']>0)
    {


        a['N']-=a['O'];
        a['E']-=a['O'];

        ans[1]+=a['O'];
         a['O']-=a['O'];
    }
    if(a['I']>0)
    {

        a['N']-=a['I'];

        a['N']-=a['I'];
        a['E']-=a['I'];
        ans[9]+=a['I'];
         a['I']-=a['I'];
    }

    printf("case #%d:\n",i);
    for(int j=0;j<10;j++)
    {

            for(int k=0;k<ans[j];k++)
            {
                printf("%d",j);
            }


    }

    printf("\n");
}
return 0;
}


