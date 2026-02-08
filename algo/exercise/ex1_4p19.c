#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

void print_id(int *a);
int main(){
	
	int i, p, q, t, id[N], access = 0;
	char buff[10];
	memset(buff,0,10);

	for(i = 0; i < N;i++)
		id[i] = i;

	while(fgets(buff,10,stdin)){
		if(buff[1] != ' ') return -1;

		p = (int)buff[0] - '0';
		q = (int)buff[2] - '0';
		access += 2;
		if(id[p] == id[q]){ 
			printf("array accessed %d times\n",access);
			access = 0;
			continue;
		}

		for(t = id[p], i = 0;i < N; i++){
			access += 1;
			if(id[i] == t){
				access += 3;
				id[i] = id[q];
			}
		}

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
	for(i = 0;i < N;i++)
		printf("%2d ",a[i]);

	printf("\n");
}
