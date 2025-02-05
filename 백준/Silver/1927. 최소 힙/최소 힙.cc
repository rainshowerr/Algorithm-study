#include <stdio.h>

int n;
int heap[263000];
int hsize;

void swap(int a, int b) {
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

int main()
{
    int i;
    scanf("%d", &n);
    int x;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if (x == 0 && hsize == 0) {
            printf("0\n");
        }
        else if (x == 0) // heap 에서 삭제
        {
            printf("%d\n", heap[1]);
            heap[1] = heap[hsize--];
            int node = 1;
            while (node <= hsize)
            {
                int lnode = node * 2;
                int rnode = node * 2 + 1;
                if (lnode > hsize) heap[lnode] = 1e9;
                if (rnode > hsize) heap[rnode] = 1e9;
                if (heap[lnode] < heap[node] && heap[lnode] <= heap[rnode])
                {
                    swap(lnode, node);
                    node = lnode;
                }
                else if (heap[rnode] < heap[node] && heap[rnode] < heap[lnode])
                {
                    swap(rnode, node);
                    node = rnode;
                }
                else break;
            }
        }
        else // heap 에 x를 추가
        {
            heap[++hsize] = x;
            int node = hsize;
            while (node != 1 && heap[node] < heap[node / 2])
            {
                swap(node, node / 2);
                node /= 2;
            }
        }
    }
    return 0;
}