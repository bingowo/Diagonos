#include<iostream>
#include<algorithm>
#include<cmath>

#define ll long long
#define ull unsigned ll
using namespace std;

struct point
{
    ll x;
    ll y;
    ull Manhattan;

    void init()
    {
        Manhattan = llabs(x) + llabs(y);
    }
};

bool cmp(point a, point b)
{
    if(a.Manhattan == b.Manhattan)
    {
        if(a.x == b.x)
        {
            return(a.y < b.y);
        }
        return(a.x < b.x);
    }
    return(a.Manhattan > b.Manhattan);
}

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

    ull distance = llabs(P[0].x - P[1].x) + llabs(P[0].y - P[1].y);
    cout << distance << endl;

    int step = 0;
    for(int i = 0; i < total - 1; i++)
    {
        distance = llabs(P[i].x - P[i + 1].x) + llabs(P[i].y - P[i + 1].y);
        if(distance % 2)
        {
            for(int j = 1; j <= 64; j++)
            {
                
                if(distance <= (1ULL << j))
                {
                    step += j;
                    break;
                }//

                if(distance > (1ULL << 63))
                {
                    step += 64;
                    break;
                }
            }
        }
        else
        {break;}    
    }
    cout << step << endl;

    
    return 0;
}
————————————————
版权声明：本文为CSDN博主「JamSlade」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/JamSlade/article/details/114898320