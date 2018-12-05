#include	<stdio.h>
#include	"symbol.h"

/* The enumerated type for intermediate opcodes */
enum optype	{opnull,opadd, opsub, opneg, opmult, opdiv, opassn,
		oparg, opjump, opifposzjump, opifposjump, opifnegzjump,
		opifnegjump, opifzjump, opifnzjump, oplabel, opfunc,
		opproc,	opread, opwrite, opreturn
};


/*  The types of operands */
enum operandtype	{opnvar, opntempvar, opnconst, opnaddr, opnnull
			};

/*  Addresses hold the type of the operand and its
		symbol table index */
struct addressrec	{
	enum operandtype	opndtype;
        int			opnd;
};

/*  The format for quadruples which are
			used as intermediate code */
struct quadtype	{
	enum optype		opcode;
	struct addressrec	op1, op2, op3;
};


struct addressrec	setaddress(enum operandtype otype, int tabindex);
struct addressrec	gettempvar(enum datatype otype);
struct addressrec 	gettemplabel(void);

int		genquad(enum optype intopcode, struct addressrec a,
				struct addressrec b, struct addressrec c);

void		permtarget(struct addressrec a);
void		printintcode(void);
void 		permtarget(struct addressrec a);
void		printquad(int i);
struct quadtype	getquad(int i);
void		intpeephole(void);
int		intglobal(void);
int		getprogstart(void);
int		getnumcodes(void);