#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int is_vowel(int ch);

int main()
{
	char wrong[100], right[100];
	int i, j, c;
	FILE *fptr1, *fptr2;
	if(NULL == (fptr1 = fopen("wrong","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	if(NULL == (fptr2 = fopen("right","w")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	memset(wrong, 0, 100);
	while('\n' != getchar())
	{
		;
	}
	while(NULL != (fgets(wrong, 100, fptr1)))
	{
		i = j = 0;
		while('\0' != wrong[i])
		{
			if(islower(wrong[i]) && (i==0 || wrong[i-1] == '.'))
			{
				right[j++] = toupper(wrong[i++]);
			}
			else if(wrong[i] == ' ' && wrong[i-1] == 'a' && is_vowel(wrong[i+1]))
			{
				right[j++] = 'n';
				right[j++] = wrong[i++];
			}
			else
			{
				right[j++] = wrong[i++];
			}
		}
		right[j] = '\0';
		fputs(right, fptr2);
	}
	printf("\nDONE!!!\n");
	fclose(fptr1);
	fclose(fptr2);
	printf("\nCONTENT OF WRONG FILE\n\n");
	if(NULL == (fptr1 = fopen("wrong","r")))
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

	printf("\nCONTENT OF RIGHT FILE\n\n");
	if(NULL == (fptr2 = fopen("right","r")))
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

int is_vowel(int ch)
{
	switch(ch)
	{
		case 'a': case 'A':
		case 'e': case 'E':
		case 'i': case 'I':
		case 'o': case 'O':
		case 'u': case 'U':
			return 1;
	}
	return 0;

}
