#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
        float f;
      
        do
        {
            f=get_float("Change owed: ");
        }
        while (f<=0);

     
     
   /*   {         int i = round(f * 100);
       
        if (i % 25==0)
        {
           i=i/25;
           printf ("%i\n",i);
        }
        else if (i % 10==0)
        {
            i=i/10;
            printf ("%i\n",i);
        }
        else if (i % 5==0)
        {
            i=i/5;
            printf ("%i\n",i);
        }
    //    else if (i % 1==0)
    //    {
     //       i=i/1; 
     //       printf ("%i\n",i);
     //   }
      }
    */ 
     { int i = round(f * 100);
       int count=0;
       
           while (i>=25)
            {
            i-=25;
            count++;
            }
        
        
      
                while (i>=10)
                   {
                   i-=10;
                   count++;
                   }
             
           
                  while (i>=5)
                     {
                     i-=5;
                     count++;
                     }
                  
                  
                     while (i>=1)
                        {
                        i-=1;
                        count++;
                        }
                    
                       
                           printf ("%i\n", count);
       }    

      

}
