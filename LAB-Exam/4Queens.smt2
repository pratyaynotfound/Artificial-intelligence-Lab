; 4-Queens problem.
; There are 4 Queens to be placed in a 4X4 chessboard in such a way that no Queen can attack the other.
; Find out a satisfying queen placement in the board using a constraint solver.


; Grid x1y0 to x3y3

(declare-fun x0y0 () bool)
(declare-fun x0y1 () bool)
(declare-fun x0y2 () bool)
(declare-fun x0y3 () bool)
(declare-fun x1y0 () bool)
(declare-fun x1y1 () bool)
(declare-fun x1y2 () bool)
(declare-fun x1y3 () bool)
(declare-fun x2y0 () bool)
(declare-fun x2y1 () bool)
(declare-fun x2y2 () bool)
(declare-fun x2y3 () bool)
(declare-fun x3y0 () bool)
(declare-fun x3y1 () bool)
(declare-fun x3y2 () bool)
(declare-fun x3y3 () bool)

(assert (or x0y0 x0y1 x0y2 x0y3))
(assert (or x1y0 x1y1 x1y2 x1y3))
(assert (or x2y0 x2y1 x2y2 x2y3))
(assert (or x3y0 x3y1 x3y2 x3y3))
; for the rows and cols
(assert (=> x0y0 (and (not x0y1) (not x0y2) (not x0y3) (not x1y0) (not x2y0) (not x3y0))))
(assert (=> x0y1 (and (not x0y0) (not x0y2) (not x0y3) (not x1y1) (not x2y1) (not x3y1))))
(assert (=> x0y2 (and (not x0y0) (not x0y1) (not x0y3) (not x1y2) (not x2y2) (not x3y2))))
(assert (=> x0y3 (and (not x0y0) (not x0y2) (not x0y1) (not x1y3) (not x2y3) (not x3y3))))

(assert (=> x1y0 (and (not x1y1) (not x1y2) (not x1y3) (not x0y0) (not x2y0) (not x3y0))))
(assert (=> x1y1 (and (not x1y0) (not x1y2) (not x1y3) (not x0y1) (not x2y1) (not x3y1))))
(assert (=> x1y2 (and (not x1y0) (not x1y1) (not x1y3) (not x0y2) (not x2y2) (not x3y2))))
(assert (=> x1y3 (and (not x1y0) (not x1y2) (not x1y1) (not x0y3) (not x2y3) (not x3y3))))

(assert (=> x2y0 (and (not x2y1) (not x2y2) (not x2y3) (not x0y0) (not x1y0) (not x3y0))))
(assert (=> x2y1 (and (not x2y0) (not x2y2) (not x2y3) (not x0y1) (not x1y1) (not x3y1))))
(assert (=> x2y2 (and (not x2y0) (not x2y1) (not x2y3) (not x0y2) (not x1y2) (not x3y2))))
(assert (=> x2y3 (and (not x2y0) (not x2y2) (not x2y1) (not x0y3) (not x1y3) (not x3y3))))

(assert (=> x3y0 (and (not x3y1) (not x3y2) (not x3y3) (not x0y0) (not x1y0) (not x2y0))))
(assert (=> x3y1 (and (not x3y0) (not x3y2) (not x3y3) (not x0y1) (not x1y1) (not x2y1))))
(assert (=> x3y2 (and (not x3y0) (not x3y1) (not x3y3) (not x0y2) (not x1y2) (not x2y2))))
(assert (=> x3y3 (and (not x3y0) (not x3y2) (not x3y1) (not x0y3) (not x1y3) (not x2y3))))

; Diagonals
(assert (=> x0y0 (and (not x1y1) (not x2y2) (not x3y3))))
(assert (=> x0y1 (and (not x1y2) (not x2y3) (not x1y0))))
(assert (=> x0y2 (and (not x1y3) (not x1y1) (not x2y0))))
(assert (=> x0y3 (and (not x1y2) (not x2y1) (not x3y0))))

(assert (=> x1y0 (and (not x2y1) (not x3y2) (not x0y1))))
(assert (=> x1y1 (and (not x0y0) (not x2y2) (not x3y3) (not x0y2) (not x2y0))))
(assert (=> x1y2 (and (not x0y1) (not x0y3) (not x2y1) (not x2y3) (not x3y0))))
(assert (=> x1y3 (and (not x0y2) (not x2y2) (not x3y1))))

(assert (=> x2y0 (and (not x1y1) (not x0y2) (not x3y1))))
(assert (=> x2y1 (and (not x1y0) (not x3y2) (not x1y2) (not x0y3) (not x3y0))))
(assert (=> x2y2 (and (not x3y1) (not x1y3) (not x3y3) (not x1y1) (not x0y0))))
(assert (=> x2y3 (and (not x0y1) (not x1y2) (not x3y2))))

(assert (=> x3y0 (and (not x2y1) (not x1y2) (not x0y3))))
(assert (=> x3y1 (and (not x2y0) (not x2y2) (not x1y3))))
(assert (=> x3y2 (and (not x1y0) (not x2y1) (not x2y3))))
(assert (=> x3y3 (and (not x1y1) (not x2y2) (not x0y0))))

(check-sat)
(get-model)
(exit)