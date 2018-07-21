Single-line comments start with //. Multi-line comments start with /* and end with */.

## Protocols

```
protocol = 'protocol' identifier ['(' major_version ',' minor_version ')'] {note} ('{' {protocol_member | ';'} '}' | ';');
major_version = unsigned_integer_literal;
minor_version = unsigned_integer_literal;
protocol_member = const | enum | set | group | message | bloc | proc;
```
