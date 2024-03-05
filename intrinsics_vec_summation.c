#include <stdio.h>
#include <stdint.h>
#include <xmmintrin.h>
#include <emmintrin.h>



void intrinsics_sum(float* a, float* b){
    //using _mm_load_ps
    __m128 arr_a =  _mm_load_ps(a);
    __m128 arr_b =  _mm_load_ps(b);

 /*//using _mm_set_ps
    __m128 arr_a = _mm_set_ps(4.0, 2.3, 5.6, 7.0);
    __m128 arr_b = _mm_set_ps(5.6, 7.0, 8.5, 6.6);
*/   

    __m128 arr_c = _mm_add_ps(arr_a, arr_b);

    float add_arr[4];

    _mm_storeu_ps(add_arr, arr_c);


    for(int i = 0; i < sizeof(add_arr)/sizeof(add_arr[0]); i++){
        printf("%f\n",add_arr[i]);
    };
    
    printf("..........\n");
}

void intrinsics_mul(float* a, float* b){
    //loading the arrays
    __m128 arr_a =  _mm_load_ps(a);
    __m128 arr_b =  _mm_load_ps(b);

    //doing math operation
    __m128 arr_c  = _mm_mul_ps(arr_a, arr_b);

    //initializing an array to store this value
    float mult_arr[4];

    //transferring end result to above array
    _mm_storeu_ps(mult_arr, arr_c);

    for(int i = 0;i < sizeof(mult_arr)/sizeof(mult_arr[i]); i++){
        printf("%f\n",mult_arr[i]);
    };
    
    printf("..........\n");
}



int main(){
   float first[4] = {4.0, 2.3, 5.6, 7.};
   float second[4] = {5.6, 7.0, 8.5, 6.6};

   intrinsics_sum(first, second);
   intrinsics_mul(first, second);

   return 0;

} 

