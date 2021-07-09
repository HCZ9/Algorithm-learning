#include<iostream>
#include<string>

using namespace std;

#pragma region 快速排序

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

#pragma endregion

#pragma region 归并排序

void Merge_Sort(int q[],int l,int r)
{
    //判断边界
    if(l>=r)return;

    //确定分界点
    int mid=l+r>>1;

    //递归调用进行分割
    Merge_Sort(q,l,mid);
    Merge_Sort(q,mid+1,r);

    //设置临时数组进行归并
    int temp[10];
    //设置双指针进行归并，并设置一个指向临时数组当前位置的指针
    int i=l,j=mid+1,k=0;
    
    //循环迭代进行归并
    while (i<=mid && j<=r)
    {
        if(q[i]<q[j])temp[k++]=q[i++];
        else temp[k++]=q[j++];
    }
    while(i<=mid)temp[k++]=q[i++];
    while(j<=r)temp[k++]=q[j++];

    for(int i=l,j=0;i<=r;i++,j++)q[i]=temp[j];
    
}

#pragma endregion

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
#pragma endregion

#pragma region 浮点数二分
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

#pragma endregion