s = input()
alpha = ""
num = 0
for c in s:
	if c.isalpha() == True:
		alpha += c
	else:
		num += int(c)

alpha = sorted(alpha)

if num != 0: # 숫자가 하나라도 있는 경우에만 출력해야함!
	print(str(alpha)+str(num))
else:
	print(''.join(alpha)) # 리스트를 문자열로 변환