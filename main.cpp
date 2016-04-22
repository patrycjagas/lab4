#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string ex1 (int n);
int ex2 (int n);

int main(int argc, char *argv[])
{

	int number = atoi(argv[1]);
	int k = ex2(number);

	if (k!=0)
	{
		cout << "k=" << k << endl << "product=" << number*k<< endl;
		cout << "k wynosi " << ex1(k) << endl << "iloczyn wynosi " << ex1(number*k) << endl;
	}
	else
		cout << "not found" << endl;
	
	return 0;
}

string ex1 (int n)
{
	string text = "";

	string ones [] = {"", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"};
	string teens1 [] ={"dziesiec", "jedenascie", "dwanascie", "trzynascie", "czterynascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};
	string teens2 [] = {"dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat"};
	string hundreds [] = {"", "sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset", "osiemset", "dziewiecset"};
	string thousands [] = {"tysiac", "tysiace", "tysiecy"};
	
	int num1 = n/1000;
	int num2 = n%1000;
 	
 	//piewsza czesc liczby
 	int tmp = num1;
	text += hundreds[tmp/100] + " ";
	tmp = tmp%100;
	if (tmp/10>1)
	{
		text += teens2[(tmp/10)-2] + " ";
		tmp = tmp%10;
		text += ones[tmp] + " ";
	}
	else
		if (tmp/10==0)
		{
			tmp = tmp%10;
			tmp = tmp;
			text += ones[tmp] + " ";
		}
		else
			{	
				tmp = tmp%10;
				tmp = tmp;
				text += teens1[tmp] + " ";
			}

	if (num1 !=0)		
		if (num1==1) text += thousands[0] + " ";
		else if (tmp>1 && tmp<5) text += thousands[1] + " ";
		else text += thousands[2] + " ";

	//druga czesc liczby
	tmp = num2;
	text += hundreds[tmp/100] + " ";
	tmp = tmp%100;
	if (tmp/10>1)
	{
		text += teens2[(tmp/10)-2] + " ";
		tmp = tmp%10;
		text += ones[tmp] + " ";
	}
	else
		if (tmp/10==0)
		{
			tmp = tmp%10;
			tmp = tmp;
			text += ones[tmp] + " ";
		}
		else
			{	
				tmp = tmp%10;
				tmp = tmp;
				text += teens1[tmp] + " ";
			}

	return text;
}


int ex2 (int n)
{
	int k = 0;
	int remainder;
	for (int i = 1; i < 1000000; i++)
	{
		int product = n*i;
		bool condition = true;
		while (product)
		{
			remainder = product%10;
			if (remainder!=0 && remainder!=1) 
			{
				condition = false;
				break;
			}
			product = product/10;
		}

		if (condition == true) 
		{

			k = i;
			break;
		}
	}

	return k;
}