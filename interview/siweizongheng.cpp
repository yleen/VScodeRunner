typedef struct Row
{
    int a;
    int b;
} Row;
/*!
* Task 1.
*
* Find out all the rows that sastify below conditions:
*
* ((b >= 10 && b < 50) &&
* (a == 1000 || a == 2000 || a == 3000))
*
* Print them to the terminal, one row per line, for example:
*
* 1000,20
* 1000,23
* 2000,16
*
* @param nrows The total number of rows.
* @param rows The rows, for example rows[0] is the first row.
*/
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
// 任务1
void task1(const Row *rows, int nrows)
{
    /*
* TODO: implement this function.
*/
    for (int i = 0; i < nrows; i++)
    {
        rows = rows + i;
        int a = rows->a;
        int b = rows->b;
        if ((a == 1000 || a == 2000 || a == 3000) && b >= 10 && b < 50)
        {
            cout << a << "," << b << endl;
        }
    }
}

//任务2
void task1(const Row *rows, int nrows)
{
    /*
* TODO: implement this function.
*/
    int left = 0;
    int right = nrows;
    //二分法查找a
    while (left <= right)
    {
        int pivot = (left + right) / 2 + left;
        const Row *newRows = rows + pivot;
        int pLe = pivot - 1;
        int pRi = pivot + 1;
        if (newRows->a >= 1000 && newRows->a <= 3000)
        {
            //遍历pivot左半部分
            while (pLe >= left)
            {
                const Row *leRows = rows + pLe;
                if ((leRows->a == 1000 || leRows->a == 2000 || leRows->a == 3000) && leRows->b >= 10 && leRows->b < 50)
                {
                    cout << leRows->a << "," << leRows->b << endl;
                    pLe--;
                }
            }
            //遍历pivot右半部分
            while (pRi <= right)
            {
                const Row *riRows = rows + pRi;
                if ((riRows->a == 1000 || riRows->a == 2000 || riRows->a == 3000) && riRows->b >= 10 && riRows->b < 50)
                {
                    cout << riRows->a << "," << riRows->b << endl;
                    pRi++;
                }
            }
            return;
        }
        //没有定位到位置，重新定位
        if (newRows->a < 1000)
        {
            left = pivot+1;
        }
        else{
            right=pivot-1;
        }
    }
}
//任务3
void task1(const Row *rows, int nrows)
{
    /*
* TODO: implement this function.
*/
    int left = 0;
    int right = nrows;
    vector<Row> res;
    //二分法查找a
    while (left <= right)
    {
        int pivot = (left + right) / 2 + left;
        const Row *newRows = rows + pivot;
        int pLe = pivot - 1;
        int pRi = pivot + 1;
        if (newRows->a >= 1000 && newRows->a <= 3000)
        {
            //遍历pivot左半部分
            while (pLe >= left)
            {
                const Row *leRows = rows + pLe;
                if ((leRows->a == 1000 || leRows->a == 2000 || leRows->a == 3000) && leRows->b >= 10 && leRows->b < 50)
                {
                    //cout << leRows->a << "," << leRows->b << endl;
                    res.push_back(*leRows);
                    pLe--;
                }
            }
            //遍历pivot右半部分
            while (pRi <= right)
            {
                const Row *riRows = rows + pRi;
                if ((riRows->a == 1000 || riRows->a == 2000 || riRows->a == 3000) && riRows->b >= 10 && riRows->b < 50)
                {
                    // cout << riRows->a << "," << riRows->b << endl;
                    res.push_back(*riRows);
                    pRi++;
                }
            }
            sort(res.begin(),res.end(),compare);
            return;
        }
        //没有定位到位置，重新定位
        if (newRows->a < 1000)
        {
            left = pivot+1;
        }
        else{
            right=pivot-1;
        }
    }
}

bool compare(Row *a,Row *b){
    return a->b<b->b;
}

//任务4
/*
使用b+树，叶子结点按照范围划分，既可以快速查找效率也快
*/