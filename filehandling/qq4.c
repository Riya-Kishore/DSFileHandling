#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fptr1, *fptr2;
	char ch[100];
	int c;
	if(NULL == (fptr1 = fopen("source","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	
	if(NULL == (fptr2 = fopen("dest","w")))
	{
		printf("Error in opening file\n");
		exit(1);
	}

	while(!feof(fptr1))
	{
		fgets(ch,100,fptr1);
		if(0 == strcmp(ch,"\n"))
		{
			continue;
		}
		fputs(ch,fptr2);
		strcpy(ch,"\0");
	}
	printf("Done!!!\n");
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
