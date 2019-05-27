#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fptr1, *fptr2;
	int c, c1,c2;

	if(NULL==(fptr1=fopen("testfile.c","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	
	if(NULL==(fptr2=fopen("testq1.c","w")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	while((c1=fgetc(fptr1)) != EOF)
	{
		if(c1 == '/')
		{
			c2 = fgetc(fptr1);
			if(c2 == '/')
			{
				while((c1 = fgetc(fptr1)) != '\n')
				{
					;
				}
				fputc('\n',fptr2);
			}
			if(c2 == '*')
			{
				while((c2=c1) != '*' && (c1=fgetc(fptr1)) != '/')
				{
					;
				}
				fputc('\n',fptr2);
			}
		}
		else
		{
			fputc(c1,fptr2);
		}
	}
	printf("done!!!\n");
	fclose(fptr1);
	fclose(fptr2);

	printf("\nCONTENT OF FILE_1 (testfile.c)\n\n");
	if(NULL==(fptr1=fopen("testfile.c","r")))
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

	printf("\nCONTENT OF FILE_2 AFTER REMOVING COMMENT LINES(testq1.c)\n\n");
	if(NULL==(fptr2=fopen("testq1.c","r")))
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
	
	return 0;
}
