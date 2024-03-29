Асистентът ви много харесва балони и иска да му давате балони всеки ден в продължение на N дни (номерирани с числата от 1 до N). На поредния ден i, вашият асистент иска Ai балона. Проблемът е, че имате само M балона.

За щастие може да давате бонбони вместо балони на асистента си. На поредния ден i
той е съгласен да получи Bi бонбона за всеки балон който не сте му дали, или по-формално казано, ако му дадете Xi балона на ден i, тогава трябва да му дадете и Ci = max(0, Ai - Xi) * Bi бонбона.

Задачата ви е да минимизирате максималният брой бонбони, които трябва да дадете на асистента си в един ден − намерете минималната възможна стойност на max(C1,C2,...,Cn).

Input Format

На първият ред от входа ще са дадени числата N
и M.

На вторият ред от входа ще бъдат дадени числата A1, A2,...,An.

На третият ред от входа ще бъдат дадени числата B1,B2,...,Bn.

Constraints

1 ≤ 10^5

N ≤ M ≤ 10^18

0 ≤ Ai ≤ 10^9

0 ≤ Bi ≤ 10^9

Output Format

Изведете едно число - минималната стойност на max(C1,C2,...,Cn).

Sample Input 0

5 3

1 2 3 4 5

1 2 3 4 5

Sample Output 0

15

Explanation 0

Оптималното разпределение на балоните по дни е (0, 0, 0, 1, 2) което води и до отговора 15 (бонбоните които ще трябва да дадете на 5тия ден).

(Ограничението N <= M е изпълено във всички останали тестове, тук М е по-млако за по-лесно разписване на теста)

Sample Input 1

5 6

1 3 3 3 2

4 1 5 3 7

Sample Output 1

5

Explanation 1

Оптималното разпределение на балоните по дни е (0, 0, 2, 2, 2) което води и до отговора 5 (бонбоните които ще трябва да дадете на 3тия ден).
