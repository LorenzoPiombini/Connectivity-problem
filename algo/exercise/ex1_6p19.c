#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define N 10

void print_id(int *a);
int convert(char *str, int *a, int *b);
int main(){
	
	int i, p, q, t, j, id[N], sz[N], access = 0;
	char buff[500] = {0};

	for(i = 0; i < N;i++){
		id[i] = i;
		sz[i] = 1;
	}

	while(fgets(buff,500,stdin)){
		int r = 0;
		if((r = convert(buff,&p,&q)) == -1)
			continue;
		else if(r == 2)
			return 0;

		for(i = p, access += 1; i != id[i]; i = id[i], access += 1);
		for(j = q, access += 1; j != id[j]; j = id[j],access += 1);
		if(j == i){ 
			print_id(id);
			printf("array accessed %d times\n",access);
			access = 0;
			memset(buff,0,strlen(buff));
			continue;
		}
		
		if(sz[i] < sz[j]){
			id[i] = j;
			sz[j] += sz[i];
			access += 1;
		}else{
			id[j] = i;
			access += 1;
			sz[i] += sz[j];
		}

		printf("%d - %d\n",p,q);
		print_id(id);
		printf("array accessed %d times\n",access);
		access = 0;
		memset(buff,0,strlen(buff));
	}	

	return 0;
}

void print_id(int *a)
{
	int i;
	printf("array content:\n");
	for(i = 0;i < N; i++)
		printf("%2d ",a[i]);
	printf("\n");
}

int convert(char *str, int *a, int *b)
{
	str[strlen(str)-1] = '\0';
	if(strstr(str,"q"))
		return 2;

	if(strlen(str) < 3){
		printf("wrong entry, enter two numbers: i.e 9 3\n");
		return -1;
	}

	char *space = strstr(str," ");
	if(!space){
		printf("wrong entry, enter two numbers: i.e 9 3\n");
		return -1;
	}
	
	int ix = space - str;
	char n[ix+1];
	memset(n,0,ix+1);
	strncpy(n,str,ix);
	errno = 0;
	char *endp;
	*a = (int)strtol(n,&endp,10);
	if(errno == EINVAL || errno == ERANGE || *a >= (N - 1)){
		printf("wrong entry, enter two numbers: i.e 9 3. the numbers have to be lower than %d\n",N);
		return -1;
	}

	int l = strlen(&str[++ix]);
	char n2[l+1];
	memset(n2,0,l+1);
	strncpy(n2,&str[ix],l);
	*b = (int)strtol(n2,&endp,10);
	if(errno == EINVAL || errno == ERANGE || *a >= (N - 1)){
		printf("wrong entry, enter two numbers: i.e 9 3. the numbers have to be lower than %d\n",N);
		return -1;
	}
	return 0;
}
