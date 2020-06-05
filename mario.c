#include <cs50.h>
#include <stdio.h>
int main(void)
{
  {   int i;
      do
      {
         i = get_int ("Height: ");
      }
      while (8<i || i<1); 
       
     for (int x=0; x<i; x++)
     {
             int y1= i-x-1;
             int y2=x+1;
         for (int y=0; y<y1 ; y++)
         {
            printf (" ");
         }
        
         for (int y=0; y<y2 ; y++)
         {
            printf ("#");
         }  
          
          printf("\n");
        
      }
   }
}
