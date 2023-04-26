#include<stdio.h>
#include<string.h>

int main()
{
    int N;
    scanf("%d\n",&N);
    for(int i = 0;i<N;i++)
    {
        char s[100] = {'\0'};
        char order[4] = {'\0'};
        scanf("%s",s);
        int count = 0;
        int flag = 0;
        while(count<strlen(s))
        {
            if(s[count]!='!'&&order[flag]=='\0')
            {
                order[flag] = s[count];
            }
            flag++;
            if(flag==4)
            {
                flag = 0;
            }
            count++;
        }



        int should[4];
        int times = strlen(s)/4;
        should[0] = times;
        should[1] = times;
        should[2] = times;
        should[3] = times;


        times = strlen(s)%4;
        if(times == 1)
        {
            should[0]++;
        }
        else if(times == 2)
        {
            should[0]++;
            should[1]++;
        }
        else if(times == 3)
        {
            should[0]++;
            should[1]++;
            should[2]++;
        }


        count = 0;
        while(count<strlen(s))
        {
            if(s[count] == order[0])
            {
                should[0]--;
            }
            else if(s[count]==order[1])
            {
                should[1]--;
            }
            else if(s[count]==order[2])
            {
                should[2]--;
            }
            else if(s[count]==order[3])
            {
                should[3]--;
            }
            count++;
        }
        printf("case #%d:\n",i);
        printf("%d %d %d %d\n",should[0],should[1],should[2],should[3]);


    }
    return 0;
}
