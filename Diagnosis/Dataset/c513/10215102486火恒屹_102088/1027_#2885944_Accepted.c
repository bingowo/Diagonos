#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define PI acos(-1)

int main()
{
    int quesnum;
    scanf("%d",&quesnum);
    for(int i=0;i<quesnum;i++)
    {
        printf("case #%d:\n",i);
        int kazu;
        scanf("%d",&kazu);
        double length[1002]={0};
        double angle[1002]={0};
        for(int j=0;j<kazu;j++)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            length[j]=sqrt(x*x+y*y);
            angle[j]=atan(y/x);
            if((x==0)&&(y>0))
                angle[j]=PI/2;
            else if((x==0)&&(y<0))
                angle[j]=PI*3/2;
            else if((x<0)&&(y==0))
                angle[j]=PI;
            else if((x<0)&&(y>0))
                angle[j]+=PI;
            else if((x<0)&&(y<0))
                angle[j]+=PI;
            else if((x>0)&&(y<0))
                angle[j]+=2*PI;
            else if((x>0)&&(y==0))
                angle[j]=0;
        }
        for(int j=0;j<kazu;j++)
        {
            int goal=0;
            for(int k=0;k<kazu;k++)
            {
                while(angle[goal]==100)
                    goal++;
                if(goal==k)
                    continue;
                if(angle[k]<angle[goal])
                    goal=k;
                else if((angle[k]==angle[goal])&&(length[k]>length[goal]))
                    goal=k;
            }
            printf("(%.4lf,%.4lf)\n",length[goal],angle[goal]);
            angle[goal]=100;
        }
    }
    return 0;
}
