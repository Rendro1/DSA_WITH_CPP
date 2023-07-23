#include<bits/stdc++.h>
using namespace std;

bool areAnagram(string s1, string s2)
{
	map<char, int> m;
	for(int i = 0; i < s1.length(); i++)
		m[s1[i]]++;
		
	for(int i = 0; i < s2.length(); i++)
		m[s2[i]]--;
		
	for(auto it = m.begin(); it != m.end(); it++)
		if(it -> second != 0)
			return false;
			
		return true;
}

int countAnagrams(string text, string word)
{
	
	int res = 0;
	for(int i = 0; i < text.length() - word.length() + 1; i++)
	{
		if (areAnagram(text.substr(i, word.length()),word))
			res++;
	}
	return res;
}
int main()
{
	string text = "forxxorfxdofr";
	string word = "for";
    // cout<<text.substr( word.length())<<endl;
	
	cout << countAnagrams(text, word);
	
	return 0;
}