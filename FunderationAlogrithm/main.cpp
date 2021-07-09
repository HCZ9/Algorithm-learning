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
    int query_x;
    scanf("%d",&query_x);
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

    system("pause");
    return 0;
    
}