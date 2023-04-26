#include <stdio.h>
#include <string.h>

int main()
{
    int count,count1,temp;
    scanf("%d",&count);
    count1=count;
    int SU[]={2,3,5,7,11,13,17,19,23,27,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int i=0,len1,len2,jinwei=0,len3;

    while(count--)
    {

        char A[50];
        char B[50];
        int z=0;
        int sign=1;
        int a=0,b=0;
        int C[100];
        for(int k=0;k<100;k++)
        {
            C[k]=0;
        }
        int* p3=C;
        scanf("%s",A);
        scanf("%s",B);
        char* p1=A;
        char* p2=B;
        len1=strlen(A);
        len2=strlen(B);
        p1=A;p2=B;p3=C;
        p1=p1+len1-1;
        p2=p2+len2-1;
        while(p1>=A||p2>=B)
        {
            if(p1<A||p2<B)
            {
                if(p1<A)
                {
                    if(*p2==',')
                    {
                    p2--;
                    }
                    while(*p2!=','&&p2>=B)
                    {
                       b=b*10+*p2-'0';
                       p2--;
                       z++;
                    }
                    if(b>=10||z==2)
                    {
                        b=(b%10)*10+(b/10);
                        z=0;
                    }


                *p3=b;
                p3++;
                p2--;
                b=0;
                z=0;
                }
                if(p2<B)
                {
                    if(*p1==',')
                {
                    p1--;}
                    while(*p1!=','&&p1>=A)
                    {
                       a=a*10+*p1-'0';
                       p1--;
                       z++;
                    }
                    if(a>=10||z==2)
                    {
                        a=(a%10)*10+(a/10);
                        z=0;
                    }


                *p3=a;
                p3++;
                p1--;
                a=0;
                z=0;

                }

            }
            else
            {
                a=*p1-'0';
                b=*p2-'0';
                if(*p1==',')
                {

                    p1--;
                    a=0;
                    while(*p1!=','&&p1>=A)
                    {
                       a=a*10+*p1-'0';
                       p1--;
                       z++;
                    }
                    if(a>=10||z==2)
                    {
                        a=(a%10)*10+(a/10);
                        z=0;
                    }
                    z=0;

                }
                if(*p2==',')
                {
                    p2--;
                    b=0;
                    while(*p2!=','&&p2>=B)
                    {
                       b=b*10+*p2-'0';
                       p2--;
                       z++;
                    }
                    if(b>=10||z==2)
                    {
                        b=(b%10)*10+(b/10);
                        z=0;
                    }
                }
                *p3=a+b;
                /*printf("%c!!!!\n",*p1);
                printf("%c!!!!\n",*p2);
                printf("%d!!!!\n",*p3);*/
                p3++;
                p1--;
                p2--;
                a=0;
                b=0;
                z=0;
            }

        }

        /*for(int k=0;k<100;k++)
        {
            printf("%d",C[k]);
        }
        printf("\n");*/

        len3=p3-C;

        while(i<len3+1)
        {
            temp=C[i];
            C[i]=(C[i]+jinwei)%SU[i];
            jinwei=(temp+jinwei)/SU[i];
            /*printf("?%d?",jinwei);*/
            i++;
        }
        len3=i;

        /*for(int k=0;k<100;k++)
        {
            printf("%d",C[k]);
        }*/

        printf("case #%d:\n",count1-count-1);
        int j=len3-1;

        while(j>=0)
        {
            if(j==len3-1)
            {
                if (C[j]!=0)
                {
                    sign=-1;
                }
                else if(j==0)
                {
                    printf("%d\n",C[j]);
                }
            }
            while(sign!=-1&&C[j]==0)
            {
                /*printf("wdwadadasd");*/
                j--;
            }
            sign=-1;
            if(j==0)
            {
                printf("%d\n",C[j]);
                j--;
            }
            else
            {
            printf("%d",C[j]);
            printf(",");
            j--;
            }

        }
        jinwei=0;
        i=0;

    }
}
