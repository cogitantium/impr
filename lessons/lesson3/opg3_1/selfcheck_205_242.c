a:6 b:9 c:14 flag:1

a: c==a+b || !flag = 0 non-short
b: a!=7 && flag || c>=6 = 1 non-short
c: !(b<=12) && a%2==0 = 0 short circuit
d: !(a>5 || c<a+b) = non-short

1.
What will be printed by this carelessly constructed 
switch statement if the value of color is 'R' ?

switch (color) { /* break statements missing */
case 'R':
      printf("red\n");
case 'B':
      printf("blue\n");
case 'Y':
      printf("yellow\n");
}

Program falls through, since no break has been added to the switch-statement. 
Therefore, red\nblue\nyellow\n will be printed.

