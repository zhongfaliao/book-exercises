// Chapter-6.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <cctype>
#include <algorithm>

#include <iostream>
#include <vector>

using std::vector;
using std::string;

struct Rotation
{
	vector<string>::size_type size;
	vector<string> words;
};

std::string get_line() {
	std::string line;
	getline(std::cin, line);
	return line;
}

vector<string> split(string & line) {
	vector<string> words;
	string::size_type i = 0;
	while (i != line.size())
	{
		while (i != line.size() && isspace(line[i]))
		{
			++i;
		}
		string::size_type j = i;
		while (j != line.size() && !isspace(line[j]))
		{
			++j;
		}

		if (j != i)
		{
			words.push_back(line.substr(i, j - i));
			i = j;
		}
	}
	return words;
}

bool space(char c) {
	return isspace(c);
}

bool not_space(char c) {
	return !isspace(c);
}

bool is_palindrome(const string & s) {
	return std::equal(s.begin(), s.end(), s.rbegin());
}

vector<string> split1(const string & line) {
	vector<string> words;
	typedef string::const_iterator iter;
	iter i = line.begin();

	while (i != line.end())
	{
		i = std::find_if(i, line.end(), not_space);
		iter j = std::find_if(i, line.end(), space);

		if (i!=line.end())
		{
			words.push_back(string(i, j));
		}
		i = j;
	}

	return words;
}

std::vector<std::string> get_lines() {
	std::vector<std::string> lines;
	std::string line;
	while (getline(std::cin, line))
	{
		lines.push_back(line);
	}
	return lines;
}

void print_lines(const std::vector<std::string> & lines) {
	for (std::vector<std::string>::size_type i = 0; i < lines.size(); i++)
	{
		std::cout << lines[i] << std::endl;
	}
}

int main()
{
	std::string line = get_line();
	
	std::cout << "The following prints the words that you just entered as a line: " 
		<< std::endl;
	

	vector<string> words = split1(line);
	print_lines(words);
	std::cout << words.size() << std::endl;
	
	string test_word;
	std::cout << "enter a word for palindrome test: ";
	std::cin >> test_word;
	if (is_palindrome(test_word)) {
		std::cout << "Yes it is"<< std::endl;
	}
	else
	{
		std::cout << "No it is not" << std::endl;
	}
	

    return 0;
}

