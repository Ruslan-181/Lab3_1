#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include "math_df.h"
#include "math_f.h"


double f(double x) {
    double term = (x / 16.0) - 4.0;
    return 8.0 * pow(term, 3) - 4.0 * x - 12.0;
}
