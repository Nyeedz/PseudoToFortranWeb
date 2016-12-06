PROGRAM INTER

INTEGER base

INTEGER expoente

INTEGER cont

INTEGER resp

INTEGER valida

PRINT *, "Potenciacao usando loop"

PRINT *, "DIGITE A BASE"

READ *, base

valida  =  0

DO WHILE( valida < 1 )

PRINT *, "DIGITE O EXPOENTE"

READ *, expoente

IF( expoente >= 0 ) THEN

valida  =  1

ENDIF
ENDDO
IF( expoente == 0 ) THEN

resp  =  1

ELSE

resp  =  1

DO cont = 1, expoente

resp  =  resp * base
ENDDO
ENDIF

PRINT *, "Resposta"

PRINT *, resp

END PROGRAM INTER
