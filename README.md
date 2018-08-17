# NFA2Parikh
Convert Non Deterministic Automata to Parikh Images in z3 format

click [here](https://github.com/Z3Prover/z3) for z3

## Usage
```
$ make
$ bin/NFA2Parikh NFA.nfa
```

## Input Format:
state_num, terminal_num, alphabet_num, transition_num
states
initial state
terminal states
alphabets
transitions1(p,a,q)
transitions1(p,a,q)
.
.
.
### Example: a(b|c)*
![NFA](https://i.imgur.com/iSZEUZj.png)
```
2 1 3 3
q0 q1
q0
q1
a b c
qo a q1
q1 b q1
q1 c q1
```
### Output:
```
(declare-const r_a Int)
(declare-const r_q1q1 Int)
(declare-const r_b Int)
(declare-const out_q0 Int)
(declare-const out_q1q0q1a Int)
(declare-const in_q0 Int)
(declare-const in_q1q0q1a Int)
(declare-const start_q0 Bool)
(declare-const start_q1q0q1a Bool)
(declare-const t_q0 Int)
(declare-const t_q1q0q1a Int)
(declare-const t_cqo Int)
(declare-const flag_q0_1 Bool)
(declare-const flag_q0_2 Bool)
(declare-const flag_q0_3 Bool)
(declare-const flag_q1q0q1a_1 Bool)
(declare-const flag_q1q0q1a_2 Bool)
(declare-const flag_q1q0q1a_3 Bool)
(assert (>= r_a 0))
(assert (>= r_q1q1 0))
(assert (>= r_b 0))
(assert (>= out_q0 0))
(assert (>= out_q1q0q1a 0))
(assert (>= in_q0 0))
(assert (>= in_q1q0q1a 0))
(assert (>= t_q0 0))
(assert (<= t_q0 1))
(assert (>= t_q1q0q1a 0))
(assert (<= t_q1q0q1a 1))
(assert (>= t_cqo 0))
(assert (<= t_cqo 1))
(assert (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (= r_a 0 )(= r_q1q1 0 ))(= r_b 0 ))(= out_q0 0 ))(= out_q1q0q1a 0 ))(= in_q0 0 ))(= in_q1q0q1a 0 ))(not  start_q0 ))(not  start_q1q0q1a ))(= t_q0 0 ))(= t_q1q0q1a 0 ))(= 1 t_cqo ))(or (or flag_q0_1 flag_q0_2 )flag_q0_3 ))(= flag_q0_1 (and (and (not start_q0  )(= t_q0 1 ))(= in_q0 (+ out_q0 1 )))))(= flag_q0_2 (and (and start_q0 (= t_q0 0 ))(= in_q0 (- out_q0 1 )))))(= flag_q0_3 (and (= in_q0 out_q0 )(not (xor start_q0 (= t_q0 1 )) ))))(or (or flag_q1q0q1a_1 flag_q1q0q1a_2 )flag_q1q0q1a_3 ))(= flag_q1q0q1a_1 (and (and (not start_q1q0q1a  )(= t_q1q0q1a 1 ))(= in_q1q0q1a (+ out_q1q0q1a 1 )))))(= flag_q1q0q1a_2 (and (and start_q1q0q1a (= t_q1q0q1a 0 ))(= in_q1q0q1a (- out_q1q0q1a 1 )))))(= flag_q1q0q1a_3 (and (= in_q1q0q1a out_q1q0q1a )(not (xor start_q1q0q1a (= t_q1q0q1a 1 )) )))))
(check-sat)
(get-model)
```