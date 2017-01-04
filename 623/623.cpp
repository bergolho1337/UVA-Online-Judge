/* 623 500! Accepted C++ 0.040 2011-02-03 12:04:35 */
#include<stdio.h>
#include<string.h>

char str1[5000];
char str2[6];
char result[5000];
char table[1001][5000];

// Simula a operacao de multiplicacao entre dois numeros (numero = string)
void mul()
{
	int i,j,k,m,carry;
	int len_1=strlen(str1);
	int len_2=strlen(str2);
	for(i=0;i<len_1+len_2+1;i++)
		result[i]='0';
	for(i=len_1-1;i>=0;i--)
    {
		for(j=len_2-1,carry=0;j>=0;j--)
        {	
			m=i+j+1;
			k=(str1[i]-'0')*(str2[j]-'0')+(result[m]-'0')+carry;
			result[m]='0'+k%10;
			carry=k/10;
        }
		k=i;
		result[i]+=carry;
		while(result[k]>'9')
        {
			result[k-1]++;
			result[k]-=10;
			k--;
        }
	}
	result[len_1+len_2]='\0';
	if(result[0]=='0')
		for(i=0;result[i]!='\0';i++)
			result[i]=result[i+1];
	strcpy(str1,result);
}
int main()
{
	str1[0]='1';
	str1[1]='\0';
	int i;
    // Monta a tabela com os fatoriais
	for(i=1;i<=1001;i++)
    {
		strcpy(table[i-1],str1);
		sprintf(str2,"%d",i);		
		mul();
    }			
	int n;
	while(scanf("%d",&n)==1)
    {
		printf("%d!\n",n);
		if(n==0)
        {
			puts("1");
			continue;
        }
		printf("%s\n",table[n]);
	}
	return 0;
}