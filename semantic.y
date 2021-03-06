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
	int id_cls = 0;
	
	int constr_arg_count = 0;
	
	int return_count = 0;
	
	int lab_num = -1;
	
	int constr_type = -1;
	
	int ret_type = -1;
	
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
%token _CLASS			
%token _STATIC
%token _DOT

%type <i> num_exp exp literal function_call argument rel_exp if_part

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
			int cls_idx = lookup_symbol($3, CLS);
			
			if(cls_idx == NO_INDEX)
			{
        class_count++;
        $<i>$ = insert_symbol($3, CLS, $1, NO_ATR, class_count);
      }
      else 
        err("redefinition of class '%s'", $3);

	} class_statements {
		if (get_type($<i>4)==1) {
			 clear_symbols($<i>4+1);
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
	: 
	| constructor_list constructor
	;

constructor
	: _CLASSNAME {
		func_count++;
		int idx = lookup_symbol_last($1, CLS, class_count);
		if (idx==NO_INDEX) {
			err("Wrong constructor");
		}
		insert_symbol($1, CONSTR, NO_ATR, NO_ATR, class_count);
	} _LPAREN _constr_param_list _RPAREN  _LBRACKET _constructor_body _RBRACKET 
	;

_constr_param_list
	: {constr_type=-1; }
	| {constr_type=-1; } _constr_with_params
	;

_constr_with_params
	: _constr_param
	| _constr_with_params _COMMA _constr_param {
	}
	;

_constr_param
	: _TYPE {
		if (constr_type==-1)
			constr_type = $1;
		else {
			if (constr_type!=$1)
				err("parameter cannot be of VOID type");
		}
	} _ID	{
		insert_symbol($3, PAR, $1, NO_ATR, func_count);
		if($1 == VOID)
			err("parameter cannot be of VOID type");
	}
	;

_constructor_body
	: 
	| _constructor_body _constructor_row
	;

_constructor_row
	: _THIS _DOT _ID _ASSIGN _ID {

		int idx = lookup_symbol($3, CLS_ATR);
		if (idx==-1) {
			err("Variable is not declared in last class");
		}
		
		if (get_atr2(idx) != class_count) {
			err("Variable is not declared in last class");
		}
		
		if(lookup_symbol_last($5, PAR, func_count)==NO_INDEX) {
			if(lookup_symbol_last($5, CLS_ATR, class_count)==NO_INDEX) {
				err("value for param is not declared in this scope: '%s'", $5);
			}
		}
		
	} _SEMICOLON
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
          fun_idx = insert_symbol($4, FUN, $3, $1, class_count);
}
        else {
        	if (get_atr2(fun_idx)!=class_count) {
        		fun_idx = insert_symbol($4, FUN, $3, $1, class_count);
        	}
        	else 
          	err("redefinition of function '%s'", $4);
        }
        $<i>$ = fun_idx;
      }
    _LPAREN parameter _RPAREN func_body
      {
      
        if( (return_count == 0) && ($3 != VOID) ) 
					warn("Function should return a value");
				return_count = 0;
      
      	if ($1==1) {
      		clear_symbols($<i>5 + 1);
      	}
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
    		if($1 == VOID)
					err("parameter cannot be of VOID type");
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
	| make_object_statement
	| inc_statement
	| assignment_statement
	| return_statement
	| if_statement
	;

make_object_statement
	: _CLASSNAME {
		id_cls = lookup_symbol($1, CLS);
		if (id_cls == -1) 
			err("Class not found"); 
		$<i>$ = id_cls;
	} _ID {
		int id_index = lookup_symbol($3, VAR);
		if (id_index!=-1) {
			if (func_count==get_atr2(id_index)) {
				err("Redefinition of variable"); 
			}
		}
	} _ASSIGN _NEW _CLASSNAME {
		if (lookup_symbol($7, CLS)!=lookup_symbol($1, CLS))
			err("Class not the same"); 
		insert_symbol($3, VAR, $<i>2, ++var_num, func_count);
	} _LPAREN ids _RPAREN _SEMICOLON
	; 

ids 
	:
	| id_list
	;

id_list
	: _ID	{
		if(lookup_symbol_last($1, VAR|PAR, func_count)==NO_INDEX) {
			if(lookup_symbol_last($1, CLS_ATR, class_count)==NO_INDEX) {
				err("value for inc is not declared in this scope: '%s'", $1);
			}
		}
	}
	| id_list _COMMA _ID {
		if(lookup_symbol_last($3, VAR|PAR, func_count)==NO_INDEX) {
			if(lookup_symbol_last($3, CLS_ATR, class_count)==NO_INDEX) {
				err("value for inc is not declared in this scope: '%s'", $3);
			}
		}
	}
	;
	
inc_statement
	: _ID 
	{
		if (lookup_symbol($1, FUN)!=NO_INDEX) {
			err("Postincrement may be only used on variables, not functions.");
		}
		if(lookup_symbol_last($1, VAR|PAR, func_count)==NO_INDEX) {
			if(lookup_symbol_last($1, CLS_ATR, class_count)==NO_INDEX) {
				err("value for inc is not declared in this scope: '%s'", $1);
			}
		}
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
  

compound_statement
	: _LBRACKET statement _RBRACKET
	;
  

if_statement
  : if_part %prec ONLY_IF
  | if_part _ELSE compound_statement 
  ;

if_part
  : _IF _LPAREN
      {
        $<i>$ = ++lab_num;
      }
    rel_exp
    _RPAREN compound_statement
      {
        $$ = $<i>3;
      }
  ;

for_statement
	: _FOR _LPAREN _TYPE _ID {
		int fun_idx = lookup_symbol($4, FUN);
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
		printf("$<i>15 %d", $<i>15);
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
      if($1 == VOID)
				err("variable cannot be of VOID type");
      }
  ;

class_variable
	: _TYPE { list_vars_type = $1; } class_line_vars _SEMICOLON 
	{
    if($1 == VOID)
			err("variable cannot be of VOID type");
	}
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
		int idx = lookup_symbol($3, CLS_ATR);
		if(idx != -1)
			if (get_atr2(idx)!=class_count) {
			  insert_symbol($3, CLS_ATR, list_vars_type, ++var_num, class_count);
			}
			else	{
		  	err("redefinition of '%s'", $3);
			}
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
  
return_statement
: _RETURN num_exp _SEMICOLON
	{
		if(get_type(fun_idx) == VOID) 
			err("Function cannot return value");
		else if(get_type(fun_idx) != get_type($2))
			err("incompatible types in return");
		return_count++; 
	}
	| _RETURN _SEMICOLON
	{
		if(get_type(fun_idx) != VOID) 
		warn("Function should return a value");
		return_count++; 
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

