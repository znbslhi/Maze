#include <iostream>
#include<vector>
#include <stack>
using namespace std;
#define MaxN 12
vector<int> visit;
void inputMatrix(int n,int[][MaxN]);
void printMatix(int n,int a[][MaxN]);
bool IsVisited(int key);
bool check(int n,int a[][MaxN],int i,int j);
void printStack(stack<int>);

int main()
{

    int Array[12][12];
    int n;
    int i=0,j=0;
    stack<int> move;
    stack<int>solution;
    cin>>n;

    inputMatrix(n,Array);



    visit.push_back(1);//first cell is visited: 0*n+0+1=1
    move.push(1);
    do
    {
        if ( check(n,Array,i,j+1))//Rigth
        {
            j++;
            visit.push_back((i*n)+j+1);
            move.push((i*n)+j+1);
            if(i==n-1&&j==n-1)
                break;
        }
        else if(check(n,Array,i+1,j))//Down
        {
            i++;
            visit.push_back((i*n)+j+1);
            move.push((i*n)+j+1);
            if(i==n-1&&j==n-1)
                break;
        }
        else if(check(n,Array,i,j-1))//Left
        {
            j--;
            visit.push_back((i*n)+j+1);
            move.push((i*n)+j+1);
            if(i==n-1&&j==n-1)
                break;
        }
        else if(check(n,Array,i-1,j))//Up
        {
            i--;
            visit.push_back((i*n)+j+1);
            move.push((i*n)+j+1);
            if(i==n-1&&j==n-1)
                break;
        }
        else
        {
            if(move.size()>1)
            {
                int top1,top2;
                top1= move.top();
                move.pop();
                top2=move.top();
                if(top1-top2==n)
                    i--;
                else if(top1-top2==1)
                    j--;
                else if(top1-top2==-n)
                    i++;
                else if(top1-top2==-1)
                    j++;
            }
            else
            {
                cout<<-1;
                exit(0);
            }
        }
    }while(true);
    while(!move.empty())
    {
      solution.push(move.top());
      move.pop();
    }
    printStack(solution);

}
void inputMatrix(int n,int a[][MaxN])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        { cin>>a[i][j]; }
    }
}
void printMatix(int n,int a[][MaxN])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        { cout<<a[i][j]<<" "; }
        cout<<endl;
    }
}
bool IsVisited(int key)
{
    for(int i=0;i<visit.size();i++)
    {if(key==visit[i])
            return 1; }
    return 0;
}
bool check(int n,int a[][MaxN],int i,int j)
{
    if (a[i][j]==1||IsVisited(i*n+j+1)||i==n||j==n||i==-1||j==-1)
        return false;
    return true;
}
void printStack(stack<int>mystack)
{
    while(!mystack.empty())
    {
        cout<<mystack.top()<<" ";
        mystack.pop();
    }

}
