con = open('program2.c').read()

str = con.replace('$', "%c")
str = str.replace('\n', "%c")
str = str.replace('\t', "%c")
str = str.replace('"', "%c")

l = [{'$':37, '\n':10, '\t':9, '"':34}[c] for c in con if c in ['$\n\t"']]
