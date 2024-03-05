#include <stdio.h>
#include <stdint.h>
#include <xmmintrin.h>
#include <emmintrin.h>

void intrinsics_sum(){
    //using _mm_load_ps
    float a[4] = {4.0, 2.3, 5.6, 7.} ;
    float b[4] = {5.6, 7.0, 8.5, 6.6};

    __m128 arr_a =  _mm_load_ps(a);
    __m128 arr_b =  _mm_load_ps(b);

 /*//using _mm_set_ps
    __m128 arr_a = _mm_set_ps(4.0, 2.3, 5.6, 7.0);
    __m128 arr_b = _mm_set_ps(5.6, 7.0, 8.5, 6.6);
*/   

    __m128 val_c = _mm_add_ps(arr_a, arr_b);

    float d[4];

    _mm_storeu_ps(d, val_c);
    
    for(int i = 0; i < sizeof(d)/sizeof(d[0]); i++){
        printf("%f\n",d[i]);
    };
}


int main(){
   intrinsics_sum();
   return 0;

} 

