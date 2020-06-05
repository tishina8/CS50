#include <cs50.h>
#include <stdio.h>
long l(void);
int main(void)
{     
        long l =get_long ("Number: ");
        //проверяем кол-во цифр в введенном числе и  начинаются  ли с нужных цифр
       
        double n=l/10000000000000; //10^13
        double n1=l/100000000000000; //10^14 
        double n2=l/100000000000;  // 10^11

        if ( (37<=n && n<38) || (34<=n && n<35) ||
         ( 51<=n1 && n1<56) ||  (40<=n1 && n1<50) ||
          (40<=n2 && n2<50))
  {  
             //находим сумму всех вторых по счету цифр, начиная с конца
           long z = l;
           int sum1 = 0;
            while (z!=0)
                {
                  sum1 =sum1 + z%10;
                  z= z/100;
                }
        
         
  //находим сумму умножения на 2 всех вторых чисел начиная со второго числа с конца
        
           long w = l;
             w=w/10;
           int sum2=0;
           int k;
             while (w!=0)
             {
               k =(w%10)*2;
               
                 if (k < 10 )   
                  {
                        
                  sum2 =sum2 + k;
                 w= w/100; 
                  }
                 else if (k >= 10)
                  {
                    k=k%10+k/10;
                    sum2 =(sum2 + k);
                    w=w/100;
                  }    
                }        
          
      
         
                          
    //проверяем  является ли остаток от делений введенного числа на 10 нулем

               int sum = sum1+sum2;
              
                if (sum%10!=0)
                    {
                        printf("INVALID\n");  // если не делится, то invalid
                    }
     
                else 
                    {  int s=1 ;            // подсчитываем длину числа l
                      long p = l;
                       while ((p=p/10)>0)
                            {
                               s++;
                            } 
                         if (s==15)
                         {
                            printf ("AMEX\n");
                         }
                         else if (s==13)
                         {
                             printf ("VISA\n");
                         }
                         else if (s==16)
                         {     
                              if ((l/1000000000000000)==5)
                              {
                               printf ("MASTERCARD\n");
                              }
                              else if ((l/1000000000000000)==4)
                              {
                                printf ("VISA\n");
                              }
                         }
                    }
  }
     else
     {
          printf("INVALID\n");
     }
}    



