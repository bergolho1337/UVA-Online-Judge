#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

int main ()
{
	int i;
	string line;
	bool flag;
	int cont;
	while (getline(cin,line))
	{
		cont = 0;
		for (i = 0; i < line.size(); i++)
		{	
			if ((line[i] >= 'a' && line[i] <= 'z')||(line[i] >= 'A' && line[i] <= 'Z'))
				flag = true;
			else
			{
				if (flag)
				{
					cont++;
					flag = false;
				}
			}
		}
		if (flag)
			cont++;
		cout << cont << endl;
	}
}
