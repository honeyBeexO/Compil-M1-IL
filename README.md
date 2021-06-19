# Compil-M1-IL

### Compile with:

[-1] flex lexical.l ## change: lexical.l to your <lexical_file_name.l>
[-2] bison -d syntax.y ## change: syntax.y to your <syntax_file_name.y>
[-3] cc lex.yy.c syntax.tab.c -ll -ly ## name_of_file.yy.c and name_file.tab.c
[-4] ./a.out name_of_your_programme.txt
