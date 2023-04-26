#include <stdio.h>
#include <stdlib.h>
int read()
{
    char s[3];
    int x;
    scanf("%s",s);
    if(strcmp(s,"A")==0)x=1;
    else if(strcmp(s,"AB")==0)x=2;
    else if(strcmp(s,"B")==0)x=3;
    else if(strcmp(s,"O")==0)x=4;
    else if(strcmp(s,"?")==0)x=0;
    return x;

}
void write(int l)
{
    if(l==1)printf("A");
    if(l==2)printf("AB");
    if(l==3)printf("B");
    if(l==4)printf("O");

}
int main()
{
    const int abo[4][4][4]={1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1};
    int pdabo[4]={0};
    int father,mother,child;
    father=read();mother=read();child=read();
    if(father==0)
    {
        int i,count=0;
        for(i=0;i<4;i++)
        pdabo[i]=abo[i][mother-1][child-1];
         for(i=0;i<4;i++)
                if(pdabo[i]==1)count++;
        if(count==0)printf("impossible");
        else
        {
            printf("{");

            for(i=0;i<4;i++)
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
        for(i=0;i<4;i++)
        pdabo[i]=abo[father-1][i][child-1];
        write(father); printf(" ");
         for(i=0;i<4;i++)
                if(pdabo[i]==1)count++;
         if(count==0)printf("impossible");
        else
        {
            printf("{");

            for(i=0;i<4;i++)
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
        for(i=0;i<4;i++)
        pdabo[i]=abo[father-1][mother-1][i];
         write(father); printf(" ");
         write(mother); printf(" ");
         for(i=0;i<4;i++)
            if(pdabo[i]==1)count++;
        if(count==0)printf("impossible");
        else
        {
            printf("{");
            for(i=0;i<4;i++)
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
    return 0;
}
