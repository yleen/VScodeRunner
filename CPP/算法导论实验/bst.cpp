/*
于雷 2020180010
求解问题：最优二叉搜索树相关问题
（1）最优二叉搜索树的构造：给定关键字的排列次序，给出对应的查找成功和失败的概率，据此使用基本算法构造最优二叉搜索树；
（2）用改进的算法构造最优二叉搜索树，使构造的时间复杂度由O(n3)由变成O(n2).设置关键字个数分别为100，1000，5000，对于概率进行如下的设置：
（a）全部查找成功，并且关键字等概率；
（b）包含关键字查找成功和失败的情形，所有情况是等概率的（即约一半成功一半失败），从理论上分析其查找次数的期望和树高；
（c）查找成功的概率为80%，不成功为20%，在成功的情况下10%的元素的概率为成功的60%（全部概率的0.48），其余90%的元素概率为成功时的40%（全部概率的0.32），设定查找成功最高概率元素的概率小于10/n，并注意元素查找成功概率较高时，其失败时的概率相比其他失败情况的概率也要高. 
对元素的分布进行一些假定，构建最优二叉搜索树，统计不同情况下树的高度和查找次数的期望（随机数使用不同的种子，多次执行算法后求平均）。
与查找成功的概率为90%，不成功为10%的情形比较。
（3）讨论少量查找概率发生小的变化时最佳搜索树的调整的近似算法。
*/
#include<iostream>
#include<vector>
using namespace std;

const int N=100;
const int MAX=9999999;
vector<float> p;//找到的概率
vector<float>  q;//找不到的概率

float e[N+2][N+1];
int root[N+1][N+1];
float w[N+2][N+1];

vector<float> pFill(int m){
    int minV=5,maxV=20;
    int count=N;
    int M=m;
    vector<float> res;
    while(count > 0){
        int l = max(minV, M - (N-1)*maxV);
        int r = min(maxV, M - (N-1)*minV);
        int num = rand() % (r - l + 1) + l;;
        count -= 1;
        res.push_back(num*1.0/100);
    }
    return res;
}


void optimal_bst_search_tree(vector<float> p,vector<float> q,int n)
{
    int i;
    for(i=1;i<=n+1;i++)
    {
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }
    int l,j,r;
    for(l=1;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            e[i][j]=MAX;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(r=i;r<=j;r++)
            {
                double t=e[i][r-1]+e[r+1][j]+w[i][j];
                if(t<e[i][j])
                {
                    e[i][j]=t;
                    root[i][j]=r;
                }
            }
        }
    }
}

void print_root()
{
    int i,j;
    cout<<"各子树的根："<<endl;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
            cout<<root[i][j]<<" ";
        cout<<endl;
    }
}

void construct_optimal_bst(int i,int j)
{
    if(i<=j)
    {
        int r=root[i][j];
        cout<<r<<" ";
        construct_optimal_bst(i,r-1);
        construct_optimal_bst(r+1,j);
    }
}
void print_bst(int i,int j)
{
    if(i==1&&j==N)
        cout<<"root is "<<root[i][j]<<endl;
    if(i<j)
    {
        int r=root[i][j];
        if(i!=r)
            cout<<"left child root "<<root[i][r-1]<<endl;
        print_bst(i,root[i][j]-1);
        if(j!=r)
            cout<<"right child root "<<root[r+1][j]<<endl;
        print_bst(root[i][j]+1,j);
    }
}
int main()
{
    p=pFill(80);
    q=pFill(20);
    optimal_bst_search_tree(p,q,N);
    //print_root();
    cout<<"构造的最优二叉树："<<endl;
    construct_optimal_bst(1,100);
    cout<<endl;
    print_bst(1,100);
}
