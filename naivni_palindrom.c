#include <stdio.h>
#include <string.h>

#define MAX_INPUT 500

int main(int argc, const char * argv[])
{
    char content[MAX_INPUT];
    FILE * pFile;
    size_t len;
	int max = 0; 
    int i, j, ukLevy, ukPravy;
    
    if (2 != argc)
    {
        printf("Usage: palindrome <filename>");
        return 1;
    }
                
    pFile = fopen(argv[1], "r");
    fscanf(pFile, "%s", content);
        
    len = strlen(content);
    
    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
            ukLevy = i;
            ukPravy = j;
            
            while (content[i] == content[j])
            {
                if (ukPravy - ukPravy <= 1)
                {
                    if (j-i > max) max = j-i;
                    break;
                }
                else ++ukLevy, ++ukPravy;
            }
        }
    }
    
    printf("%d\n", max);

    return 0;
}

