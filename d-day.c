#include <stdio.h>


int month(int gm, int hm, int leapt){
	int m[12];
	if(gm > hm){
		while(gm != hm){
			int i = 0;
			gm--;
			m[i] = gm;
			i++; 
		}
		return m;	
	}
	else if(hm > gm){
		while(gm != hm){
			int j = 0;
			hm--;
			m[i] = hm;
			j++;
		}
		return m;
	}
	for(int d = 0; m[d] != '\0'; d++){
		if(m[d] == 1 || m[d] == 3 || m[d] == 5 || m[d] == 7 || m[d] == 8 || m[d] == 10 || m[d] == 12){
			return 31;
		}
		if(m[d] == 2){
			if(leapt >= 1){
				return 29;
			}else{
				return 28;
			}
		}
	
		if(m[d] == 4 || m[d] == 6 || m[d] == 9 || m[d] == 11){
			return 30;
		}
	}

	
}


int dayc(int gday, int hday){
	int day = 0;
	if(gday > hday){
		day = gday - hday;
	}
	else if(gday < hday){
		day = hday - gday;
	}
	return day;
}





int leap(int hyear, int gyear){
	int leapt = 0;
	while(gyear != hyear){
		if((gyear % 4 == 0 && gyear % 100 == 0)|| gyear % 400 == 0){
			leapt++;
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
	int leap = 0;
	int hday = 0;
	int gday = 0;

	scanf("%d %d %d %d %d %d", &gm, &gday, &gyear, &hm, &hday, &hyear);
	
	leap += leap(year);
	
	
}
