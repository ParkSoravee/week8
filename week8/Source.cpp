#include<stdio.h>
void getStr(char*);
void checkStr(char*);
bool isVowel(char);

int main() {
	char str[1000];
	char* pStr = str;
	getStr(pStr);
	//printf("%s\n", str);
	checkStr(pStr);
	return 0;
}

void getStr(char* pStr) {
	scanf_s("%[^\n]s", &*pStr, 999);
}

void checkStr(char* pStr) {
	int i = 0;
	int alpha = 0, vowel = 0, num = 0, word = 0;
	while (*(pStr+i) != '\0') {
		if ( (*(pStr+i) >= 'a' && *(pStr + i) <= 'z') || (*(pStr + i) >= 'A' && *(pStr + i) <= 'Z') ) //vowel
		{
			if ( isVowel(*(pStr+i)) ) vowel++;
			else alpha++;
		}
		else if ((*(pStr + i) >= '0' && *(pStr + i) <= '9')) num++; //num
		
		if (*(pStr + i) == ' ') //space // && *(pStr + i - 1) != ' ' && *(pStr + i + 1) != '\0'
		{
			if (i > 0) word++;
			if (i > 0 and *(pStr + i - 1) == ' ') word--;
			if (*(pStr + i + 1) == '\0') word--;
		}

		i++;
	}
	printf("Alphabet = %d\n", alpha);
	printf("Vowel = %d\n", vowel);
	printf("Number = %d\n", num);
	printf("Word = %d", word+1);
}

bool isVowel(char ch)
{
	char vowel[5] = { 'a','e','i','o','u' };
	for (int i=0;i<5;i++)
	{
		if (ch == vowel[i] || ch == vowel[i] - 'a' + 'A') return true;

	}
	return false;
}
