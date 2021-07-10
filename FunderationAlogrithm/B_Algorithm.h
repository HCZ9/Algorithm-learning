#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

#define Arry_Size 100

//快速排序
void Quick_Sort(int q[],int l,int r)
{
    //判断边界
    if (l>=r)
    {
        return;
    }

    //设置分界点以及双指针，分界点可以是L,R,(L+R)/2,Random
    int x=q[l], i=l-1,j=r+1;

    //迭代交换
    while (i<j)
    {
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j)swap(q[i],q[j]);
    }
    
    //递归
    Quick_Sort(q,l,j);
    Quick_Sort(q,j+1,r);
    
}


//归并排序（分治的思想）
void Merge_Sort(int q[],int l,int r)
{
    //判读边界
    if(l>=r)return;
    
    //确定分的界线
    int mid=l+r>>1;

    //先进行递归拆分，不用循环
    Merge_Sort(q,l,mid);
    Merge_Sort(q,mid+1,r);

    //定义双指针、临时数组及其指针
    int i=l,j=mid+1,temp[10],k=0;

    //归并（治）
    while (i<=mid && j<=r )
    {
        if(q[i]<q[j])temp[k++]=q[i++];
        else temp[k++]=q[j++];
    }
    while(i<=mid)temp[k++]=q[i++];
    while(j<=r)temp[k++]=q[j++];

    //注意此处是i=l
    for(int i=l,j=0;i<=r;i++,j++)q[i]=temp[j];

}


#pragma region 整数二分
//check函数可以随意指定，只要能够满足将左边和右边分开就好
bool check(int x){return true;}

//当区间被分为[l,mid-1][mid,r]时用

int bSerch_2(int q[],int l,int r)
{
    while (l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    return  l;
}

//当区间被分为[l,mid][mid+1,r]时用
int b_Serch_2(int q[],int l,int r)
{
    while (l<r)
    {
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    return l;
}

#pragma endregion 整数二分


//浮点数二分
//求一个数的平方根
double get_sqrt(double x)
{
    //确定边界
    double l=0,r=x;
    
    //设置置信区间
    while (r-l>1e-8)
    {
        double mid=(l+r)/2;
        if(mid * mid >= x)r=mid;
        else l=mid;
    }
    cout<<l<<endl;
    return l;
}

#pragma region 高精度

//高精度加法,此时的A,B是从个位开始存储的，即用vector存储大数。A[0]=个位，A[A.size()-1]=最高位，同时返回的vector也是从个位开始存储的
vector<int> High_prec_add(vector<int> &A, vector<int> &B)
{
    vector<int>C;
    int t=0;
    for(int i=0;i<A.size() || i<B.size() ;i++)
    {
        if(i<A.size())t+=A[i];
        if(i<B.size())t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t)C.push_back(1);
    return C;
}

//高精度减法,要确保是大数减小数
bool comp_2_num(const vector<int> &A,const vector<int> &B)
{
    if(A.size() != B.size())return A.size()<B.size();
    for(int i=A.size();i>=0;i--)if(A[i]!=B[i])return A[i]<B[i];
    return true;
}
vector<int> High_prec_sub(vector<int>&A ,vector<int>&B)
{
    if(comp_2_num(A,B))return High_prec_sub(B,A);
    int t=0;
    vector<int>C;
    for(int i=0;i<A.size()||i<B.size();i++)
    {
        t=A[i]-t;
        if(i<B.size())t-=B[i];
        C.push_back((t+10)%10);
        if(t>=0)t=0;
        else t=1;
    }
    while(C.size()>1 && C.back()==0)C.pop_back();
    return C;
}

//高精度乘法
vector<int> High_prec_mul(vector<int> &A,int b)
{
    vector<int>C;
    int t=0;
    for(int i=0;i<A.size() || t;i++)
    {
        if(i<A.size())t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    //if(t)C.push_back(t);
    return C;
}

//高精度除法，与其他的不同，要从高位开始计算
vector<int>High_prec_div(vector<int> &A,int b)
{
    vector<int>C;
    int r=0;
    for(int i=A.size()-1;i>=0;i--)
    {
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1 && C.back()==0)C.pop_back();
    return C;
}

#pragma endregion 高精度

#pragma region 前缀和，要保证前缀和数组是从下标1开始的

//一维前缀和
void Prefix_Sum1(int pre_sum[],int q[],int r)
{
    for(int i=0;i<r;i++)
    {
        pre_sum[i+1]=pre_sum[i]+q[i];
    }
}
int Get_Sub_Sum(int pre_sum[],int begin,int end)
{
    return (pre_sum[end]-pre_sum[begin-1]);
}

//二维前缀和
void Prefix_Sum2(int pre_sum[][Arry_Size],int q[][3],int m,int n)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            pre_sum[i][j]=pre_sum[i][j-1]+pre_sum[i-1][j]-pre_sum[i-1][j-1]+q[i-1][j-1];
        }
    }
}
int Get_SubMatrix_sum(int pre_sum[][Arry_Size],int x1,int y1,int x2,int y2)
{
    return (pre_sum[x2][y2]-pre_sum[x2][y1-1]-pre_sum[x1-1][y2]+pre_sum[x1-1][y1-1]);
}

#pragma endregion前缀和

#pragma region 差分，要保证差分数组是从下标1开始的

//一维差分，下标也是从1开始的
void Insert_1(int Diff[],int l, int r, int c)
{
    Diff[l]+=c;
    Diff[r+1]-=c;
}
void Differial_1(int q[],int size,int l,int r,int c)
{
    int diff[Arry_Size];
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=size;i++)
    {
        Insert_1(diff,i,i,q[i-1]);
    }
    Insert_1(diff,l,r,c);
    for(int i=1;i<=size;i++)diff[i]+=diff[i-1];
    for(int i=0;i<size;i++)q[i]=diff[i+1];
}

//二维差分
void Insert_2(int Diff[][Arry_Size],int x1,int y1,int x2,int y2,int c)
{
    Diff[x1][y1]+=c;
    Diff[x2+1][y1]-=c;
    Diff[x1][y2+1]-=c;
    Diff[x2+1][y2+1]+=c;
}
void Differial_2(int q[][3],int m,int n,int x1,int y1,int x2,int y2,int c)
{
    int diff[Arry_Size][Arry_Size];
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            Insert_2(diff,i,j,i,j,q[i-1][j-1]);
        }
    }
    Insert_2(diff,x1,y1,x2,y2,1);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            diff[i][j]=diff[i][j-1]+diff[i-1][j]-diff[i-1][j-1]+diff[i][j];
            q[i-1][j-1]=diff[i][j];
        }
    }
}

#pragma endregion 差分