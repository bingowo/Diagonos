#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int deletee(char*p1,char*p2)//将删后的结果储存在P2中
{
    int judge =1;
    int length = strlen(p1);
    int n = 0;
    for(int i= 1;i<length;i++)
    {
        if(p1[i] == p1[i-1])
        { judge =0;
            continue;

        }
        else if(!judge)
        {
            judge =1;
            continue;
        }
        else {
            judge =1;
                p2[n++] = p1[i-1];
            }
    }
    if(p1[length-2]!=p1[length-1])p2[n++] = p1[length-1];
    p2[n]='\0';
    if(n!=length )return 1;
    else return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        int max = 0;
        char now[150];
        scanf("%s",now);
        printf("case #%d:\n",i);
        int length1 = strlen(now);
        if(length1 == 1)
        {printf("2\n");
        continue;
        }
        int lenghth2 ;//储存最小结果
        for(int g= 0;g<=length1;g++)
        {
            char p[150];

            for(int z =0;z<g;z++)
            {
                p[z] = now[z];
            }

            for(int q =0;q<3;q++)
            {
                p[g] = 'A'+q;
            for(int z = g;z<length1;z++)
            {
                p[z+1] = now[z];
            }//进行某种情况下的复制

            p[length1+1] = '\0';
            char next[150];
            char next2[150];
            strcpy(next,p);
            while(deletee(next,next2))
            {
                strcpy(next,next2);
            }
            int length2=strlen(next2);
            max = (max<length1-length2+1)?length1-length2+1:max;

            }
        }
            printf("%d\n",max);
    }


    return 0;
}
