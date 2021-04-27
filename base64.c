#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <wctype.h>

int main()
{
    int i, j, m, k, l, a_length, temp1_length, var, new_std, w;
    char std[10] = "\0";
    char p[10] = "\0";
    char p2[10] = {'0','0'};
    char space[10] = {'0','0','1','0','0','0','0','0'};
    char pad1[10] = {'='};
    char pad2[10] = {'=', '='};
    char padding[10] = "\0";
    char temp0[10] = "\0";
    char temp1[10000] = "\0";
    char temp2[10] = "\0";
    char temp3[10] = "\0";
    char temp4[10000] = "\0";
    char temp5[10000] = "\0";
    char a[1000] = "\0";
    char BASE64[100] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f',
    'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
    'w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};

    printf("input string: \n");
    scanf("%[^\n]s", a);
    printf("%d\n", strlen(a));

    a_length = strlen(a);
    m = a_length%3;
    if(m == 1)
    {
        padding[0] = '0';
        padding[1] = '0';
    }else if (m == 2)
    {
        padding[0] = '0';
    }
    strncat(a, padding, strlen(padding));

    for(i = 0; a[i] != '\0'; i++)
    {
        if (a[i]== ' ')
        {
            strncat(temp1, space, strlen(space));
        }
        else
        {
            itoa(a[i], temp0, 2);
            for (w = 0; w < (8-strlen(temp0)); w++)
            {
                padding[w] = '0';
            }
            strncpy(p, padding, strlen(padding));
            strncat(p, temp0, strlen(temp0));
            strncat(temp1, p, strlen(p));
            memset(padding, '\0', sizeof(padding));
            memset(p, '\0', sizeof(p));
            memset(temp0, '\0', sizeof(temp0));
        }
    }

    temp1_length = strlen(temp1);

    for(j = 0; j <= temp1_length; j++)
    {
        strncat(temp2, temp1+j, 1);
        if(strlen(temp2) == 6)
        {
            strncat(std, p2, 2);
            strncat(std, temp2, strlen(temp2));
            new_std = (int)strtol(std, NULL, 2);
            temp3[0] = BASE64[new_std];
            strncat(temp4, temp3, 1);
            memset(temp2, '\0', sizeof(temp2));
            memset(temp3, '\0', sizeof(temp3));
            memset(std, '\0', sizeof(std));
        }
    }
    if(m==1)
    {
        strncpy(temp5, temp4, strlen(temp4)-2);
        strncat(temp5, pad2, 2);
    }else if (m==2)
    {
        strncpy(temp5, temp4, strlen(temp4)-1);
        strncat(temp5, pad1, 1);
    }else if (m==0)
    {
        strncpy(temp5, temp4, strlen(temp4));
    }
    
    printf("%s\n", temp5);
    system("pause");
    return 0;
}