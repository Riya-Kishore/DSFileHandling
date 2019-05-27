#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fptr1, *fptr2;
	char str[100];
	int n=0, page =1, c;
	if(NULL == (fptr1 = fopen("source1","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	
	if(NULL == (fptr2 = fopen("new","w")))
	{
		printf("Error in opening file\n");
		exit(1);
	}

	while(NULL != (fgets(str,100,fptr1)))
	{
		if(0 == n%50)
		{
			fprintf(fptr2,"\n-------------Page %d -------------\n\n",page++);
		}
		fprintf(fptr2,"%d ",n++);
		fputs(str,fptr2);
	}
	fclose(fptr1);
	fclose(fptr2);

	printf("\n\n-----FILE CONTENT BEFORE ADDING PAGE NUMBER AND LINE NUMBER-----\n\n");
	if(NULL == (fptr1 = fopen("source1","r")))
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
	printf("\n\n-----FILE CONTENT AFTER ADDING PAGE NUMBER AND LINE NUMBER-----\n\n");
	if(NULL == (fptr2 = fopen("new","r")))
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
	
