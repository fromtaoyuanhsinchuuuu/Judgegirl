#include <stdio.h>

int main(void)
{
    int n;
    int now_position = -1;
    int first_1_position = -1,first_2_position = -1,first_3_position = -1;
    int largest_1_distance = 0,largest_2_distance = 0,largest_3_distance = 0;
    int second_largest_1_distance = 0,second_largest_2_distance = 0,second_largest_3_distance = 0;
    int now_1_distance,now_2_distance,now_3_distance;
    int second_largest_1_rear_position,second_largest_1_front_position;
    int second_largest_2_rear_position,second_largest_2_front_position;
    int second_largest_3_rear_position,second_largest_3_front_position;
    int largest_1_rear_position,largest_1_front_position;
    int largest_2_rear_position,largest_2_front_position;
    int largest_3_rear_position,largest_3_front_position;
    while (scanf("%d",&n) != EOF){
        now_position++;
        switch (n)
        {
            case 1:
                if (first_1_position < 0){
                    first_1_position = now_position;
                }
                else{
                    now_1_distance = now_position - first_1_position;
                    if (largest_1_distance == 0 || now_1_distance == largest_1_distance){
                        largest_1_distance = now_1_distance;
                        largest_1_front_position = first_1_position;
                        largest_1_rear_position = now_position;
                        // printf("largest_1_front_position:%d largest_1_rear_position:%d\n",largest_1_front_position,largest_1_rear_position);
                    }
                    else if (now_1_distance > largest_1_distance){
                        second_largest_1_distance = largest_1_distance;
                        largest_1_distance = now_1_distance;
                        second_largest_1_front_position = largest_1_front_position;
                        second_largest_1_rear_position = largest_1_rear_position;
                        largest_1_front_position = first_1_position;
                        largest_1_rear_position = now_position;
                        // printf("largest_1_front_position:%d largest_1_rear_position:%d\n",largest_1_front_position,largest_1_rear_position);
                        // printf("second_largest_1_front_position:%d seconde_largest_1_rear_position:%d\n",second_largest_1_front_position,second_largest_1_rear_position);
                    }
                    else if (now_1_distance >= second_largest_1_distance && now_1_distance < largest_1_distance ){
                        second_largest_1_distance = now_1_distance;
                        second_largest_1_rear_position = now_position;
                        second_largest_1_front_position = first_1_position;
                        // printf("second_largest_1_front_position:%d seconde_largest_1_rear_position:%d\n",second_largest_1_front_position,second_largest_1_rear_position);
                    }
                }
                first_1_position = now_position;
                break;
            case 2:
               if (first_2_position < 0){
                    first_2_position = now_position;
                }
                else{
                    now_2_distance = now_position - first_2_position;
                    if (largest_2_distance == 0 || now_2_distance == largest_2_distance){
                        largest_2_distance = now_2_distance;
                        largest_2_front_position = first_2_position;
                        largest_2_rear_position = now_position;
                    }
                    else if (now_2_distance > largest_2_distance){
                        second_largest_2_distance = largest_2_distance;
                        largest_2_distance = now_2_distance;
                        second_largest_2_front_position = largest_2_front_position;
                        second_largest_2_rear_position = largest_2_rear_position;
                        largest_2_front_position = first_2_position;
                        largest_2_rear_position = now_position;
                    }
                    else if (now_2_distance >= second_largest_2_distance && now_2_distance < largest_2_distance ){
                        second_largest_2_distance = now_2_distance;
                        second_largest_2_rear_position = now_position;
                        second_largest_2_front_position = first_2_position;
                    }
                }
                first_2_position = now_position;
                break;
            case 3:
               if (first_3_position < 0){
                    first_3_position = now_position;
                }
                else{
                    now_3_distance = now_position - first_3_position;
                    if (largest_3_distance == 0 || now_3_distance == largest_3_distance){
                        largest_3_distance = now_3_distance;
                        largest_3_front_position = first_3_position;
                        largest_3_rear_position = now_position;
                    }
                    else if (now_3_distance > largest_3_distance){
                        second_largest_3_distance = largest_3_distance;
                        largest_3_distance = now_3_distance;
                        second_largest_3_front_position = largest_3_front_position;
                        second_largest_3_rear_position = largest_3_rear_position;
                        largest_3_front_position = first_3_position;
                        largest_3_rear_position = now_position;
                    }
                    else if (now_3_distance >= second_largest_3_distance && now_3_distance < largest_3_distance ){
                        second_largest_3_distance = now_3_distance;
                        second_largest_3_rear_position = now_position;
                        second_largest_3_front_position = first_3_position;
                    }
                }
                first_3_position = now_position;
                break;
            default:
                break;
        }
    }
    printf("%d %d %d\n",second_largest_1_distance,second_largest_1_front_position,second_largest_1_rear_position);
    printf("%d %d %d\n",second_largest_2_distance,second_largest_2_front_position,second_largest_2_rear_position);
    printf("%d %d %d\n",second_largest_3_distance,second_largest_3_front_position,second_largest_3_rear_position);
    return 0;
}
    
