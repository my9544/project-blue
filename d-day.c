#include <stdio.h>


int month(int m, int leapt){
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
		return 31;
	}
	if(m == 2){
		if(leapt >= 1){
			return 29;
		}else{
			return 28;
		}
	}
	
	if(m == 4 || m == 6 || m == 9 || m == 11){
		return 30;
	}
	
}






int leap(int year){
	int leapt = 0;
	if((year % 4 == 0 && year % 100 == 0)|| year % 400 == 0){
		leapt += 1;
		return leapt;
	}
}


int main(){
	int m = 0;
	int year = 0;
	int leapt = 0;
	scanf("%d %d", &m, &year);
	
	leapt += leap(year);
	
	printf("%d", month(m, leapt));
}