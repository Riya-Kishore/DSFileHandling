#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fptr1, *fptr2;
	char ch[50];
	if(NULL == (fptr1 = fopen("s1","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	
	if(NULL == (fptr2 = fopen("d2","w")))
	{
		printf("Error in opening file\n");
		exit(1);
	}

	while(!feof(fptr1))
	{
		fgets(ch,50,fptr1);
		if(0 == strcmp(ch,"\n"))
		{
			continue;
		}
		fputs(ch,fptr2);
		strcpy(ch,"\0");
	}

	printf("content copied successfully to the third file\n");

	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
