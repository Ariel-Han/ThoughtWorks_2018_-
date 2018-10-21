#pragma once

#include <string>

using namespace std;

typedef unsigned long DWORD;

class text_processor 
{
private:
	string cat_rows(int rowBegin, int rowEnd);

public:
	bool check_width(DWORD width);
	string process(const string& text, DWORD width);
};
