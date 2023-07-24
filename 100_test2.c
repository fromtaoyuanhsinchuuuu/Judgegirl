#include <stdio.h>


void snake(const int *ptr_array[100][100], int m)
{
    int len = m*m;
    const int *array[len];
    int index = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            array[index] = ptr_array[i][j];
            index++;
        }
    }
    
    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            if (*array[i] > *array[j]){
                const int *temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    // for (int i = 0; i< len ; i++){
    //     printf("%d ",*array[i]);
    // }
    // printf("\n");
    index = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (i % 2 == 0){
                ptr_array[i][j] = array[index];
            }
            else{
                ptr_array[i][m-1-j] = array[index];
            }
            index++;
        }
    }

}
#include <stdio.h>
#include <assert.h>
 
void snake(const int *ptr_array[100][100], int m);
 
int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int i, j, m;
 
  scanf("%d", &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}