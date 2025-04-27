#include <stdio.h>


int main(){
	int m;
	scanf("%d",&m);	
		for(int j=1;j<=m;j++){
			printf("* ");
	}
	printf("\n");
	for(int i=1;i<=m-2;i++){
		printf("* ");
		for(int j=1;j<=m-2;j++){
			printf("  ");
		}
		printf("* ");
		printf("\n");
	}
		for(int j=1;j<=m;j++){
			printf("* ");
	}
	
	
	return 0;
}

