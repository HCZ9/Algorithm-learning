
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cstdio>
#include<stack>
#include<deque>
using namespace std;

#define Arry_Size 100

#pragma region 单调栈、滑动窗口
//数组实现的单调栈，栈中存储值，来实现每次的栈满足单调性
void Monotonic_Stack(int q[],int length)
{
    int tt=0;
    int stk[Arry_Size];
    memset(stk,0,Arry_Size);
    for(int i=0;i<length;i++)
    {
        while(tt && stk[tt]>=q[i])tt--;
        if(tt)
        {
            printf("%d ",stk[tt]);
        }        
        else
        {
            printf("-1 ");
        }     
        stk[++tt]=q[i];
    }

}

//STL(stack)实现的单调栈
void Single_Stack(vector<int> &q)
{
	stack<int>sInt;
	for (size_t i = 0; i < q.size(); i++)
	{
		while (!sInt.empty() &&sInt.top()>=q[i])
		{
			sInt.pop();
		}
		if (!sInt.empty())
		{
			cout << sInt.top()<<" , ";
		}
		else
		{
			cout << "-1" << " , ";
		}
		sInt.push(q[i]);
	}
}

//滑动窗口内值最小,单调队列相当于双端队列，队列中存储下标来实现窗口的滑动，而不是存储值
void Monotonic_queue(int q[],int length,int size)
{
    int hh=0, tt=-1;
    int que[Arry_Size];
    memset(que,0,Arry_Size);
    for(int i=0;i<length;i++)
    {
        while(hh<=tt && i-size+1>que[hh])hh++;
        while(hh<=tt && q[que[tt]]>=q[i])tt--;
        que[++tt]=i;
       if(i>=size-1)printf("%d ",q[que[hh]]);
    }
}

//STL(deque)实现滑动窗口
void Move_Window(vector<int>Ivec,int WindowSize)
{
    deque<int>Ideu;
    for (size_t i = 0; i < Ivec.size(); i++)
    {
        while (!Ideu.empty() && i-WindowSize+1>Ideu[0])
        {
            Ideu.erase(Ideu.begin());
        }
        while (!Ideu.empty() && Ivec[Ideu.back()]>Ivec[i])
        {
            Ideu.erase(Ideu.end()-1);
        }
        Ideu.push_back(i);
        if(i>WindowSize-1)cout<<Ivec[Ideu[0]]<<endl;
        
    }
    
}
#pragma endregion 单调栈、滑动窗口

#pragma region KMP
//KMP算法匹配字符串，从1开始的
void GetNext(string &P,int P_Next[])
{
    for(int i=2,j=0;i<=P.size();i++)
    {
        while(j && P[i]!=P[j+1])j=P_Next[j];
        if(P[i]==P[j+1])j++;
        P_Next[i]=j;
        cout<<P_Next[i]<<" ";
    }   
    
}
//KMP算法匹配字符串，从1开始的
void KMP_First_pos(string &S,string &P,int P_next[])
{
    GetNext(P,P_next);
    for(int i=1,j=0;i<S.size();i++)
    {
        while (j && S[i]!=P[j+1])
        {
            j=P_next[j];
        }
        if(S[i]==P[j+1])j++;
        if(j==P.size()-1)
        {
            printf("%s%d","the first match subscript is : ",i-j+1);
            j=P_next[j];
            break;
        }
        
    }
}

#pragma region KMP从0开始
//从0开始的KMP算法,正经的KMP算法
void GetKMPNext(string p,int p_next[])
{
    int pSize=p.size();
    int j=0;
    int k=-1;
    p_next[0]=-1;
    while (j<pSize-1)
    {
        if(k=-1 || p[j]==p[k])
        {
            ++k;
            ++j;
            p_next[j]=k;
        }
        else
        {
            k=p_next[k];
        }
        
    }    
}

//优化nect数组
void GetKMPNext_OP(string p,int p_next[])
{
    int pSize=p.size();
    int j=0;
    int k=-1;
    p_next[0]=-1;
    while (j<pSize-1)
    {
        if(k=-1 || p[j]==p[k])
        {
            ++k;
            ++j;
            if(p[j]!=p[k])
            {
                p_next[j]=k;
            }
            else
            {
                p_next[j]=p_next[k];
            }
            
        }
        else
        {
            k=p_next[k];
        }
        
    }    
}

void KmpSearch(string s,string p)
{
    int i=0;
    int j=0;
    int sSize=s.size();
    int pSize=p.size();
    int *p_next=new int[pSize];
    GetKMPNext_OP(p,p_next);
    while (i<sSize && j<pSize)
    {
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
			//next[j]即为j所对应的next值        
			j = p_next[j];
		}
	}
	if (j == p.size())
    {
        printf("%s%u","position: ",i-j);
        //cout<<"the match position is： "<<i-j<<endl;
    }		
	else
    {
        cout<<"not match !"<<endl;

    }
}
    
#pragma endregion KMP 0开始

#pragma endregion KMP

#pragma region STL容器的使用
/*
    vector//变长数组，倍增
    string//可以当栈用，substr(),c_str()
    queue//push(),front,pop()，queue没有clear清空操作为进行重新构造
    priority_queue//堆，优先队列，push(),top(),pop()，默认是大根堆，变成小根堆可以插入负数来实现，或者priority<vector<int>,greater<int>>heap;
    stack//栈,push(),top(),pop();
    deque//双端队列，
    set,map,multiset,multimap//基于平衡二叉树（红黑数），动态维护有序序列
    unordered_set,undered_map,unordered_multiset,unordered_multimap//哈希表
    bitset//压位，位存储、状态压缩，每一个字节存储8位，例：比正常的数组省内存，是正常bool数组的1/8；可以省8倍空间
        bitset<10000>s;长度为10000的bitset，和以前的容器不一样他定义的时候是个数。
        ~s,&,|,^
        >>,<<
        ==,!=
        [],
        count()//返回有多少个1
        any()//判断是否至少有1个1
        none()//判断是否全为0
        set()//把所有的位置成1
        set(k,v)//把第k位变成v
        reset()//把所有位变成0
        flip()//等价于~
        flip(k)//把第k位取反
*/
#pragma endregion STL容器的使用

#pragma region 并查集
//将两个个集合合并到一个集合、询问元素是否在集合中
int BCJ_find(int x,int p[])
{
    if(p[x]!=x)p[x]=BCJ_find(p[x],p);
    return p[x];
}
//合并元素所在的集合
void bcj_Merge(int a,int b,int p[],int size_BCJ[])
{
    p[BCJ_find(a,p)]=BCJ_find(b,p);
    size_BCJ[BCJ_find(b,p)]+=size_BCJ[BCJ_find(b,p)];
}
void BCJ_Search(int a,int b,int p[])
{
    if(BCJ_find(a,p)==BCJ_find(b,p))
    {
        printf("They are in one set!\n");
    }
    else
    {
        printf("They are not in one set!\n");
    }   
}
#pragma endregion 并查集

#pragma region 堆(小根)
void Heap_Swap(int a,int b,int h[])
{
    std::swap(h[a],h[b]);
}
//从下标0开始,注意此处的size是个数，构建堆从n/2开始就是n是size。最后一个叶子节点的父节点开始往下Down
void Heap_Down(int u,int h[],int h_size)
{
    int t=u;
    if(u*2+1<=h_size-1 && h[u*2+1]<h[t])t=u*2+1;
    if(u*2+2<=h_size-1 && h[u*2+2]<h[t])t=u*2+2;
    if(u!=t)
    {
        swap(h[u],h[t]);
        Heap_Down(t,h,h_size);
    }
}
void Heap_Up(int u,int h[],int h_size)
{
    while ((u-1)/2>=0 && h[u]<h[(u-1)/2])
    {
        Heap_Swap(u,(u-1)/2,h);
        u=(u-1)>>1;
    }    
}

//下标从1开始的堆的UP和Down
void Heap_Down_1(int u,int h[],int h_size)
{
    int t=u;
    if(u*2 <= h_size && h[u*2]<h[t])t=u*2;
    if(u*2+1 <= h_size && h[u*2+1]<h[t])t=u*2+1;
    if(u!=t)
    {
        std::swap(h[u],h[t]);
        Heap_Down_1(t,h,h_size);
    }

}

void Heap_UP_1(int u,int h[],int h_size)
{
    while (u/2 && h[u]<h[u/2])
    {
        Heap_Swap(u,u/2,h);
        u>>=1;
    }    
}

#pragma endregion 堆

#pragma region 哈希表和哈希字符串
//获取比x大的最小质数
int Get_Max_Prime_Num(int x)
{
    for (int i = x; ; i++)
    {
        bool flag=true;
        for (int j = 2; j*j <=i; j++)
        {
            if(i%j==0)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<"The Max Num:"<<i;
            break;
        }     
        return i;  
    }   
    return -1;
}
//拉拉链法
void Hash_Insert_LL(int x,int h[],int h_size,int e[],int ne[],int &idx)
{
    //首先获取h_size更大一些的质数
    int Max_PrimeNum=Get_Max_Prime_Num(h_size);
    int k=(x%Max_PrimeNum+Max_PrimeNum)%Max_PrimeNum;
    
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;    
}
void Hash_Find_LL(int x,int h[],int h_size,int e[],int ne[])
{
    int Max_PrimeNum=Get_Max_Prime_Num(h_size);
    int k=(x%Max_PrimeNum+Max_PrimeNum)%Max_PrimeNum;
    bool flag=true;
    for (int i = h[k]; i !=-1; i=ne[i])
    {   
        if(e[i]==x)
        {
            printf("is in hash!");
            flag=false;
            break;
        }
    }
    if(flag)printf("not in hash !");
}

//开放寻址法
int Hash_find_Open_add(int x,int h[],int h_size)
{
    int Max_PrimeNum=Get_Max_Prime_Num(h_size);
    int k=(x % Max_PrimeNum + Max_PrimeNum) % Max_PrimeNum;
    while (h[k]!=0 && h[k]!=x)
    {
        k++;
        if(k=h_size-1)k=0;
    }
    return k;
}

//哈希字符串
//P取131,p[]存储的是p^k，h[]存储的是前缀和，从左往右k递增
void Set_Hash_str(string s,int h[],int p[])
{
    p[0]=1;
    h[0]=s[0];
    for (size_t i = 1; i <=s.size(); i++)
    {
        p[i]=p[i-1]*131;
        h[i]=h[i-1]*131+s[i];
    }   
}

unsigned long long get_hash_str(int l,int r,int h[],int p[])
{
    if(l==0)return h[r];
    return h[r]-h[l-1]*p[r-l+1];//乘以p[r-l+1]是乘以之间的差距次方，来进行前面的消除
}

#pragma endregion 哈希表和哈希字符串