/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long ip2long(char *ip)
{
    unsigned short a,b,c,d;
    sscanf(ip, "%hu.%hu.%hu.%hu", &a, &b, &c, &d);
    return ((a<<24) | (b<<16) | (c<<8) | (d));
}
void long2ip(unsigned long ipNum, int post, int char *buf) {
    int i = 0;
    unsigned long tmp[4] = {0};
    for(int i =0; i < 4; i++) {
        tmp[i] = ip & 0xff;
        ip >> 8;
    }
    sprintf(buf, "%lu.%lu.%lu.%lu/%lu", tmp[3], tmp[2], tmp[1], tmp[0], post);
    return;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **ipToCIDR(char *ip, int n, int *returnSize)
{
    if(ip == NULL || returnSize ==NULL) {
        return NULL;
    }
    int count = 0;
    unsigned long ipNum = ip2long(ip);
    unsigned long startNum = ipNum;
    while (n > 0) {
        int postNum = 0;
        int lowZeroBitsNum = startNum | (-1) * startNum;
        while (lowZeroBitsNum > n) {
            lowZeroBitsNum >> 1;
        }
        startNum += lowZeroBitsNum;
        n -= lowZeroBitsNum;
        while(lowZeroBitsNum > 0) {
            lowZeroBitsNum >> 1;
            postNum++;
        }
        
    }
}
// TestSuite
int main()
{
    int count = 0;
    char *ip = "192.168.122.150";
    unsigned long ipNum = ip2long(ip);
    for(int start = ipNum; )
    //printf("%lu\n", ip2long(ip));
    return 0;
}
