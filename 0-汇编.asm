DATA   SEGMENT                         ; 定义数据段
PRINT  DB "Hello World!Qiu XiaoShuai", 0AH, 0DH, '$'
NUM1   DB 10
NUM2   DB 20
RESULT DB ?
DATA   ENDS                            ; 数据段结束

STACK  SEGMENT STACK                   ; 定义栈段
       DW 20 DUP(0)                    ; 分配40字节的栈空间
STACK  ENDS

CODE   SEGMENT
ASSUME CS:CODE, DS:DATA, SS:STACK

START:
        MOV     AX, DATA               ; 将 DATA 段地址放入 AX
        MOV     DS, AX                 ; 设置 DS 段寄存器指向数据段
        MOV     AX, STACK              ; 初始化栈段
        MOV     SS, AX
        MOV     SP, 40H                ; 栈顶地址（偏移）

        ; 【408常考指令1】MOV 传送
        MOV     AL, NUM1               ; 将 NUM1 的值（10）加载到 AL
        MOV     BL, NUM2               ; 将 NUM2 的值（20）加载到 BL

        ; 【408常考指令2】ADD 加法
        ADD     AL, BL                 ; AL = AL + BL（结果应为 30）
        MOV     RESULT, AL             ; 将结果存入 RESULT

        ; 【408常考指令3】PUSH / POP
        PUSH    AX                     ; 将 AX 压栈
        POP     CX                     ; 弹出到 CX，验证栈操作

        ; 【408常考指令4】CMP / JZ 跳转（如果 RESULT 为 0 就跳转）
        CMP     RESULT, 0
        JZ      ZERO_LABEL             ; 如果 RESULT == 0，跳转

        ; 【408常考指令5】XCHG 交换
        XCHG    AX, CX                 ; 交换 AX 和 CX 的值

        ; 正常输出字符串
        MOV     DX, OFFSET PRINT       ; 加载字符串偏移地址
        MOV     AH, 09H                ; AH=09 表示输出字符串
        INT     21H                    ; 调用中断，输出字符串

        JMP     EXIT_PROGRAM           ; 跳转到退出程序

ZERO_LABEL:
        ; 显示错误信息（这里只是标识，不会真的输出）
        NOP                            ; 什么都不做，占位

EXIT_PROGRAM:
        ; 【408常考指令6】INT 21H 调用 4CH 退出
        MOV     AH, 4CH
        INT     21H

CODE   ENDS
END    START
