#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;

static int _currentChar = 0;
static int _charsNumber = 0;
static char _buffer[1024];

static inline int _read() {
	if (_charsNumber < 0) {
		exit(1);
	}
	if (!_charsNumber || _currentChar == _charsNumber) {
		_charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
		_currentChar = 0;
	}
	if (_charsNumber <= 0) {
		return -1;
	}
	return _buffer[_currentChar++];
}

static inline int _readInt() {
	int c, x, s;
	c = _read();
	while (c <= 32) c = _read();
	x = 0;
	s = 1;
	if (c == '-') {
		s = -1;
		c = _read();
	}
	while (c > 32) {
		x *= 10;
		x += c - '0';
		c = _read();
	}
	if (s < 0) x = -x;
	return x;
}


int main(void)
{
	deque<int>dq;
	vector<int> Data;
	int n, l;
	n = _readInt();
	l = _readInt();
	Data.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		Data[i] = _readInt();
		if (dq.empty())
			dq.push_back(Data[i]);
		else
		{
			while (!dq.empty() && dq.back() > Data[i])
				dq.pop_back();
			dq.push_back(Data[i]);
		}
		if (i > l)
		{
			if (dq.front() == Data[i - l])
				dq.pop_front();
		}
		printf("%d ", dq.front());
	}
	//while (1);
	return 0;
}