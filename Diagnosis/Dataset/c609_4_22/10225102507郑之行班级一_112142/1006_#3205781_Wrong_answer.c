#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;scanf("%d",&T);
    int asc[150];
    int cal[61];
    int val,out;
    char in[61];
    for (int i=0;i<T;i++)
    {
        val=0,out=0;
        for(int i=0;i<150;i++)asc[i]=-1;
        for(int i=0;i<61;i++)cal[i]=-1;
        scanf("%s",&in);

        if(in[0]=='0' && in[1]=='\0'){printf("case #%d:\n0\n",i);continue;}

        for(int j=0;in[j]!='\0';j++)
        {
            if(asc[in[j]]==-1)
                asc[in[j]]=(val++);
            cal[j]=asc[in[j]];
            //printf("asc=%d\ncal=%d\nj=%d\n",asc[in[j]],cal[j],j);
        }

        for(int j=0;cal[j]!=-1;j++)
        {
            if (val==1)val++;
            if (cal[j]==0)out=out*val+1;
            else if (cal[j]==1)out=out*val+0;
            else out=out*val+cal[j];
        }
        printf("case #%d:\n%d\n",i,out);
    }
    return 0;
}
