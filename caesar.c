#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, string argv[])
{
           if (argc == 2)                           //     проверяем наличие 1 аргумента
           {
                int i;
                int h;                              // проверяем или нет букв
            //  string argv[1];
                for ( i = 0, h = strlen(argv[1]); i < h; i++)
                {
                    if  (argv[1][i] >= 'A' && argv[1][i] <= 'z')
                    {
                            printf("Usage: ./caesar key\n"); return 1;
                    }
                }         

            }
            else
            {
                printf("Usage: ./caesar key\n");  return 1;
            }
            
            int c = atoi(argv[1]);
        //    printf("%i\n", c);                 //конBертировать из string в int

        int i;
           int h;
           string s = get_string ("plaintext: ");  
           printf ("ciphertext: ");   
           for ( i = 0, h = strlen(s); i < h; i++) 
           {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    printf("%s\n", s); return 1;
                }
           }
           for ( i = 0, h = strlen(s); i < h; i++) 
           {
                if  (s[i] >= 'A' && s[i] <= 'Z')
                {  // int v = atoi(s);
                //    printf("%c", (v+c)%26);
                    printf ("%c", ((s[i]-65)+c)%26+65);
                }
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    printf ("%c", ((s[i]-97)+c)%26+97); 
                }
                if ((s[i] < '0') || ('9'< s[i] && s[i] < 'A') ||
                    ('Z' < s[i] && s[i]< 'a' )|| ('z' < s[i] ) )
                    // (s[i] >= '0' && s[i] <= '127')
                {
                    printf ("%c", s[i]);
                }
            }
            printf("\n");
}




