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