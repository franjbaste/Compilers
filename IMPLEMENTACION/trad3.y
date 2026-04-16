%{                          // SECCION 1 Declaraciones de C-Yacc
/*
Grupo 84: Fran Jurado Basté, Sergio González Jiménez
Correos: 100522213@alumnos.uc3m.es, 100522264@alumnos.uc3m.es
*/

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *my_malloc (int);
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

// MIS DECLARACIONES
extern int in_function ;          
extern char current_func[256] ;
char* get_var_name(char *name);
void add_local(char *name);
int is_local(char *name);
void clear_locals();


char temp [2048] ;

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr

%}

// Definitions for explicit attributes

%token NUMBER        
%token IDENTIF       // Identificador=variable
%token INTEGER       // identifica el tipo entero
%token STRING
%token MAIN          // identifica el comienzo del proc. main
%token WHILE         // identifica el bucle main
%token PUTS
%token PRINTF
%token AND OR EQ NEQ LEQ GEQ
%token IF ELSE
%token FOR INC DEC
%token SWITCH CASE DEFAULT BREAK
%token RETURN

%right '='                    // es la ultima operacion que se debe realizar
%left OR
%left AND
%left EQ NEQ
%left '<' '>' LEQ GEQ
%left '+' '-'                 // menor orden de precedencia
%left '*' '/' '%'             // orden de precedencia intermedio
%left UNARY_SIGN '!'          // mayor orden de precedencia

%%                            // Seccion 3 Gramatica - Semantico

axioma:       sentencia ';'              { printf ("%s\n", $1.code) ; }
                r_axioma                 { ; }
            | funcion_main               { printf ("%s\n", $1.code) ; } 
                r_axioma                 { ; }
            | funcion_user               { printf ("%s\n", $1.code) ; }   
                r_axioma                 { ; }
            ;
            ;

inicio_main:  MAIN '(' ')' '{'           { in_function = 1 ; strcpy(current_func, "main") ; } 
            ;

funcion_main: inicio_main lista_sentencias '}' { 
                  sprintf (temp, "(defun main ()\n%s\n)", $2.code) ;
                  $$.code = gen_code (temp) ; 
                  in_function = 0 ; clear_locals() ; // Limpiamos al salir
              }
            ;

funcion_user: IDENTIF '(' lista_params_def ')' '{' 
                  { in_function = 1; strcpy(current_func, $1.code); } 
                  lista_sentencias '}' 
                  { 
                      sprintf (temp, "(defun %s (%s)\n%s\n)", $1.code, $3.code, $7.code) ;
                      $$.code = gen_code (temp) ; 
                      in_function = 0 ; clear_locals() ; 
                  }
                ;

lista_params_def: /* vacio */                    { $$.code = gen_code("") ; }
                | param_def                      { $$ = $1 ; }
                | lista_params_def ',' param_def { 
                      sprintf (temp, "%s %s", $1.code, $3.code) ;
                      $$.code = gen_code (temp) ; 
                  }
                ;

param_def:        INTEGER IDENTIF                { $$ = $2 ; }
                ;

instruccion:  sentencia ';'          { $$ = $1 ; }
            | bucle_while            { $$ = $1 ; }
            | sentencia_if           { $$ = $1 ; }
            | bucle_for              { $$ = $1 ; }
            | sentencia_switch       { $$ = $1 ; }
            ;

lista_sentencias: instruccion                        { $$ = $1 ; }
                | lista_sentencias instruccion       { 
                      sprintf (temp, "%s\n%s", $1.code, $2.code) ;
                      $$.code = gen_code (temp) ; 
                  }
                ;



lista_elems:  elem                       { $$ = $1 ; }
            | lista_elems ',' elem       { sprintf (temp, "%s %s", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            ;

elem:         expresion                  { sprintf (temp, "(princ %s)", $1.code) ;
                                           $$.code = gen_code (temp) ; }
            | STRING                     { sprintf (temp, "(princ \"%s\")", $1.code) ;
                                           $$.code = gen_code (temp) ; }
            ;





r_axioma:                                { ; }
            |   axioma                   { ; }
            ;

sentencia:   IDENTIF '=' expresion      { sprintf (temp, "(setf %s %s)", get_var_name($1.code), $3.code) ; 
                                           $$.code = gen_code (temp) ; }
            | IDENTIF '[' expresion ']' '=' expresion { 
                                           sprintf (temp, "(setf (aref %s %s) %s)", get_var_name($1.code), $3.code, $6.code) ; 
                                           $$.code = gen_code (temp) ; }
            | declaracion                { $$ = $1 ; }
            | PUTS '(' STRING ')'        { sprintf (temp, "(print \"%s\")", $3.code) ;  
                                           $$.code = gen_code (temp) ; }
            | PRINTF '(' STRING ',' lista_elems ')' { $$ = $5 ; } // 
            | IDENTIF '(' ')'                { sprintf(temp, "(%s)", $1.code); $$.code = gen_code(temp); }
            | IDENTIF '(' lista_args ')'     { sprintf(temp, "(%s %s)", $1.code, $3.code); $$.code = gen_code(temp); }
            | RETURN expresion               { sprintf(temp, "(return-from %s %s)", current_func, $2.code); $$.code = gen_code(temp); }
            ;
          




declaracion:  INTEGER lista_vars         { $$ = $2 ; }
            ;

lista_vars:   var_init                   { $$ = $1 ; }
            | lista_vars ',' var_init    { sprintf (temp, "%s %s", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            ;

var_init:     IDENTIF                    { 
                                           char *vname = $1.code ;
                                           if (in_function) { add_local(vname); vname = get_var_name(vname); }
                                           sprintf (temp, "(setq %s 0)", vname) ;
                                           $$.code = gen_code (temp) ; 
                                         }
            | IDENTIF '=' NUMBER         { 
                                           char *vname = $1.code ;
                                           if (in_function) { add_local(vname); vname = get_var_name(vname); }
                                           sprintf (temp, "(setq %s %d)", vname, $3.value) ;
                                           $$.code = gen_code (temp) ; 
                                         }
            | IDENTIF '[' NUMBER ']'     { 
                                           char *vname = $1.code ;
                                           if (in_function) { add_local(vname); vname = get_var_name(vname); }
                                           sprintf (temp, "(setq %s (make-array %d))", vname, $3.value) ;
                                           $$.code = gen_code (temp) ; 
                                         }
            ;
            ;


bucle_while:  WHILE '(' expresion ')' '{' lista_sentencias '}' { 
                  sprintf (temp, "(loop while %s do\n%s\n)", $3.code, $6.code) ;
                  $$.code = gen_code (temp) ; 
              }
            ;


incremento:   INC '(' IDENTIF ')'    { 
                                         sprintf(temp, "(setf %s (+ %s 1))", get_var_name($3.code), get_var_name($3.code));
                                         $$.code = gen_code(temp); 
                                     }
            | DEC '(' IDENTIF ')'    { 
                                         sprintf(temp, "(setf %s (- %s 1))", get_var_name($3.code), get_var_name($3.code));
                                         $$.code = gen_code(temp); 
                                     }
            ;

bucle_for:    FOR '(' sentencia ';' expresion ';' incremento ')' '{' lista_sentencias '}' { 
                  sprintf(temp, "%s\n(loop while %s do\n%s\n%s\n)", $3.code, $5.code, $10.code, $7.code);
                  $$.code = gen_code(temp); 
              }
            ;


sentencia_switch: SWITCH '(' expresion ')' '{' lista_casos '}' { 
                      sprintf(temp, "(case %s\n%s\n)", $3.code, $6.code);
                      $$.code = gen_code(temp); 
                  }
                ;

lista_casos:      caso_switch                  { $$ = $1 ; }
                | lista_casos caso_switch      { 
                      sprintf(temp, "%s\n%s", $1.code, $2.code);
                      $$.code = gen_code(temp); 
                  }
                ;

caso_switch:      CASE NUMBER ':' lista_sentencias BREAK ';' { 
                      sprintf(temp, "(%d\n%s)", $2.value, $4.code);
                      $$.code = gen_code(temp); 
                  }
                | DEFAULT ':' lista_sentencias BREAK ';' { 
                      sprintf(temp, "(otherwise\n%s)", $3.code);
                      $$.code = gen_code(temp); 
                  }
                ;



sentencia_if: IF '(' expresion ')' '{' lista_sentencias '}' { 
                  sprintf (temp, "(if %s\n(progn\n%s\n))", $3.code, $6.code) ;
                  $$.code = gen_code (temp) ; 
              }
            | IF '(' expresion ')' '{' lista_sentencias '}' ELSE '{' lista_sentencias '}' { 
                  sprintf (temp, "(if %s\n(progn\n%s\n)\n(progn\n%s\n))", $3.code, $6.code, $10.code) ;
                  $$.code = gen_code (temp) ; 
              }
            ;



expresion:      termino                  { $$ = $1 ; }
            |   expresion '+' expresion  { sprintf (temp, "(+ %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '-' expresion  { sprintf (temp, "(- %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '*' expresion  { sprintf (temp, "(* %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   expresion '/' expresion  { sprintf (temp, "(/ %s %s)", $1.code, $3.code) ;
                                           $$.code = gen_code (temp) ; }
            | expresion '%' expresion  { sprintf (temp, "(mod %s %s)", $1.code, $3.code) ;
                                         $$.code = gen_code (temp) ; }
            | expresion '<' expresion  { sprintf (temp, "(< %s %s)", $1.code, $3.code) ;
                                         $$.code = gen_code (temp) ; }
            | expresion '>' expresion  { sprintf (temp, "(> %s %s)", $1.code, $3.code) ;
                                         $$.code = gen_code (temp) ; }
            | expresion LEQ expresion  { sprintf (temp, "(<= %s %s)", $1.code, $3.code) ;
                                         $$.code = gen_code (temp) ; }
            | expresion GEQ expresion  { sprintf (temp, "(>= %s %s)", $1.code, $3.code) ;
                                         $$.code = gen_code (temp) ; }
            | expresion EQ expresion   { sprintf (temp, "(= %s %s)", $1.code, $3.code) ;
                                         $$.code = gen_code (temp) ; }
            | expresion NEQ expresion  { sprintf (temp, "(/= %s %s)", $1.code, $3.code) ;
                                         $$.code = gen_code (temp) ; }
            | expresion AND expresion  { sprintf (temp, "(and %s %s)", $1.code, $3.code) ;
                                         $$.code = gen_code (temp) ; }
            | expresion OR expresion   { sprintf (temp, "(or %s %s)", $1.code, $3.code) ;
                                         $$.code = gen_code (temp) ; }
            ;

termino:        operando                           { $$ = $1 ; }                          
            |   '+' operando %prec UNARY_SIGN      { $$ = $1 ; }
            |   '-' operando %prec UNARY_SIGN      { sprintf (temp, "(- %s)", $2.code) ;
                                                     $$.code = gen_code (temp) ; }
            | '!' operando %prec UNARY_SIGN      { sprintf (temp, "(not %s)", $2.code) ;
                                                   $$.code = gen_code (temp) ; }
            ;

operando:       IDENTIF                    { sprintf (temp, "%s", get_var_name($1.code)) ;
                                           $$.code = gen_code (temp) ; }
            |   IDENTIF '[' expresion ']'  { sprintf (temp, "(aref %s %s)", get_var_name($1.code), $3.code) ;
                                           $$.code = gen_code (temp) ; }
            |   NUMBER                   { sprintf (temp, "%d", $1.value) ;
                                           $$.code = gen_code (temp) ; }
            |   '(' expresion ')'        { $$ = $2 ; }
            | IDENTIF '(' ')'                { sprintf(temp, "(%s)", $1.code); $$.code = gen_code(temp); }
            | IDENTIF '(' lista_args ')'     { sprintf(temp, "(%s %s)", $1.code, $3.code); $$.code = gen_code(temp); }
            ;


lista_args:   expresion                      { $$ = $1 ; }
            | lista_args ',' expresion       { sprintf (temp, "%s %s", $1.code, $3.code) ; $$.code = gen_code (temp) ; }
            ;


%%                            // SECCION 4    Codigo en C

int n_line = 1 ;


// --- GESTIÓN DE VARIABLES LOCALES ---
char local_vars[100][256] ;
int num_locals = 0 ;
int in_function = 0 ;           // Bandera: 1 si estamos dentro de una función
char current_func[256] = "" ;   // Nombre de la función actual

void add_local (char *name) {
    strcpy (local_vars[num_locals++], name) ;
}

int is_local (char *name) {
    for (int i = 0; i < num_locals; i++) {
        if (strcmp (local_vars[i], name) == 0) return 1 ; // Es local
    }
    return 0 ; // Es global
}

void clear_locals () {
    num_locals = 0 ;
}

char* get_var_name (char *name) {
    if (is_local (name)) {
        // Si es local, devolvemos "funcion_variable"
        char *new_name = my_malloc (strlen(current_func) + strlen(name) + 2) ;
        sprintf (new_name, "%s_%s", current_func, name) ;
        return new_name ;
    }
    return name ; // Si es global, devolvemos el nombre normal
}
// ------------------------------------



int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%d", n) ;

    return gen_code (ltemp) ;
}

char *char_to_string (char c)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%c", c) ;

    return gen_code (ltemp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "puts",        PUTS,
    "printf",      PRINTF,
    "&&",          AND,            
    "||",          OR,
    "==",          EQ,
    "!=",          NEQ,
    "<=",          LEQ,
    ">=",          GEQ,
    "while",       WHILE, 
    "if",          IF,            
    "else",        ELSE, 
    "for",         FOR,           
    "inc",         INC,
    "dec",         DEC,   
    "switch",      SWITCH,        
    "case",        CASE,
    "default",     DEFAULT,
    "break",       BREAK,    
    "return",      RETURN,  
    NULL,          0
                  // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
