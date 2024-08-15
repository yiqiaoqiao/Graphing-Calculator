#ifndef QUEUE_OUTPUT_H
#define QUEUE_OUTPUT_H
/*
-------------------- Testing Push ----------------
------------ Test 1 ------------
H->[2]->|||
H->[2]->[3]->|||
H->[2]->[3]->[4]->|||
------------ Test 2 ------------
H->[a]->|||
H->[a]->[b]->|||
H->[a]->[b]->[c]->|||
------------ Test 3 ------------
H->[World]->|||
H->[World]->[Hello]->|||



-------------------- Testing Pop ----------------
------------ Test 1 ------------
H->[2]->[3]->[4]->|||
H->[3]->[4]->|||
H->[4]->|||
H->|||
------------ Test 2 ------------
H->[a]->[b]->[c]->|||
H->[b]->[c]->|||
H->[c]->|||
H->|||
------------ Test 3 ------------
H->[World]->[Hello]->|||
H->[Hello]->|||
H->|||


-------------------- Testing Front ----------------
------------ Test 1 ------------
H->[2]->[3]->[4]->|||
This queue front: 2
------------ Test 2 ------------
H->[a]->[b]->[c]->|||
This queue front: a
------------ Test 3 ------------
H->[World]->[Hello]->|||
This stack front: World


-------------------- Testing Big Three ----------------
H->[2]->[3]->[4]->|||
----------- Testing Copy CTOR ----------
H->[2]->[3]->[4]->|||
----------- Testing Assignment Operator ----------
H->[2]->[3]->[4]->|||
Press <RETURN> to close this window...
 */
#endif // QUEUE_OUTPUT_H
