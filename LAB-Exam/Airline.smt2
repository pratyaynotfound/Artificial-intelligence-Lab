; Given a set of 6 airlines A,B,C,D,E,F and 2 gates Red and Green, allot departure gates to each airline respecting the following constraints:
; 1. Two airlines having flights at the same time have to be scheduled different gates.
; 2. Each airline to depart all its flights from the same gate.
; The airline departure time-table is shown below:
; [6 AM to 8 AM]: A and B
; [8 AM to 10 AM]: A and D
; [11 AM to 1 PM]: B, C and D
; [1 PM to 3 PM]: C, D and F
; [3 PM to 5 PM]: D and E
; [5 PM to 7 PM]: E and F
; Goal: Find an airline to gate allotment using a constraint solver. 

; Gates: R,G,Y
; Flights: A,B,C,D,E,F

(declare-fun AR () bool)
(declare-fun AG () bool)
(declare-fun AY () bool)
(declare-fun BR () bool)
(declare-fun BG () bool)
(declare-fun BY () bool)
(declare-fun CR () bool)
(declare-fun CG () bool)
(declare-fun CY () bool)
(declare-fun DR () bool)
(declare-fun DG () bool)
(declare-fun DY () bool)
(declare-fun ER () bool)
(declare-fun EG () bool)
(declare-fun EY () bool)
(declare-fun FR () bool)
(declare-fun FG () bool)
(declare-fun FY () bool)

; For flight A
(assert (=> AR (and (not BR) (not DR))))
(assert (=> AG (and (not BG) (not DG))))
(assert (=> AY (and (not BY) (not DY))))

; Exclusivity of A
(assert (=> AR (and (not AG) (not AY))))
(assert (=> AG (and (not AR) (not AY))))
(assert (=> AY (and (not AG) (not AR))))

(assert (or (or AR AG) AY))

; For flight B
(assert (=> BR (and (not AR) (not DR) (not CR))))
(assert (=> BG (and (not AG) (not DG) (not CG))))
(assert (=> BY (and (not AY) (not DY) (not CY))))

(assert (=> BR (and (not BG) (not BY))))
(assert (=> BG (and (not BR) (not BY))))
(assert (=> BY (and (not BG) (not BR))))

(assert (or (or BR BG) BY))

; For flight C
(assert (=> CR (and (not BR) (not DR) (not FR))))
(assert (=> CG (and (not BG) (not DG) (not FG))))
(assert (=> CY (and (not BY) (not DY) (not FY))))

(assert (=> CR (and (not CG) (not CY))))
(assert (=> CG (and (not CR) (not CY))))
(assert (=> CY (and (not CG) (not CR))))

(assert (or (or CR CG) CY))

; For flight D
;conflict constraints on airline D
(assert (=> DR ( and ( and (and (and (not AR) (not BR)) (not CR)) (not ER)) (not FR)) ) )
(assert (=> DG ( and ( and (and (and (not AG) (not BG)) (not CG)) (not EG)) (not FG)) ) )
(assert (=> DY ( and ( and (and (and (not AY) (not BY)) (not CY)) (not EY)) (not FY)) ) )
;exclusive gate assignment to airline D
(assert (=> DR (and (not DG) (not DY))))
(assert (=> DG (and (not DR) (not DY))))
(assert (=> DY (and (not DR) (not DG))))
;must assign a gate to airline D
(assert ( or (or DR DG) DY) )
;
; conflict constraints on airline E
(assert (=> ER (and (not DR) (not FR)) ) )
(assert (=> EG (and (not DG) (not FG)) ) )
(assert (=> EY (and (not DY) (not FY)) ) )
;exclusive gate assignment to airline E
(assert (=> ER (and (not EG) (not EY))))
(assert (=> EG (and (not ER) (not EY))))
(assert (=> EY (and (not ER) (not EG))))
;must assign a gate to airline E
(assert ( or (or ER EG) EY) )
;
; conflict constraints on airline F
(assert (=> FR (and (and (not CR) (not DR)) (not ER))))
(assert (=> FG (and (and (not CG) (not DG)) (not EG))))
(assert (=> FY (and (and (not CY) (not DY)) (not EY))))
;exclusive gate assignment to airline F
(assert (=> FR (and (not FG) (not FY))))
(assert (=> FG (and (not FR) (not FY))))
(assert (=> FY (and (not FR) (not FG))))
;must assign a gate to airline F
(assert ( or (or FR FG) FY) )
; 
(check-sat)
(get-model)
(exit)
