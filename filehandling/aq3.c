#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int pos, ch;
	FILE *fptr1, *fptr2;
	if(NULL == (fptr1 = fopen("file1","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}

	if(NULL == (fptr2 = fopen("file2","w")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	
	fseek(fptr1, 0L, SEEK_END); 
	pos = ftell(fptr1);
	fseek(fptr1, 0L, SEEK_SET); 
	while (pos--)
	{
		ch = fgetc(fptr1); 
		fputc(ch, fptr2);
	}
	fclose(fptr1);
	fclose(fptr2);    
}
