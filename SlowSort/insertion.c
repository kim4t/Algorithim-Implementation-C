#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))   
void insertion_sort(int* arr, int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}
