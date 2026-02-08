#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main(){
	
	int i, p, q, t, id[N];
	char buff[10];
	memset(buff,0,10);

	for(i = 0; i < N;i++)
		id[i] = i;

	while(fgets(buff,10,stdin)){
		if(buff[1] != ' ') return -1;

		p = (int)buff[0] - '0';
		q = (int)buff[2] - '0';
		if(id[p] == id[q]) continue;

		for(t = id[p], i = 0;i < N; i++)
			if(id[i] == t) id[i] = id[q];

		printf("%d - %d\n",p,q);
	}	

	return 0;
}
