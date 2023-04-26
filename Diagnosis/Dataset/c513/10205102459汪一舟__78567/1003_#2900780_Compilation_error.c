#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=362880;
char op[]= {'u','d','l','r'};
int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};
struct node
{
    int state[9];
    int step;
    int id;
};

struct pre
{
    int id;
    int operation;
} pre[maxn+10];

bool vis[maxn+10];
int start[9],target[9];//初始状态和目标状态
int fac[]= {1,1,2,6,24,120,720,5040,40320,362880};
node que[maxn*2];
int sta[maxn+10];
int front,rear;
int top;

bool Cantor(int str[],int n)
{
    int result=0;
    for(int i=0; i<=n; i++)
    {
        int count=0;
        for(int j=i+1; j<=n; j++)
        {
            if(str[i]>str[j])
            {
                ++count;
            }
        }
        result+=(count*fac[n-i]);
    }
    if(!vis[result])
    {
        vis[result]=true;
        return true;
    }
    else
    {
        return false;
    }
}

void get_ans(node now)
{
    int pos=now.id;
    while(pre[pos].id!=-1)
    {
        sta[top++]=pre[pos].operation;
        pos=pre[pos].id;
    }

    while(top!=0)
    {
        int now=sta[--top];
        printf("%c",op[now]);
    }
    printf("\n");
}

void bfs()
{
    node s;
    memcpy(s.state,start,sizeof(s.state));
    s.id=0;
    pre[s.id].id=-1;
    pre[s.id].operation=-1;
    s.step=0;
    Cantor(s.state,8);
    que[rear++]=s;
    int pos=0;

    while(front<rear)
    {
        node now=que[front++];
        if(memcmp(now.state,target,sizeof(target))==0)
        {
            get_ans(now);
            return ;
        }
        int i;
        for(i=0; i<=8; i++)
        {
            if(now.state[i]==0)
            {
                break;
            }
        }
        int x=i/3;
        int y=i%3;
        for(int j=0; j<4; j++)
        {
            node in;
            int dx=x+dir[j][0];
            int dy=y+dir[j][1];
            if(dx<0||dx>=3||dy<0||dy>=3) continue;

            int where=dy+3*dx;
            memcpy(in.state,now.state,sizeof(in.state));
            swap(in.state[where],in.state[i]);
            in.step=now.step+1;

            if(Cantor(in.state,8))
            {
                in.id=(++pos);
                pre[in.id].id=now.id;
                pre[in.id].operation=j;
                que[rear++]=in;
            }
        }
    }
    printf("unsolvable\n");
}

int main()
{
    int i,j;
    for(i=0; i<=8; i++)
    {
        char c;
        scanf("%c",&c);
        if(c>='0'&&c<='9')
        {
            start[i]=c-'0';//char到int
        }
        else
        {
            start[i]=0;//将x转为0
        }
    }
    for(i=0; i<=8; i++)
    {
        if(i!=8)
        {
            target[i]=i+1;
        }
        else
        {
            target[i]=0;//目标：123456780
        }
    }
    memset(vis,false,sizeof(vis));//vis先置为false
    front=rear=0;
    top=0;
    bfs();
    return 0;
}
