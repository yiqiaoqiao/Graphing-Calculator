#ifndef STACK_OUTPUT_H
#define STACK_OUTPUT_H
/*
-------------------- Testing Push ----------------
------------ Test 1 ------------
H->[2]->|||
H->[3]->[2]->|||
H->[4]->[3]->[2]->|||
------------ Test 2 ------------
H->[a]->|||
H->[b]->[a]->|||
H->[c]->[b]->[a]->|||
------------ Test 3 ------------
H->[World]->|||
H->[Hello]->[World]->|||


-------------------- Testing Pop ----------------
------------ Test 1 ------------
H->[4]->[3]->[2]->|||
H->[3]->[2]->|||
H->[2]->|||
H->|||
------------ Test 2 ------------
H->[c]->[b]->[a]->|||
H->[b]->[a]->|||
H->[a]->|||
H->|||

------------ Test 3 ------------
H->[Hello]->[World]->|||
H->[World]->|||
H->|||


-------------------- Testing Top ----------------
------------ Test 1 ------------
H->[4]->[3]->[2]->|||
This stack top: 4
------------ Test 2 ------------
H->[c]->[b]->[a]->|||
This stack top: c
------------ Test 3 ------------
H->[Hello]->[World]->|||
This stack top: Hello


-------------------- Testing Big Three ----------------
H->[4]->[3]->[2]->|||
----------- Testing Copy CTOR ----------
H->[4]->[3]->[2]->|||
----------- Testing Assignment Operator ----------
H->[4]->[3]->[2]->|||
Press <RETURN> to close this window...
 */
#endif // STACK_OUTPUT_H
