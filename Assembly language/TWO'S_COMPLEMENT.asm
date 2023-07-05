
;<Program title>

jmp start

;data


;code
start: nop


LXI H,3000H
MVI C,05H

MOV B,M
LOOP: ADD B
INR B
DCR C
JNZ LOOP
STA 3005H


hlt