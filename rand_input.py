# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    rand_input.py                                      :+:    :+:             #
#                                                      +:+                     #
#    By: zenotan <zenotan@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/22 18:08:16 by zenotan       #+#    #+#                  #
#    Updated: 2021/06/23 18:49:36 by zenotan       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

import sys
import random

random.seed()

s = 4
if len(sys.argv) > 1:
	for i in range(4, 10):
		if sys.argv[1] == str(i):
			s = int(sys.argv[1])
seq = ""
for i in range(1, s + 1):
	seq += str(i)
ran = ""
for i in range(0, 4):
	ran += ' ' + ' '.join(random.choices(seq, k = s))
print(str(ran)[1:])

x = range(s)
for i in range(len(x)):
	j =  i + int((len(x) - i)*random.random())
	print(str(j))
	# c = x[j]
	# x[j] = x[i]
	# x[i] = c
# print(str(x))