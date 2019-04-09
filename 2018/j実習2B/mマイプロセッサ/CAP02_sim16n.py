import numpy as np


class memory:
    def __init__(self, size):  # size: #Bytes of the memory
        self.mem = np.arange(size // 2)
        self.size = size
        self.addr = 0

    def readm16(self, a):  # Read 16 bits from memory
        return self.mem[(a // 2) & 0xffff] & 0xffff

    def writem16(self, a, d):  # Write 16 bits to memory
        self.mem[(a // 2) & 0xffff] = d & 0xffff

    def LD(self, d, s):
        self.writem16(self.addr, (0x2 << 12) | (d << 8) | (0xc << 4) | s)
        self.addr += 2

    def LD2(self, d, s, disp):
        self.writem16(self.addr, (0xa << 12) | (d << 8) | (0xc << 4) | s)
        self.writem16(self.addr + 2, disp)
        self.addr += 4

    def ST(self, s1, s2):
        self.writem16(self.addr, (0x2 << 12) | (s1 << 8) | (0x4 << 4) | s2)
        self.addr += 2

    def ST2(self, s1, s2, disp):
        self.writem16(self.addr, (0xa << 12) | (s1 << 8) | (0x4 << 4) | s2)
        self.writem16(self.addr + 2, disp)
        self.addr += 4

    def MV(self, d, s):
        self.writem16(self.addr, (0x1 << 12) | (d << 8) | (0x8 << 4) | s)
        self.addr += 2

    def LDI(self, d, imm):
        self.writem16(self.addr, (0x9 << 12) | (d << 8) | 0xf0)
        self.writem16(self.addr + 2, imm)
        self.addr += 4

    def ADD(self, d, s):
        self.writem16(self.addr, (0x0 << 12) | (d << 8) | (0xa << 4) | s)
        self.addr += 2

    def ADDI(self, d, imm8):
        self.writem16(self.addr, (0x4 << 12) | (d << 8) | (imm8 & 0xff))
        self.addr += 2

    def SUB(self, d, s):
        self.writem16(self.addr, (0x0 << 12) | (d << 8) | (0x2 << 4) | s)
        self.addr += 2

    def AND(self, d, s):
        self.writem16(self.addr, (0x0 << 12) | (d << 8) | (0xc << 4) | s)
        self.addr += 2

    def OR(self, d, s):
        self.writem16(self.addr, (0x0 << 12) | (d << 8) | (0xe << 4) | s)
        self.addr += 2

    def CMP(self, s1, s2):
        self.writem16(self.addr, (0x0 << 12) | (s1 << 8) | (0x4 << 4) | s2)
        self.addr += 2

    def BRA(self, pcdisp8):
        self.writem16(self.addr, (0x7f << 8) | ((pcdisp8 // 2) & 0xff))
        self.addr += 2

    def BC(self, pcdisp8):
        self.writem16(self.addr, (0x7c << 8) | ((pcdisp8 // 2) & 0xff))
        self.addr += 2

    def BEQ(self, s1, s2, pcdisp):
        self.writem16(self.addr, (0xb << 12) | (s1 << 8) | (0x0 << 4) | s2)
        self.writem16(self.addr + 2, pcdisp)
        self.addr += 4

    def JMP(self, s):
        self.writem16(self.addr, (0x1fc << 4) | s)
        self.addr += 2

    def JL(self, s):
        self.writem16(self.addr, (0x1ec << 4) | s)
        self.addr += 2

    # http://www17.tok2.com/home/taro/rjj09b0107_32fpusm.pdf
    def MUL(self, d, s):
        self.writem16(self.addr, (0x1 << 12) | (d << 8) | (0x6 << 4) | s)
        self.addr += 2

    def DIV(self, d, s):
        self.writem16(self.addr, (0x9 << 12) | (d << 8) | (0x0 << 4) | s)
        self.addr += 2

    def REM(self, d, s):
        self.writem16(self.addr, (0x9 << 12) | (d << 8) | (0x2 << 4) | s)
        self.addr += 2


class cpu16n:
    def __init__(self, mem):
        self.m = mem
        self.rf = np.arange(16)
        self.pc = 0
        self.c = 0

    def exec1(self):  # Execute one instruction
        ins = self.m.readm16(self.pc)
        if (ins & 0x8000) == 0:  # 16-bit instruction
            npc = self.pc + 2
        else:  # 32-bit instruction
            disp = self.m.readm16(self.pc + 2)
            npc = self.pc + 4
        opcode1 = (ins >> 12) & 0xf
        opcode2 = (ins >> 4) & 0xf
        operand1 = (ins >> 8) & 0xf
        operand2 = ins & 0xf
        if opcode1 == 0x2:
            if opcode2 == 0xc:  # LD
                self.rf[operand1] = self.m.readm16(self.rf[operand2])
            elif opcode2 == 0x4:  # ST
                self.m.writem16(self.rf[operand2], self.rf[operand1])
            else:
                print("Unknown instruction")
        elif opcode1 == 0xa:
            if opcode2 == 0xc:  # LD2
                self.rf[operand1] = self.m.readm16(self.rf[operand2] + disp)
            elif opcode2 == 0x4:  # ST2
                self.m.writem16(self.rf[operand2] + disp, self.rf[operand1])
            else:
                print("Unknown instruction")
        elif opcode1 == 0x1:
            if opcode2 == 0x8:  # MV
                self.rf[operand1] = self.rf[operand2]
            elif ((ins >> 4) & 0xff) == 0xfc:  # JMP
                npc = self.rf[operand2]
            elif ((ins >> 4) & 0xff) == 0xec:  # JL
                self.rf[14] = npc & 0xffff
                npc = self.rf[operand2]
            #MUL
            elif ((ins >> 4) & 0xff) == 0x06:
                self.rf[operand1] = (
                    self.rf[operand1] * self.rf[operand2]) & 0xffff
            else:
                print("Unknown instruction")
        elif opcode1 == 0x9:
            if (ins & 0xff) == 0xf0:  # LDI
                self.rf[operand1] = disp & 0xffff
            #REM
            elif ((ins >> 4) & 0xff) == 0x02:
                self.rf[operand1] = (
                    self.rf[operand1] % self.rf[operand2]) & 0xffff
            #DIV
            elif ((ins >> 4) & 0xff) == 0x00:
                self.rf[operand1] = (
                    self.rf[operand1] / self.rf[operand2]) & 0xffff
            else:
                print("Unknown instruction")
        elif opcode1 == 0x0:
            if opcode2 == 0xa:  # ADD
                self.rf[operand1] = (
                    self.rf[operand1] + self.rf[operand2]) & 0xffff
            elif opcode2 == 0x2:  # SUB
                self.rf[operand1] = (
                    self.rf[operand1] - self.rf[operand2]) & 0xffff
            elif opcode2 == 0xc:  # AND
                self.rf[operand1] = (
                    self.rf[operand1] & self.rf[operand2]) & 0xffff
            elif opcode2 == 0xe:  # OR
                self.rf[operand1] = (self.rf[operand1]
                                     | self.rf[operand2]) & 0xffff
            elif opcode2 == 0x4:  # CMP
                self.c = 1 if self.rf[operand1] < self.rf[operand2] else 0
            else:
                print("Unknown instruction")
        elif opcode1 == 0x4:  # ADDI
            imm8 = ins & 0xff
            if (imm8 & 0x80) != 0:
                imm8 |= 0xff00  # Sign extention of 8-bit data
            self.rf[operand1] = (self.rf[operand1] + imm8) & 0xffff
        elif opcode1 == 0x7:
            pcdisp8 = ins & 0xff
            if (pcdisp8 & 0x80) != 0:
                pcdisp8 |= 0xff00  # Sign extention of 8-bit data
            if operand1 == 0xf:  # BRA
                npc = self.pc + (pcdisp8 * 2)
            elif operand1 == 0xc:  # BC
                if self.c == 1:
                    npc = self.pc + (pcdisp8 * 2)
            else:
                print("Unknown instruction")
        elif opcode1 == 0xb:
            if opcode2 == 0x0:  # BEQ
                if self.rf[operand1] == self.rf[operand2]:
                    npc = self.pc + disp
            else:
                print("Unknown instruction")
        else:
            print("Unknown instruction")
        print("Exec ins at %02x" % self.pc)
        self.pc = npc & 0xffff

    def execn(self, n):  # Execute N instructions
        for i in range(n):
            self.exec1()


m = memory(128)  # Make a memory of 128 bytes
cpu = cpu16n(m)  # Make a cpu and connect it to the memory

# First pass of assmbling
L0 = 0
# m.ADD(0,1)  # R0 = R0+R1
# m.SUB(0,0)  # R0 = 0
# m.LDI(1,10) # R1 = 10
# m.LDI(2,1)  # R2 = 1
# m.SUB(3, 3)  # R3 = 0

m.LDI(3, 2)  # R3 = 2
m.LDI(4, 4)  # R4 = 4
m.MUL(3, 4)  # R3 * R4 = 8
m.DIV(4, 3)  # R4 / R3 = 2
m.REM(4, 3)  # R4 % R3 = 0

# L0 = m.addr # Label L0:
# m.ADD(0,1)  # R0 = R0+R1
# m.SUB(1,2)  # R1 = R1-1
# m.CMP(3,1)  # if 0 < R1
m.BC(L0 - m.addr)  # Then branch to L0
m.BRA(0)  # Endless loop

print("Generated code: 0 - %02x" % (m.addr - 1))
for i in range(m.addr // 2):
    print("%02x" % (i * 2), "%04x" % m.mem[i])

print("\nRun code from 0:")
for i in range(13):
    cpu.execn(5)
    print("pc = %02x" % cpu.pc, "R0 = ", cpu.rf[0])
