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

TARG1	= qsortf		## modify as needed
OBJS1   = qsortf.o

TARG2 = qsortl
OBJS2 = qsortl.o

TARG3 = qsortm
OBJS3 = qsortm.o


TARG4 = qsortr
OBJS4 = qsortr.o


#################################################################
# rules:
# indented lines have a tab (^I) at the start of line!!
#################################################################
all: $(TARG1) $(TARG2) $(TARG3) $(TARG4)


$(TARG1): $(OBJS1)
	$(LD) $(OBJS1) $(LDFLAGS) -o $(TARG1)

$(TARG2): $(OBJS2)
	$(LD) $(OBJS2) $(LDFLAGS) -o $(TARG2)

$(TARG3): $(OBJS3)
	$(LD) $(OBJS3) $(LDFLAGS) -o $(TARG3)

$(TARG4): $(OBJS4)
	$(LD) $(OBJS4) $(LDFLAGS) -o $(TARG4)


%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARG1) $(TARG2) $(TARG3) $(TARG4) 

#################################################################
# dependencies -- none in this program
#################################################################
