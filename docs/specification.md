# Specification

Below is a formal language specification provided in a EBNF-like notation. 

### Comments

Single-line comments start with //. Multi-line comments start with /* and end with */.

### Protocols

```
protocol =
    'protocol' identifier 
    ['(' major_version ',' minor_version ')'] {note} 
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
```

### Constants

```
const = 
    boolean_const | 
    char_const | 
    integer_const | 
    unsigned_integer_const | 
    real_const | 
    string_const;

boolean_const = 
    'const' 'bool' ['?'] identifier 
    '=' 
    boolean_literal {note} ';';

char_const = 
    'const' 'char' ['?'] identifier 
    '=' 
    char_literal {note} ';';

integer_const = 
    'const' integer_const_type ['?'] identifier 
    '=' 
    integer_literal {note} ';';

integer_const_type =
    'int8' |
    'int16' |
    'int32' | 
    'int32' | 
    'int64';

unsigned_integer_const = 
    'const' unsigned_integer_const_type ['?'] identifier 
    '=' 
    unsigned_integer_literal {note} ';';

unsigned_integer_const_type =
    'uint8' | 
    'uint16' | 
    'uint32' | 
    'uint64';

real_const = 
    'const' 'double' ['?'] identifier 
    '=' 
    real_literal {note} ';';

string_const = 
    'const' 'string' ['?'] identifier 
    '=' 
    string_literal {note} ';';
```

### Enumerations

```
enum =
    'enum' identifier {note}
    ('{' [enum_member {',' enum_member}] '}' | ';');

enum_member =
    identifier 
    ['=' unsigned_integer_literal] {note};
```

### Sets

```
set = 
    'set' identifier {note} 
    ('{' [set_member {',' set_member}] '}' | ';');

set_member = 
    identifier ['=' unsigned_integer_literal] {note};
```

### Groups

```
group = 
    'group' identifier {note} 
    ('{' {field | ';'} '}' | ';');
```

### Messages

```
message = 
    'message' identifier 
    ['@' message_id]
    [':' super_message_reference] {note} 
    ('{' {field | ';'} '}' | ';');

message_id = 
    unsigned_integer_identifier;

super_message_reference = 
    message_reference;
```

### Fields

```
field = 
    field_type ['?'] ['[' ']'] identifier 
    ['@' field_id] {note} ';';

field_type = 
    'bool' |
    'char' |
    'uchar' |
    'int8' |
    'uint8' |
    'int16' |
    'uint16' |
    'int32' |
    'uint32' |
    'int64' |
    'uint64' |
    'double' |
    'timestamp' |
    'string' |
    'ustring' |
    'bytes' |
    enum_reference |
    set_reference |
    group_reference;

field_id = 
    unsigned_integer_literal;
```

### Blocs

```
bloc = 
    'bloc' identifier '(' ')' {note}
    ('{' {statement | ';'} '}' | ';');
```

### Procedures

```
proc = 
    'proc' identifier '(' [proc_id_type] ')' 
    [':' proc_reference '(' [message_reference_expression {',' message_reference_expression} | field_reference_expression {',' field_reference_expression}] ')'] {note} 
    ('{' {statement | ';'} '}' | '=' proc_reference  | '=!' proc_reference | ';');

proc_id_type = 
    'int8' | 
    'uint8' |
    'int16' | 
    'uint16' | 
    'int32' | 
    'uint32' | 
    'int64' | 
    'uint64' | 
    'string' | 
    'ustring';
```

### Statements

```
statement = 
    recsen | 
    repeat | 
    return | 
    loop | 
    continue | 
    break | 
    call | 
    disconnect;

recsen = 
    ['@' identifier] operation {'or' operation};

repeat = 
    ['@' identifier] 'repeat' [recsen_reference] ';';

return = 
    ['@' identifier] 'return' ';';

loop = 
    ['@' identifier] 'loop' 
    (statement | '{' {statement | ';'} '}' | ';');

continue = 
    ['@' identifier] 'continue' [loop_reference] ';';

break = 
    ['@' identifier] 'break' [loop_reference] ';';

call = 
    ['@' identifier] bloc_reference '(' ')' ';';

disconnect = 
    ['@' identifier] 'disconnect' ';';
```

### Operations

```
operation = 
    (('recv' | 'send') [identifier] ['(' [message_reference_expression {',' message_reference_expression}] ')'] {note}) |
    (block_reference '(' ')')
    (statement | '{' {statement} '}' | ';');
```

### References

```
message_reference_expression = 
    message_reference [':' expression];

field_reference_expression = 
    message_reference '.' field_reference [':' expression];

const_reference = 
    identifier;

enum_member_reference = 
    enum_reference '.' identifier;

enum_reference = 
    identifier;

set_member_reference = 
    set_reference '.' identifier;

set_reference = 
    identifier;

group_reference = 
    identifier;

field_reference = 
    identifier {'.' identifier};

message_reference = 
    identifier;

recsen_reference = 
    identifier;

loop_reference = 
    identifier;

bloc_reference = 
    identifier;

proc_reference = 
    identifier;
```

### Expressions

```
expression = 
    expression_1 | expression '||' expression_1;

expression_1 = 
    expression_2 | expression_1 '&&' expression_2;

expression_2 = 
    expression_3 | expression_2 ('==' | '!=' | '<' | '<=' | '>' | '>=') expression_3;

expression_3 = 
    expression_4 | '!' expression_4;

expression_4 = 
    expression_5 | '(' expression ')';

expression_5 = 
    [message_reference '.'] field_reference | 
    const_reference | 
    enum_member_reference | 
    set_member_reference |
    boolean_literal | 
    char_literal | 
    integer_literal | 
    unsigned_integer_literal |
    real_literal |
    string_literal |
    null_literal;
```

### Identifiers

```
identifier = 
    (alpha | '_') {alpha | digit | '_'};
```

### Literals

```
boolean_literal = 
    'true' | 'false';

char_literal = 
    ''' char ''';

integer_literal = 
    ['-'] digit {digit};

unsigned_integer_literal = 
    digit {digit};

real_literal = 
    ['-'] digit {digit} ['.' digit {digit}];

string_literal = 
    '"' {schar | '\"'} '"';

null_literal = 
    'null'
```

### Notes

```
note = 
    '`' {nchar | '\`' | '\;' | '\,' | '\{' | '\}'};
```

### Characters

```
alpha = 
    ? any alpha character ?

digit = 
    ? any numeric character ?

schar = 
    ? any character except " ?

nchar = 
    ? any character except ` ; , { } LF ?

char = 
    ? any character ?
```
