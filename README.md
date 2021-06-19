# Compil-M1-IL

### Compile with:

```C
flex lexical.l
// change: lexical.l to your <lexical_file_name.l>
```

```C
bison -d syntax.y
// change: syntax.y to your <syntax_file_name.y>
```

```C
cc lex.yy.c syntax.tab.c -ll -ly
// change: name_of_file.yy.c and name_file.tab.c to your files
```

```C
./a.out name_of_your_programme.txt
```
