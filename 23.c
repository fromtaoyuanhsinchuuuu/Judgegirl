int max(int *iptr[], int n)
{
    int max_num = 0;
    for (int i = 0 ; i < n ; i++){
        if (*iptr[i] > max_num){
            max_num = *iptr[i];
        }
    }
    return max_num;
}