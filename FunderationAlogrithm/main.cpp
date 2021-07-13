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

#pragma region 高精度、前缀和、差分
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
#pragma endregion 高精度、前缀和、差分

#pragma region 双指针、位运算、离散化、区间合并

    system("cls");
    string s="this is the first words !";
    PrintWords(s);

    int temp_want_sub[5]={1,3,3,4,2};
    cout<<"the max sublength of sequence is: "<<GetSubSeqLength(temp_want_sub,5)<<endl;

    GetBinaryPrintf(10);
    cout<<"the 1 count of 10 in binary is: "<<Get_Binary1_Count(10)<<endl;

    vector<int>alls={10,20,30,40,50,10,20};
    vector<PII>add={{10,1},{20,2},{30,3},{40,4},{50,5}};
    vector<PII>query={{10,50},{20,40}};
    Discretization(alls,add,query);

    vector<PII>Interval={{1,2},{2,3},{3,4}};
    Interval_Merge(Interval);
    for(auto i:Interval)cout<<"the Interval has been merged to : "<<i.first<<","<<i.second<<endl;

#pragma endregion 双指针、位运算、离散化、区间合并
    system("pause");
    return 0;
    
}