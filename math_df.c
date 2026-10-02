#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include "math_df.h"
#include "math_f.h"


double df(double x) {
    double term = (x / 16.0) - 4.0;
    return 1.5 * pow(term, 2) - 4.0;
}
