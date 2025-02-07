## Organization
DB -> A directory of data files (in the `data` directory) and metadata files (in the `metadata` directory). The later contains metadata about the entire database. 
File -> Each file will contain data for 1024 (2^10) blocks. These files will be structures using semi-columnar storage: there will be type A (contains the bulk of the data) and type B (contains metadata) files. The files will also lead with a 64 bit encoding version number and a 64 bit integer determining how many blocks are in the file. 
``` c
// Pseudo code depicting what the encoding for a file will be like. 
typedef struct File {
    uint64_t encoding_version; // This is proposal 2, so the version number would be 2
    uint64_t length;
    Block blocks[1024]
};
```
Blocks -> Each block will be 8192 (2^13) bytes, it will contain 8136 bytes with some additional metadata.
    - `id`: ID of the file this block belongs to (the SHA256 hash of the file name). Stored in type B files.
    - `checksum`: The SHA256 hash. Stored in type B files.
    - `length`: Number of relevant bytes in the block. Stored in type B files.
    - `block_type`: Type of the block (Create, Update, Delete)
    - `unix_timestamp`: Time the entry was recorded. Stored in typeBA files.
    - `block_num`: The order of the block in its file. Stored in type B files.
    - `data`: The actual bytes stored in the file. Stored in type A files.

## File naming convention
- The filename will be the hexadecimal version of their order number (as an unsigned 64-bit integer) followed by the `-X.verdb` where `X` is either `A` or `B` depending on the type of file it is.

## Metadata File
The main metadata file (`metadata/metadata.bin`) will contain some global statistics. 
- Bytes backed-up
- Bytes used to store it. 
- Earliest date of any entry

## Object Metadata
The metadata will be stored in `metadata/XXXXX.bin` where `XXXXX` is the object's 256-bit key (as 64 hex characters). This metadata will have the following fields. 
- number of bytes contained within the object.
- Global checksum (SHA256 hash of all of the hashes of all the blocks) 
- checksums of all the blocks (variadic field)