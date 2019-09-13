#----------------------------------------------------------------------------
#       Macros
#----------------------------------------------------------------------------
CC            = gcc
CXX           = g++
LD            = $(CXX) $(CCFLAGS) $(CPPFLAGS)
AR            = ar
PICFLAGS      = -fPIC
CPPFLAGS      = $(PICFLAGS) $(GENFLAGS) -std=c++11 -D_REENTRANT
OBJEXT        = .o
OUTPUT_OPTION = -o "$@"
COMPILE.c     = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc    = $(CXX) $(CCFLAGS) $(CPPFLAGS) -c
LDFLAGS       = -L"."
CCC           = $(CXX)
MAKEFILE      = Makefile.assignment3
DEPENDENCIES  = .depend.$(MAKEFILE)
BTARGETDIR    = ./
BIN           = $(BTARGETDIR)assignment3$(EXESUFFIX)$(EXEEXT)
CAT           = cat
MV            = mv -f
RM            = rm -rf
CP            = cp -p
NUL           = /dev/null
MKDIR         = mkdir -p
TESTDIRSTART  = test -d
TESTDIREND    = ||
TOUCH         = touch
EXEEXT        = 
LIBPREFIX     = lib
LIBSUFFIX     = 
GENFLAGS      = -O
LDLIBS        = -ldl $(subst lib,-l,$(sort $(basename $(notdir $(wildcard /usr/lib/librt.so /lib/librt.so))))) -lpthread
OBJS          = driver$(OBJEXT) Stack_Expr_Command_Factory$(OBJEXT) Infix_Expr_Evaluator$(OBJEXT) Add_Expr_Command$(OBJEXT) Subtract_Expr_Command$(OBJEXT) Multiply_Expr_Command$(OBJEXT) Divide_Expr_Command$(OBJEXT) Mod_Expr_Command$(OBJEXT) Bin_Expr_Command$(OBJEXT) Num_Expr_Command$(OBJEXT) Unary_Expr_Command$(OBJEXT) Expr_Command_Factory$(OBJEXT) Expr_Command$(OBJEXT)
SRC           = driver.cpp Stack_Expr_Command_Factory.cpp Infix_Expr_Evaluator.cpp Add_Expr_Command.cpp Subtract_Expr_Command.cpp Multiply_Expr_Command.cpp Divide_Expr_Command.cpp Mod_Expr_Command.cpp Bin_Expr_Command.cpp Num_Expr_Command.cpp Unary_Expr_Command.cpp Expr_Command_Factory.cpp Expr_Command.cpp
LINK.cc       = $(LD) $(LDFLAGS)
EXPORTFLAGS   = 
DEPLIBS       = $(foreach lib, , $(foreach libpath, ., $(wildcard $(libpath)/lib$(lib).a)))

#----------------------------------------------------------------------------
#       Local targets
#----------------------------------------------------------------------------

all: $(BIN)

$(BIN): $(OBJS) $(DEPLIBS)
	@$(TESTDIRSTART) "$(BTARGETDIR)" $(TESTDIREND) $(MKDIR) "$(BTARGETDIR)"
	$(LINK.cc) $(OBJS) $(LDLIBS) $(OUTPUT_OPTION)

generated: $(GENERATED_DIRTY)
	@-:

driver$(OBJEXT): driver.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) driver.cpp

Stack_Expr_Command_Factory$(OBJEXT): Stack_Expr_Command_Factory.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Stack_Expr_Command_Factory.cpp

Infix_Expr_Evaluator$(OBJEXT): Infix_Expr_Evaluator.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Infix_Expr_Evaluator.cpp

Add_Expr_Command$(OBJEXT): Add_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Add_Expr_Command.cpp

Subtract_Expr_Command$(OBJEXT): Subtract_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Subtract_Expr_Command.cpp

Multiply_Expr_Command$(OBJEXT): Multiply_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Multiply_Expr_Command.cpp

Divide_Expr_Command$(OBJEXT): Divide_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Divide_Expr_Command.cpp

Mod_Expr_Command$(OBJEXT): Mod_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Mod_Expr_Command.cpp

Bin_Expr_Command$(OBJEXT): Bin_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Bin_Expr_Command.cpp

Num_Expr_Command$(OBJEXT): Num_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Num_Expr_Command.cpp

Unary_Expr_Command$(OBJEXT): Unary_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Unary_Expr_Command.cpp

Expr_Command_Factory$(OBJEXT): Expr_Command_Factory.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Expr_Command_Factory.cpp

Expr_Command$(OBJEXT): Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) Expr_Command.cpp

clean:
	-$(RM) $(OBJS)

realclean: clean
	-$(RM) $(BIN)

check-syntax:
	$(COMPILE.cc) $(EXPORTFLAGS) -Wall -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

#----------------------------------------------------------------------------
#       Dependencies
#----------------------------------------------------------------------------


depend:
	-$(MPC_ROOT)/depgen.pl  $(CFLAGS) $(CCFLAGS) $(CPPFLAGS) -f $(DEPENDENCIES) $(SRC) 2> $(NUL)

-include $(DEPENDENCIES)

run:
	./assignment3

val:
	valgrind --tool=memcheck --log-file=Valgrind.txt ./assignment3
