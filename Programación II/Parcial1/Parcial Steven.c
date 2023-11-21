#include <stdio.h>
#include <conio.h>

int f3(int *, char, int);
char *gupta(char *);
int f9(char *);

void main(void){
	char f = 100, *t = 0, cr = 13, *j = 0;
	int k = -1, e = 0;
	
	do{
		f = getch();
		if(f != cr){
			e = f3(&k, f, 8);
			t[k] = e;
			printf("%c", e);
		} else 
		t[k+1] = '\0';
	} while(f != cr);
	j = gupta (t);
	printf("%c", *j);
}

int f3(int *f, char k, int d){
	*f = *f + 1;
	return k + 24 + d;
}

char *gupta(char *k){
	int w = 0, f = 0;
	char *str;
	w = f9(k);
	
	for(f = w; f >= 0; f = f - 1)
		str[w - f] = k[f];
	str[w + 1] = '\0';
	return str;
}

int f9(char *w){
	int f = 0;
	for(f = 0; w[f] != '\0'; f = f + 1);
	return (f - 1);
}
