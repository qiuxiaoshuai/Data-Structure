DATA   SEGMENT                         ; �������ݶ�
PRINT  DB "Hello World!Qiu XiaoShuai", 0AH, 0DH, '$'
NUM1   DB 10
NUM2   DB 20
RESULT DB ?
DATA   ENDS                            ; ���ݶν���

STACK  SEGMENT STACK                   ; ����ջ��
       DW 20 DUP(0)                    ; ����40�ֽڵ�ջ�ռ�
STACK  ENDS

CODE   SEGMENT
ASSUME CS:CODE, DS:DATA, SS:STACK

START:
        MOV     AX, DATA               ; �� DATA �ε�ַ���� AX
        MOV     DS, AX                 ; ���� DS �μĴ���ָ�����ݶ�
        MOV     AX, STACK              ; ��ʼ��ջ��
        MOV     SS, AX
        MOV     SP, 40H                ; ջ����ַ��ƫ�ƣ�

        ; ��408����ָ��1��MOV ����
        MOV     AL, NUM1               ; �� NUM1 ��ֵ��10�����ص� AL
        MOV     BL, NUM2               ; �� NUM2 ��ֵ��20�����ص� BL

        ; ��408����ָ��2��ADD �ӷ�
        ADD     AL, BL                 ; AL = AL + BL�����ӦΪ 30��
        MOV     RESULT, AL             ; ��������� RESULT

        ; ��408����ָ��3��PUSH / POP
        PUSH    AX                     ; �� AX ѹջ
        POP     CX                     ; ������ CX����֤ջ����

        ; ��408����ָ��4��CMP / JZ ��ת����� RESULT Ϊ 0 ����ת��
        CMP     RESULT, 0
        JZ      ZERO_LABEL             ; ��� RESULT == 0����ת

        ; ��408����ָ��5��XCHG ����
        XCHG    AX, CX                 ; ���� AX �� CX ��ֵ

        ; ��������ַ���
        MOV     DX, OFFSET PRINT       ; �����ַ���ƫ�Ƶ�ַ
        MOV     AH, 09H                ; AH=09 ��ʾ����ַ���
        INT     21H                    ; �����жϣ�����ַ���

        JMP     EXIT_PROGRAM           ; ��ת���˳�����

ZERO_LABEL:
        ; ��ʾ������Ϣ������ֻ�Ǳ�ʶ��������������
        NOP                            ; ʲô��������ռλ

EXIT_PROGRAM:
        ; ��408����ָ��6��INT 21H ���� 4CH �˳�
        MOV     AH, 4CH
        INT     21H

CODE   ENDS
END    START
