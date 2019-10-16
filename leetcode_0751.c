#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long ip2long(char *ip)
{
    unsigned short a, b, c, d;
    sscanf(ip, "%hu.%hu.%hu.%hu", &a, &b, &c, &d);
    return ((a << 24) | (b << 16) | (c << 8) | (d));
}
void long2ip(unsigned long ipNum, int post, char *buf)
{
    unsigned long tmp[4] = {0};
    for (int i = 0; i < 4; i++)
    {
        tmp[i] = ipNum & 0xff;
        ipNum >>= 8;
    }
    sprintf(buf, "%lu.%lu.%lu.%lu/%d", tmp[3], tmp[2], tmp[1], tmp[0], post);
    return;
}
char **ipToCIDR(char *ip, int n, int *returnSize)
{
    if (ip == NULL || returnSize == NULL)
    {
        return NULL;
    }
    int count = 0;
    unsigned long ipNum = ip2long(ip);
    unsigned long startNum = ipNum;
    char **output = NULL;
    while (n > 0)
    {
        int postNum = 0;
        int lowZeroBitsNum = startNum | (-1) * startNum;
        while (lowZeroBitsNum > n)
        {
            lowZeroBitsNum >>= 1;
        }
        startNum += lowZeroBitsNum;
        n -= lowZeroBitsNum;
        while (lowZeroBitsNum > 0)
        {
            lowZeroBitsNum >>= 1;
            postNum++;
        }
        output = (char **)realloc(output, (count + 1) * sizeof(char *));
        output[count] = (char *)malloc(25 * sizeof(char));
        long2ip(startNum, postNum, output[count]);
        count++;
    }
    *returnSize = count;
    return output;
}
// TestSuite
int main()
{
    char *ip = "255.0.0.7";
    int n = 10;
    //unsigned long ipNum = ip2long(ip);
    char **buf;
    int rslt = 0;
    //long2ip(ipNum, 24, buf);
    //printf("%s\n", buf);
    buf = ipToCIDR(ip, n, &rslt);
    printf("%s\n", buf[0]);
    printf("%s\n", buf[1]);
    printf("%s\n", buf[2]);
    return 0;
}