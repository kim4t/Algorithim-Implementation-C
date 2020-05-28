#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))   
void selection_sort(int* arr, int size)
{
    int i, j, least, tmp;
    for (i = 0; i < size - 1; i++)
    {
        least = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[least]) least = j;
        SWAP(arr[i], arr[least], tmp);
    }
}
