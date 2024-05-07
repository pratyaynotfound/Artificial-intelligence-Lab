; This example illustrates basic arithmetic and 
; uninterpreted functions
(declare-fun q1 () Int)
(declare-fun q2 () Int)
(declare-fun q3 () Int)
(declare-fun q4 () Int)

(assert (and (>= q1 1) (<= q1 4)))
(assert (and (>= q2 1) (<= q2 4)))
(assert (and (>= q3 1) (<= q3 4)))
(assert (and (>= q4 1) (<= q4 4)))

;queen cannot attack above or below
(assert (or (> q2 q1) (< q2 q1)))
(assert (or (> q3 q1) (< q3 q1)))
(assert (or (> q4 q1) (< q4 q1)))
(assert (or (> q3 q2) (< q3 q2)))
(assert (or (> q4 q2) (< q4 q2)))
(assert (or (> q4 q3) (< q4 q4)))

;queen cannot attack diagonally
(assert (or (> q2 (+ q1 1)) (< q2 (+ q1 1))))
(assert (or (> q2 (- q1 1)) (< q2 (- q1 1))))
(assert (or (> q3 (+ q1 2)) (< q3 (+ q1 2))))
(assert (or (> q3 (- q1 2)) (< q3 (- q1 2))))
(assert (or (> q4 (+ q1 3)) (< q4 (+ q1 3))))
(assert (or (> q4 (- q1 3)) (< q4 (- q1 3))))
(assert (or (> q3 (+ q2 1)) (< q3 (+ q2 1))))
(assert (or (> q3 (- q2 1)) (< q3 (- q2 1))))
(assert (or (> q4 (+ q2 2)) (< q3 (+ q2 2))))
(assert (or (> q4 (- q2 2)) (< q3 (- q2 2))))
(assert (or (> q4 (+ q3 1)) (< q4 (+ q3 1))))
(assert (or (> q4 (- q3 1)) (< q4 (- q3 1))))

(check-sat)
(get-model)
(exit)
