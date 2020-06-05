#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "bmp.h"
#include <string.h>
int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // ensure proper n:
    int n = atoi(argv[1]);
    if ((1 > n) || (n > 101))
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }



    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 1;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines
    int y = sizeof(RGBTRIPLE);
    int padding = (4 - (bi.biWidth * y) % 4) % 4;


    // iterate over infile's scanlines
    int amountpic = (abs(bi.biHeight) * (bi.biWidth));  //количество пикселей в структуре

    RGBTRIPLE P[amountpic];                   // массив пикселей infaila
    int i = 0;

    for (int w = 0, biHeight = abs(bi.biHeight) ; w < biHeight; w++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth ; j++)
        {
            RGBTRIPLE triple;

            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            P[i] = triple;
            i++;

        }
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

    }                                                                                                                                                                                                                                                                                                                                                                                                                                              int l=9*n*n;

            int t = amountpic * n * n;
            RGBTRIPLE Z[t];
            int q = bi.biWidth;
            int d = abs(bi.biHeight);
            i = 0;
            int m = 0;

        for (int r=0; r<d; r++)
        {
            for (int k=0; k<n; k++)
            {
               if (k == 0)
               {
                   i = r * d;
               }
               if (k < n && k > 0)
               {
                   i = i - q ;
               }
                for (int g=0; g<q; g++)
                {
                        for(int j=0; j<n; j++)
                        {
                            Z[m]=P[i];
                            m++;
                        }
                  i++;
                }

            }

        }

     //  длина и ширина в пикселях
    bi.biWidth = bi.biWidth * n;

    bi.biHeight =bi.biHeight * n;

    padding = (4 - (bi.biWidth * y) % 4) % 4;
 
    y = sizeof(RGBTRIPLE);
    bi.biSizeImage = (abs(bi.biHeight) * (bi.biWidth * y + padding));

   

    DWORD size = (abs(bi.biHeight) * (bi.biWidth * y + padding)) + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER); // размер в байтах
    bf.bfSize = size;


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    int f = 0;
    int Height;
    for ( i = 0, Height = abs(bi.biHeight) ; i < Height; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth ; j++)
        {

        RGBTRIPLE triple;
        triple =  Z[f];

        // write RGB triple to outfile
        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        f++;

        }
        //  fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }



    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    return 0;


}
