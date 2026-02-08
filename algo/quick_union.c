#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main(){
	
	int i, p, q, t, j, id[N];
	char buff[10];
	memset(buff,0,10);

	for(i = 0; i < N;i++)
		id[i] = i;

	while(fgets(buff,10,stdin)){
		if(buff[1] != ' ') return -1;

		p = (int)buff[0] - '0';
		q = (int)buff[2] - '0';
		for(i = p; i != id[i]; i = id[i]);
		for(j = q; j != id[j]; j = id[j]);
		if(j == i) continue;
		
		id[i] = j;

		printf("%d - %d\n",p,q);
	}	

	return 0;
}
