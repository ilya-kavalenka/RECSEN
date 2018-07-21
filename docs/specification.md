Single-line comments start with //. Multi-line comments start with /* and end with */.

## Protocols

protocol = 
    'protocol' identifier ['(' major_version ',' minor_version ')'] 
    {note} 
    ('{' {protocol_member | ';'} '}' | ';');

major_version = 
    unsigned_integer_literal;

minor_version = 
    unsigned_integer_literal;

protocol_member =
    const |
    enum | 
    set | 
    group | 
    message |
    bloc |
    proc;

## Constants

const = 
    boolean_const | 
    char_const | 
    integer_const | 
    unsigned_integer_const | 
    real_const | 
    string_const;

boolean_const = 
    'const' 'bool' ['?'] identifier '=' boolean_literal {note} ';';

char_const = 
    'const' 'char' ['?'] identifier '=' char_literal {note} ';';

integer_const = 
    'const' ('int8' | 'int16' | 'int32' | 'int32' | 'int64') ['?'] identifier '=' integer_literal {note} ';';

unsigned_integer_const = 
    'const' ('uint8' | 'uint16' | 'uint32' | 'uint64') ['?'] identifier '=' unsigned_integer_literal {note} ';';

real_const = 
    'const' 'double' ['?'] identifier '=' real_literal {note} ';';

string_const = 
    'const' 'string' ['?'] identifier '=' string_literal {note} ';';
