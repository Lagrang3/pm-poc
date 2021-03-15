#pragma once

// C's interface
#ifdef __cplusplus
extern "C" {
#endif
typedef struct ParticleMesh ParticleMesh;
typedef struct handler_t handler_t;

ParticleMesh* pm_new(handler_t*);
void pm_free(ParticleMesh*);
void pm_change(ParticleMesh*);
int pm_sum(ParticleMesh*);

#ifdef __cplusplus
}
#endif
