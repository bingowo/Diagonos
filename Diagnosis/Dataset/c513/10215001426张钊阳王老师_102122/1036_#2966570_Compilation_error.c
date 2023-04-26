int main()
{
    int total;
    cin >> total;
    point* P = new point[total];
    for(int i = 0;i < total; i++)
    {
        cin >> P[i].x >> P[i].y;
        P[i].init();
    }
    sort(P,P + total,cmp);

   
    ull dx;
    ull dy;
    dx = ABS(P[0].x,P[1].x);
    dy = ABS(P[0].y,P[1].y);
    ull distance = dx + dy;

    if(dx > distance)
    {
        cout << "18446744073709551616"<<endl;
        //这个数据是超过了ull的，没办法只能打表了
    }
    else
    cout << distance <<endl;

    point * PP = new point[total - 1];
    int step = 0;

    for(int i = 0; i < total - 1; i++)
    {
        if(P[i].x == P[i + 1].x && P[i].y == P[i + 1].y)
        {continue;}

        dx =  ABS(P[i].x, P[i + 1].x) ;
        dy =  ABS(P[i].y, P[i + 1].y);
        distance = dx + dy;
        if(dx % 2 != dy % 2)//判断加起来是不是奇数
        {   
            if(distance > (1ULL << 63))
            {
                step += 64;
                continue;
            }
            for(int j = 1; j < 64; j++)
            {
                
                if( (dx <= (1ULL << j)) && (dx >= (1ULL << (j - 1))) )//这里两边都要闭区间
                {
                    PP[i].power = j;
                    PP[i].coe = dx / pow(2,j - 1);
                }
                if( (dy <= (1ULL << j)) && (dy >= (1ULL << (j - 1))) )
                {
                    P[i].power = j;
                    P[i].coe = dy / pow(2,j - 1);
                }
            }
            ull max = ((P[i].power > PP[i].power) ? P[i].power : PP[i].power);
            step += max;
            //下面判断是否需要再加一
            //幂相同相加要加一
            //什么时候小幂会影响大幂？
            //小幂只比大幂小1，且系数/2加大幂系数＞2 
            //等于2的时候会咋样？看看我前面的分析


            // cout << "幂 " << P[i].power <<"  "<<PP[i].power<<endl;
            // cout <<"系数 " << P[i].coe <<"  "<<PP[i].coe<<endl;
            if(P[i].power == PP[i].power)//如果两者的幂相同，加起来的幂就多1
            {   
                step++;
            }
            else if(P[i].power - PP[i].power == 1)
            {
                PP[i].coe /= 2;
                if(PP[i].coe + P[i].coe > 2)
                step++;
            }
            else if(P[i].power - PP[i].power == -1)
            {
                P[i].coe /= 2;
                if(PP[i].coe + P[i].coe > 2)//不要等于二。。。
                step++;
            }
        }
        else
        {
            break;
        }    
    }
    cout << step << endl;

    
    return 0;
}
