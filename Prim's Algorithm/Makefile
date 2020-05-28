#################################################################
# Read the handout makeandmakefile.pdf for details.
# variables, flags for CFLAGS
# -Wall flags all errors
# -Werror treats warning as an error
# -g  includes symbol table to help gdb
#
# ****** do not change the CFLAGS line **** 
#
#################################################################
CFLAGS  = -g -Wformat-security -Wall -Wextra -Werror -ansi
LDFLAGS = 
CC	= gcc
LD	= gcc

TARG1	= a5		## modify as needed
OBJS1   = a5.o






#################################################################
# rules:
# indented lines have a tab (^I) at the start of line!!
#################################################################
all: $(TARG1)

$(TARG1): $(OBJS1)
	$(LD) $(OBJS1) $(LDFLAGS) -o $(TARG1)




%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARG1) $(TARG2) $(TARG3) $(TARG4) 

#################################################################
# dependencies -- none in this program
#################################################################
