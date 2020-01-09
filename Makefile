#----------------------------------------------------------------------------
#       Macros
#----------------------------------------------------------------------------
CC            = gcc
CXX           = g++
LD            = $(CXX) $(CCFLAGS) $(CPPFLAGS)
AR            = ar
PICFLAGS      = -fPIC
CPPFLAGS      = $(PICFLAGS) $(GENFLAGS) -std=c++11 -D_REENTRANT -I"./headers" -I"./source" -I"./inline" -I"./bin" -I"./template"
OBJEXT        = .o
OUTPUT_OPTION = -o "$@"
COMPILE.c     = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc    = $(CXX) $(CCFLAGS) $(CPPFLAGS) -c
LDFLAGS       = -L"."
CCC           = $(CXX)
MAKEFILE      = Makefile.assignment3
DEPENDENCIES  = .depend.$(MAKEFILE)
BTARGETDIR    = ./bin/
BIN           = $(BTARGETDIR)assignment3.exe$(EXESUFFIX)$(EXEEXT)
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
OBJS          = ./source/Add_Expr_Command$(OBJEXT) ./source/Bin_Expr_Command$(OBJEXT) ./source/Divide_Expr_Command$(OBJEXT) ./source/Expr_Command$(OBJEXT) ./source/Expr_Command_Factory$(OBJEXT) ./source/Infix_Expr_Evaluator$(OBJEXT) ./source/Mod_Expr_Command$(OBJEXT) ./source/Multiply_Expr_Command$(OBJEXT) ./source/Num_Expr_Command$(OBJEXT) ./source/Stack_Expr_Command_Factory$(OBJEXT) ./source/Subtract_Expr_Command$(OBJEXT) ./source/Unary_Expr_Command$(OBJEXT) ./source/driver$(OBJEXT)
SRC           = ./source/Add_Expr_Command.cpp ./source/Bin_Expr_Command.cpp ./source/Divide_Expr_Command.cpp ./source/Expr_Command.cpp ./source/Expr_Command_Factory.cpp ./source/Infix_Expr_Evaluator.cpp ./source/Mod_Expr_Command.cpp ./source/Multiply_Expr_Command.cpp ./source/Num_Expr_Command.cpp ./source/Stack_Expr_Command_Factory.cpp ./source/Subtract_Expr_Command.cpp ./source/Unary_Expr_Command.cpp ./source/driver.cpp
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

./source/Add_Expr_Command$(OBJEXT): ./source/Add_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Add_Expr_Command.cpp

./source/Bin_Expr_Command$(OBJEXT): ./source/Bin_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Bin_Expr_Command.cpp

./source/Divide_Expr_Command$(OBJEXT): ./source/Divide_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Divide_Expr_Command.cpp

./source/Expr_Command$(OBJEXT): ./source/Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Expr_Command.cpp

./source/Expr_Command_Factory$(OBJEXT): ./source/Expr_Command_Factory.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Expr_Command_Factory.cpp

./source/Infix_Expr_Evaluator$(OBJEXT): ./source/Infix_Expr_Evaluator.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Infix_Expr_Evaluator.cpp

./source/Mod_Expr_Command$(OBJEXT): ./source/Mod_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Mod_Expr_Command.cpp

./source/Multiply_Expr_Command$(OBJEXT): ./source/Multiply_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Multiply_Expr_Command.cpp

./source/Num_Expr_Command$(OBJEXT): ./source/Num_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Num_Expr_Command.cpp

./source/Stack_Expr_Command_Factory$(OBJEXT): ./source/Stack_Expr_Command_Factory.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Stack_Expr_Command_Factory.cpp

./source/Subtract_Expr_Command$(OBJEXT): ./source/Subtract_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Subtract_Expr_Command.cpp

./source/Unary_Expr_Command$(OBJEXT): ./source/Unary_Expr_Command.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/Unary_Expr_Command.cpp

./source/driver$(OBJEXT): ./source/driver.cpp
	$(COMPILE.cc) $(EXPORTFLAGS) $(OUTPUT_OPTION) ./source/driver.cpp

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
