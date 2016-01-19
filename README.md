# Compiling

Run `make`

*Sometimes it appears that the system version of ncurses is not up to date sufficiently to compile.  In which case run:*
```
brew install ncurses
brew link ncurses --force
```
*It should work now*

# Usage

*Note: Make sure terminal window is at least 20 rows long and 40 columns wide*

Run `./gameOfLife`
...and enjoy!

# Cleanup

Run `make clean`
