#include <stdio.h>

int month(int bm, int sm){ """ 달을 입력받아 며칠인지 계산함"""
	int dmd = 0;
	while(bm != sm){
		bm--;
		if(bm == 1 || bm == 3 || bm == 5 || bm == 7 || bm == 8 || bm == 10 || bm == 12){
			dmd += 31;
		}
		else if(bm == 4 || bm == 6 || bm == 9 || bm == 11){
			dmd += 30;
		}
		else if(bm == 2){
			dmd += 28;	
		}
		
		
	}
	
	return dmd;
}


int monthc(int gm, int hm){ """달이 큰지 작은지를 비교한 후 month함수에 넣음"""
	if(gm > hm){
		month(gm, hm);
	}
	else{
		month(hm, gm);
	}
	
}


int dayc(int gday, int hday){ """날을 계산"""
	int day = 0;
	if(gday > hday){
		day = gday - hday;
	}
	else if(gday < hday){
		day = hday - gday;
	}
	else{
		day = 0;
	}
	
	return day;
}

int yearc(int gyear, int hyear){ """년도를 계산"""
	int dyd = 0;
	int i = 0;
	i = hyear - gyear;
	
	dyd = (i * 365);
	
	return dyd;
}




int leapc(int gyear, int hyear){"""윤년 계산"""
	int leapt = 0;
	while(gyear != hyear){
		if((gyear % 4 == 0 && gyear % 100 != 0)|| gyear % 400 == 0){
			leapt++;
			gyear++;
		}
		else{
			gyear++;
		}
	}
	return leapt;
}


int main(){
	int gm = 0;
	int hm = 0;
	int hyear = 0;
	int gyear = 0;
	int leapt = 0;
	int hday = 0;
	int gday = 0;
	int dd = 0;
	printf("input 1 start: ");
	while(getchar() != EOF){"""EOF가 입력될때까지 무한히 계산함 """

		printf("Year, month, day\n");
		scanf("%d %d %d", &gyear, &gm, &gday);
		printf("Year, month, day\n");
		scanf("%d %d %d", &hyear, &hm, &hday);
		
		leapt = leapc(gyear, hyear);
		if(gm > hm){
			dd = yearc(gyear, hyear) - monthc(gm, hm) - dayc(gday, hday);
		}
		else if(hm > gm){
			dd = yearc(gyear, hyear) + monthc(gm, hm) + dayc(gday, hday);
		}
		else{
			dd = yearc(gyear, hyear) + dayc(gday, hday) + leapc(gyear, hyear);
		}

		printf("%d\n", dd);
	}
}
