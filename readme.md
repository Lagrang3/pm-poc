PM Proof of Concept
===

This is a Proof of Concept of a C/C++ Particle-Mesh library.

C++ API
===
The library provides a C++ interface consisting of
two classes `ParticleMesh` and `handler_t` (pure virtual).

- `ParticleMesh` does all the computations,
- `handler_t` provides read/write access to the application's particles.

Since every application could encode particle's states in different ways, the
user must derive a handler class from `handler_t` to provide correctly the
input/output streams to the `ParticleMesh`. eg. reading particles' positions
and/or writting particles' forces.

C API
===

The library provides a C interface for `ParticleMesh`.
As in the C++ case, the user must derive a C++ class from `handler_t` for
particles' read/write. In addition the user must write a C interface 
(only for the constructor and destructor) for the derived `handler_t` class.
