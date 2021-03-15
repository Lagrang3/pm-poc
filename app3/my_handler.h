#pragma once

#include <stdlib.h>
#include "my_particle_data.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef struct my_handler my_handler;

my_handler* handler_new(my_particle_data* , size_t, double);
void handler_free(my_handler*);

#ifdef __cplusplus
}
#endif
