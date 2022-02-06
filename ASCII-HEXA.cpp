#include <stdio.h>

int main() {
	FILE* soubor = fopen("Tabulka.txt", "w");

	if (soubor == NULL) {
		printf("Error: Soubor nelze otevrit pro zapis.\n");
		return 1;
	}

	int ASCII = 0x40;

	for (int i = 0; i <26 ; i++) {
		ASCII = ASCII + 1;
		fwrite(&ASCII, sizeof(int), 1, soubor);
		fprintf(soubor, "Hexadecimálně: %x\n", ASCII);
	}

	if (fclose(soubor) == EOF) {
		printf("Error: Soubor se nepodarilo otevrit.\n");
		return 1;
	}

	return(0);
}