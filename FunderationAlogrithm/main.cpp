#include"B_Algorithm.h"

int main()
{
    int a[5]={2,4,1,5,3};
    Merge_Sort(a,0,4);
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d",a[i]);
    }

#pragma region 整数二分
    int b[6]={1,2,2,3,3,4};
    int query_x=3;
    //scanf("%d",&query_x);
    int l=0,r=5;
    while (l<r)
    {
        int mid=l+r>>1;
        if(b[mid]>=query_x)r=mid;
        else l=mid+1;
    }
    if(b[l]!=query_x)cout<<"-1 -1"<<endl;
    else
    {
        cout<<l<<" ";
        int l=0,r=5;
        while (l<r)
        {
            int mid=l+r+1>>1;
            if(b[mid]<=query_x)l=mid;
            else r=mid-1;
        }
        cout<<l<<endl;
        
    }
 #pragma endregion   

    cout<<get_sqrt(0.01)<<endl;

    system("cls");
    vector<int>High_Ivec1={4,2};
    vector<int>High_Ivec2={8,8};
    vector<int>add_result=High_prec_add(High_Ivec1,High_Ivec2);
    for(auto i:add_result)cout<<i<<" ";

    vector<int>Sub_res=High_prec_sub(High_Ivec1,High_Ivec2);
    for(auto i:Sub_res)cout<<i<<" ";
    cout<<endl;

    vector<int>Mul_ans=High_prec_mul(High_Ivec2,3);
    for(auto i: Mul_ans)cout<<i<<" ";
    cout<<endl;

    vector<int>Div_ans=High_prec_div(High_Ivec2,4);
    for(auto i:Div_ans)cout<<i<<" ";
    cout<<endl;

    system("cls");
    //一维前缀和
    int pre_1a[5]={1,2,3,4,5};
    int pre_1sum[7];
    memset(pre_1sum,0,sizeof(int)*7);
    Prefix_Sum1(pre_1sum,pre_1a,4);
    
    cout<<Get_Sub_Sum(pre_1sum,2,4)<<endl;//9,下标从1开始

    //二维前缀和
    int pre_2a[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            pre_2a[i][j]=i*3+j+1;
        }
    }
    int pre_2sum[Arry_Size][Arry_Size];
    memset(pre_2sum,0,sizeof(pre_2sum));
    Prefix_Sum2(pre_2sum,pre_2a,3,3);

    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
           cout<<pre_2sum[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<Get_SubMatrix_sum(pre_2sum,1,1,2,2)<<endl;

    //一维差分
    Differial_1(a,5,2,3,100);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    //二维差分
    Differial_2(pre_2a,3,3,1,1,2,2,1);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<pre_2a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    system("pause");
    return 0;
    
}