    #include <stdio.h>
    #include <stdio.h>
    #include <string.h>
    #define L 41

    int main()
    {
        char function[50];
        while(scanf("%s",function) == 1)
        {
            int i,j,len;
            int a = 0,b = 0;
            //a为系数，b为指数
            len = strlen(function);
            char graph[L][L];
            for(i = 0;i < L;i++)
            {
                for(j = 0;j < L;j++)
                {
                    if(i == 0 && j == L / 2)
                        graph[i][j] = '^';
                    else if(i != L / 2 && j == L / 2)
                        graph[i][j] = '|';
                    else if(i == L / 2)
                    {
                        if(j != L - 1 && j != L / 2)
                            graph[i][j] = '-';
                        else if(j == L - 1)
                            graph[i][j] = '>';
                        else if(j == L / 2)
                            graph[i][j] = '+';
                    }
                    else
                        graph[i][j] = '.';
                }
            }
            int exp[4] = {0},cnt = 0;
            char*pt = strchr(function,'=');
            char state,state1 = 'd';
            while(*pt)
            {
                switch(*pt)
                {
                    case '=':
                        state = 'e';
                        pt++;
                        break;
                    case '-':
                        if(state == 'u')
                        {
                            exp[1] = a;
                            a = 0;
                        }
                        else if(state == 'i')
                        {
                            exp[b] = a;
                            b = 0;
                            a = 0;
                        }  
                        state = 'n';
                        pt++;
                        break;
                    case '+':
                        if(state == 'u')
                        {
                            exp[1] = a;
                            a = 0;
                        }
                        else if(state == 'i')
                        {
                            exp[b] = a;
                            b = 0;
                            a = 0;
                        }  
                        state = 'p';
                        pt++;
                        break;
                    case 'x':
                        if(state1 == 'g')
                        {
                            if(state == 'n')
                                a = -a;
                            state1 = 'd';
                        }
                        else if(state1 == 'd')
                        {
                            if(state == 'n')
                                a = -1;
                            else if(state == 'p')
                                a = 1;
                            else if(state == 'e')
                                a = 1;
                        }
                        state = 'u';
                        pt++;
                        break;
                    case '^':
                        state = 'i';
                        pt++;
                        break;
                    default:
                        if(state == 'n')
                        {
                            a = a * 10 + (*pt - '0');
                            state1 = 'g';
                        }
                        else if(state == 'p' || state == 'e')
                        {
                            a = a * 10 + (*pt - '0');
                            state1 = 'g';
                        }
                        else if(state == 'i')
                            b = b * 10 + (*pt - '0');
                        pt++;
                }
            }
            if(state == 'u')
                exp[1] = a;
            else if(state == 'i')
            {
                exp[b] = a;
            }
            else if(state == 'n')
                exp[b] = -a;
            else
                exp[b] = a;
            for(i = -20;i <= 20;i++)
            {
                int y = exp[3] * i * i * i + exp[2] * i * i + exp[1] * i + exp[0];
                if(y > 20 || y < -20)
                    continue;
                else
                    graph[20 - y][i + 20] = '*';
            }
            for(i = 0;i < L;i++)
            {
                for(j = 0;j < L;j++)
                    putchar(graph[i][j]);
                putchar('\n');
            }
            putchar('\n');
        }
        return 0;   
    }
