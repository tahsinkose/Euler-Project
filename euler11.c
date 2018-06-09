#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ** grid;
	grid = (int **)malloc(sizeof(int*)*26);
	for(int i=0;i<26;i++)
		grid[i] = (int *) malloc(sizeof(int)*26);
	
	// Pad with zeroes to ease the problem.
	for(int i=0;i<3;i++)
		for(int j=0;j<26;j++)
			grid[i][j]=0;
	for(int i=23;i<26;i++)
		for(int j=0;j<26;j++)
			grid[i][j]=0;
	for(int j=0;j<3;j++)
		for(int i=0;i<26;i++)
			grid[i][j]=0;
	for(int j=23;j<26;j++)
		for(int i=0;i<26;i++)
			grid[i][j]=0;
	//......	
	for(int i=3;i<23;i++)
		for(int j=3;j<23;j++)
			scanf("%d",&grid[i][j]);
	
	
	long horizontal_largest=1;
	long vertical_largest=1;
	long diagonal=1;
	long product;
	size_t i=0;
	for(;i<26;i++)//This is the horizontally biggest value
	{
		for(size_t j=0;j<23;j++)
		{
			product=grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
			if(product>horizontal_largest)
				horizontal_largest=product;
		}
	}//end for
	
	for(size_t k=0;k<26;k++)//This calculates vertical largest value
	{
		for(i=0;i<23;i++)
		{
			product=grid[i][k]*grid[i+1][k]*grid[i+2][k]*grid[i+3][k];
			if(product>vertical_largest)
				vertical_largest=product;
		}
	}
	
	for(size_t k=0;k<23;k++){
		for(size_t j=0;j<23;j++){
			product = grid[k][j]*grid[k+1][j+1]*grid[k+2][j+2]*grid[k+3][j+3];
			if(product>diagonal)
				diagonal = product;
		}
	}

	for(size_t k=0;k<23;k++){
		for(size_t j=23;j>=3;j--){
			product = grid[k][j]*grid[k+1][j-1]*grid[k+2][j-2]*grid[k+3][j-3];
			if(product>diagonal)
				diagonal = product;
		}
	}

	for(size_t k=23;k>=3;k--){
		for(size_t j=23;j>=3;j--){
			product = grid[k][j]*grid[k-1][j-1]*grid[k-2][j-2]*grid[k-3][j-3];
			if(product>diagonal)
				diagonal = product;
		}
	}

	for(size_t k=23;k>=3;k--){
		for(size_t j=0;j<=23;j++){
			product = grid[k][j]*grid[k-1][j+1]*grid[k-2][j+2]*grid[k-3][j+3];
			if(product>diagonal)
				diagonal = product;
		}
	}

	if(horizontal_largest > vertical_largest){
		if(horizontal_largest > diagonal)
			printf("%ld\n",horizontal_largest);
		else
			printf("%ld\n",diagonal);	
	}
	else{
		if(vertical_largest > diagonal)
			printf("%ld\n",vertical_largest);
		else
			printf("%ld\n",diagonal);
	}
	
}
