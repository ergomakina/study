# 乗算 2*3を行いたいとする。

# MUL命令がない場合
print('MUL命令')
result = 0
for i in range(3):
    result += 2
print(result)


# MUL命令がある場合
def MUL(x, y):
    return x * y


result = 0
result = MUL(2, 3)
print(result)

# 除算 3/2を行いたいとする。
# DIV命令がない場合
print('DIV命令')
result = 0
x = 3
while x > 2:
    x -= 2
    result += 1
print(result)
# DIV命令がある場合
print(3 // 2)

# 除算 3%2を行いたいとする。
# REM命令がない場合
print('REM命令')
result = 3
while result > 2:
    result -= 2
print(result)
# REM命令がある場合
result = 3
print(result % 2)
