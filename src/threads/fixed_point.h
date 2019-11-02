#ifndef PINTOS_FIXED_POINT_H
#define PINTOS_FIXED_POINT_H


typedef int fp;  // define fixed point variable.

#define FRACTION_SHIFT 14 // used for fractional value.


#define CONVERTER(A) ((fp)(A << FRACTION_SHIFT)) // convert value to fixed point representation.

/* Get rounded integer of a fixed-point value. */
#define FP_ROUND(A) (A >= 0 ? ((A + (1 << (FRACTION_SHIFT - 1))) >> FRACTION_SHIFT) \
                            : ((A - (1 << (FRACTION_SHIFT - 1))) >> FRACTION_SHIFT))


#define FP_ADD_FP(A, B) (A + B) // add two fixed point.

#define FP_ADD_INT(A, B) (A + (B << FRACTION_SHIFT)) // add fixed point value to integer value.

#define FP_SUB_FP(A, B) (A - B) // subtract two fixed point.

#define FP_SUB_INT(A, B) (A - (B << FRACTION_SHIFT)) // subtract integer value from fixed point.

#define FP_MUL_FP(A, B) ((fp)(((int64_t) A) * B >> FRACTION_SHIFT)) // multiply two fixed point.

#define FP_DIV_FP(A, B) ((fp)((((int64_t) A) << FRACTION_SHIFT) / B)) // divide two fixed point.

#define FP_MUL_INT(A, B) (A * B) // multiply fixed point and integer.

#define FP_DIV_INT(A, B) (A / B) // divide a fixed point by integer.

#define FP_INT_PART(A) (A >> FRACTION_SHIFT) // return decimal part from fixed point.


#endif //PINTOS_FIXED_POINT_H