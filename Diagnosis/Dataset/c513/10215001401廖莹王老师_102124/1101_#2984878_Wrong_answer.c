#include <stdio.h>
#include <stdlib.h>
int read()
{
    char s[5];
    int x;
    scanf("%s",s);
    if(strcmp(s,"A+")==0)x=1;
    else if(strcmp(s,"A-")==0)x=2;
    else if(strcmp(s,"AB+")==0)x=3;
    else if(strcmp(s,"AB-")==0)x=4;
    else if(strcmp(s,"B+")==0)x=5;
    else if(strcmp(s,"B-")==0)x=6;
    else if(strcmp(s,"O+")==0)x=7;
    else if(strcmp(s,"O-")==0)x=8;
    else if(strcmp(s,"?")==0)x=0;
    return x;

}
void write(int l)
{
    if(l==1)printf("A+");
    if(l==2)printf("A-");
    if(l==3)printf("AB+");
    if(l==4)printf("AB-");
    if(l==5)printf("B+");
    if(l==6)printf("B-");
    if(l==7)printf("O+");
    if(l==8)printf("O-");

}
void xuexing(int h)
{
    const int abo[8][8][8]={1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,
    1,1,0,0,0,0,1,1,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0,1,
    1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
    1,1,1,1,1,1,0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,0,0,0,1,0,1,0,1,0,0,1,1,0,0,1,1,0,0,0,1,0,0,0,1,0,0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,
    1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,1,
    1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,
    1,1,0,0,0,0,1,1,0,1,0,0,0,0,0,1,1,1,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1
    };
    int pdabo[8]={0};
    int father,mother,child;
    father=read();mother=read();child=read();
    printf("case #%d:\n",h);
    if(father==0)
    {
        int i,count=0;
        for(i=0;i<8;i++)
        pdabo[i]=abo[i][mother-1][child-1];
         for(i=0;i<8;i++)
                if(pdabo[i]==1)count++;
        if(count==0)printf("impossible");
        else  if(count==1){for(i=0;i<8;i++)if(pdabo[i]==1)write(i+1);}
        else
        {
            printf("{");

            for(i=0;i<8;i++)
            {
                if(pdabo[i]==1)
                    {write(i+1);
                    if(count>1){printf(",");count--;}
                    }

            }
            printf("}");
        }
        printf(" ");write(mother); printf(" ");write(child);


    }
    if(mother==0)
    {
        int i,count=0;
        for(i=0;i<8;i++)
        pdabo[i]=abo[father-1][i][child-1];
        write(father); printf(" ");
         for(i=0;i<8;i++)
                if(pdabo[i]==1)count++;
         if(count==0)printf("impossible");
        else if(count==1){for(i=0;i<8;i++)if(pdabo[i]==1)write(i+1);}
        else
        {
             printf("{");

            for(i=0;i<8;i++)
            {
                if(pdabo[i]==1)
                  {
                      write(i+1);
                if(count>1){printf(",");count--;}
                  }
            }
            printf("}");
        }

        printf(" ");write(child);



    }
    if(child==0)
    {
        int i,count=0;
        for(i=0;i<8;i++)
        pdabo[i]=abo[father-1][mother-1][i];
         write(father); printf(" ");
         write(mother); printf(" ");
         for(i=0;i<8;i++)
            if(pdabo[i]==1)count++;
        if(count==0)printf("impossible");
        else if(count==1){for(i=0;i<8;i++)if(pdabo[i]==1)write(i+1);}
            else
            {
                 printf("{");
            for(i=0;i<8;i++)
            {
                if(pdabo[i]==1)
                {
                     write(i+1);
                if(count>1){printf(",");count--;}
                }

            }
            printf("}");
            }


    }
    printf("\n");
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)xuexing(h);
}
