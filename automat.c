#include <stdio.h>
void main()
{
	float entered_amount, kalan;
	int urun;
	printf("1-cips = 5tl \n");
	printf("2-cay = 10tl \n");
	printf("3-capcitor = 15tl \n");
	printf("4-inductor = 20tl \n");
	printf("\nTutar giriniz \n");
	scanf_s("%f", &entered_amount);
	printf("Urun seciniz \n");
	scanf_s("%d", &urun);
	if (urun == 1) {
		if (entered_amount >= 5) {
			kalan = entered_amount - 5;
			printf("You bought Cips and your change is: %f", kalan);
		}
		else {
			printf("Insufficient money!");
		}
	}
	if (urun == 2) {
		if (entered_amount >= 10) {
			kalan = entered_amount - 10;
			printf("You bought Cay and your change is: %f", kalan);
		}
		else {
			printf("Insufficient money!");
		}
	}
	if (urun == 3) {
		if (entered_amount >= 15) {
			kalan = entered_amount - 15;
			printf("You bought Capcitor and your change is: %f", kalan);
		}
		else {
			printf("Insufficient money!");
		}
	}
	if (urun == 4) {
		if (entered_amount >= 20) {
			kalan = entered_amount - 20;
			printf("You bought Inductor and your change is: %f", kalan);
		}
		else {
			printf("Insufficient money!");
		}
	}
	if ( urun > 4 )
	{
		printf("Wrong selection");
	}
	if (urun < 1)
	{
		printf("Wrong selection");
	}
}
