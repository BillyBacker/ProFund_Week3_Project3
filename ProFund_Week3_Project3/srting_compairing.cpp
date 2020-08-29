#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int len(const char In[256]) {
	int count = 0;
	for (count = 0; count < 256; count++) {
		if (In[count] == 0) {
			break;
		}
	}
	return count;
}
char lowerCase(char In) {
		if (In >= 65 && In <= 90) {
			In += 32;
		}
	return In;
}
int getMin(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

bool less_than(char In1[256], char In2[256]) {
	char* p1 = In1;
	char* p2 = In2;
	for (int i = 0; i < getMin(len(In1), len(In2)); i++) {
		if (lowerCase(*(p1 + i)) < lowerCase(*(p2 + i))) {
			return true;
		}
		else if (lowerCase(*(p1 + i)) > lowerCase(*(p2 + i))) {
			return false;
		}
		else {
			continue;
		}
	}
	if (len(In1) < len(In2)) {
		return true;
	}
	else {
		return false;
	}
}

char* getFirst(char In[5][256]) {
	int MinPos = 0;
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			MinPos = 0;
		}
		else if (less_than(In[i], In[MinPos]) && i != 4 && i != 0) {
			MinPos = i;
		}
		else if (i == 4) {
			if (less_than(In[4], In[MinPos])) {
				MinPos = 4;
			}
		}
	}
	return In[MinPos];
}

int main() {
	char In[5][256];
	printf("Enter 5 word : \n");
	for (int i = 0; i < 5; i++) {
		scanf("%s", &In[i]);
	}
	//scanf("%s, %s, %s, %s, %s", str[0][256], str[1][256], str[2][256], str[3][256], str[4][256]);
	//for (int i = 0; i < 5; i++) {

	//}
	printf("First word in Alphabetical order of these word : %s", getFirst(In));
}