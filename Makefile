hello: hello.c
	clang -Wall -Wextra -std=c2x -pedantic -o hello.out hello.c

foo: foo.c bar.c 
	clang -Wall -Wextra -std=c2x -pedantic -o foo.out foo.c bar.c

args: args.c
	clang -Wall -Wextra -std=c2x -pedantic -o args.out args.c

envvars: envvars.c
	clang -Wall -Wextra -std=c2x -pedantic -o envvars.out envvars.c
