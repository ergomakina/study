# A simple assembler


def LD(dest, src):
    code1 = ((0x2 << 12) | ((dest) << 8) | (0xc << 4) | (src))
    print('%04x     ' % code1, ' // LD')
    return 2


def LD2(dest, src, disp):
    code1 = ((0xa << 12) | ((dest) << 8) | (0xc << 4) | (src))
    code2 = disp
    print('%04x %04x' % (code1, code2), ' // LD2')
    return 4


def ST(src1, src2):
    code1 = ((0x2 << 12) | ((src1) << 8) | (0x4 << 4) | (src2))
    print('%04x     ' % code1, ' // ST')
    return 2


def ST2(src1, src2, disp):
    code1 = ((0xa << 12) | ((src1) << 8) | (0x4 << 4) | (src2))
    code2 = disp
    print('%04x %04x' % (code1, code2), ' // ST2')
    return 4


def MV(dest, src):
    code1 = ((0x1 << 12) | ((dest) << 8) | (0x8 << 4) | (src))
    print('%04x     ' % code1, ' // MV')
    return 2


def LDI(dest, imm):
    code1 = ((0x9 << 12) | ((dest) << 8) | (0xf << 4) | 0x0)
    code2 = imm
    print('%04x %04x' % (code1, code2), ' // LDI')
    return 4


def ADD(dest, src):
    code1 = ((0x0 << 12) | ((dest) << 8) | (0xa << 4) | (src))
    print('%04x     ' % code1, ' // ADD')
    return 2


def ADDI(dest, imm8):
    code1 = ((0x4 << 12) | ((dest) << 8) | ((imm8) & 0xff))
    print('%04x     ' % code1, ' // ADDI')
    return 2


def SUB(dest, src):
    code1 = ((0x0 << 12) | ((dest) << 8) | (0x2 << 4) | (src))
    print('%04x     ' % code1, ' // SUB')
    return 2


def AND(dest, src):
    code1 = ((0x0 << 12) | ((dest) << 8) | (0xc << 4) | (src))
    print('%04x     ' % code1, ' // AND')
    return 2


def OR(dest, src):
    code1 = ((0x0 << 12) | ((dest) << 8) | (0xe << 4) | (src))
    print('%04x     ' % code1, ' //OR')
    return 2


def CMP(src1, src2):
    code1 = ((0x0 << 12) | ((src1) << 8) | (0x4 << 4) | (src2))
    print('%04x     ' % code1, ' // CMP')
    return 2


def BRA(pcdisp8):
    code1 = ((0x7f << 8) | ((pcdisp8 >> 1) & 0xff))
    print('%04x     ' % code1, ' // BRA')
    return 2


def BC(pcdisp8):
    code1 = ((0x7c << 8) | ((pcdisp8 >> 1) & 0xff))
    print('%04x     ' % code1, ' // BC')
    return 2


def BEQ(src1, src2, pcdisp):
    code1 = ((0xb << 12) | ((src1) << 8) | (0x0 << 4) | (src2))
    code2 = pcdisp
    print('%04x %04x' % (code1, code2), ' // BEQ')
    return 4


def JMP(src):
    code1 = ((0x1f << 8) | (0xc << 4) | (src))
    print('%04x     ' % code1, ' //JMP')
    return 2


def JL(src):
    code1 = ((0x1e << 8) | (0xc << 4) | (src))
    print('%04x    ' % code1, ' //JL')
    return 2

# http://www17.tok2.com/home/taro/rjj09b0107_32fpusm.pdf


def REM(dest, src):  # 乗除算命令 符号付き剰余
    code1 = ((0x9 << 12) | ((dest) << 8) | (0x2 << 4) | (src))
    print('%04x     ' % code1, ' // REM')
    return 2


def MUL(dest, src):
    code1 = ((0x1 << 12) | ((dest) << 8) | (0x6 << 4) | (src))
    print('%04x     ' % code1, ' // MUL')
    return 2


def DIV(dest, src):
    code1 = ((0x9 << 12) | ((dest) << 8) | (0x0 << 4) | (src))
    print('%04x     ' % code1, ' // DIV')
    return 2


R0 = 0
R1 = 1
R2 = 2
R3 = 3
R4 = 4
R5 = 5
R6 = 6
R7 = 7
R8 = 8
R9 = 9
R10 = 10
R11 = 11
R12 = 12
R13 = 13
R14 = 14
R15 = 15

# Sample program
a = 0
a += SUB(R0, R0)  # R0 = 0
a += LDI(R1, 10)  # R1 = 10
a += LDI(R2, 1)  # R2 = 1
a += SUB(R3, R3)  # R3 = 0
L0 = a
a += ADD(R0, R1)  # R0 = R0+R1
a += SUB(R1, R2)  # R1 = R1-R2 (= R1-1)
a += CMP(R3, R1)  # R1>R3? (R1>0?)
a += BC(L0-a)   # if yes then branch to L0
