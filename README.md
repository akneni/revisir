## Organization
DB -> A directory of files
File -> Each file will contain 4096 (2^12) blocks
Blocks -> Each block will be 8192 (2^13) bytes, it will contain 8136 bytes with some additional metadata

## File naming convention
- The filename will be the hexadecimal version of their order number (as an unsigned 64-bit integer) followed by the `.verdb` extension.