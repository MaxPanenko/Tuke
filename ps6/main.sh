# Del old
if [ -f program ]; then
	rm program
fi

# Build new
gcc program.c -o program -Wno-unused -lncurses

# Run
./program
