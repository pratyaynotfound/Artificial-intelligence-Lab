; Mines:
; In a 3X3 grid, a bot is placed initially in the [1,1] cell. In one-step, the bot can move to one of its adjacent cells to its left, its right or above but it cannot move to its adjacent cell below. The cells [2,1] and [1,3] have mines and hence the bot must avoid entering these cells. The task assigned to the bot is to reach the the destination cell [3,3].
; Using a constraint solver, find a path following which the bot can accomplish the task. 


;  Mines
(declare-fun x110 () Bool)
(declare-fun x121 () Bool)
(declare-fun x222 () Bool)
(declare-fun x323 () Bool)
(declare-fun x233 () Bool)
(declare-fun x314 () Bool)
(declare-fun x334 () Bool)
(declare-fun x335 () Bool)
(declare-fun x224 () Bool)
(declare-fun x325 () Bool)
(declare-fun x315 () Bool)
(declare-fun x235 () Bool)
(declare-fun x336 () Bool)
(declare-fun x316 () Bool)
(declare-fun x226 () Bool)

; move constraints with avoiding mines
(assert (=> x110 x121))
(assert (=> x121 x222))
(assert (=> x222 (or x233 x323)))
(assert (=> x233 x334))
(assert (=> x323 (or x334 x314)))
(assert (=> x314 x325))
(assert (=> x325 x336)) 

; destination constraint
(assert (or (or x334 x335) x336 ))
(assert x110) 

(check-sat)
(get-model)
(exit)
