#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fptr1, *fptr2, *fptr3;
	char ch;
	int c;
	if(NULL == (fptr1 = fopen("s1","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	if(NULL == (fptr2 = fopen("s2","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}

	if(NULL == (fptr3 = fopen("d1","w")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	
	
	while((ch = fgetc(fptr1)) != EOF)
	{
		fputc(ch,fptr3);
	}

	while((ch = fgetc(fptr2)) != EOF)
	{
		fputc(ch,fptr3);
	}

	printf("\nContent copied successfully to the third file\n");

	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);

	printf("\nContent of file_1\n\n");
	if(NULL == (fptr1 = fopen("s1","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	else
	{
		c=getc(fptr1);
		while(c != EOF)
		{
			putchar(c);
			c=getc(fptr1);
		}
	}
	fclose(fptr1);
	printf("\nContent of file_2\n\n");
	if(NULL == (fptr2 = fopen("s2","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	else
	{
		c=getc(fptr2);
		while(c != EOF)
		{
			putchar(c);
			c=getc(fptr2);
		}
	}
	fclose(fptr2);
	printf("\nContent of file_3\n\n");
	if(NULL == (fptr3 = fopen("d1","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	else
	{
		c=getc(fptr3);
		while(c != EOF)
		{
			putchar(c);
			c=getc(fptr3);
		}
	}
	fclose(fptr3);
	return 0;
}
