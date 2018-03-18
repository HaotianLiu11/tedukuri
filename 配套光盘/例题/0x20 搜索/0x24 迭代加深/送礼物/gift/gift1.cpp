#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
unsigned int g[53],w,n,ans,gy[1<<25],t,ww;
void tdiv(unsigned int x)
{
     int f=w-x;
     int a=0;int b=t-1;int mid;
     while (b-a>1)
     {
           mid=(a+b)/2;
           if  (gy[mid]<f) {a=mid;continue;}
           if  (gy[mid]==f) {ans=w;return;}
           b=mid-1;
     }
     if (gy[a]+x<=w && gy[a]+x>ans) ans=gy[a]+x;
     if (gy[b]+x<=w && gy[b]+x>ans) ans=gy[b]+x;
}
void dfs(int i,unsigned int x,int y)
{
     if (ans==w) return;
     if (x>w) return;
     if (y==0)
        if (i==n/2+1) 
        {
           gy[t++]=x;
           return;
        }
     if (y==1)  
        if (i==n+1) 
        {
           tdiv(x);
           return;
        }
     dfs(i+1,x,y);
     dfs(i+1,x+g[i],y);
}     
int cmp(const void*a,const void*b){return *((int*)a)-*((int*)b);}
int main()
{
    freopen("gift.in","r",stdin);
    freopen("gift.out","w",stdout);
    scanf("%d%d",&w,&n);
    ans=0;
    for (int i=1;i<=n;i++) scanf("%d",&g[i]);
    sort(g+1,g+n+1);
    dfs(1,0,0);
    sort(gy,gy+t);
    dfs(n/2+1,0,1);
    printf("%d\n",ans);
}
    
    
