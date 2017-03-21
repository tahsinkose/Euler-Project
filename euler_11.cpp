#include <stdio.h>

int main()
{
	
	int array[][20]={8,02,22,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91,8,
					 49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00,
					 81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65,
					 52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91,
					 22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80,
					 24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50,
					 32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70,
					 67,26,20,68,02,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21,
				     24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72,
					 21,36,23,9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95,
					 78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14,9,53,56,92,
					 16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57,
					 86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58,
					 19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40,
					 04,52,8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66,
					 88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69,
					 04,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36,
					 20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16,
					 20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54,
					 01,70,54,71,83,51,54,69,16,92,33,48,61,43,52,01,89,19,67,48};
	long horizontal_largest=1;
	long vertical_largest=1;
	long diagonal=1;
	long product;
	long diagon_product;
	size_t i=0;
	for(;i<20;i++)//This is the horizontally biggest value
	{
		for(size_t j=0;j<17;j++)
		{
			product=array[i][j]*array[i][j+1]*array[i][j+2]*array[i][j+3];
			if(product>horizontal_largest)
			{
				horizontal_largest=product;
			}
		}
	}//end for
	printf("%d\n",horizontal_largest);
	
	for(size_t k=0;k<20;k++)//This calculates vertical largest value
	{
		for(i=0;i<17;i++)
		{
			product=array[i][k]*array[i+1][k]*array[i+2][k]*array[i+3][k];
			if(product>vertical_largest)
			{
				vertical_largest=product;
			}
		}
	}
	printf("%d\n",vertical_largest);
	
	for(size_t i=0;i<20;i++)
	{
		for(size_t j=0;j<20;j++)
		{
			if(i<3 && j<3)
			{
				product=array[i][j]*array[i+1][j+1]*array[i+2][j+2]*array[i+3][j+3];
				if(product>diagonal)
					diagonal=product;
			}//end if
			else if(i>16 &&j<3)
			{
				product=array[i][j]*array[i-1][j+1]*array[i-2][j+2]*array[i-3][j+3];
				if(product>diagonal)
					diagonal=product;
			}//end else if
			else if(i>=3 && i<=16 && j<3)
			{
				
				product=array[i][j]*array[i+1][j+1]*array[i+2][j+2]*array[i+3][j+3];
				diagon_product=array[i][j]*array[i-1][j+1]*array[i-2][j+2]*array[i-3][j+3];
				if(diagon_product>product)
					product=diagon_product;
				if(product>diagonal)
					diagonal=product;
			}//end else if
			/*--------------------FIRST THREE COLUMNS ARE DESIGNED ACCURATELY--------------------*/
			else if (i<3 && j>16)
			{
				product=array[i][j]*array[i+1][j-1]*array[i+2][j-2]*array[i+3][j+3];
				if(product>diagonal)
					diagonal=product;
			}//end if
			else if(i>16 && j>16)
			{
				product=array[i][j]*array[i-1][j-1]*array[i-2][j-2]*array[i-3][j-3];
				if(product>diagonal)
					diagonal=product;
			}//end else if
			else if(i>=3 && i<=16 && j>16)
			{
				product=array[i][j]*array[i+1][j-1]*array[i+2][j-2]*array[i+3][j+3];
				diagon_product=array[i][j]*array[i-1][j-1]*array[i-2][j-2]*array[i-3][j-3];
				if(diagon_product>product)
					product=diagon_product;
				if(product>diagonal)
					diagonal=product;
			}//end else if
			/*----------------LAST THREE COLUMNS ARE DESIGNED ACCURATELY------------------------*/
			else if(j>=3 && j<=16 && i<3)
			{
				product=array[i][j]*array[i+1][j+1]*array[i+2][j+2]*array[i+3][j+3];
				diagon_product=array[i][j]*array[i+1][j-1]*array[i+2][j-2]*array[i+3][j-3];
				if(diagon_product>product)
					product=diagon_product;
				if(product>diagonal)
					diagonal=product;
			}//end else if
			/*-------------NOW FIRST THREE ROWS ARE DESIGNED ACCURATELY-------------------------*/
			else if(j>=3 && j<=16 && i>16)
			{
				product=array[i][j]*array[i-1][j+1]*array[i-2][j+2]*array[i-3][j+3];
				diagon_product=array[i][j]*array[i-1][j-1]*array[i-2][j-2]*array[i-3][j-3];
				if(diagon_product>product)
					product=diagon_product;
				if(product>diagonal)
					diagonal=product;
			}//end else if
			/*----------------NOW LAST THREE ROWS ARE DESIGNED ACCURATELY-----------------------*/
			else
			{
				product=array[i][j]*array[i+1][j+1]*array[i+2][j+2]*array[i+3][j+3];
				diagon_product=array[i][j]*array[i+1][j-1]*array[i+2][j-2]*array[i+3][j-3];
				if(diagon_product>product)
					product=diagon_product;
				diagon_product=array[i][j]*array[i-1][j+1]*array[i-2][j+2]*array[i-3][j+3];
				if(diagon_product>product)
					product=diagon_product;
				diagon_product=array[i][j]*array[i-1][j-1]*array[i-2][j-2]*array[i-3][j-3];
				if(diagon_product>product)
					product=diagon_product;
				if(product>diagonal)
					diagonal=product;
			}//end else
		}//end for
	}//end for
	printf("%d\n",diagonal);
	
}
