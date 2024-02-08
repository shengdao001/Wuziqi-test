#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace::std;
#define N 20
char chessboardflag = ' ';  
void color(int a)//改变颜色的函数
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
class coordinate            //坐标类
{
public:
	int x;
	int y;
};
class fivechess
{
public:
	void initchessboard()//初始化棋盘
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				chessboard[i][j] = chessboardflag;
		printchessboard();
	}
	void printchessboard()//打印棋盘
	{
		system("cls");
		system("color 70");
		cout << "  1 2 3 4 5 6 7 8 9 10111213141516171819"<<endl;
		for (int i = 1; i < N; ++i) {
			for (int j = 0; j < N; ++j)
			{
				if (j == 0) {
					if (i <= 9)cout << i << " ";
					else cout << i;
				}
				else
				{
					if (chessboard[i][j] == 'x')
					{
						color(0x70);
						cout << "●";
					}
					else if (chessboard[i][j] == 'o')
					{
						color(0x7f);
						cout << "●";
					}
					else 
					{
						color(0x74);
						cout << "■";
					}
				}
			}
			cout << endl;
			color(0x70);
		}
	}
	coordinate playchess1()  //玩家1下棋
	{
		cout << "请玩家1输入坐标:" << endl;
		int x1, y1;
		while (cin >> x1 >> y1)
		{
			if (x1 > N-1 || y1 > N-1 || x1 < 0 || y1 < 0)
			{
				cout << "输入超出范围，请从新输入" << endl;
				continue;
			}
			if (chessboard[x1][y1] == ' ') {
				chessboard[x1][y1] = 'x';
				break;
			}
			else
			{
				cout << "输入错误,请重新输入";
			}
		}
		coordinate temp;
		temp.x = x1;
		temp.y = y1;
		return temp;
	}
	coordinate playchess2()  //玩家2下棋
	{
		cout << "请玩家2输入坐标:" << endl;
		int x2, y2;
		while (cin >> x2 >> y2)
		{
			if (x2 > N-1 || y2 > N-1 || x2 < 0 || y2 < 0)
			{
				cout << "输入超出范围，请从新输入" << endl;
				continue;
			}
			if (chessboard[x2][y2] == ' ') {
				chessboard[x2][y2] = 'o';
				break;
			}
			else
			{
				cout << "输入错误,请重新输入";
			}
		}
		coordinate temp;
		temp.x = x2;
		temp.y = y2;
		return temp;
	}
	coordinate computerplayer()//人机下棋
	{
		coordinate temp;
		srand((unsigned)time(NULL));
		int x1 = 0, y1 = 0;
		while ((x1 = (rand() % (N-1)) + 1) && (y1 = (rand() % (N-1)) + 1))
		{
			if (chessboard[x1][y1] == ' ') {
				chessboard[x1][y1] = 'x';
				break;
			}
			else continue;
		}
		temp.x = x1; temp.y = y1;
		return temp;
	}
	int judgewiner1(char a, coordinate temp)//判断横排
	{
		coordinate begin, end;
		begin.x = end.x = temp.x;
		if (temp.y <= 5)begin.y = 1;
		else begin.y = temp.y - 4;
		if (temp.y >= N-5)end.y = N-1;
		else end.y = temp.y + 4;
		for (int i = begin.x, j = begin.y; j <= end.y - 4; ++j)
		{
			if (chessboard[i][j] == a 
				&& chessboard[i][j] == chessboard[i][j + 1] 
				&& chessboard[i][j + 1] == chessboard[i][j + 2]
				&& chessboard[i][j + 2] == chessboard[i][j + 3] 
				&& chessboard[i][j + 3] == chessboard[i][j + 4])
				return 1;
		}
		return 0;
	}
	int judgewiner2(char a, coordinate temp)//判断竖排
	{
		coordinate begin, end;
		begin.y = end.y = temp.y;
		if (temp.x <= 5)begin.x = 1;
		else begin.x = temp.x - 4;
		if (temp.x >= N-5)end.x =N-1;
		else end.x = temp.x + 4;
		for (int i = begin.x, j = begin.y; i <= end.x - 4; ++i)
		{
			if (chessboard[i][j] == a
				&& chessboard[i][j] == chessboard[i + 1][j] 
				&& chessboard[i + 1][j] == chessboard[i + 2][j] 
				&& chessboard[i + 2][j] == chessboard[i + 3][j] 
				&& chessboard[i + 3][j] == chessboard[i + 4][j])
				return 1;
		}
		return 0;
	}
	int judgewiner3(char a, coordinate temp)//判断主对角线
	{
		coordinate begin, end;
		if (temp.x <= 5)begin.x = 1;
		else begin.x = temp.x - 4;
		if (temp.y <= 5)begin.y = 1;
		else begin.y = temp.y - 4;
		if (temp.x >= N-5)end.x = N-1;
		else end.x = temp.x + 4;
		if (temp.y >= N-5)end.y = N-1;
		else end.y = temp.y + 4;
		for (int i = begin.x, j = begin.y; i <= end.x - 4 && j <= end.y - 4; ++i, ++j)
		{
			if (chessboard[i][j] == a && chessboard[i][j] == chessboard[i + 1][j + 1] 
				&& chessboard[i + 1][j + 1] == chessboard[i + 2][j + 2] 
				&& chessboard[i + 2][j + 2] == chessboard[i + 3][j + 3] 
				&& chessboard[i + 3][j + 3] == chessboard[i + 4][j + 4])
				return 1;
		}
		return 0;
	}
	int judgewiner4(char a, coordinate temp)//判断负对角线
	{
		coordinate begin, end;
		if (temp.x <= 5)begin.x = 1;
		else begin.x = temp.x - 4;
		if (temp.y >= N-5)begin.y = N-1;
		else begin.y = temp.y + 4;
		if (temp.x >= N-5)end.x = N-1;
		else end.x = temp.x + 4;
		if (temp.y <= 5)end.y = 1;
		else end.y = temp.y - 4;
		for (int i = begin.x, j = begin.y; i <= end.x - 4 && j >= end.y - 4; ++i, --j)
		{
			if (chessboard[i][j] == a 
				&& chessboard[i][j] == chessboard[i + 1][j - 1] 
				&& chessboard[i + 1][j - 1] == chessboard[i + 2][j - 2]
				&& chessboard[i + 2][j - 2] == chessboard[i + 3][j - 3] 
				&& chessboard[i + 3][j - 3] == chessboard[i + 4][j - 4])
				return 1;
		}
		return 0;
	}
	int judgeheqi()//判断是否和棋
	{
		for (int i = 1; i < N; ++i)
			for (int j = 1; j < N; ++j)
				if (chessboard[i][j] == ' ')return 1;
		return -1;
	}
	void play()
	{
		initchessboard();//初始化棋盘
		int t;
		cout << "请选择模式，单人模式输入1，两人模式输入2" << endl;
		cin >> t;
		while (t == 1)
		{
			int m = judgeheqi();
			if (m == -1)
			{
				cout << "和棋" << endl;
				break;
			}
			coordinate temp1 = computerplayer();//电脑下棋
			printchessboard();//打印棋盘
			if (judgewiner1('x', temp1) || judgewiner2('x', temp1) || judgewiner3('x', temp1) || judgewiner4('x', temp1))
			{
				cout << "电脑胜";
				break;
			}
			coordinate temp2 = playchess2();//玩家2下棋
			printchessboard();//打印棋盘
			if (judgewiner1('o', temp2) || judgewiner2('o', temp2) || judgewiner3('o', temp2) || judgewiner4('o', temp2))
			{
				cout << "玩家2胜";
				break;
			}
		}
		while (t == 2)
		{
			int m = judgeheqi();
			if (m == -1)
			{
				cout << "和棋" << endl;
				break;
			}
			coordinate temp1 = playchess1();//电脑下棋
			printchessboard();//打印棋盘
			if (judgewiner1('x', temp1) || judgewiner2('x', temp1) || judgewiner3('x', temp1) || judgewiner4('x', temp1))
			{
				cout << "玩家1胜";
				break;
			}
			coordinate temp2 = playchess2();//玩家2下棋
			printchessboard();//打印棋盘
			if (judgewiner1('o', temp2) || judgewiner2('o', temp2) || judgewiner3('o', temp2) || judgewiner4('o', temp2))
			{
				cout << "玩家2胜";
				break;
			}
		}
	}
private:
	char chessboard[N][N];  //棋盘
};
int main()
{
	fivechess one;
	one.play();
	return 0;
}
