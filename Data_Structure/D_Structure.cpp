#include"D_Structure.h"
using namespace std;

int main()
{
    #pragma region 单调栈、滑动窗口、KMP

    int temp_Mo_stack[5]={3,4,-2,7,5};
    Monotonic_Stack(temp_Mo_stack,5);

    int temp_Mo_queue[8]={1,3 ,-1 ,-3 ,5, 3 ,6, 7};
    Monotonic_queue(temp_Mo_queue,8,3);

    //需要进行更改，使其能够适应首序为0
    system("cls");
    string s=" cababa";
    string p=" abcac";
    int p_Next[Arry_Size];
    KMP_First_pos(s,p,p_Next);
    
    cout<<"======================="<<endl;

    system("cls");
    string s1="abcadbac";
    string p1="dba";
    KmpSearch(s1,p1);

#pragma region 单调栈、滑动窗口、KMP


    system("pause");
    return 0;
}