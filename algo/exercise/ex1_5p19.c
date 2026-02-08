#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

void print_id(int *a);
int main(){
	
	int i, p, q, t, j, id[N], access = 0;
	char buff[10];
	memset(buff,0,10);

	for(i = 0; i < N;i++)
		id[i] = i;

	while(fgets(buff,10,stdin)){
		if(buff[1] != ' ') return -1;

		p = (int)buff[0] - '0';
		q = (int)buff[2] - '0';
		access += 2;	
		for(i = p; i != id[i]; i = id[i]){
			access += 2;	
		}
		access += 2;	
		for(j = q; j != id[j]; j = id[j]){
			access += 2;	
		}

		if(j == i) {
			printf("array accessed %d times\n",access);
			access = 0;
			continue;
		}
		
		access += 1;
		id[i] = j;

		printf("%d - %d\n",p,q);
		print_id(id);
		printf("array accessed %d times\n",access);
		access = 0;
	}	

	return 0;
}

void print_id(int *a)
{
	int i;
	printf("array content:\n");
	for(i = 0; i < N ; i++)
		printf("%2d ", a[i]);
	printf("\n");
}
