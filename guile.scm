#!/usr/bin/guile-2.0 -s
!#

(define (fact n) (if (zero? n) 1 (* n (fact (- n 1)))))
(display  (fact 20))
(newline)
(display (/ 3 4.21))
(current-time)
(newline)
