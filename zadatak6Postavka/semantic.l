%option noyywrap yylineno

%{
   #include <string.h>
   #include "semantic.tab.h"
   #include "defs.h"
%}
/*"private" 	         { yylval.i = PRIVATE; 
                       return _ACCESS_SPECIFIER;}	
"public"  	         { yylval.i = PUBLIC; 
                       return _ACCESS_SPECIFIER;}	*/
%%

[ \t\n]+             { /* skip */ }


"double"						 { yylval.i = DOUBLE; return _TYPE; } 
"boolean" 					 { yylval.i = BOOLEAN; return _TYPE; }
"byte" 	 					   { yylval.i = BYTE; return _TYPE; }
"char" 	 					   { yylval.i = CHAR; return _TYPE; }
"long" 		 					 { yylval.i = LONG; return _TYPE; }
"short" 					   { yylval.i = SHORT; return _TYPE; }
"float"  					   { yylval.i = FLOAT; return _TYPE; }
"void"  					   { yylval.i = VOID; return _TYPE; }
"String"						 { yylval.i = STRING; return _TYPE; }

"static"					   { return _STATIC; }


"private" 	         { yylval.i = PRIVATE; 
                       return _ACCESS_SPECIFIER;}	
"public"  	         { yylval.i = PUBLIC; 
                       return _ACCESS_SPECIFIER;}

"this"							 { return _THIS; }

"for"								 { return _FOR; } 	
"continue" 					 { return _CONTIUNE; }
"break"							 { return _BREAK; }

"new"								 {return _NEW; } 
"class"							 {return _CLASS; }



"int"                { yylval.i = INT;  return _TYPE; }
"unsigned"           { yylval.i = UINT; return _TYPE; }
"if"                 { return _IF; }
"else"               { return _ELSE; }
"return"             { return _RETURN; }

"("                  { return _LPAREN; }
")"                  { return _RPAREN; }
"{"                  { return _LBRACKET; }
"}"                  { return _RBRACKET; }
";"                  { return _SEMICOLON; }
"="                  { return _ASSIGN; }
"do"		     				 { return _DO; }
"while"		     			 { return _WHILE; }


"+"                  { yylval.i = ADD; return _AROP; }
"-"                  { yylval.i = SUB; return _AROP; }
"++"		     				 { return _INC; }

"<"                  { yylval.i = LT; return _RELOP; }
">"                  { yylval.i = GT; return _RELOP; }
"<="                 { yylval.i = LE; return _RELOP; }
">="                 { yylval.i = GE; return _RELOP; }
"=="                 { yylval.i = EQ; return _RELOP; }
"!="                 { yylval.i = NE; return _RELOP; }
","		     					 { return _COMMA; }


[A-Z][a-zA-Z0-9]* { yylval.s = strdup(yytext); 
                       return _CLASSNAME; }

[a-zA-Z][a-zA-Z0-9]* { yylval.s = strdup(yytext); 
                       return _ID; }

[+-]?[0-9]{1,10}     { yylval.s = strdup(yytext); 
                       return _INT_NUMBER;}
[0-9]{1,10}[uU]      { yylval.s = strdup(yytext); 
                       yylval.s[yyleng-1] = 0;
                       return _UINT_NUMBER;}

\/\/.*               { /* skip */ }
.                    { printf("line %d: LEXICAL ERROR on char %c\n", yylineno, *yytext);}
%%
