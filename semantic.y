%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "defs.h"
  #include "symtab.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
	int type=-1;
	char *class_names[100];  
	int class_count = 0;
	int *class_name_size[100];
	int list_vars_type = -1;
	int func_count = 0;
	
%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token <i> _ACCESS_SPECIFIER
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token <s> _CLASSNAME
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _RELOP
%token _COMMA
%token _INC


%token _WHILE
%token _DO
%token _PRIVATE
%token _PROTECTED
%token _PUBLIC
%token _THIS

%token _FOR
%token _CONTIUNE
%token _BREAK
%token _NEW
%token _CLASS			//
%token _STATIC
%token _DOT

%type <i> num_exp exp literal function_call argument rel_exp

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : 
	| class_list
  ;

class_list
	: class
	| class_list class
	;
	

class
	: _ACCESS_SPECIFIER _CLASS _CLASSNAME {
	//provera da li postoji funkcija sa datim imenom
		/*	for (int i=0; i<class_count; i++) {
				printf("bam");
				printf("%s", $3);
				printf("%s", class_names[i]);
				printf("%d", *class_name_size[i]);
				if (strcmp($3, class_names[i])==0) {
					err("Class with name %s already exist in this file", class_names[i]);
				}
			}*/
			int cls_idx = lookup_symbol($3, CLS);
			
			if(cls_idx == NO_INDEX)
			{
        $<i>$ = insert_symbol($3, CLS, $1, NO_ATR, NO_ATR);
				//class_names[class_count] = $3;
				/*printf("jea");
				printf("%s", class_names[class_count]);
				class_names[class_count] = malloc(100);
				if (class_names[class_count]) {
            strcpy(class_names[class_count], $3);
        }*/
				printf("class_count %d", class_count);
    		class_count++;
				printf("class_count %d", class_count);
      }
      else 
        err("redefinition of class '%s'", $3);

	} class_statements {
		if (get_type($<i>4)==1) {
			 clear_symbols($<i>4);
		}
	  print_symtab();
	}
	;
	
class_statements
	: _LBRACKET class_variable_list constructor_list function_list _RBRACKET
	;

class_variable_list
	: 
  | class_variable_list class_variable
  ;

constructor_list
	: constructor
	;
constructor
	: _ACCESS_SPECIFIER _CLASSNAME _LPAREN _RPAREN _LBRACKET _constructor_body _RBRACKET
	;

_constructor_body
	: 
	| _constructor_body _constructor_row
	;

_constructor_row
	: _THIS _DOT _ID _ASSIGN _ID _SEMICOLON
	;

	
	
function_list
	: 
	| function_list function
	;
	
function
  : _ACCESS_SPECIFIER static _TYPE _ID
      {
				func_count++;
        fun_idx = lookup_symbol($4, FUN);
        if(fun_idx == NO_INDEX) {
          fun_idx = insert_symbol($4, FUN, $3, NO_ATR, class_count);
}
        else {
        	if (get_atr2(fun_idx)!=class_count) {
        		fun_idx = insert_symbol($4, FUN, $3, NO_ATR, class_count);
        	}
        	else 
          	err("redefinition of function '%s'", $4);
        }
      }
    _LPAREN parameter _RPAREN func_body
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
      }
  ;
  
static 
	: 
	| _STATIC
	;
  
parameter
  : /* empty */
      { set_atr1(fun_idx, 0); }

  | _TYPE _ID
      {
        insert_symbol($2, PAR, $1, 1, NO_ATR);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, $1);
      }
  ;
  
func_body
  : _LBRACKET variable_list 
  statement_list 
  _RBRACKET
  ;
  
statement_list 
	:
	| statement_list statement
	;
  
statement
	: for_statement
	//| expression_statement
	| inc_statement
	| assignment_statement
	;
	
inc_statement
	: _ID 
	{
		if (lookup_symbol($1, FUN)!=NO_INDEX) {
err("Postincrement may be only used on variables, not functions.");
		}
		int idx = lookup_symbol($1, VAR|PAR);
    if(idx == NO_INDEX)
      err("invalid lvalue '%s' in assignment", $1); 
	}
	_INC _SEMICOLON
	;		

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else
          if(get_type(idx) != get_type($3))
            err("incompatible types in assignment");
      }
  ;

for_statement
	: _FOR _LPAREN _TYPE _ID {
		fun_idx = lookup_symbol($4, FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($4, VAR, $3, ++var_num, NO_ATR);
        else 
          err("redefinition of '%s'", $4);
	} _ASSIGN 
	literal _SEMICOLON rel_exp _SEMICOLON _ID _INC _RPAREN _LBRACKET
	{
		func_count++; 
		$<i>$ = get_last_element(); 
	}
	 statement_list _RBRACKET
	{
	 	func_count--;
	 	clear_symbols($<i>15+1);
	}
	;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
      }
  ;
  
exp 
  : literal
  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
      }
  | function_call
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  ;
  
literal		
  : _INT_NUMBER
      { $$ = insert_literal($1, INT); }

  | _UINT_NUMBER
      { $$ = insert_literal($1, UINT); }
  ;
 
function_call
  : _ID 			
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
      }
    _LPAREN argument _RPAREN
      {
        if(get_atr1(fcall_idx) != $4)
          err("wrong number of args to function '%s'", 
              get_name(fcall_idx));
        set_type(FUN_REG, get_type(fcall_idx));
        $$ = FUN_REG;
      }
  ;

argument	
  : 
    { $$ = 0; }

  | num_exp
    { 
      if(get_atr2(fcall_idx) != get_type($1))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
      $$ = 1;
    }
  ;
  
num_exp		
  : exp
  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: arithmetic operation");
      }
  ;

	
variable_list
  : 
  | variable_list variable
  ;

variable
  : _TYPE { list_vars_type = $1; } vars _SEMICOLON
      {				
			//	int i = lookup_symbol($2, VAR|PAR);
				//if( (i != -1) && (get_atr2(i) == block) )
			//		err("redefinition of '%s'", $2);
			//	else 
				//	insert_symbol($2, VAR, $1, ++var_num, NO_ATR); // block
      }
  ;

class_variable
	: _TYPE { list_vars_type = $1; } class_line_vars _SEMICOLON 
  ;

class_line_vars
	: _ID {
		int idx = lookup_symbol($1, CLS_ATR);
		if(idx != -1)
			if (get_atr2(idx)!=class_count) {
			  insert_symbol($1, CLS_ATR, list_vars_type, ++var_num, class_count);
			}
			else	{
		  	err("redefinition of '%s'", $1);
			}
		else
		  insert_symbol($1, CLS_ATR, list_vars_type, ++var_num, class_count);
  }
  | class_line_vars _COMMA _ID
  {
    if(lookup_symbol($3, CLS_ATR) != -1)
      err("redefinition of '%s'", $3);
    else
      insert_symbol($3, CLS_ATR, list_vars_type, ++var_num, class_count);
  }
	;

vars
  : _ID {
	int idx = lookup_symbol($1, VAR|PAR);
  if(idx != -1 && get_atr2(idx)==func_count)
    err("redefinition of '%s'", $1);
  else
    insert_symbol($1, VAR, list_vars_type, ++var_num, func_count);
  }
  | vars _COMMA _ID
  {
    if(lookup_symbol($3, VAR|PAR) != -1)
      err("redefinition of '%s'", $3);
    else
      insert_symbol($3, VAR, list_vars_type, ++var_num, func_count);
  }
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();

  synerr = yyparse();

  clear_symtab();
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count)
    printf("\n%d error(s).\n", error_count);

  if(synerr)
    return -1; //syntax error
  else
    return error_count; //semantic errors
}

