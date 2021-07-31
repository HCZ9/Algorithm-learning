
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
#pragma region 单调栈、滑动窗口

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