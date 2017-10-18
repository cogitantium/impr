#include <stdio.h>

int main(void) {
	int watts=0,lumens=0;

	printf("Please input brightness in watts: ");
	scanf(" %d",&watts);

	switch(watts) {
		case 100:
			lumens=1675;break;
		case 75:
			lumens=1000;break;
		case 60:
			lumens=880;break;
		case 40:
			lumens=500;break;
		case 25:
			lumens=215;break;
		case 15:
			lumens=125;break;
		default:
			printf("Y'all done fucked up now! ");
	}	
	printf("When W: %d then lumens: %d\n",watts,lumens);	
	return 0;
}