#include<stdio.h>

int main(){
	/*
	int h1,h2,m;
	scanf("%1d%1d:%d",&h1,&h2,&m);
	int h=h1*10+h2,h_rev = h2*10+h1;
	if(h==5 && m>50)
		printf("%d",240+61-m);
	else if(6<=h && h<10)
		printf("%d",60-m+1+(10-(h+1))*60);
	else if(h==15 && m>51)
		printf("%d",240+62-m);
	else if(16<=h && h<20)
		printf("%d",60-m+2+(20-(h+1))*60);
	else if(h_rev >= m)
		printf("%d",h_rev-m);
	else{
		int temp = (h+1)%24;
		temp = (temp%10)*10 + temp/10;
		printf("%d",60-m+temp);
	}
	*/
	int h,m,tot,i=0;
	scanf("%d:%d",&h,&m);
	tot = h*60+m;
	for(tot;;tot++){
		h = (tot/60)%24;
		m = tot%60;
		if(m%10 == h/10 && m/10 == h%10)
			break;
		i += 1;
	}
	printf("%d",i);
	return 0;
}