#ifndef SORTED_LIST_OUTPUT_H
#define SORTED_LIST_OUTPUT_H
/*
=======================================
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
{98}->[74]->[60]->[44]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
r

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[98]->[74]->[60]->[44]->{35}->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
r

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[98]->[74]->[60]->[44]->{38}->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
r

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[98]->[74]->[60]->[44]->{38}->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
r

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[98]->[74]->[60]->[44]->{41}->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
r

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[98]->[74]->[60]->[44]->{41}->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
i

?: 45
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[98]->[74]->[60]->{45}->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
i

?: 100
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
{100}->[98]->[74]->[60]->[45]->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
i

?: 3
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->[45]->[44]->[41]->[38]->[35]->[20]->{3}->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
d

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
{100}->[98]->[74]->[60]->[45]->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
p

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
{100}->[98]->[74]->[60]->[45]->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
n

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->{98}->[74]->[60]->[45]->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
n

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->{74}->[60]->[45]->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
n

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->{60}->[45]->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
n

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->{45}->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
n

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->[45]->{44}->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
n

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->[45]->[44]->{41}->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
n

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->[45]->[44]->[41]->{38}->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
n

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->[45]->[44]->[41]->[38]->{35}->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
n

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->[45]->[44]->[41]->[38]->[35]->{20}->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
n

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->[45]->[44]->[41]->[38]->[35]->{20}->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
h

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
{100}->[98]->[74]->[60]->[45]->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
s

?: 45
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->{45}->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
s

?: 38
..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->[45]->[44]->[41]->{38}->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
e

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
[100]->[98]->[74]->[60]->[45]->[44]->[41]->[38]->[35]->{20}->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
h

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
{100}->[98]->[74]->[60]->[45]->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
p

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
{100}->[98]->[74]->[60]->[45]->[44]->[41]->[38]->[35]->[20]->|||
[R]andom [I]nsert [D]elete [S]earch [P]revious [N]ext  [H]ome  [E]nd
x

..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..
---------- END ----------------
Press <RETURN> to close this window...
 */

//=================================== BIG THREE TEST OUTPUT ========================================
/*
========================= Test Rest Functions =========================
List: H->[98]->[74]->[60]->[44]->[20]->|||
------------- Copy CTOR -----------
List 2: H->[98]->[74]->[60]->[44]->[20]->|||
------------- Assignment Operator -----------
List 3: H->[98]->[74]->[60]->[44]->[20]->|||
------------- [] Function -----------
Element at position 3: 44

Press <RETURN> to close this window...
 */
#endif // SORTED_LIST_OUTPUT_H
