#include <stdio.h>

int main() {
    int arr1[1000] = { 0 }, arr2[1000] = { 0 }, arrmix[2000] = { 0 };
    int m, n;
    scanf("%d%d", &m, &n);
    int i;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }
    //输入完毕
    //主体部分
    int ix, i1 = 0, i2 = 0, imn = m + n;
    for (ix = 0; ix < imn; ix++)
    {
        if (i1 < m && i2 < n)
        {
            if (arr1[i1] < arr2[i2])
            {
                arrmix[ix] = arr1[i1];
                i1++;
            }
            else {
                arrmix[ix] = arr2[i2];
                i2++;
            }
        }
        else if (i1 < m)
        {
            arrmix[ix] = arr1[i1];
            i1++;
        }
        else {
            arrmix[ix] = arr2[i2];
            i2++;
        }
    }
    for (ix = 0; ix < imn; ix++)
    {
        printf("%d ", arrmix[ix]);
    }
    return 0;
}


