#ifndef _INC_DEFINE_
#define _INC_DEFINE_
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define WIDTH 7
#define HEIGHT 6
#define PLAYER_NUM 3  //登録しているplayerの数
#define OK 1  //気にしなくて大丈夫なとき
#define NG 0  //立ち止まって気にする必要あるとき
#define FORMER 0  //先攻
#define LATTER 1  //後攻
#define TIME_LAG 0
typedef pair<int, int> P;

int GetRandom_i(int min, int max);
double GetRandom_d(double min, double max);
void WaitTime(int msec);
int Input();
int string_to_digit(string s);
int reverse(int F_or_L);

#endif
