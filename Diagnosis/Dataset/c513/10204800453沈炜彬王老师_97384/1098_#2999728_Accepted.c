#include <stdio.h>
#include <string.h>

int
main()
{
    int T;
    char b[101];
    int res_cout[4];
    char res_b[4];
    int seq_R=0,seq_B=0,seq_Y=0,seq_G=0;

    scanf("%d",&T);
    
    for (int i=0; i<T; i++)
    {
        memset(res_cout, 0, sizeof(res_cout));
        
        scanf("%s",b);
        if (strlen(b)>4)
        {
            for (int j=0; j<strlen(b); j++)
            {
                if (b[j] == '!')
                {
                    res_cout[j%4] += 1;
                }
                else
                {
                    res_b[j%4] = b[j];
                }
            }
            
            for (int j=0; j<4; j++)
            {
                switch (res_b[j])
                {
                    case ('R'):
                        seq_R = j;
                        break;
                    case ('B'):
                        seq_B = j;
                        break;
                    case ('Y'):
                        seq_Y = j;
                        break;
                    case ('G'):
                        seq_G = j;
                        break;
                }
            }
        }
        else
        {
            seq_R = 0;
            seq_B = 1;
            seq_Y = 2;
            seq_G = 3;
            
            for (int j=0; j<4; j++)
            {
                res_cout[j] = -1;
            }
            for (int j=0; j<4; j++)
            {
                switch (b[j])
                {
                    case ('R'):
                        res_cout[seq_R]++;
                        break;
                    case ('B'):
                        res_cout[seq_B]++;
                        break;
                    case ('Y'):
                        res_cout[seq_Y]++;
                        break;
                    case ('G'):
                        res_cout[seq_G]++;
                        break;
                }
            }
            for (int j=0; j<4; j++)
            {
                res_cout[j] *= -1;
            }
        }
        
        printf("case #%d:\n",i);
        printf("%d %d %d %d\n",res_cout[seq_R],res_cout[seq_B],res_cout[seq_Y],res_cout[seq_G]);
    }
    
    return 0;
}