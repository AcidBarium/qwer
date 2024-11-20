#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    if (N == 2)
    {
        printf("Yes\n");
        printf("1 2\n");
        printf("3 4\n");
        return 0;
    }
    if (N == 3)
    {
        printf("Yes\n");
        printf("3 2 6\n");
        printf("4 3 3\n");
        printf("3 1 5\n");
        return 0;
    }
    printf("Yes\n");
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == 1)
            {
                if (j == 1)
                {
                    printf("1 ");
                    continue;
                }
            }
            if (i == 1)
            {
                if (j == 2)
                {
                    printf("2 ");
                    continue;
                }
            }
            if (i == 2)
            {
                if (j == 1)
                {
                    printf("3 ");
                    continue;
                }
            }
            if (i == 2)
            {
                if (j == 2)
                {
                    printf("4 ");
                    continue;
                }
            }
            if (i == 1 || i == 2)
            {
                printf("%d ", j + 2);
                continue;
            }
            printf("%d ", i + N);
        }
        printf("\n");
    }
    return 0;
}