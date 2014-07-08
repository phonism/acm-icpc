#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
int t,i,j,n,a[310],m;
double x[310],y[310],r[310],d[310],T[310],xx,yy,rr;
bool bb[310];
 
const double eps=1e-6;
 
struct nodd
{
    int y,n;
    double d;
} b[90010];
 
double dis(int a,int b)
{
    return sqrt( (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]) );
}
 
void add(int x,int y,double d)
{
    b[++m].y=y; b[m].d=d;
    b[m].n=a[x]; a[x]=m;
}
 
void init()
{
    cin>>n;
    for (i=1;i<=n;i++) cin>>x[i]>>y[i]>>r[i];
    cin>>xx>>yy>>rr;
    for (i=1;i<=n;i++)
    {
        x[i]-=xx;
        y[i]-=yy;
        r[i]+=rr;
    }
    x[0]=y[0]=0;
    // memset(a,0,sizeof(a));
    // memset(d,0,sizeof(d));
    // memset(T,0,sizeof(T));
    // memset(bb,0,sizeof(bb));
}
 
bool spfa()
{
    queue<int> q;
    int x,y;
    for (i=1;i<=n;i++) q.push(i);
    while (!q.empty())
    {
        x=q.front(); q.pop();
        for (i=a[x];i;i=b[i].n)
        {
            y=b[i].y;
            if ( d[y]>d[x]+b[i].d+eps )
            {
                d[y]=d[x]+b[i].d;
                if (bb[y])
                {
                    if ( (++T[y])>=n ) return 0;
                    bb[y]=0; q.push(y);
                }
            }
        }
        bb[x]=1;
    }
    return 1;
}
 
void work()
{
    m=0;
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++) if ( r[i]+r[j]-eps>=dis(i,j) )
        {
            double c=acos( (x[i]*x[j]+y[i]*y[j])/(dis(i,0)*dis(j,0)) );
            if ( x[i]*y[j]-x[j]*y[i] <0 ) c=-c;
            add(i,j,c);
            add(j,i,-c);
        }
    if ( spfa() ) cout<<"YES"<<endl;else cout<<"NO"<<endl;
    if (t) cout<<endl;
}
 
int main()
{
    //freopen("1.in","r",stdin);
    //cin>>t;
   // while (t--)
   // {
        init();
        work();
   // }
    return 0;
}