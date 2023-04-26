#include <stdio.h>
#include <string.h>


int main()
{
    int count,count1;
    scanf("%d",&count);
    count1=count;
    int len;
    char S[100];

    while(count--)
    {
        int A[1000];int B[1000];
        for(int i;i<1000;i++)
        {
            A[i]=0;B[i]=0;
        }
        scanf("%s",S);
        len=strlen(S);
        char *p=S;
        int temp;
        int jishu=7,jishu1=7;
        if(len%3==0)
        {
            while(*p)
            {
                temp=*p;
                //printf("%d\n",temp);
                while(temp)
                {
                    A[jishu]=temp%2;
                    temp=temp/2;
                    jishu--;
                }
                p++;
                jishu1=jishu1+8;
                jishu=jishu1;
            }
            /*for(int i=0;i<24;i++)
        {
            printf("%d",A[i]);
        }*/
            int fuzhi=2,fuzhi1=2,i=0;
            while(i<len*8)
            {
                B[fuzhi]=A[i];
                //printf("%d!%d!%d\n",fuzhi,i,A[i]);
                i++;
                fuzhi++;

                if((i)%6==0)
                {
                    fuzhi1=fuzhi1+8;
                    fuzhi=fuzhi1;
                }
            }
            /*for(int i=0;i<32;i++)
        {
            printf("%d",B[i]);
        }*/
            int j=8,duandian=0,duandian1=0,sum=0;
            printf("case #%d:\n",count1-count-1);
            while(duandian1<len*8/6*8)
            {
                //printf("%d!%d\n",duandian,B[duandian]);
                sum=sum*2+B[duandian];
                duandian++;
                j--;

                if(j==0)
                {
                    //printf("%d",sum);
                    j=8;duandian1=duandian1+8;duandian=duandian1;
                    if(sum<=25)printf("%c",'A'+sum);
                    else if(sum<=51)printf("%c",'a'+sum-26);
                    else if(sum<=61)printf("%c",'0'+sum-52);
                    else if(sum==62)printf('+');
                    else if(sum==63)printf('/');
                    sum=0;
                }

            }
            printf("\n");

        }
        else
        {
            while(*p)
            {
                temp=*p;
                //printf("%d\n",temp);
                while(temp)
                {
                    A[jishu]=temp%2;
                    temp=temp/2;
                    jishu--;
                }
                p++;
                jishu1=jishu1+8;
                jishu=jishu1;
            }
            /*for(int i=0;i<24;i++)
        {
            printf("%d",A[i]);
        }*/
            int fuzhi=2,fuzhi1=2,i=0;
            while(i<len*8)
            {
                B[fuzhi]=A[i];
                //printf("%d!%d!%d\n",fuzhi,i,A[i]);
                i++;
                fuzhi++;

                if((i)%6==0)
                {
                    fuzhi1=fuzhi1+8;
                    fuzhi=fuzhi1;
                }
            }

            int j=8,duandian=0,duandian1=0,sum=0;
            printf("case #%d:\n",count1-count-1);
            while(duandian1<(len*8/6+1)*8)
            {
                //printf("%d!%d\n",duandian,B[duandian]);
                sum=sum*2+B[duandian];
                duandian++;
                j--;

                if(j==0)
                {
                    //printf("%d",sum);
                    j=8;duandian1=duandian1+8;duandian=duandian1;
                    if(sum<=25)printf("%c",'A'+sum);
                    else if(sum<=51)printf("%c",'a'+sum-26);
                    else if(sum<=61)printf("%c",'0'+sum-52);
                    else if(sum==62)printf('+');
                    else if(sum==63)printf('/');
                    sum=0;
                }



            }
            if(len%3==1)printf("==");
                else if (len%3==2)printf("=");
            printf("\n");
        }
    }
}
