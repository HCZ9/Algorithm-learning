#include"D_Structure.h"
using namespace std;

int main()
{
    #pragma region 单调栈、滑动窗口、KMP

    int temp_Mo_stack[5]={3,4,-2,7,5};
    Monotonic_Stack(temp_Mo_stack,5);

    int temp_Mo_queue[5]={5,4,3,2,1};
    Monotonic_queue(temp_Mo_queue,5,2);

    //需要进行更改，使其能够适应首序为0
    system("cls");
    string s=" cababa";
    string p=" abcac";
    int p_Next[Arry_Size];
    KMP_First_pos(s,p,p_Next);

    system("cls");
    string s1="abcadbac";
    string p1="dba";
    KmpSearch(s1,p1);

#pragma region 单调栈、滑动窗口、KMP

    system("cls");
    cout<<"============Join Search Set==============\n";
    int p_BCJ[100];
    int size_BCJ[100];
    for (size_t i = 0; i < 100; i++)
    {
        p_BCJ[i]=i;
        size_BCJ[i]=1;
    }
    BCJ_Search(1,3,p_BCJ);
    bcj_Merge(1,3,p_BCJ,size_BCJ);
    BCJ_Search(1,3,p_BCJ);
    
    cout<<"==================Little_Heap============\n";
    int h[10]={9,8,7,6,5,4,3,2,1,0};
    int h_size=10;
    for (int i = h_size/2; i>=0 ; i--)
    {
        Heap_Down(i,h,h_size);    
    }
    for (size_t i = 0; i < 10; i++)
    {
        cout<<h[i]<<" ";
    }
    cout<<endl;
    h[7]=-1;
    Heap_Up(7,h,h_size);
    cout<<"After UP: "<<endl;
    for (size_t i = 0; i < 10; i++)
    {
        cout<<h[i]<<" ";
    }
    cout<<endl;
    cout<<"the Order is: ";
    for (int i = 0; i < 10; i++)
    {
        cout<<h[0]<<" ";
         h[0]=h[h_size-1];
        h_size--;    
        Heap_Down(0,h,h_size);
    }
    system("cls");
    cout<<"======================Hash Table======================"<<endl;
    int hash[Arry_Size];
    int e[Arry_Size];
    int ne[Arry_Size];
    memset(ne,-1,sizeof(ne));
    memset(hash,-1,sizeof(hash));

    int idx=0;
    for (int i = 0; i < 50; i++)
    {
        Hash_Insert_LL(i*20,hash,100,e,ne,idx);
    }
   
    cout<<"idx:"<<idx<<endl;
    Hash_Find_LL(101,hash,100,e,ne);

    int hash_open[Arry_Size];
    memset(hash_open,0,4*100);
    int position = Hash_find_Open_add(20,hash_open,100);
    cout<<"Insert Position_find1: "<<position<<endl;
    hash_open[position]=20;
    int position_find = Hash_find_Open_add(20,hash_open,100);
    cout<<"Insert Position_find2: "<<position_find<<endl;
    system("cls");
    cout<<"======================string hash======================="<<endl;
    string hash_s="abcdeabcde";
    int hash_str[Arry_Size];
    int hash_p[Arry_Size];
    Set_Hash_str(hash_s,hash_str,hash_p);
    if(get_hash_str(5,7,hash_str,hash_p)==get_hash_str(0,2,hash_str,hash_p))
    {
        cout<<"yes"<<endl;
    }
    system("pause");
    return 0;
}