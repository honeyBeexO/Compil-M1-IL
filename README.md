# Compil-M1-IL

### Compile with:
[-] bison -d syntax.y
[-] flex lexical.l
[-] cc lex.yy.c syntax.tab.c -ll -ly
