#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};

int Readnumber(int temp[],int input[])
{
    int i=0;
    char ch;
    do{
        scanf("%d",&temp[i++]);
        ch=getchar();
    }while(ch==',');
    int tag=25;
    int count=i;
    while(i>0)
    {
        input[tag--]=temp[i-1];
        i--;
    }
    /*for(int j=tag+1;j<26;j++)
    {
        printf("%d ",input[j]);
    }
    printf("\n");
    printf("%d\n",count);*/
    return count;
}


void ADD(int a[],int b[],int c[],int anumber,int bnumber)
{
    int tag=25;
    while(1){
        int x=a[tag]+b[tag]+c[tag];
        int y=prime[tag];
        /*printf("%d %d ",x,y);*/


           c[tag]=x%y;

          c[tag-1]=x/y;
          tag--;
       anumber--;
        bnumber--;
       /* printf("%d %d \n",c[tag],c[tag-1]);*/

     if(anumber<=0&&bnumber<=0)
     {
         /*printf("%d %d\n",anumber,bnumber);*/
         break;
     }
    }

}

void output(int c[])
{
    int temp=0;
    while(c[temp]==0)
    {
        temp++;
    }
    /*printf("%d\n",temp);*/

    for(;temp<25;temp++)
    {
        printf("%d,",c[temp]);
    }
    if(temp==26)
    {
        printf("0\n");
    }
    else{
            printf("%d\n",c[temp]);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int tag=0;tag<T;tag++)
    {
        printf("case #%d:\n",tag);
        int temp[100];
        int a[26]={0};
        int b[26]={0};
        int c[26]={0};

        int anumber=Readnumber(temp,a);

        int bnumber=Readnumber(temp,b);
        ADD(a,b,c,anumber,bnumber);
        output(c);

    }
}
