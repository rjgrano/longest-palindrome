#include <stdio.h>
#include <string.h>

#define MAX_INPUT 500

int isLetter(int i);

int main(int argc, const char * argv[])
{
    char content[MAX_INPUT];
    FILE * pFile;
    size_t len;
    int max;
    int i, curr, ukLevy, ukPravy;
    
    if (2 != argc)
    {
        printf("Usage: palindrome <filename>");
        return 1;
    }
                
    pFile = fopen(argv[1], "r");
    fscanf(pFile, "%s", content);
        
    len = strlen(content);
    max = 0;
    
    /* i%2 == 0 -> je to pismeno */
    /* i%2 == 1 -> je to mezera */
    
    for (i = 0; i < 2*len + 1; i++)
    {
        if (isLetter(i))
        {
            ukLevy = i / 2 - 1;
            ukPravy = ukLevy + 2;
            curr = 1;
        }
        else
        {
            ukLevy = (i - 1) / 2;
            ukPravy = ukLevy + 1;
            curr = 0;
        }
        
        if (curr > max) max = curr;
        
        while (ukLevy >= 0 && ukPravy < len)
        {
            if (content[ukLevy] == content[ukPravy])
            {
                curr += 2;
                --ukLevy;
                ++ukPravy;
                if (curr > max) max = curr;
            }
            else
            {
                break;
            }
        }
    }
    
    printf("%d\n", max);

    return 0;
}

/* Is it letter or space? */
inline int isLetter(int i)
{
    return i % 2 == 0;
}

