#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int a[100];
	int j=0;
	while(n){
		a[j++]=n%10;
		n/=10;
	}
	int flag=1;
	for(int i=0;i<j;i++){
		if(a[i]!=a[j-1]){
			flag=0;
			break;
		}
	}
	if (flag) {
		printf("Y\n");
	} else {
		printf("N\n");
	}
	return 0;
}
