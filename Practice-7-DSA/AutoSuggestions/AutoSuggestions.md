Трябва да имплементирате една от най-важните функции на търсачките - Autocomplete. Например когато пишете думи в Google, техният Autocomplete ви предлага някакви възможности, базирани на написаното до момента.

За целта ви е даден речник с N на брой популярни думи - знаете, че тези думи са често търсени от потребителите и съответно трябва да ги предлагате, когато е възможно. Напишете програма, която да може бързо да намира по дадено начало на дума колко от думите от речника я autocomplete-ват (т.е на колко думи от речника е префикс).

Ще трябва да отговаряте на Q на брой заявки. Всяка заявка се състои от един низ - начало на дума. Програмата ви трябва да намери колко от думите в речника започват с дадения префикс.

Input Format

Първия ред на входа съдържа числата N и Q - съответно броят на думите в речника и броят на заявките.

На следващия ред има N низа - всички думи от речника.

Следват Q реда с по един низ - префиксът за който се търсят броят думи, които го autocomplete-ват.

Constraints

1 ≤ N ≤ 200 000

1 ≤ Q ≤ 200 000

1 ≤ дължина на дума от речника ≤ 20

1 ≤ дължина на префикс ≤ 20

Думите и префиксите се състоят само от малки латински букви.

Output Format

Изведете Q реда с по едно число за всеки префикс - съответно броят думи от речника, които го autocomplete-ват.

Sample Input 0

    4 5
    baba banica boza ba
    b
    ba
    ban
    bi
    a

Sample Output 0

    4
    3
    1
    0
    0

