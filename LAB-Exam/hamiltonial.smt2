
(set-option :produce-models true)

; Note that the bound of length 5 (0 to 4) because hamiltonian path will be exactly 5 long.

(declare-const a0  Bool)
(declare-const a1  Bool)
(declare-const a2  Bool)
(declare-const a3  Bool)
(declare-const a4  Bool)

(declare-const b0  Bool)
(declare-const b1  Bool)
(declare-const b2  Bool)
(declare-const b3  Bool)
(declare-const b4  Bool)

(declare-const c0  Bool)
(declare-const c1  Bool)
(declare-const c2  Bool)
(declare-const c3  Bool)
(declare-const c4  Bool)

(declare-const d0  Bool)
(declare-const d1  Bool)
(declare-const d2  Bool)
(declare-const d3  Bool)
(declare-const d4  Bool)

; constraints on transition relations. Note the indices to capture path sequence

(assert (=> a0 b1))
(assert (=> a1 b2))
(assert (=> a2 b3))
(assert (=> a3 b4))

(assert (=> b0 (xor c1 d1)))
(assert (=> b1 (xor c2 d2)))
(assert (=> b2 (xor c3 d3)))
(assert (=> b3 (xor c4 d4)))

(assert (=> c0 a1))
(assert (=> c1 a2))
(assert (=> c2 a3))
(assert (=> c3 a4))

(assert (=> d0 c1))
(assert (=> d1 c2))
(assert (=> d2 c3))
(assert (=> d3 c4))

; exclusivity constraint saying two locations cannot be in the same position in a path

(assert (or a0 b0 c0 d0))
(assert (=> a0 (and (not b0) (not c0) (not d0))))
(assert (=> b0 (and (not a0) (not c0) (not d0))))
(assert (=> c0 (and (not a0) (not b0) (not d0))))
(assert (=> d0 (and (not a0) (not b0) (not c0))))

(assert (or a1 b1 c1 d1))
(assert (=> a1 (and (not b1) (not c1) (not d1))))
(assert (=> b1 (and (not a1) (not c1) (not d1))))
(assert (=> c1 (and (not b1) (not a1) (not d1))))
(assert (=> d1 (and (not a1) (not b1) (not c1))))

(assert (or a2 b2 c2 d2))
(assert (=> a2 (and (not b2) (not c2) (not d2))))
(assert (=> b2 (and (not a2) (not c2) (not d2))))
(assert (=> c2 (and (not b2) (not a2) (not d2))))
(assert (=> d2 (and (not a2) (not b2) (not c2))))

(assert (or a3 b3 c3 d3))
(assert (=> a3 (and (not b3) (not c3) (not d3))))
(assert (=> b3 (and (not a3) (not c3) (not d3))))
(assert (=> c3 (and (not b3) (not a3) (not d3))))
(assert (=> d3 (and (not a3) (not b3) (not c3))))

(assert (or a4 b4 c4 d4))
(assert (=> a4 (and (not b4) (not c4) (not d4))))
(assert (=> b4 (and (not a4) (not c4) (not d4))))
(assert (=> c4 (and (not b4) (not a4) (not d4))))
(assert (=> d4 (and (not a4) (not b4) (not c4))))

; tour constraint saying the first and last locations should be same
(assert (or (= a0 a4) (= b0 b4) (= c0 c4) (= d0 d4)) )

; constraint for avoiding location repetition in the path except first and last
(assert (or a0 a1 a2 a3))
(assert (or b0 b1 b2 b3))
(assert (or c0 c1 c2 c3))
(assert (or d0 d1 d2 d3))

(assert (=> a0 (and (not a1) (not a2) (not a3))))
(assert (=> b0 (and (not b1) (not b2) (not b3))))
(assert (=> c0 (and (not c1) (not c2) (not c3))))
(assert (=> d0 (and (not d1) (not d2) (not d3))))

(assert (=> a1 (and (not a0) (not a2) (not a3))))
(assert (=> b1 (and (not b0) (not b2) (not b3))))
(assert (=> c1 (and (not c0) (not c2) (not c3))))
(assert (=> d1 (and (not d0) (not d2) (not d3))))

(assert (=> a2 (and (not a0) (not a1) (not a3))))
(assert (=> b2 (and (not b0) (not b1) (not b3))))
(assert (=> c2 (and (not c0) (not c1) (not c3))))
(assert (=> d2 (and (not d0) (not d1) (not d3))))

(assert (=> a3 (and (not a0) (not a2) (not a1))))
(assert (=> b3 (and (not b0) (not b2) (not b1))))
(assert (=> c3 (and (not c0) (not c2) (not c1))))
(assert (=> d3 (and (not d0) (not d2) (not d1))))

(check-sat)
(get-model)






