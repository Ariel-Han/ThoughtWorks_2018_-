/*******************
Function: Text preprocessor
By: Dongxue Han
*******************/
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "text_processor.h"

using namespace std;

typedef unsigned long DWORD;

	/*function：cat row numbers, comma(",") and parentheses("()") to a string
	param<in>: the number of beginning row, the number of ending row
	return: string
	*/
string text_processor:: cat_rows(int rowBegin, int rowEnd){
	string res("(");
	for (int row = rowBegin; row < rowEnd; row++){
		res += to_string(row);
		res += ",";
	}
	res += to_string(rowEnd);
	res += ");";
	return res;
}

	/*function：check width in range [10, 80]
	param<in>: width of row
	return: T/F
	*/
bool text_processor::check_width(DWORD width){
	if (width >= 10 && width <= 80)
		return true;
	else
		throw  "ERROR: Width out of range!";
}

	/*function：cat row numbers, comma(",") and parentheses("()") to a string
	param<in>: input raw text, row width
	return: post-processed string
	*/
string text_processor::process(const string& text, DWORD width){
	check_width(width);
	int len = text.length();
	string res;
	int type;
	regex pattern_char("^[a-zA-Z]+"); //匹配开头至少一个英文字符
	regex pattern_s("^ +");     //匹配开头至少一个空格
	smatch sm;
	auto iterStart = text.begin();
	auto iterEnd = text.end();
	int rowBegin, rowEnd;
	while (iterStart != iterEnd){
		if (regex_search(iterStart, iterEnd, sm, pattern_char)
			|| regex_search(iterStart, iterEnd, sm, pattern_s)){
			rowBegin = (iterStart - text.begin()) / width;
			rowEnd = (sm[0].second - 1 - text.begin()) / width;
			res += sm[0];
			res += cat_rows(rowBegin + 1, rowEnd + 1);
			iterStart = sm[0].second;
		}
		else{
			throw "ERROR: Invalid character detected!";
		}
	}
	return res;
}


int main(){
	string text, res;
	DWORD width;
	cout << "************Happy Mooncake's Day!***************"<<endl;
	getline(cin, text);
	//text = "The main theme of education in engineering school is learning to teach yourself";
	cin >> width;

	text_processor t;

	try{
		res = t.process(text, width);
	}
	catch (const char* msg){
		cerr << msg << endl;
	}
	cout << res << endl;

	return 0;
}
