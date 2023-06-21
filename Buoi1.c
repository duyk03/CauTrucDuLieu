#include <stdio.h>

void sapXep()
{
	// Chua sap xep
	int i, j;
	int arrNumber[] = {4, 21, -6, 2};
	printf("Mang chua sap xep\n");
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", arrNumber[i]);
	}

	// Sap xep
	for (i = 0; i < 4; i++)
	{
		for (j = j + 1; j < 4; j++)
		{
			if (arrNumber[i] > arrNumber[j])
			{
				int temp = arrNumber[i];
				arrNumber[i] = arrNumber[j];
				arrNumber[j] = temp;
				printf("%d\n", arrNumber[i]);
			}
		}
	}
	// In ra mang sap xep
	
}
void timkiemsocantim(int arrNumber[], int soCanTim)
{
	for(int i = 0; i < 4; i++){
		if(arrNumber[i] == soCanTim){
			printf("So can tim %d\n", arrNumber[i]);
			return;
		}else{
			printf("Khong tim thay");
		}
	}
}
void viTri(int arrNumber[], int soCanTim){
	for( int i = 0; i < 4; i++){
		if(arrNumber[i] == soCanTim){
			
			return i;
		}
	}
return -1;
}
int main()
{
	sapXep();
	int arrNumber[] = {4, 21, -6, 2};
	// timkiemsocantim(arrNumber, 21);
	// if (viTri(arrNumber, 21)== -1)
	// {
	// 	printf("Khong tim thay");
	// }else{
	// 	printf("Vi tri la : %d", viTri(arrNumber, 21));
	// }
	
	return 0;
}
