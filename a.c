#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main()
{
    int a[10] = {0};

    printf("size of a = %d\n", (int)sizeof(a));
}

void main18()
{
    int *p = 0;
    int x = sizeof(*p); // this is valid because sizeof doesn't actually dereference the pointer

    p = malloc(sizeof(*p)); // same reason why this is also valid
    *p = 1;
    printf("*p = %d; x = %d\n", *p, x);
    free(p);
}

void main17()
{
    typedef enum
    {
        ENUM_A = 12,
        ENUM_B
    } ENUM_T;

#define BLAH 10
    ENUM_T enumvar = BLAH;

    switch(enumvar)
    {
        case ENUM_A:
            printf("A\n");
            break;
        case ENUM_B:
            printf("B\n");
            break;
        case BLAH:
            printf("BLAH\n");
            break;
        default:
            printf("default\n");
            break;
    }
}

void main16()
{
    //printf("strlen = %d\n", strlen("thisisatest"));
    //printf("sizeof = %d\n", sizeof("thisisatest"));
}

void main15()
{
    int a = 0;
    unsigned char b = 0xFF;

    a = b << 24;

    printf("a = %d\n", a);
}

void main14()
{
    char enOrDis[8];
    int no = 1;
    (no == 0) ? memcpy(enOrDis, "disabled", strlen("disabled"))
              : memcpy(enOrDis, "enabled", strlen("enabled"));
    printf("%s\n", enOrDis);
}

#include "testLib.h"
void main13()
{
    int i = 10, n;

    printf("calling library with %d\n", i);
    // call test library function.
    //n = libfunc(i);
    printf("library returned %d\n", n);
}

#define MAKE_BIG_ENDIAN_L(X) (X) = htonl((X))

void main12()
{
    int a = 10;

    printf("little endian = %d\n", a);
    MAKE_BIG_ENDIAN_L(a);
    printf("big endian = %d\n", a);
}

void main11()
{
    char str[10];

    memcpy(str, "content", strlen("content"));

    printf("before %s after\n", str);
}

void main10()
{
    int bytes = 1;
    void *ptr = malloc(bytes);

    printf("allocating %d bytes at memory location %p.\n", bytes, ptr);

    printf("freeing at memory location %p.\n", ptr);
    free(ptr);
}

void main9()
{
    printf("%d", -1);
}

void main8()
{
    char arr[100];

    memset(arr, 2, sizeof(arr));
    arr[99] = '\0';

    printf("%s\n", arr);
    sprintf(arr, "test\n");
    printf("%s\n", arr);
}

#define DBG_PRINTF(...) printf("\033[1;31m"), printf(__VA_ARGS__), printf("\033[0m")

void main7()
{
    int i;

    DBG_PRINTF("Hello world\n"); printf("test\n"); return;
    for (i = 30; i < 40; i++)
    {
        //DBG_PRINTF("Hello world\n", i);
        printf("%d -->    normal = \033[0;%dmGoogie\033[0m    bold = \033[1;%dmGoogie\033[0m\n", i, i, i);
    }
}

int func()
{
    return (0);
}

void main1()
{
    if(func() == 0) {
        printf("== 0\n");
    }
    else {
        printf("> 0\n");
    }
}

void main2()
{
    int hexNum = 0xF;
    printf("hex = %x, dec = %d\n", hexNum, hexNum);
}

#define MYPRINTF printf
void main3()
{
    MYPRINTF("hello world %d\n", 1);
}

void main4()
{
    printf("int = %lu\n", sizeof(int));
    printf("%lu\n", sizeof(unsigned long int));
    printf("%lu\n", sizeof(unsigned long long));
}

void main5()
{
    10;
    printf("done\n");
}

#define Global_Addr 100
#define Comp1_Addr (Global_Addr + 100)
#define Comp2_Addr (Comp1_Addr + 100)
#define COMMON_ADDR_END (Comp2_Addr + 100)

//#define VSP
#ifdef VSP
#define vspComp1_Addr COMMON_ADDR_END
#define vspComp2_Addr (vspComp1_Addr + 100)
#define vspComp3_Addr (vspComp2_Addr + 100)
#define VSP_ADDR_END (vspComp3_Addr + 100)
#else
#define VSP_ADDR_END COMMON_ADDR_END
#endif

#define lastComp_Addr VSP_ADDR_END


void main6()
{
    printf("last comp addr = %d\n", lastComp_Addr);
}


#if 0
int main()
{
    printf("short     = %lu bytes\n", sizeof(short));
    printf("int       = %lu bytes\n", sizeof(int));
    printf("long      = %lu bytes\n", sizeof(long));
    printf("long long = %lu bytes\n", sizeof(long long));
    return 0;
}

int main()
{
    if ((-1 % 2) == 0)
    {
        printf("even\n");
    }

    return 0;
}

void main()
{
    int a[10] = { -1 };
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d -> %d\n", i, a[i]);
    }
}

void main()
{
    struct tm o;
    time_t t1=0;
    char timeStr[30] = {0};

    localtime_r(&t1, &o);
    strftime(timeStr, 30, "%H:%M:%S ??? on %d %b %Y", &o);
    printf("%s\n", timeStr);

    gmtime_r(&t1, &o);
    strftime(timeStr, 30, "%H:%M:%S UTC on %d %b %Y", &o);
    printf("%s\n", timeStr);

    //printf("%d:%d:%d UTC on %d/%d/%d\n",
    //       o.tm_hour, o.tm_min, o.tm_sec,
    //       (o.tm_year + 1900), (o.tm_mon + 1), o.tm_mday);
}

void main()
{
    int time;

    while (1)
    {
        fflush(stdin);
        printf("Enter time in seconds (0 to quit): ");
        scanf("%d", &time);

        if (time == 0)
        {
            break;
        }

        printf("%u s = %u.%u m\n", time, (time / 60), ((time % 60) / 10));
    }
}

#define INC(_port, _ctr) (((_port) >= 0) ? a[_port][_ctr]++ : _port)

void main()
{
    int a[2][2] = { 1, 2, 3, 4 };
    int i, j;

    INC(-1, 0);

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    FILE *fp = fopen("/tmp/1", "w");
    fprintf(fp, "Hello %d\n", 1);
    fprintf(fp, "There %d\n", 2);
    close(fp);
}

void main7()
{
    char str[50];

    sprintf(str, "%s", "short string");
    printf("%s\n", str);

    sprintf(str, "%s", "much longer string");
    printf("%s\n", str);

    sprintf(str, "%s", "v sh str");
    printf("%s\n", str);
}

void main6()
{
    printf("blah         : %7d\n", 1500000);
    printf("dgkhsdn      : %7d\n", 1900);
    printf("dgkhsdn      : %7d\n", 900);
    printf("dgkhsdn      : %7d\n", 1000);
}

void main5()
{
    printf("%7.2f\n", 4294967295/1024.0/1024.0);
#if 0
    int Fahrenheit;

        for (Fahrenheit = 0; Fahrenheit <= 300; Fahrenheit = Fahrenheit + 20)
                printf("%3d %06.3f\n", Fahrenheit, (5.0/9.0)*(Fahrenheit-32));
#endif
}

int func2()
{
    int x = 10;

    return ((x == 10) ? 50 : 100);
}

void main4()
{
    int c;

    c = func2();

    printf("c = %d\n", c);
}

int a = 10;
int b = 20;

void func(int **x, int *y)
{
    int *p = &b;

    //if ((*x == 0) || (y == 0))
    if ((x == 0) || (y == 0))
    {
        printf("invalid params\n");
        return;
    }

    *y = 15;
    *x = p;
}

void main3()
{
    int l = 5;
    int *p = &a;
    printf("before: p points to %d; l = %d\n", *p, l);
    func(&p, &l);
    printf("after: p points to %d; l = %d\n", *p, l);
    func(0, 0);
}

void main2()
{
    //printf("size of int = %d\n", sizeof(int));
    //printf("size of long int = %d\n", sizeof(long int));
    //printf("size of long long int = %d\n", sizeof(long long int));
}

void main1()
{
    char a[] = "This is the original sentence";
    char *p1 = &a[5];
    char *p2 = &a[12];

    printf("Before: %s", a);

    sprintf(p1, "%s", p2);

    printf("After: %s", a);
}
#endif
