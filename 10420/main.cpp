#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int main ()
{
	string line, country;
	map<string,int> list;
	map<string,int>::iterator it;
	int n;
	char *token, *lineC;
	cin >> n;
	cin.ignore(256,'\n');
	while (n > 0)
	{
		getline(cin,line);
		//cout << line << endl;
		lineC = new char[line.size()+1];
		strcpy(lineC,line.c_str());
		token = strtok(lineC," ");
		country = lineC;
		if (list.find(country) != list.end())
			list[country] += 1;
		else
			list[country] = 1;
		//cout << country << endl;
		n--;
	}
	for (it = list.begin(); it != list.end(); ++it)
		cout << it->first << " " << it->second << endl;
}
