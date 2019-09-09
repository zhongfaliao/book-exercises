// Chapter-6.1.2.cpp : Defines the entry point for the console application.
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

bool not_url_char(char c) {
	// characters, in addition to alphanumerics,
	// that can appear in a URL
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	// see whether c can appear in a URL 
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e) {
	static const string sep = "://";
	typedef string::const_iterator iter;

	iter i = b;

	while ((i=search(i, e, sep.begin(), sep.end()))!=e)
	{

		//make sure the separator isn't at the beginning or end of the line
		if (i != b && i + sep.size() != e) {

			// beg marks the beginning of the protocol-name
			iter beg = i;
			while (beg!=b && isalpha(beg[-1]))
			{
				--beg;
			}

			// is there at least one appropriate character before and after the separator
			if (beg != i && !not_url_char(i[sep.size()]))
			{
				return beg;
			}
		}

		// the separator we found was not part of a valid URL, advance i past this separator
		i += sep.size();

	}

	return e;
}


string::const_iterator
url_end(string::const_iterator b, string::const_iterator e) {
	return std::find_if(b, e, not_url_char);
}

vector<string> find_urls(const string & s) {
	vector<string> ret; // the variable to return
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();
	// look through the entire input
	while (b!=e)
	{
		// look for one or more letters followed by ://
		b = url_beg(b, e);

		// if we found it
		if (b != e) {
			// get the rest of the url
			iter after = url_end(b, e);
			
			//remember the url
			ret.push_back(string(b, after));

			//advance b and check for more urls on the line
			b = after;
		}
	}

	return ret;
}

int main()
{
	
	
	std::cout << "Please input some random text containing URLs: " << std::endl;
	
	std::string line = get_line();

	vector<string> URLs = find_urls(line);

	for (vector<string>::iterator i = URLs.begin(); i != URLs.end(); i++)
	{
		std::cout << *i << std::endl;
	}

    return 0;
}

