/*
于雷 2020180010
世界名画陈列馆由m× n 个排列成矩形阵列的陈列室组成。为了防止名画被盗，需要在陈列室中设置警卫机器人哨位。每个警卫机器人除了监视它所在的陈列室外，还可以监视与它所在的陈列室相邻的上、下、左、右4 个陈列室。试设计一个安排警卫机器人哨位的算法，使得名画陈列馆中每一个陈列室都在警卫机器人的监视之下，且所用的警卫机器人数最少。
设计一个算法，计算警卫机器人的最佳哨位安排，使得名画陈列馆中每一个陈列室都在警卫机器人的监视之下，且所用的警卫机器人数最少。

输入：由文件input.txt输入数据,文件的第一行有2 个正整数m 和n (1≤m,n≤20)。
输出：将计算出的警卫机器人数及其最佳哨位安排输出到output.txt。文件中第一行是警卫机器人数；接下来的m 行中每行n 个数，0 表示无哨位，1 表示哨位。
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<time.h>
#define MAX 30
int m , n , best;//m*n,最优解的机器人数
int robots[MAX][MAX];//表示警卫机器人情况
int bestRobots[MAX][MAX];//存放当前最优的机器人安排情况
int monitor[MAX][MAX];//表示受监视情况
//从文件中读取m,n
void readFile ()
{
	FILE*f = fopen ( "input.txt" , "r" );
	if (f == NULL)
	{
		printf ( "读取文件错误" );
		return;
	}
	fscanf ( f , "%d%d" , &m , &n );
	fclose ( f );
}

//初始化数据
void initData ()
{
	best = INT_MAX;
	memset ( monitor , 0 , sizeof ( monitor ) );
	memset ( robots , 0 , sizeof ( robots ) );
}

//在控制台输出机器人安排情况并打印到文件中
void printArrange ()
{
	FILE* file = fopen ( "./output.txt" , "w" );
	printf ( "\n" );
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf ( "%2d" , bestRobots[i][j] );
			fprintf ( file,"%2d" , bestRobots[i][j] );
		}
		printf ( "\n" );
		fprintf (file, "\n" );
	}
	fclose ( file );
}

//检查是否全部被监视
bool checkAllRooms ()
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (monitor[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

//剪枝函数，是否可以不放
bool canKeepUnsafe ( int x , int y )
{
	if (monitor[x][y - 1] == 0)
		return false;
	if (y==n)
	{
		if (y > 0 && monitor[x][y - 1] == 0)
			return false;
		if (y = n && monitor[x][y] == 0)
			return false;
	}
	return true;
}

//安排机器人监视陈列室
void arrangeRobots ( int x , int y , int robot )
{
	if (robot > best)//剪枝
		return;
	if (x == m + 1)//安排完了所有的陈列室
	{
		if (checkAllRooms () && robot < best)//如果所有的陈列室都被监控且所用的机器人数少于之前的最小机器人数
		{
			best = robot;
			memcpy ( bestRobots , robots , sizeof ( robots ) );//将当前的机器人摆放情况复制存入bestRobots
		}
		return;
	}
	//如果可以摆放机器人
	if(monitor[x][y]==0&& monitor[x-1][y] == 0 && monitor[x][y-1] == 0 && 
		monitor[x][y+1] == 0 && monitor[x+1][y] == 0 )
	{
		//在这里摆放一个机器人
		robots[x][y] = 1;
		robot++;
		monitor[x][y] = 1;
		monitor[x-1][y] = 1;
		monitor[x][y-1] = 1;
		monitor[x+1][y] = 1;
		monitor[x][y+1] = 1;
		//遍历下一个陈列室
		if (y < n)
		{
			arrangeRobots ( x , y + 1 , robot );
		}
		else
		{
			arrangeRobots ( x + 1 , 1 , robot );
		}
		//回溯，撤销刚才摆放的机器人
		robots[x][y] = 0;
		robot--;
		monitor[x][y] = 0;
		monitor[x - 1][y] = 0;
		monitor[x][y - 1] = 0;
		monitor[x + 1][y] = 0;
		monitor[x][y + 1] = 0;
	}
	//不摆，直接考虑下一个陈列室
	if (canKeepUnsafe)//剪枝，如果可以不摆的话
	{
		if (y < n)
		{
			arrangeRobots ( x , y + 1 , robot );
		}
		else
		{
			arrangeRobots ( x + 1 , 1 , robot );
		}

	}
}

int main ()
{
	readFile ();
	initData ();
	arrangeRobots ( 1 , 1 , 0 );
	if (best == INT_MAX)//如果最终best仍然未INT_MAX表示没有方案
	{
		printf ( "no solution!" );
	}
	else
	{
		printf ( "最优安排的机器人数是：%d" , best );
		printArrange ();
	}
	return 0;
}