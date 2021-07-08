#include<iostream>
#include<string>

using namespace std;

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

//归并排序
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