#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("begincorrect:%d\n",i);  //test
        int stu,ques,pass;
        scanf("%d %d %d",&stu,&ques,&pass);
        int stuscore[103]={0};
        int quesscore[13]={0};
        char stunum[101][14]={'0'};
        for(int j=1;j<ques+1;j++)
            scanf("%d",&quesscore[j]);
        for(int j=1;j<stu+1;j++)
        {
            scanf("%s",&stunum[j]);
            int seikai;
            scanf("%d",&seikai);
            for(int k=0;k<seikai;k++)
            {
                int seikaibangou;
                scanf("%d",&seikaibangou);
                stuscore[j]+=quesscore[seikaibangou];
            }
        }
        printf("case #%d:\n",i);
        int gougakunum=0;
        for(int j=1;j<stu+1;j++)
        {
            if(stuscore[j]>=pass)
                gougakunum++;
            else
                stuscore[j]=-1;
        }
        printf("%d\n",gougakunum);
        for(int j=0;j<gougakunum;j++)
        {
            int max=1;
            for(int k=1;k<stu+1;k++)
            {   if(stuscore[max]==-1)
                    {max++;continue;}
                if(k==max)
                    continue;
                if(stuscore[k]>stuscore[max])
                    max=k;
                else if((stuscore[k]==stuscore[max])&&(atoi(stunum[k])<atoi(stunum[max])))
                    max=k;
            }
            printf("%s %d\n",stunum[max],stuscore[max]);
            stuscore[max]=-1;
        }
        printf("endcorrect:%d\n",i);  //test
    }
    return 0;
}
