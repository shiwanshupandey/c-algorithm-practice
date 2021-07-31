;JOSEPH BDARO
;CALCULATOR HW
.model small

.data
    message1 db " Enter a integer between 0 and 9. $"
    message2 db " Enter another integer between 0 and 9. $"
    message db " Enter an Arithmetic symbol. $"
    message3 db " + $"
    message4 db " - $"
    message5 db " * $"
    message6 db " / $"
    message7 db " = $"
    message9 db " Invalid Selection. Try AGAIN $"
    var1 db 1
    msg1 db " You Have Chosen Addition!! $"
    msg2 db " You Have Chosen SUBTRACTION!! $"
    msg3 db " You Have Chosen MULTIPLICATION!! $"
    msg4 db " You Have Chosen Division!! $"
.code                                 
    main proc
        
        mov ax, seg message ;prints message
        mov ds, ax
        mov dx, offset message
        mov ah, 9h
        int 21h
       
        INPUT:
        INC CX
        mov ah, 1h ;input from user is stored in al automatically
        int 21h
        
        cmp al,2BH ;checks if the user endered plus sign, if not it moves on to check for more signs
        jz adding  ;if zero flag is activated that means the user entered + and the procedure for addition starts
        
        cmp al,2DH ;if 
        jz subt
        
        cmp al,2AH
        jz multi
        
        cmp al,2FH
        jz divis
        
        mov ax, seg message9 ;prints message9
        mov ds, ax
        mov dx, offset message9
        mov ah, 9h
        int 21h
        
        loop INPUT
        jmp endproc
                
        adding:
        call ADDITION
        jmp endproc
                
        subt:
        call SUBTRACT
        jmp endproc
         
        multi:
        call MULTIPLY
        jmp endproc 
        
        divis:
        call DIVIDE
        jmp endproc

endp
    
    ADDITION proc ;adding procedure
        
        mov ax, seg msg1 ;prints message
        mov ds, ax
        mov dx, offset msg1
        mov ah, 9h
        int 21h
        
        top:
        INC CX
        mov ax, seg message1 ;prints message1
        mov ds, ax
        mov dx, offset message1
        mov ah, 9h
        int 21h 
        
        mov ah, 1h ;input from user is stored in al automatically
        int 21h
        
        CMP al,30h
        jz continue
        CMP al,31h
        jz continue
        CMP al,32h
        jz continue
        CMP al,33h        ;checks if the number entered is between 0 and 9 otherwise it loops till the user enters a valid selection
        jz continue
        CMP al,34h
        jz continue
        CMP al,35h
        jz continue
        CMP al,36h
        jz continue
        CMP al,37h
        jz continue
        CMP al,38h
        jz continue
        CMP al,39h
        jz continue
        
        mov ax, seg message9 ;prints message
        mov ds, ax
        mov dx, offset message9
        mov ah, 9h
        int 21h
        
        loop top
        
        continue:
        mov bl, al ; moves the value that the user inputs in the bl register so that when the user enters the second integer the user the first input does not get replaced
        
        top1:
        INC CX
        mov ax, seg message2 ;prints message2
        mov ds, ax
        mov dx, offset message2
        mov ah, 9h
        int 21h
        
        mov ah, 1h ;input from user is stored in al automatically
        int 21h
        
        CMP al,30h
        jz continue1
        CMP al,31h
        jz continue1
        CMP al,32h
        jz continue1
        CMP al,33h        ;checks if the number entered is between 0 and 9 otherwise it loops till the user enters a valid selection
        jz continue1
        CMP al,34h
        jz continue1
        CMP al,35h
        jz continue1
        CMP al,36h
        jz continue1
        CMP al,37h
        jz continue1
        CMP al,38h
        jz continue1
        CMP al,39h
        jz continue1
        
        mov ax, seg message9 ;prints message
        mov ds, ax
        mov dx, offset message9
        mov ah, 9h
        int 21h
        
        loop top1
        
        continue1:
        
        
        mov cl, al ; moves the value that the user inputs from al register to cl register.
        
        mov ax, seg message ;prints message
        mov ds, ax
        mov dx, offset message
        mov ah, 9h
        int 21h  
        
        mov dl, bl ;prints the first value the user entered
        mov ah, 2h
        int 21h
        
         mov ax, seg message3 ;prints message3 which is the plus sign
        mov ds, ax
        mov dx, offset message3
        mov ah, 9h
        int 21h
        
        mov dl, cl ;prints the second value 
        mov ah, 2h
        int 21h
        
        mov ax, seg message7 ;prints message7
        mov ds, ax
        mov dx, offset message7
        mov ah, 9h
        int 21h
        
        sub bl, 30h ;converts the first user input from ascii to decimal
        sub cl, 30h ;converts the second user input from ascii to decimal
        add bl, cl ;adds the decimal values of the first input the user entered and the second input the user entered and stores it in the bl register
        add bl, 30h ;converts the value of bl from decimal back to ascii
        
        mov dl, bl ;moves the ascii value of bl to the dl register so it can print the final value
        mov ah, 2h
        int 21h 
        
        ret
                
    ADDITION endp
    
    SUBTRACT proc ;substracting procedure
        
        mov ax, seg msg2 ;prints message1
        mov ds, ax
        mov dx, offset msg2
        mov ah, 9h
        int 21h 
        
        top3:
        INC CX
        mov ax, seg message1 ;prints message1
        mov ds, ax
        mov dx, offset message1
        mov ah, 9h
        int 21h 
        
        mov ah, 1h ;input from user is stored in al automatically
        int 21h
        
        CMP al,30h
        jz continue3
        CMP al,31h
        jz continue3
        CMP al,32h
        jz continue3
        CMP al,33h        ;checks if the number entered is between 0 and 9 otherwise it loops till the user enters a valid selection
        jz continue3
        CMP al,34h
        jz continue3
        CMP al,35h
        jz continue3
        CMP al,36h
        jz continue3
        CMP al,37h
        jz continue3
        CMP al,38h
        jz continue3
        CMP al,39h
        jz continue3
        
        mov ax, seg message9 ;prints message
        mov ds, ax
        mov dx, offset message9
        mov ah, 9h
        int 21h
        
        loop top3
        
        continue3:
        mov bl, al ; moves the value that the user inputs in the bl register so that when the user enters the second integer the user the first input does not get replaced
        
        top4:
        INC CX
        mov ax, seg message2 ;prints message2
        mov ds, ax
        mov dx, offset message2
        mov ah, 9h
        int 21h
        
        mov ah, 1h ;input from user is stored in al automatically
        int 21h
        
        CMP al,30h
        jz continue4
        CMP al,31h
        jz continue4
        CMP al,32h
        jz continue4
        CMP al,33h        ;checks if the number entered is between 0 and 9 otherwise it loops till the user enters a valid selection
        jz continue4
        CMP al,34h
        jz continue4
        CMP al,35h
        jz continue4
        CMP al,36h
        jz continue4
        CMP al,37h
        jz continue4
        CMP al,38h
        jz continue4
        CMP al,39h
        jz continue4
        
        mov ax, seg message9 ;prints message
        mov ds, ax
        mov dx, offset message9
        mov ah, 9h
        int 21h
        
        loop top4
        
        continue4:
        
        
        mov cl, al ; moves the value that the user inputs from al register to cl register.
        
        mov ax, seg message ;prints message
        mov ds, ax
        mov dx, offset message
        mov ah, 9h
        int 21h 
        
        mov dl, bl ;prints the first value the user entered
        mov ah, 2h
        int 21h
        
         mov ax, seg message4 ;prints message4 which is the minus sign
        mov ds, ax
        mov dx, offset message4
        mov ah, 9h
        int 21h
        
        mov dl, cl ;prints the second value 
        mov ah, 2h
        int 21h
        
        mov ax, seg message7 ;prints message7
        mov ds, ax
        mov dx, offset message7
        mov ah, 9h
        int 21h
        
        sub bl, 30h ;converts the first user input from ascii to decimal
        sub cl, 30h ;converts the second user input from ascii to decimal
        sub bl, cl ;subtracts the decimal values of the first input the user entered and the second input the user entered and stores it in the bl register
        add bl, 30h ;converts the value of bl from decimal back to ascii
        
        mov dl, bl ;moves the ascii value of bl to the dl register so it can print the final value
        mov ah, 2h
        int 21h 
        
        ret
                
    SUBTRACT endp
    
        MULTIPLY proc ;multiplication procedure
        mov ax, seg msg3 ;prints message1
        mov ds, ax
        mov dx, offset msg1
        mov ah, 9h
        int 21h 
        
        top6:
        INC CX
        mov ax, seg message1 ;prints message1
        mov ds, ax
        mov dx, offset message1
        mov ah, 9h
        int 21h 
        
        mov ah, 1h ;input from user is stored in al automatically
        int 21h
        
        CMP al,30h
        jz continue6
        CMP al,31h
        jz continue6
        CMP al,32h
        jz continue6
        CMP al,33h        ;checks if the number entered is between 0 and 9 otherwise it loops till the user enters a valid selection
        jz continue6
        CMP al,34h
        jz continue6
        CMP al,35h
        jz continue6
        CMP al,36h
        jz continue6
        CMP al,37h
        jz continue6
        CMP al,38h
        jz continue6
        CMP al,39h
        jz continue6
        
        mov ax, seg message9 ;prints message
        mov ds, ax
        mov dx, offset message9
        mov ah, 9h
        int 21h
        
        loop top6
        
        continue6:
        mov bl, al ; moves the value that the user inputs in the bl register so that when the user enters the second integer the user the first input does not get replaced
        
        top7:
        INC CX
        mov ax, seg message2 ;prints message2
        mov ds, ax
        mov dx, offset message2
        mov ah, 9h
        int 21h
        
        mov ah, 1h ;input from user is stored in al automatically
        int 21h
        
        CMP al,30h
        jz continue7
        CMP al,31h
        jz continue7
        CMP al,32h
        jz continue7
        CMP al,33h        ;checks if the number entered is between 0 and 9 otherwise it loops till the user enters a valid selection
        jz continue7
        CMP al,34h
        jz continue7
        CMP al,35h
        jz continue7
        CMP al,36h
        jz continue7
        CMP al,37h
        jz continue7
        CMP al,38h
        jz continue7
        CMP al,39h
        jz continue7
        
        mov ax, seg message9 ;prints message
        mov ds, ax
        mov dx, offset message9
        mov ah, 9h
        int 21h
        
        loop top7
        
        continue7:
        
        mov cl, al ; moves the value that the user inputs from al register to cl register.
        
        mov ax, seg message ;prints message
        mov ds, ax
        mov dx, offset message
        mov ah, 9h
        int 21h  
        
        mov dl, bl ;prints the first value the user entered
        mov ah, 2h
        int 21h
        
        mov ax, seg message5 ;prints message5 which is the times sign
        mov ds, ax
        mov dx, offset message5
        mov ah, 9h
        int 21h
        
        mov dl, cl ;prints the second value 
        mov ah, 2h
        int 21h
        
        mov ax, seg message7 ;prints message7
        mov ds, ax
        mov dx, offset message7
        mov ah, 9h
        int 21h
        
        mov al, cl ;moves the value of the second input back to AX register for multiplication
         
        sub bl, 30h ;converts the first user input from ascii to decimal
        sub al, 30h ;converts the second user input from ascii to decimal
        mul bl ;multiplies the decimal values of the first input the user entered and the second input the user entered and stores it in the ax register
        mov bl, al
        add bl, 30h ;converts the value of bl from decimal back to ascii
        
        mov dl, bl ;moves the ascii value of bl to the dl register so it can print the final value
        mov ah, 2h
        int 21h  
        
        ret             
                     
        MULTIPLY endp
        
        DIVIDE proc
        
        mov ax, seg msg4 ;prints message1
        mov ds, ax
        mov dx, offset msg4
        mov ah, 9h
        int 21h 
        
        top8:
        INC CX
        mov ax, seg message1 ;prints message1
        mov ds, ax
        mov dx, offset message1
        mov ah, 9h
        int 21h 
        
        mov ah, 1h ;input from user is stored in al automatically
        int 21h
        
        CMP al,30h
        jz continue8
        CMP al,31h
        jz continue8
        CMP al,32h
        jz continue8
        CMP al,33h        ;checks if the number entered is between 0 and 9 otherwise it loops till the user enters a valid selection
        jz continue8
        CMP al,34h
        jz continue8
        CMP al,35h
        jz continue8
        CMP al,36h
        jz continue8
        CMP al,37h
        jz continue8
        CMP al,38h
        jz continue8
        CMP al,39h
        jz continue8
        
        mov ax, seg message9 ;prints message
        mov ds, ax
        mov dx, offset message9
        mov ah, 9h
        int 21h
        
        loop top8
        
        continue8:
        mov bl, al ; moves the value that the user inputs in the bl register so that when the user enters the second integer the user the first input does not get replaced
        
        top9:
        INC CX
        mov ax, seg message2 ;prints message2
        mov ds, ax
        mov dx, offset message2
        mov ah, 9h
        int 21h
        
        mov ah, 1h ;input from user is stored in al automatically
        int 21h
        
        CMP al,30h
        jz continue9
        CMP al,31h
        jz continue9
        CMP al,32h
        jz continue9
        CMP al,33h        ;checks if the number entered is between 0 and 9 otherwise it loops till the user enters a valid selection
        jz continue9
        CMP al,34h
        jz continue9
        CMP al,35h
        jz continue9
        CMP al,36h
        jz continue9
        CMP al,37h
        jz continue9
        CMP al,38h
        jz continue9
        CMP al,39h
        jz continue9
        
        mov ax, seg message9 ;prints message
        mov ds, ax
        mov dx, offset message9
        mov ah, 9h
        int 21h
        
        loop top9
        
        continue9:
        
        mov cl, al ; moves the value that the user inputs from al register to cl register.
        
        mov ax, seg message ;prints message
        mov ds, ax
        mov dx, offset message
        mov ah, 9h
        int 21h  
        
        mov dl, bl ;prints the first value the user entered
        mov ah, 2h
        int 21h
        
        mov ax, seg message5 ;prints message5 which is the times sign
        mov ds, ax
        mov dx, offset message5
        mov ah, 9h
        int 21h
        
        mov dl, cl ;prints the second value 
        mov ah, 2h
        int 21h
        
        mov ax, seg message7 ;prints message7
        mov ds, ax
        mov dx, offset message7
        mov ah, 9h
        int 21h
        
        mov al, cl ;moves the value of the second input back to AX register for multiplication
         
        sub bl, 30h ;converts the first user input from ascii to decimal
        sub al, 30h ;converts the second user input from ascii to decimal
        div bl ;multiplies the decimal values of the first input the user entered and the second input the user entered and stores it in the ax register
        mov bl, al
        add bl, 30h ;converts the value of bl from decimal back to ascii
        
        mov dl, bl ;moves the ascii value of bl to the dl register so it can print the final value
        mov ah, 2h
        int 21h
        
        
               
            ret
            
        DIVIDE endp
    


        
      endproc:
    
end main